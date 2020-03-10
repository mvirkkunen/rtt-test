#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "RTT/SEGGER_RTT.h"
#include "RTT/SEGGER_RTT.c"
#include "RTT/SEGGER_RTT_printf.c"

/*static void sleep(uint32_t ticks) {
    while (ticks--)
        __asm__("nop");
}*/

int main(void) {
    SEGGER_RTT_Init();

    SEGGER_RTT_SetFlagsUpBuffer(0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
    
    rcc_periph_clock_enable(RCC_GPIOC);

    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    unsigned int i = 0;

    while (1) {
        gpio_clear(GPIOC, GPIO13);
        //sleep(800000);

        SEGGER_RTT_printf(0, "Hello from RTT %d\n", i);

        gpio_set(GPIOC, GPIO13);
        //sleep(800000);

        i++;
    }
}
