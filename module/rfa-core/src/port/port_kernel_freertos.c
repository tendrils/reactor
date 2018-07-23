/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "rfa.h"
#include "port_kernel_freertos.h"

#if (RFAPORT_KERNEL == RFAPORT_KERNEL_FREERTOS)

#   include "FreeRTOS.h"
#   include "queue.h"
#   include "task.h"

rfa_result_t rfaport_kernel_freetos_scheduler_start() {
    return vTaskStartScheduler();
}
rfa_result_t rfaport_kernel_freetos_scheduler_pause() {
    return vTaskStopScheduler();
}

rfa_scheduler_state_t rfaport_kernel_freertos_scheduler_state_get() {
    switch(xTaskGetSchedulerState()) {
         
    }
}

size_t rfaport_kernel_freertos_task_size() {
    
}
os_task_t rfaport_kernel_freetos_task_alloc();
rfa_result_t rfaport_kernel_freetos_task_destroy(os_task_t task);
rfa_result_t rfaport_kernel_freetos_task_start(os_task_t task);
rfa_result_t rfaport_kernel_freetos_task_stop(os_task_t task);

size_t rfaport_kernel_freertos_queue_size(os_queue_t queue);
os_queue_t rfaport_kernel_freertos_queue_alloc(uint8_t cell_size, uint8_t cell_count);
rfa_result_t rfaport_kernel_freertos_queue_destroy(os_queue_t queue);


#endif
