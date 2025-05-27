#include "FreeRTOS.h"
#include "task.h"
#include "print.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    print("$ [Warning] \"%s\" stack over flow!\n", pcTaskName);
}
