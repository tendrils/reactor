/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   platform_internal.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 11:39 PM
 */

#ifndef PLATFORM_INTERNAL_H
#define PLATFORM_INTERNAL_H

#if(RPI_KERNEL == RPI_KERNEL_FREERTOS)
#   include "kernel_freertos.h"
#endif

struct task
{
    RPI_task_t handle;
    RPI_taskfunc_t run;
};

struct queue
{
    RPI_queue_t handle;
};

rfa_result_t rpi_scheduler_start();
rfa_result_t rpi_scheduler_pause();
scheduler_state_t rpi_scheduler_state_get();

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rpi_task_create
    (
        RPI_taskfunc_t function, const char * const name, unsigned short stack_depth,
        void *pvParameters, RPI_prio_t uxPriority, RPI_task_t *pxCreatedTask
    );
rfa_result_t rpi_task_destroy(RPI_task_t task);
#endif

rfa_result_t rpi_task_create_static(RPI_task_t task);
rfa_result_t rpi_task_start(RPI_task_t task);
rfa_result_t rpi_task_stop(RPI_task_t task);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rpi_queue_create(RPI_queue_t *out, uint8_t cell_size, uint8_t cell_count);
rfa_result_t rpi_queue_destroy(RPI_queue_t queue);
#endif

rfa_result_t rpi_queue_create_static(RPI_queue_t *out, StaticQueue_t *queue, uint8_t cell_size, uint8_t cell_count);

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
void* rpi_malloc(size_t length);
void rpi_free(void *object);
size_t rpi_get_free_heap_size();
#endif

#endif /* PLATFORM_INTERNAL_H */
