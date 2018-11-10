/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   platform_internal.h
 * 
 * Reactor Platform Interface front-end API types and functions
 *
 * Created on March 27, 2018, 11:39 PM
 */

#ifndef PLATFORM_INTERNAL_H
#define PLATFORM_INTERNAL_H

#include <rpi_backend.h>

#if(RPI_KERNEL == RPI_KERNEL_FREERTOS)
#include "kernel_freertos.h"
#endif

struct queue {
    RPI_queue_t handle;
    RPI_staticqueue_t *header;
};

struct lock {
    RPI_semaphore_t handle;
    RPI_staticsemaphore_t *header;
};

struct task {
    RPI_task_t handle;
    RPI_statictask_t *header;
    RPI_stack_t *stack;
    RPI_heap_t *heap;
};

struct heap {
    RPI_heap_t header;
};

rfa_result_t rpi_scheduler_start();
rfa_result_t rpi_scheduler_pause();
scheduler_state_t rpi_scheduler_state_get();

taskprio_t rpi_prio_from_source(RPI_prio_t source);
RPI_prio_t rpi_prio_to_source(taskprio_t prio);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rpi_task_create(
    RPI_taskfunc_t function, const char * const name, unsigned short stack_depth,
    void *params, RPI_prio_t priority, RPI_task_t *out);

rfa_result_t rpi_task_destroy(RPI_task_t task);
#endif

RPI_task_t rpi_task_create_static(
    RPI_taskfunc_t function, const char * const name, const uint32_t stack_depth,
    void * const params, RPI_prio_t priority, RPI_stack_t * const stack_buffer, RPI_statictask_t *task);

rfa_result_t rpi_task_start(RPI_task_t task);
rfa_result_t rpi_task_stop(RPI_task_t task);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rpi_queue_create(RPI_queue_t *out, uint8_t cell_size, uint8_t cell_count);
rfa_result_t rpi_queue_destroy(RPI_queue_t queue);
#endif

RPI_queue_t rpi_queue_create_static(
    RPI_staticqueue_t *header, uint8_t *buffer, uint8_t cell_size, uint8_t cell_count);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
void* rpi_malloc(size_t length);
void rpi_free(void *object);
size_t rpi_get_free_heap_size();
#endif

#endif /* PLATFORM_INTERNAL_H */
