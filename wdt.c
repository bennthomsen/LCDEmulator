 #include "wdt.h" 
  void WDTConfigure(void)
{
  WDTCTL = WDTPW + WDTHOLD;    // Stop WDT
  DCOCTL = 0;                  // Select lowest DCOx and MODx settings
  BCSCTL1 = CALBC1_1MHZ;       // Set DCO to 1MHz
  DCOCTL = CALDCO_1MHZ;
  BCSCTL3 |= LFXT1S_2;         // LFXT1 = VLO 12kHz
  BCSCTL1 = (BCSCTL1 & 0x0CF) + DIVA_3; // Set WDT Clock = ACLK/8

  IE1 |= WDTIE;                // enable WDT interrupt
}

void WDTdelay(void)
{

    WDTCTL = WDT_delay_setting;             // Start Watchdog timer for delay. WDT, ACLK, interval timer
    __bis_SR_register(LPM3_bits);           // Put CPU in low power mode 3 to wait for WDT interupt
}

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
    __bic_SR_register_on_exit(LPM3_bits);   // Exit LPM3 on reti
}
