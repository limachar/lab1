#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

void led_state(char *str){
if(strcmp(buffer, "ON\r\n") == 0){
PORTB |= (1 << PB0);
i = 0;
}
else if(strcmp(buffer, "OFF\r\n") == 0){
PORTB &= ~(1 << PB0);
i = 0;
}
}
