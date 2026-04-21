#ifndef UART_H
#define UART_H

#include <stdint.h>

// rcc base address and registers (clock enable)
#define RCC_BASE    0x40021000
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC_BASE + 0x18))
#define RCC_CR     (*(volatile uint32_t*)(RCC_BASE + 0x00))
#define RCC_CFGR   (*(volatile uint32_t*)(RCC_BASE + 0x04))

#define AFIO_BASE  0x40010000
#define AFIO_MAPR  (*(volatile uint32_t*)(AFIO_BASE + 0x04))

// gpiob base address and registers (for pb6 tx pin)
#define GPIOB_BASE  0x40010C00
#define GPIOB_CRL   (*(volatile uint32_t*)(GPIOB_BASE + 0x00))

// usart1 base address and registers
#define USART1_BASE 0x40013800
#define USART1_SR   (*(volatile uint32_t*)(USART1_BASE + 0x00))
#define USART1_DR   (*(volatile uint32_t*)(USART1_BASE + 0x04))
#define USART1_BRR  (*(volatile uint32_t*)(USART1_BASE + 0x08))
#define USART1_CR1  (*(volatile uint32_t*)(USART1_BASE + 0x0C))

// status register bits
#define USART_SR_TXE  (1 << 7)  // tx buffer empty
#define USART_SR_TC   (1 << 6)  // transmission complete

// control register bits
#define USART_CR1_UE  (1 << 13) // uart enable
#define USART_CR1_TE  (1 << 3)  // transmitter enable

// function prototypes
void uart_init(void);
void uart_putchar(char c);
void uart_puts(char *str);

#endif