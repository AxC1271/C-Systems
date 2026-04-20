#include "uart.h"

int main(void) {
    uart_init();
    
    char *msg = "Hello";
    while (*msg) {
        uart_putchar(*msg++);
        for (volatile int i = 0; i < 100000; i++);
    }
    
    while(1);
}