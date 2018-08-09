/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include "FS.h"

//int count = 0;
    int i =0;
    int j =0;
    int Col =16;
    int Row =16;
    int colnow = 0;
    int rownow = 0;
    int hri = 0;
    int right = 0;
    int left = 0;
    int playerturn=0;
    uint8 red[16][16];
    uint8 green[16][16];
    uint8 blue[16][16];
    #include "stdio.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

/* The size of the buffer is equal to maximum packet size of the 
*  IN and OUT bulk endpoints. 
*/
#define BUFFER_SIZE 1u
#define IN_EP 2u
#define OUT_EP 3u

char8 *parity[] = { "None", "Odd", "Even", "Mark", "Space" };
char8 *stop[] = { "1", "1.5", "2" };
uint16 count = 0;
uint16 count1 = 0;
uint16 bytesReceived = 0;

char8 wifiRxBuffer[64] = {0};
char8 tempstr[64] = {0};

uint8 RxBuffer0[BUFFER_SIZE] = {0};
uint8 RxBuffer1[BUFFER_SIZE] = {0};
uint8 size = 1;
uint8 rxCount = 0;

void USBwork();
void move(uint16 movement);
void wincheck(int length, int width);

typedef enum {
    WIFI_ADVERTISE,
    WIFI_CONNECT,
    WIFI_PLAY
}WifiState;

CY_ISR(InterruptHandler)
{
	/* Read Status register in order to clear the sticky Terminal Count (TC) bit 
	 * in the status register. Note that the function is not called, but rather 
	 * the status is read directly.
	 */
    for(i = 0; i < 8; i++)
    {
        if (i == 0){
            CBA_Write(7);
        }else CBA_Write(i-1);
        
        for(j=0; j < 32; j++)
        {
            if(j<16)
            {
               OE_Write(0);
                if(red[i][j]==0)
                {
                    red_Write(0);
                    
                }else if (red[i][j]==1)
                {
                    red_Write(1);
                }
                if(green[i][j]==0)
                {
                    green_Write(0);
                   
                }else if(green[i][j]==1)
                {
                    green_Write(1);
                }
                if(blue[i][j]==0)
                {
                    blue_Write(0);
                   
                }else if(blue[i][j]==1)
                {
                    blue_Write(1);
                }
                
                  if(red[i+8][j]==0)
                {
                    red2_Write(0);
                    
                }else if (red[i+8][j]==1)
                {
                    red2_Write(1);
                }
                if(green[i+8][j]==0)
                {
                    green2_Write(0);
                    
                }else if(green[i+8][j]==1)
                {
                    green2_Write(1);
                }
                if(blue[i+8][j]==0)
                {
                    blue2_Write(0);
                    
                }else if(blue[i+8][j]==1)
                {
                    blue2_Write(1);
                }
                if(blue[i][j]==1||red[i][j]==1||green[i][j]==1||blue[i+8][j]==1||red[i+8][j]==1||green[i+8][j]==1)
                {
                    OE_Write(0);
                }else
                {
                    OE_Write(1);
                }
                clk_Write(1);
                clk_Write(0);
            }
            
            if(j>15)
            {
                blue_Write(0);
                red_Write(0);
                green_Write(0);
                 blue2_Write(0);
                red2_Write(0);
                green2_Write(0);
                clk_Write(1);
                clk_Write(0);
                
                if (j == 31)
                {
                    OE_Write(1);
                    Latch_Write(1);
                    Latch_Write(0);
                }
            }
        }
    }
   	Timer_1_STATUS;
}

CY_ISR(RxHandler){
    uint8 rxStatus;
    
    rxStatus = UART_1_ReadRxStatus();
    
    while(rxStatus & UART_1_RX_STS_FIFO_NOTEMPTY){
        
        wifiRxBuffer[rxCount] = UART_1_ReadRxData();
        
        if(wifiRxBuffer[rxCount] == '\n'){
            while(USBUART_1_CDCIsReady() == 0u);
            
            strncpy(tempstr, wifiRxBuffer, rxCount);
            USBUART_1_PutData(tempstr, rxCount);;
            rxCount = 0;
            
        }else{
            rxCount++;
        }
        rxStatus = UART_1_ReadRxStatus();
    }
    if(rxCount >= 64){
        rxCount = 0;
    }
}

CY_ISR(TxHandler){
    
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    FS_Init();
    
//    char plays[]="Player One did another thing\n";
//    FS_FILE *pFile;
//    
//    pFile = FS_FOpen("log.txt", "w");
//    
//    if (pFile != 0) {
//        FS_FWrite(plays, 1, strlen(plays), pFile);
//        FS_FClose(pFile);
//    }
    
    uint16 count = 0;
    uint16 count1 = 0;
    uint16 bytesReceived = 0;
    
    
    uint8 RxBuffer0[BUFFER_SIZE] = {0};
    uint8 RxBuffer1[BUFFER_SIZE] = {0};
    uint8 size = 64;
    
    /* Enable Global Interrupts */
    CyGlobalIntEnable;                        

    //Start the UART
    UART_1_Start();
    /* Start USBFS Operation with 3V operation */
       USBUART_1_Start(0u, USBUART_1_3V_OPERATION);
       USBUART_1_CDC_Init();
       USBUART_1_EnableOutEP(OUT_EP);
    
    /* Start LCD */
    LCD_Char_Start();
     /* Enable the global interrupt */
    CyGlobalIntEnable;
    
    /* Enable the Interrupt component connected to Timer interrupt */
    isr_1_StartEx(InterruptHandler);
    
    //Start UART interrupts
    isr_Tx_StartEx(TxHandler);
    isr_Rx_StartEx(RxHandler);
	/* Start the components */
    Timer_1_Start();
    for(i=0;i<16;i++)
    {
        for(j=0;j<16;j++)
        {
            red[i][j]=0;
            blue[i][j]=0;
            green[i][j]=0;
        }
    }
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
       // USBwork();
        /* Place your application code here. */
       
    }
}


void USBwork(){
    if(USBUART_1_IsConfigurationChanged() != 0u)
        {
            /* Re-enable endpoint when device is configured */
            if(USBUART_1_GetConfiguration() != 0u)
            {
                USBUART_1_EnableOutEP(OUT_EP);
            }
        }
        
        /* Check for data received */
        if(USBUART_1_GetEPState(OUT_EP) == USBUART_1_OUT_BUFFER_FULL)
        {
            // Read  the received byte count 
            bytesReceived = USBUART_1_GetEPCount(OUT_EP);
        
            // Unload the OUT buffer into the first buffer
            if (count < BUFFER_SIZE && count1 == 0)
            {
                USBUART_1_ReadOutEP(OUT_EP, RxBuffer1,size);
                RxBuffer0[count] = RxBuffer1[0];
                LCD_Char_PrintDecUint16(RxBuffer0[count] );
                LCD_Char_Position(1,5);
                move(RxBuffer0[count]);
                count+= bytesReceived;//store bytes into the count 
            }
            
            if (count > BUFFER_SIZE +1)//if first buffer is full unload the rest into the next buffer
            {
                USBUART_1_ReadOutEP(OUT_EP, RxBuffer0,size);//
                RxBuffer1[count1] = RxBuffer0[0];
                move(RxBuffer1[count1]);
                count1+= bytesReceived;
            }
        }
        
       
        if (count == BUFFER_SIZE && (USBUART_1_GetEPState(IN_EP) == USBUART_1_IN_BUFFER_EMPTY)) // Load the IN buffer from bufffer0
        {
            USBUART_1_LoadInEP(IN_EP, RxBuffer0, size);
            count=0;//count++
        }
        if (count == (BUFFER_SIZE+1) && (USBUART_1_GetEPState(IN_EP) == USBUART_1_IN_BUFFER_EMPTY))//send null character
        {
            USBUART_1_LoadInEP(IN_EP, NULL, 0);//64 bit needs this to send the max packet size
            count++;
        }
        
        if ((USBUART_1_GetEPState(IN_EP) == USBUART_1_IN_BUFFER_EMPTY) && (count1 >= BUFFER_SIZE) && (count >= (BUFFER_SIZE+2))) // Load the IN buffer from bufffer1
        {
            USBUART_1_LoadInEP(IN_EP, RxBuffer1, size);
            count1=0;//count1++
            count=0;
        }
        if (count1 >= (BUFFER_SIZE + 1) && count == 0 &&(USBUART_1_GetEPState(IN_EP) == USBUART_1_IN_BUFFER_EMPTY))
        {
            USBUART_1_LoadInEP(IN_EP, NULL, 0);//64 bit needs this to send the max packet size
            count1 = 0;
        }
        if(count == 0 && count1 == 0)//clear lcd screen when both counts are 0
        {
//            CyDelay(30);
            LCD_Char_ClearDisplay();
        }

        LCD_Char_Position(0,0);//show number for each array
        LCD_Char_PrintString("Count:");
        LCD_Char_Position(1,0);
        LCD_Char_PrintDecUint16(RxBuffer0[count] );
        LCD_Char_Position(1,5);
        LCD_Char_PrintNumber(count1);
    
}



void move(uint16 movement)
{
    
    if(movement == 1 )//up arrow initialize to top left corner of array
                {
                    if (playerturn%2==0)
                    {
                        red[0][hri+right-left]=0;
                        red[0][hri] = 1;
                    }else
                    {
                        blue[0][hri+right-left]=0;
                        blue[0][hri] = 1;
                    }
                    
                    left=0;
                    right=0;
                }
                if(movement == 29 )
                {
                    right++;
                    if(hri+right-left==16)
                    {
                        hri=0;
                        right=0;
                        red[0][15] = 0;
                        blue[0][15] = 0;
                    }
                     if (playerturn%2==0)
                    {
                        red[0][hri+right-left]=1;
                        red[0][hri+right-left-1] = 0;
                    }else
                    {
                        blue[0][hri+right-left]=1;
                        blue[0][hri+right-left-1] = 0;
                    }
                }
                 if(movement == 28 )
                { 
                    if(hri-left+right==0)
                    {
                        hri=15;
                        right=0;
                        left = 0;
                        red[0][0] = 0;
                        blue[0][0] = 0;
                    }
                    left++;
         
                      if (playerturn%2==0)
                    {
                        red[0][hri+right-left]=1;
                        red[0][hri+right-left+1] = 0;
                    }else
                    {
                        blue[0][hri+right-left]=1;
                        blue[0][hri+right-left+1] = 0;
                    }
                }
                if(movement==31)
                {
                    
                    for(i=0;i<16;i++)
                    {
                        
                        
                        if(red[15-i][hri+right-left]==0 && blue[15-i][hri+right-left]==0)
                        {
                            
                               if (playerturn%2==0)
                                {
                                    red[15-i][hri+right-left]=1;
                                    rownow = 15-i;
                                    colnow = hri+right-left;
                                    red[0][hri+right-left] = 0;
                                }else
                                {
                                    blue[15-i][hri+right-left]=1;
                                    blue[0][hri+right-left] = 0;
                                }
                                 i=16;
                        }
                        
                    
                    }
                    wincheck(rownow, colnow);
                    playerturn++;
                    right=0;
                    left=0;
                }
                
}
//messed up since the numbers are from 0 to 15 not 15 to 0 
void wincheck(int length, int width)
{
    int value = 0;
    if(width<5)
    {
     width = 4;
    }
    int countpiece =0;
    int countpieceV =0;
    for(i= rownow-4;i<(16);i++)
    {
        
        for(j=width-4;j<(colnow+4);j++)//(width-4)
        {
           
            if(playerturn%2==1)
            {
                if(blue[i][j]==1)
                {
                    
                    countpiece++;
                    if (countpiece == 4) //horizontal check
                    {
                        green[3][3] =1;
                    }
                   
                
                    if(blue[i-1][j]==1)//vertical check
                    {
                        if(blue[i-2][j]==1&&blue[i-3][j]==1)
                        {
                            countpieceV++;
                            green[4][4]=1;
                        }
                    }
                    if(blue[i-1][j-1]==1)//vertical/horizontal check
                    {
                        if(blue[i-2][j-2]==1&&blue[i-3][j-3]==1)
                        {
                            countpieceV++;
                            green[5][4]=1;
                        }
                    }
                    if(blue[i-1][j+1]==1)//vertical/horizontal check
                    {
                        if(blue[i-2][j+2]==1&&blue[i-3][j+3]==1)
                        {
                            countpieceV++;
                            green[4][3]=1;
                        }
                    }
                }else 
                {
                countpiece = 0;
                }
            }else
            {
                if (red[i][j] == 1)
                {
                    countpiece++;
                    if (countpiece == 4) 
                    {
                        green[3][3] =1;
                    }
                    if(red[i-1][j]==1)//vertical check
                    {
                        if(red[i-2][j]==1&&red[i-3][j]==1)
                        {
                            countpieceV++;
                            green[4][4]=1;
                        }
                    }
                    if(red[i-1][j-1]==1)//vertical/horizontal check
                    {
                        if(red[i-2][j-2]==1&&red[i-3][j-3]==1)
                        {
                            countpieceV++;
                            green[5][4]=1;
                        }
                    }
                    if(red[i-1][j+1]==1)//vertical/horizontal check
                    {
                        if(red[i-2][j+2]==1&&red[i-3][j+3]==1)
                        {
                            countpieceV++;
                            green[4][3]=1;
                        }
                    }
                } else{
                countpiece = 0;
                }

            }

        }
        
    }
        
}
    
/* [] END OF FILE */
