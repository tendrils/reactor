/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>

#include "platform_internal.h"

#if (RPI_KERNEL != RPI_KERNEL_FREERTOS)
#error "[" __FILE__ "] cannot be compiled against kernel [" RPI_KERNEL "]"
#endif

#include <FreeRTOS.h>
#include <queue.h>
#include <task.h>

rfa_result_t rpi_scheduler_start() {
    vTaskStartScheduler();
    return RFA_RES_OK;
}

rfa_result_t rpi_scheduler_pause() {
    vTaskEndScheduler();
    return RFA_RES_OK;
}

scheduler_state_t rpi_scheduler_state_get() {
    switch (xTaskGetSchedulerState()) {
        case taskSCHEDULER_SUSPENDED:
            return SCHEDULER_PAUSE;
        case taskSCHEDULER_NOT_STARTED:
            return SCHEDULER_INIT;
        case taskSCHEDULER_RUNNING:
            return SCHEDULER_RUN;
    }
}

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

rfa_result_t rpi_task_create
(
        TaskFunction_t function, const char * const name, unsigned short stack_depth,
        void *pvParameters, UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask
        ) {
    RPI_task_t *task = rpi_malloc(sizeof RPI_task_t);
    
    if(task == NULL) {
        return RFA_RES_FAIL;
    }

    if (xTaskCreate(*task)) {
        out = task;
        return RFA_RES_OK;
    } else {
        rpi_free(task);
        return RFA_RES_FAIL;
    }
}
#endif

xTaskHandle rpi_task_create_static
(
        TaskFunction_t function, const char *name, const uint32 stack_depth,
        void * const params, UBaseType priority, StackType_t * const stack_buffer, StaticTask_t *task
        ) {
    return xTaskCreateStatic(function, name, stack_depth, params, priority, stack_buffer, task);
}

rfa_result_t rpi_task_destroy(xTaskHandle task);
rfa_result_t rpi_task_start(xTaskHandle task);
rfa_result_t rpi_task_stop(xTaskHandle task);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

rfa_result_t rpi_queue_create(xQueueHandle *out, uint8_t cell_size, uint8_t cell_count) {
    if (*out = xQueueCreate(cell_count, cell_size)) {
        return RFA_RES_OK;
    }
    return RFA_RES_FAIL;
}
#endif

xQueueHandle rpi_queue_create_static(
        StaticQueue_t *queue, uint8_t *buffer, uint8_t cell_size, uint8_t cell_count) {
    return xQueueCreateStatic(cell_count, cell_size, buffer, queue);
}

rfa_result_t rpi_queue_destroy(xQueueHandle queue) {
    vQueueDelete(queue);
    return RFA_RES_OK;
}

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

void* rpi_malloc(size_t length) {
    return pvPortMalloc(length);
}

void rpi_free(void *object) {
    return vPortFree(object);
}

size_t rpi_get_free_heap_size() {
    return xPortGetFreeHeapSize();
}
#endif
