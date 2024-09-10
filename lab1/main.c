#include "include/mini_uart.h"

int main()
{
    mini_uart_init();
    mini_uart_puts("Hello World!\n");
    while (1) {
        mini_uart_send(mini_uart_getc());
    }
    return 0;
}