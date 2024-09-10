#include "term.h"
#include "mini_uart.h"

#define CMD_LENGTH 32

void term_init()
{
    mini_uart_init();
}

static void term_help()
{
    mini_uart_puts("No Support Command!\n");
}

static void term_hello()
{
    mini_uart_puts("Hello World!\n");
}

int term_parse(char *cmd, int end)
{
    const char hello[] = "hello";
    const char help[] = "help";

    if (end == 4) {
        int is_help = 1;
        for (int i = 0; i < 4; i++)
            is_help = is_help && (cmd[i] == help[i]);
        if (is_help)
            term_help();
        return 1;
    }
    if (end == 5) {
        int is_hello = 1;
        for (int i = 0; i < 5; i++)
            is_hello = is_hello && (cmd[i] == hello[i]);

        if (is_hello)
            term_hello();
        return 1;
    }
    return 0;
}

void term_run()
{
    char cmd[CMD_LENGTH] = {0};
    int end = 0;

    mini_uart_puts("Welcome~\n# ");
    while (1) {
        char c = mini_uart_getc();

        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            cmd[end] = c;
            end++;
            mini_uart_send(c);
        } else if (c == '\n') {
            cmd[end] = '\0';
            mini_uart_send('\n');
            term_parse(cmd, end);
            mini_uart_puts("# ");
            end = 0;
        } else {
            mini_uart_send('\n');
            mini_uart_puts("# ");
            end = 0;
        }
        end &= (CMD_LENGTH - 1);
        cmd[end] = '\0';
    }
}