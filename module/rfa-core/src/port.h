/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   port.h
 * Author: Tendril
 *
 * Created on June 9, 2018, 1:40 PM
 */

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C" {
#endif

#   if(RFAPORT_KERNEL == RFAPORT_KERNEL_FREERTOS)
#       include "port/port_kernel_freertos.h"
    
#       define RFAPORT_kernel_scheduler_start() rfaport_kernel_freetos_scheduler_start()
#       define RFAPORT_kernel_scheduler_pause() rfaport_kernel_freetos_scheduler_pause()
#       define RFAPORT_kernel_scheduler_state_get() rfaport_kernel_freertos_scheduler_state_get()
#       define RFAPORT_kernel_task_size() rfaport_kernel_freertos_task_size()
#       define RFAPORT_kernel_task_alloc() rfaport_kernel_freetos_task_alloc()
#       define RFAPORT_kernel_task_destroy(task) rfaport_kernel_freetos_task_destroy(task)
#       define RFAPORT_kernel_task_start(task) rfaport_kernel_freetos_task_start(task)
#       define RFAPORT_kernel_task_stop(task) rfaport_kernel_freetos_task_stop(task)
#       define RFAPORT_kernel_queue_size(queue) rfaport_kernel_freertos_queue_size(queue)
#       define RFAPORT_kernel_queue_alloc(cell_size, cell_count) rfaport_kernel_freertos_queue_alloc(cell_size, cell_count)
#       define RFAPORT_kernel_queue_destroy(queue) rfaport_kernel_freertos_queue_destroy(queue)
#   endif

#ifdef __cplusplus
}
#endif

#endif /* PORT_H */

