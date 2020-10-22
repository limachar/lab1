#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#define FOSC 16000000UL
#define BAUD 38400
#define BRC (((FOSC /(16*BAUD)))-1)

void uart_init(){

    UBRR0H = ((BRC) >> 8);
    UBRR0L = BRC;

    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = 0b110;
}

void uart_putchar(char chr){
    if(chr =='\n'){
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = '\r';
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0  = '\n';
    }
    else{
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = chr;
    }

}

char uart_getchar(){
    char chr;
        while(!(UCSR0A & (1<<RXC0)));
        chr = UDR0;
return chr;
}


void uart_putstr(const char *str){
    int i = 0;

        while(str[i] !='\0'){
            uart_putchar(str[i]);
            i++;
        }
}


void uart_echo(void){
uart_putchar(uart_getchar());
}


void uart_getstr(char *buffer){
    int i = 0;
    buffer[i] = uart_getchar(); 

        while((buffer[i] != '\r') & (buffer[i] !='\n')){ 
            if(i<=47){
                i++; 
                buffer[i] = uart_getchar();
            }
            else{
                buffer[i] = uart_getchar();
            }
        }
    buffer[i] = '\r';
    i++;
    buffer[i] = '\n';
    buffer[i+1] = '\0'; 
}
