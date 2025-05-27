#include "FreeRTOS.h"
#include "task.h"
#include "print.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    print(pcTaskName);
}
