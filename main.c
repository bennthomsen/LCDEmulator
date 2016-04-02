#include "wdt.h"
#include "UART.h"
#include "ADC.h"
#include "print.h"

/* Main function */

int main(void)
{
  WDTConfigure();
  UARTConfigure();
  ADCConfigure();
  
  P1DIR |= (BIT0);              // P1.0 to output
  P1OUT &= ~(BIT0);             // Clear the LEDs P1.0
      
  while(1)
  {
    P1OUT ^= (BIT0);                       // Clear the LEDs P1.0 and P1.6 to on
    UARTPrint("back,100,100,200\r\n");     // Paint Background R=100,G=100,B=100    
    
    ADCAcquireChannel5();                   //Start single acquistion on ADC channel 5
    __bis_SR_register(CPUOFF + GIE);        // LPM0 with interrupts enabled to wait for ADC interupt
    printformat("rect,%i,350,50,20\r\n",(ADCvalue  >> 2));  // Send formatted ADC reading to UART 
    
    WDTdelay();     // Delay between readings
  }
}


