/**
 * Copyright (c) 2014 - 2017, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/** @file
 *
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example
 * @brief Blinky Example Application main file.
 *
 * This file contains the source code for a sample application to blink LEDs.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <nrf_drv_saadc.h>
#include "nrf.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "boards.h"

#define ANALOG_PIN 3
#define VIBR_PIN 25
#define SAADC_CONFIG_RESOLUTION 100
#define SAADC_CONFIG_OVERSAMPLE 0
#define SAADC_CONFIG_IRQ_PRIORITY 0

/*static void gpio_init(void)
{
    nrf_gpio_cfg_output(VIBR_PIN);
    nrf_gpio_pin_set(VIBR_PIN);
}*/

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    //gpio_init();
    /* Configure board. */
    //bsp_board_leds_init();

    nrf_gpio_cfg_output(VIBR_PIN);
    nrf_gpio_pin_clear(VIBR_PIN);

    //nrf_drv_saadc_config_t* p_config; //will this just choose defaults?
        /*{
            .resolution         = SAADC_CONFIG_RESOLUTION,
            .oversample         = SAADC_CONFIG_OVERSAMPLE,
            .interrupt_priority = SAADC_CONFIG_IRQ_PRIORITY
        };*/
    //nrf_drv_saadc_config_t* p_config = NRF_DRV_SAADC_DEFAULT_CONFIG_SE;
    //p_config.pin_p = ANALOG_PIN;
    //nrf_drv_saadc_event_handler_t p_event; //does this need to be initialized?
    //nrf_drv_saadc_init(p_config, p_event); //check for error!
    //nrf_drv_saadc_init(NRF_DRV_SAADC_DEFAULT_CONFIG, p_event); //check for error!

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            //nrf_saadc_value_t gripValue;
            //ret_code_t analogReturn = nrf_drv_saadc_sample_convert(ANALOG_PIN, &gripValue);
            
            //bsp_board_led_invert(i);
            nrf_gpio_pin_toggle(VIBR_PIN);
            nrf_delay_ms(500);
        }
    }
}

/**
 *@}
 **/
