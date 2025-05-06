#include <stdio.h>

#include "pico/stdlib.h"
// #include "pico/multicore.h"

#include "FreeRTOS.h"
#include "task.h"

void main_task(__unused void *params) {

#if USE_LED
    // start the led blinking
    xTaskCreate(blink_task, "BlinkThread", BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
#endif
    int count = 0;
    while(true) {
        // check if we have any messages
        uint32_t msg;
        if (xQueueReceive(main_queue, &msg, 0)) {
            printf("main task received %u\n", msg);
        }
        // printf("Hello from main task count=%u\n", count++);
        vTaskDelay(3000);
    }
    async_context_deinit(context);
}