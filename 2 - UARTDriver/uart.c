#include "uart.h"

void uart_init(void) {
    // enable clocks for GPIOB and USART1
    RCC_APB2ENR |= (1 << 3) | (1 << 14);

    // configure PB6 as alternate function push-pull, 2MHz
    GPIOB_CRL &= ~(0xF << 24);
    GPIOB_CRL |=  (0xA << 24);

    // set baud rate
    USART1_BRR = 0x457;

    // enable UART and transmitter
    USART1_CR1 |= USART_CR1_UE | USART_CR1_TE;
}

void uart_putchar(char c) {
    while (!(USART1_SR & USART_SR_TXE));
    USART1_DR = c;
}

void uart_puts(char* str) {
    while (*str) {
        uart_putchar(*str);
        str++;
    }
}