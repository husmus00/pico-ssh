#include <stdio.h>

#include "pico/stdlib.h"
// #include "pico/multicore.h"

#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

#include "FreeRTOS.h"
#include "task.h"

void vLaunch( void)
{
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread", MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);

    vTaskStartScheduler();
}

int main(void)
{
    stdio_init_all();

    /* Configure the hardware ready to run the demo. */
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    printf("Starting %s on core 0:\n", rtos_name);
    vLaunch();

    return 0;
}