/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   firmware_internal.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 11:39 PM
 */

#ifndef FIRMWARE_INTERNAL_H
#define FIRMWARE_INTERNAL_H

#include <stddef.h>

struct firmware {
    uint8_t module_count;
    module_t const *modules[REACTOR_FIRMWARE_MODULES_MAX];
    uint8_t component_count;
    component_t const *components[REACTOR_FIRMWARE_COMPONENTS_MAX];
    uint8_t service_count;
    service_t const *services[REACTOR_FIRMWARE_SERVICES_MAX];
};

struct firmware _rootfw = {
    0, { NULL },
    0, { NULL },
    0, { NULL },
};

#endif /* FIRMWARE_INTERNAL_H */

