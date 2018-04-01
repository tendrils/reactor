/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rfa.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 8:43 AM
 */

#ifndef RFA_H
#define RFA_H

#include "conf_rfa_core.h"

// API return codes
typedef enum api_result {
	RFA_RES_OK,
	RFA_RES_FAIL
} rfa_result_t;

// core firmware-architecture types
typedef struct firmware firmware_t;
typedef struct module module_t;
typedef struct component component_t;
typedef struct service service_t;

// message-passing subsystem interface
typedef struct message_bus message_bus_t;
typedef struct messsage_channel message_channel_t;
typedef struct message_lane message_lane_t;
typedef struct control_bus control_bus_t;

// RTOS kernel abstraction
typedef const struct kernel_if kernel_if_t;
typedef os_queue_t;
typedef os_heap_t;
typedef os_task_t;

#endif /* RFA_H */
