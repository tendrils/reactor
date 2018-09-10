/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kernel_internal.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 11:39 PM
 */

#ifndef PLATFORM_INTERNAL_H
#define PLATFORM_INTERNAL_H

#if(RPI_KERNEL == RPI_KERNEL_FREERTOS)
#   include "platform/platform_freertos.h"
#   define RPI_scheduler_start() rfa_platform_freetos_scheduler_start()
#   define RPI_scheduler_pause() rfa_platform_freetos_scheduler_pause()
#   define RPI_scheduler_state_get() rfa_platform_freertos_scheduler_state_get()
#   define RPI_task_size() rfa_platform_freertos_task_size()
#   define RPI_task_create(task) rfa_platform_freetos_task_create(task)
#   define RPI_task_destroy(task) rfa_platform_freetos_task_destroy(task)
#   define RPI_task_start(task) rfa_platform_freetos_task_start(task)
#   define RPI_task_stop(task) rfa_platform_freetos_task_stop(task)
#   define RPI_queue_size(queue) rfa_platform_freertos_queue_size(queue)
#   define RPI_queue_alloc(cell_size, cell_count) rfa_platform_freertos_queue_alloc(cell_size, cell_count)
#   define RPI_queue_destroy(queue) rfa_platform_freertos_queue_destroy(queue)
#endif

struct task {
    RPI_task_t handle;
    RPI_taskfunc_t run;
};

#endif /* PLATFORM_INTERNAL_H */

