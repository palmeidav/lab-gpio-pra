#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED = 13;
const int BTN = 12;
const int LED1 = 16;
const int LED2 = 17;
const int LED3 = 18;
const int LED4 = 19;

int main() {
    stdio_init_all();
    
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    
    gpio_init(LED1);
    gpio_set_dir(LED1, GPIO_OUT);
    
    gpio_init(LED2);
    gpio_set_dir(LED2, GPIO_OUT);
    
    gpio_init(LED3);
    gpio_set_dir(LED3, GPIO_OUT);
    
    gpio_init(LED4);
    gpio_set_dir(LED4, GPIO_OUT);
    
    gpio_init(BTN);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);

    while (true) {
        if (gpio_get(BTN) == 0) {  
            gpio_put(LED, !gpio_get(LED));
            
            for (int i = 0; i < 514; i++) {
                int leds[] = {LED1, LED2, LED3, LED4};
                for (int j = 0; j < 4; j++) {
                    gpio_put(leds[j], 1);
                    sleep_ms(10);
                    gpio_put(leds[j], 0);
                }
            }
            
            sleep_ms(200);
        }
    }
    
}