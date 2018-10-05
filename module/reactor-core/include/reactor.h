/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 8:43 AM
 */

#ifndef REACTOR_H
#define REACTOR_H

#include <stdlib.h>

#include <reactor/defs.h>
#include <reactor/compiler.h>
#include <conf_reactor_core.h>

#include <rpi_backend.h>

// API return codes

typedef enum api_result {
    REACTOR_RES_FAIL = 0,
    REACTOR_RES_OK
} rfa_result_t;

// core firmware-architecture types
typedef struct firmware firmware_t;
typedef struct module module_t;
typedef struct component component_t;
typedef struct service service_t;

// message-passing subsystem interface
typedef struct message message_t;
typedef struct message_bus message_bus_t;
typedef struct messsage_channel message_channel_t;
typedef struct message_lane message_lane_t;
typedef struct control_bus control_bus_t;

typedef enum scheduler_state {
    SCHEDULER_INIT,
    SCHEDULER_RUN,
    SCHEDULER_PAUSE
} scheduler_state_t;

// RTOS kernel abstraction
typedef struct queue queue_t;
typedef struct heap heap_t;
typedef struct task task_t;

#endif /* REACTOR_H */
