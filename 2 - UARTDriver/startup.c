#include <stdint.h>

// defined by linker script
extern uint32_t _sdata, _edata, _sidata;
extern uint32_t _sbss, _ebss;

// forward declare main
int main(void);

void reset_handler(void) {
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    // zero .bss
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    // call main
    main();

    // if main returns, loop forever
    while(1);
}

__attribute__((section(".vector_table")))
uint32_t vector_table[] = {
    0x20005000,              // initial stack pointer (top of RAM)
    (uint32_t)(uintptr_t)reset_handler
};