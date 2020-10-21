#include <avr/io.h>

#include "serial.h"
#include <util/delay.h>

int main () {
DDRB |= (1<<PB0);
char str [] = {"Linn\nMann\n"};
char buffer[50];
bool ledstate = false;
uart_init();
uart_putstr(str);

while(1)
{
uart_getstr(buffer);
}

}
