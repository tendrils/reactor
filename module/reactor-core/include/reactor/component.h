/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   component.h
 * Author: Tendril
 * 
 */

#ifndef REACTOR_COMPONENT_H
#define REACTOR_COMPONENT_H

#ifndef REACTOR_H
#   error "REACTOR_H must be included before" __FILE__
#endif

size_t rfa_component_size(void);

module_t *rfa_component_module_get(component_t *component);
void rfa_component_module_set(component_t *component, module_t *module);

rfa_result_t rfa_component_initialize(firmware_t *context, component_t *component);

#endif /* REACTOR_COMPONENT_H */

