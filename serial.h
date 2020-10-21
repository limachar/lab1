#ifndef SERIAL_H_
#define SERIAL_H_
#include <util/delay.h>

void uart_init(void);

void uart_putchar(char chr);
void uart_putstr(const char *str);

char uart_getchar(void);

void uart_echo(void);

void uart_getstr(void);

#endif
