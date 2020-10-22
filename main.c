#include <avr/io.h>

#include "serial.h"
#include "led.h"
#include <util/delay.h>

int main () {
    DDRB |= (1<<PB0);
    char str[] = {"Linn\nMann\n"};
    char buffer[50];

uart_init();

uart_putstr(str);

    while(1){
        uart_getstr(buffer);
        uart_putstr(buffer);
        led_state(buffer);
    }

}
