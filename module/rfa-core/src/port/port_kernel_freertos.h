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

rfa_result_t    rfaport_kernel_freetos_scheduler_start();
rfa_result_t    rfaport_kernel_freetos_scheduler_pause();
rfa_scheduler_state_t   rfaport_kernel_freertos_scheduler_state_get();

size_t          rfaport_kernel_freertos_task_size();
os_task_t       rfaport_kernel_freetos_task_alloc();
rfa_result_t    rfaport_kernel_freetos_task_destroy(os_task_t task);
rfa_result_t    rfaport_kernel_freetos_task_start(os_task_t task);
rfa_result_t    rfaport_kernel_freetos_task_stop(os_task_t task);

size_t          rfaport_kernel_freertos_queue_size(os_queue_t queue);
os_queue_t      rfaport_kernel_freertos_queue_alloc(uint8_t cell_size, uint8_t cell_count);
rfa_result_t    rfaport_kernel_freertos_queue_destroy(os_queue_t queue);

#ifdef __cplusplus
}
#endif

#endif /* PORT_KERNEL_FREERTOS_H */

