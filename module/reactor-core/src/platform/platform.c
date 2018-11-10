/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/platform.h>

#include "platform_internal.h"

rfa_result_t rfa_platform_scheduler_start() {
    return rpi_scheduler_start();
}

rfa_result_t rfa_platform_scheduler_pause() {
    return rpi_scheduler_pause();
}

scheduler_state_t rfa_platform_scheduler_state_get() {
    return rpi_scheduler_state_get();
}

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

rfa_result_t rfa_platform_queue_create(queue_t **out, uint8_t cell_size, uint8_t cell_count) {
    rfa_result_t res;
    queue_t *queue = rfa_platform_malloc(sizeof (queue_t));

    res = rpi_queue_create(queue->handle, cell_size, cell_count);
}

rfa_result_t rfa_platform_queue_destroy(queue_t *queue) {
    return rpi_queue_destroy(queue);
}
#endif

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

void* rfa_platform_malloc(size_t length) {
    return rpi_malloc(length);
}

void rfa_platform_free(void *object) {
    rpi_free(object);
}

size_t rfa_platform_get_free_heap_size() {
    return rpi_get_free_heap_size();
}
#endif

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)

rfa_result_t rfa_platform_task_create(taskfunc_t function,
        const char *name, unsigned short stack_depth,
        void *params, taskprio_t priority, task_t **out) {
    task_t *task;
    RPI_prio_t rpi_prio = rpi_prio_to_source(priority);
    
    task = rpi_malloc(sizeof (task_t));

    if (task == NULL) {
        return RFA_RES_FAIL;
    }

    if (rpi_task_create(function, name, stack_depth, params, rpi_prio, &task->handle)) {
        *out = task;
        return RFA_RES_OK;
    } else {
        rpi_free(task);
        return RFA_RES_FAIL;
    }
}

rfa_result_t rfa_platform_task_destroy(task_t *task) {
    return rpi_task_destroy(task);
}
#endif

rfa_result_t rfa_platform_task_create_static(task_t *task, taskfunc_t function,
        const char *name, unsigned short stack_depth,
        void *params, taskprio_t priority) {
    RPI_prio_t rpi_prio = rpi_prio_to_source(priority);
    task->handle = rpi_task_create_static(function, name, stack_depth, params, rpi_prio, task->stack, task->header);
    return RFA_RES_OK;
}

rfa_result_t rfa_platform_task_start(task_t *task) {
    return rpi_task_start(task->handle);
}

rfa_result_t rfa_platform_task_stop(task_t *task) {
    return rpi_task_stop(task->handle);
}
