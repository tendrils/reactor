/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "reactor.h"
#include "rfa/component.h"
#include "component_internal.h"

size_t rfa_component_size(void) {
    return sizeof (struct component);
}

rfa_result_t rfa_component_initialize(component_t *component) {
    return component->init_static();
}
