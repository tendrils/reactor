/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rfa/kernel.h
 * Author: Tendril
 *
 * Created on March 29, 2018, 11:28 AM
 */

#ifndef RFA_KERNEL_H
#define RFA_KERNEL_H

rfa_result_t rfa_kernel_scheduler_start();

rfa_result_t rfa_kernel_scheduler_pause();

rfa_scheduler_state_t rfa_kernel_scheduler_state_get();

size_t rfa_kernel_queue_size(os_queue_t queue);

os_queue_t rfa_kernel_queue_alloc(uint8_t cell_size, uint8_t cell_count);

size_t rfa_kernel_task_size();

os_task_t rfa_kernel_task_alloc();

rfa_result_t rfa_kernel_task_destroy(os_task_t task);

rfa_result_t rfa_kernel_task_start(os_task_t task);

rfa_result_t rfa_kernel_task_stop(os_task_t task);

#endif /* RFA_KERNEL_H */

