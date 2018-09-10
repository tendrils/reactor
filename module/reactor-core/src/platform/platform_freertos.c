/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include "platform_freertos.h"
#include "src/platform_internal.h"

#if (RPI_KERNEL == RPI_KERNEL_FREERTOS)

#include <FreeRTOS.h>
#include <queue.h>
#include <task.h>

rfa_result_t rfa_platform_freertos_scheduler_start() {
    vTaskStartScheduler();
    return REACTOR_RES_OK;
}

rfa_result_t rfa_platform_freertos_scheduler_pause() {
    vTaskEndScheduler();
    return REACTOR_RES_OK;
}

scheduler_state_t rfa_platform_freertos_scheduler_state_get() {
    switch (xTaskGetSchedulerState()) {
        case taskSCHEDULER_SUSPENDED:
            return SCHEDULER_PAUSE;
        case taskSCHEDULER_NOT_STARTED:
            return SCHEDULER_INIT;
        case taskSCHEDULER_RUNNING:
            return SCHEDULER_RUN;
    }
}

size_t rfa_platform_freertos_task_size() {

}
rfa_result_t rfa_platform_freertos_task_create(task_t **out);
rfa_result_t rfa_platform_freertos_task_create_static(task_t *task);
rfa_result_t rfa_platform_freertos_task_destroy(task_t *task);
rfa_result_t rfa_platform_freertos_task_start(task_t *task) {
    &task->handle
}
rfa_result_t rfa_platform_freertos_task_stop(task_t *task);

size_t rfa_platform_freertos_queue_size(queue_t *queue);
queue_t *rfa_platform_freertos_queue_alloc(uint8_t cell_size, uint8_t cell_count);
rfa_result_t rfa_platform_freertos_queue_destroy(queue_t *queue);


#endif
