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
    module_t *modules[RFA_FIRMWARE_MODULES_MAX];
    uint8_t component_count;
    component_t *components[RFA_FIRMWARE_COMPONENTS_MAX];
    uint8_t service_count;
    service_t *services[RFA_FIRMWARE_SERVICES_MAX];
};

const struct firmware _rootfw = {
    0, NULL,
    0, NULL,
    0, NULL
};

#endif /* FIRMWARE_INTERNAL_H */

