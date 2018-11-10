/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kernel_freertos.h
 * Author: Tendril
 *
 * Created on June 12, 2018, 9:53 PM
 */

#ifndef PLATFORM_KERNEL_FREERTOS_H
#define PLATFORM_KERNEL_FREERTOS_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct rpi_heap {
        const void *start;
        const uint32_t size;
    } rpi_heap_t;

    /* RPI back-end symbol macros */
#define RPI_queue_t                 QueueHandle_t
#define RPI_staticqueue_t           StaticQueue_t
#define RPI_semaphore_t             SemaphoreHandle_t
#define RPI_staticsemaphore_t       StaticSemaphore_t

#define RPI_task_t                  TaskHandle_t
#define RPI_statictask_t            StaticTask_t
#define RPI_taskfunc_t              TaskFunction_t
#define RPI_prio_t                  UBaseType_t
#define RPI_stack_t                 StackType_t
#define RPI_heap_t                  rpi_heap_t

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_KERNEL_FREERTOS_H */

