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

#ifndef PORT_KERNEL_FREERTOS_H
#define PORT_KERNEL_FREERTOS_H

#ifdef __cplusplus
extern "C" {
#endif

/* RPI back-end symbol macros */
#define RPI_queue_t xQueueHandle
#define RPI_heap_t port_heap_t
    
#define RPI_task_t xTaskHandle
#define RPI_taskfunc_t TaskFunction_t

    typedef struct heap {
        const void *start;
        const uint32_t size;
    } port_heap_t;

    rfa_result_t rfa_platform_freetos_scheduler_start();
    rfa_result_t rfa_platform_freetos_scheduler_pause();
    scheduler_state_t rfa_platform_freertos_scheduler_state_get();

    size_t rfa_platform_freertos_task_size();
    rfa_result_t rfa_platform_freetos_task_create(task_t *task);
    rfa_result_t rfa_platform_freetos_task_create_static(task_t *task);
    rfa_result_t rfa_platform_freetos_task_destroy(task_t *task);
    rfa_result_t rfa_platform_freetos_task_start(task_t *task);
    rfa_result_t rfa_platform_freetos_task_stop(task_t *task);

    size_t rfa_platform_freertos_queue_size(queue_t *queue);
    queue_t *rfa_platform_freertos_queue_alloc(uint8_t cell_size, uint8_t cell_count);
    rfa_result_t rfa_platform_freertos_queue_destroy(queue_t *queue);

#ifdef __cplusplus
}
#endif

#endif /* PORT_KERNEL_FREERTOS_H */

