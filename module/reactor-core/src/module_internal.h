/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   module_internal.h
 * Author: Tendril
 *
 */

#ifndef MODULE_INTERNAL_H
#define MODULE_INTERNAL_H

struct module {
    uint8_t component_count;
    component_t const *components[REACTOR_MODULE_COMPONENTS_MAX];
    service_t const *bootservices[REACTOR_MODULE_BOOTSERVICES_MAX];
    const rfa_result_t (*app_loaded)();
};

#define _module_can_register_component(module) \
    (module->component_count <= REACTOR_MODULE_COMPONENTS_MAX)

#define _module_register_component(module, component) \
    (module->components[module->component_count++] = component)

#endif /* MODULE_INTERNAL_H */

