/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <time.h>
#include <device.h>
#include <drivers/gpio.h>

#include <Test.h>
#include <TestCPP.h>

#define LED_1_NODE DT_ALIAS(led1)
void main(void)
{
    static bool isOn = false;
    static int counter = 0;
    const struct gpio_dt_spec led_1 = GPIO_DT_SPEC_GET(LED_1_NODE, gpios);

    gpio_pin_configure_dt(&led_1, GPIO_OUTPUT_ACTIVE);

    while (true) {
        k_sleep(K_MSEC(1000));
        printk("%-5d squared = %-5d\t %s\n", counter, squareIt(counter++), isOn ? "ON" : "off");
        k_sleep(K_MSEC(3)); // <== this delay is required at >= 2-3ms or greater to avoid aparent tow printk's every 2 seconds
        isOn = !isOn;
        gpio_pin_set_dt(&led_1, isOn);
    }
}
