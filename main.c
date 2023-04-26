#include <msp430.h> 
#include <stdint.h>
#include <stdbool.h>
#include <adafruit_lcd_backpack_interface.h>



/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    #ifdef __MSP430FR2XX_4XX_FAMILY__
        // Code needed for FR2433
        PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode                                                // to activate previously configured port settings  P1DIR |= 0x01;                            // P1.0 output
    #endif


	init_spi();

    init_LCD();

    write_string("Hello world! <3");

    return 0;
}
