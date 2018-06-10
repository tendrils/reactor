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

#ifndef KERNEL_INTERNAL_H
#define KERNEL_INTERNAL_H

#ifdef RFA_KERNEL_FREERTOS
#   include "FreeRTOS.h"
#   include "queue.h"
#   include "task.h"
#endif

typedef os_queue_t (*os_queue_create_t)(uint8_t cell_size, uint8_t cell_count);
typedef os_task_t (*os_task_create_t)();

struct kernel_if {
    const os_queue_create_t queue_create;
    const os_task_create_t task_create;
};

#endif /* KERNEL_INTERNAL_H */

