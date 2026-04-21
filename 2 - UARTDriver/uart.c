#include "uart.h"

void uart_init(void) {

    RCC_CR |= (1 << 16);           
    while (!(RCC_CR & (1 << 17))); 

    RCC_CFGR |= (1 << 0);         
    while (((RCC_CFGR >> 2) & 0x3) != 1); 

    RCC_APB2ENR |= (1 << 0);

    AFIO_MAPR |= (1 << 2);

    RCC_APB2ENR |= (1 << 3) | (1 << 14);
    GPIOB_CRL &= ~(0xF << 24);
    GPIOB_CRL |=  (0xA << 24);
    USART1_BRR = 0x457;   
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