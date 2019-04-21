/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conf_rfa_core.h
 * 
 * reactor-core configuration for ketl-core project
 * 
 */

#ifndef CONF_REACTOR_CORE_H
#define CONF_REACTOR_CORE_H

/* software platform configuration */

#define REACTOR_FIRMWARE_MODULES_MAX            4
#define REACTOR_FIRMWARE_COMPONENTS_MAX         16
#define REACTOR_FIRMWARE_SERVICES_MAX           16

#define REACTOR_MODULE_COMPONENTS_MAX           4
#define REACTOR_MODULE_BOOTSERVICES_MAX         4

#define REACTOR_DYNAMIC_MEMORY_ENABLED          1

#define RPI_KERNEL                      RPI_KERNEL_NONE

#endif /* CONF_REACTOR_CORE_H */
