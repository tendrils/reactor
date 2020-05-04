/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/component.h>
#include "component_internal.h"

size_t rfa_component_size(void) {
    return sizeof (struct component);
}

module_t *rfa_component_module_get(component_t *component) 
    {
        return component->module;
    }

void rfa_component_module_set(component_t *component, module_t *module) 
    {
        component->module = module;
    }

rfa_result_t rfa_component_initialize(firmware_t *context, component_t *component) {
    return component->init_static(context, component);
}
