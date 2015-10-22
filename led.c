/*
 * ----------------------------------------------------------------------------
 *            _____ _           _                   _
 *           | ____| | ___  ___| |_ _ __ ___  _ __ (_) ___
 *           |  _| | |/ _ \/ __| __| '__/ _ \| '_ \| |/ __|
 *           | |___| |  __/ (__| |_| | | (_) | | | | | (__
 *           |_____|_|\___|\___|\__|_|  \___/|_| |_|_|\___|
 *            ____                   _   ____
 *           / ___|_      _____  ___| |_|  _ \ ___  __ _ ___
 *           \___ \ \ /\ / / _ \/ _ \ __| |_) / _ \/ _` / __|
 *            ___) \ V  V /  __/  __/ |_|  __/  __/ (_| \__ \
 *           |____/ \_/\_/ \___|\___|\__|_|   \___|\__,_|___/
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <pontus@sweetpeas.se> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return - Pontus Oldberg
 * ----------------------------------------------------------------------------
 */

#include <sam.h>
#include "led.h"

volatile PortGroup *led_port = 0;

/*
 * Initialize the activity led
 */
void init_leds(void)
{
	led_port = (volatile PortGroup *)&PORT->Group[1];
	led_port->DIRSET.reg = (ACTIVITY_LED);
	led_port->OUTSET.reg = (ACTIVITY_LED);
}

/*
 * Set the desired led state
 */
void set_cdc_activity_led(int state)
{
        if (state) {
                led_port->OUTCLR.reg = (ACTIVITY_LED);
        } else {
                led_port->OUTSET.reg = (ACTIVITY_LED);
        }
}

/*
 * Toggle the activity LED
 */
void toggle_cdc_activity_led(void)
{
	led_port->OUTTGL.reg = ACTIVITY_LED;
}
/* EOF */

