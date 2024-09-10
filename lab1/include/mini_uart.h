#ifndef _MINI_UART_H_
#define _MINI_UART_H_
void mini_uart_init();
void mini_uart_send(unsigned int c);
char mini_uart_getc();
void mini_uart_puts(char *s);
#endif