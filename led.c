#include <avr/io.h>
#include <string.h>
#include "serial.h"

#include "led.h"

void led_state(char *buffer){
    if(strcmp(buffer, "on\r\n") == 0){
        PORTB |= (1 << PB0);    
    }
    else if(strcmp(buffer, "off\r\n") == 0){
        PORTB &= ~(1 << PB0);   
    }
    else if(strcmp(buffer, "\r\n") == 0){ }
}
