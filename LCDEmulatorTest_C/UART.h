#ifndef MSP430G2553
#define MSP430G2553
#include <msp430g2553.h>
#endif

volatile char UARTRxData[20];
volatile char UARTRxFlag;

void UARTConfigure(void);
void UARTSendChar(unsigned char character);
void UARTSendArray(unsigned char *TxArray, unsigned char ArrayLength);
void UARTPrint(char *TxArray);
void UARTPrintln(char *TxArray);
