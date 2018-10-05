/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   port_kernel_freertos.h
 * Author: Tendril
 *
 * Created on June 12, 2018, 9:53 PM
 */

#ifndef PLATFORM_KERNEL_FREERTOS_H
#define PLATFORM_KERNEL_FREERTOS_H

#ifdef __cplusplus
extern "C" {
#endif

/* RPI back-end symbol macros */
#define RPI_queue_t xQueueHandle
#define RPI_heap_t heap_t
    
#define RPI_task_t xTaskHandle
#define RPI_statictask_t StaticTask_t
#define RPI_taskfunc_t TaskFunction_t

    typedef struct heap {
        const void *start;
        const uint32_t size;
    } heap_t;

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_KERNEL_FREERTOS_H */

