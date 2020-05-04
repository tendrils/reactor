/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>

#include "platform/platform_internal.h"

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

rfa_result_t rpi_task_create(
        RPI_taskfunc_t function, const char * const name, unsigned short stack_depth,
        void *params, RPI_prio_t priority, RPI_task_t *out) {
    task_t *task;
    BaseType_t error;

    task = rpi_malloc(sizeof (task_t));
    if (task == NULL) {
        return RFA_RES_FAIL;
    }

    error = xTaskCreate(function, name, stack_depth, params, priority, &task->handle);
    if (error != pdPASS) {
        // TODO report error status
        rpi_free(task);
        return RFA_RES_FAIL;
    }

    *out = task;
    return RFA_RES_OK;
}
#endif

RPI_task_t rpi_task_create_static(
        RPI_taskfunc_t function, const char * const name, const uint32_t stack_depth,
        void * const params, RPI_prio_t priority, RPI_stack_t * const stack_buffer, RPI_statictask_t *header
        ) {
    return xTaskCreateStatic(function, name, stack_depth, params, priority, stack_buffer, header);
}

rfa_result_t rpi_task_destroy(TaskHandle_t task);
rfa_result_t rpi_task_start(TaskHandle_t task);
rfa_result_t rpi_task_stop(TaskHandle_t task);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

rfa_result_t rpi_queue_create(
        QueueHandle_t *out, uint8_t cell_size, uint8_t cell_count) {
    StaticQueue_t *header;
    uint8_t *buffer;

    header = rpi_malloc(sizeof (StaticQueue_t));
    if (header == NULL) {
        return RFA_RES_FAIL;
    }

    buffer = rpi_malloc(cell_count * cell_size);
    if (buffer == NULL) {
        rpi_free(header);
        return RFA_RES_FAIL;
    }

    if (*out = xQueueCreateStatic(cell_count, cell_size, buffer, header)) {
        return RFA_RES_OK;
    }
    return RFA_RES_FAIL;
}
#endif

QueueHandle_t rpi_queue_create_static(
        StaticQueue_t *header, uint8_t *buffer, uint8_t cell_size, uint8_t cell_count) {
    return xQueueCreateStatic(cell_count, cell_size, buffer, header);
}

rfa_result_t rpi_queue_destroy(QueueHandle_t queue) {
    vQueueDelete(queue);
    return RFA_RES_OK;
}

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

void* rpi_malloc(size_t length) {
    return pvPortMalloc(length);
}

void rpi_free(void *object) {
    vPortFree(object);
}

size_t rpi_get_free_heap_size() {
    return xPortGetFreeHeapSize();
}
#endif

/* 
 * static memory allocation callbacks required by FreeRTOS when in static mode
 */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize )
{
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     uint32_t *pulTimerTaskStackSize )
{
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
