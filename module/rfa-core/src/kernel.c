/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "rfa.h"
#include "rfa/kernel.h"
#include "kernel_internal.h"
#include "port.h"

rfa_result_t rfa_kernel_scheduler_start() {
    return RFAPORT_kernel_scheduler_start();
}

rfa_result_t rfa_kernel_scheduler_pause() {
    return RFAPORT_kernel_scheduler_pause();
}

rfa_scheduler_state_t rfa_kernel_scheduler_state_get() {
    return RFAPORT_kernel_scheduler_state_get();
}

size_t rfa_kernel_queue_size(os_queue_t queue) {
    return RFAPORT_kernel_queue_size(queue);
}

os_queue_t rfa_kernel_queue_alloc(uint8_t cell_size, uint8_t cell_count) {
    return RFAPORT_kernel_queue_alloc(cell_size, cell_count);
}

rfa_result_t rfa_kernel_queue_destroy(os_queue_t queue) {
    return RFAPORT_kernel_queue_destroy(queue);
}

size_t rfa_kernel_task_size() {
    return RFAPORT_kernel_task_size();
}
os_task_t rfa_kernel_task_alloc() {
    return RFAPORT_kernel_task_alloc();
}

rfa_result_t rfa_kernel_task_destroy(os_task_t task) {
    return RFAPORT_kernel_task_destroy(task);
}

rfa_result_t rfa_kernel_task_start(os_task_t task) {
    return RFAPORT_kernel_task_start(task);
}

rfa_result_t rfa_kernel_task_stop(os_task_t task) {
    return RFAPORT_kernel_task_stop(task);
}
