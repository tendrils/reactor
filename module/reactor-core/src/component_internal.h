/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   component_internal.h
 * Author: Tendril
 *
 */

#ifndef COMPONENT_INTERNAL_H
#define COMPONENT_INTERNAL_H

struct component {
    const module_t *module;
    const rfa_result_t (*init_static)(
        firmware_t *context,
        component_t *component
    );
};

#endif /* COMPONENT_INTERNAL_H */

