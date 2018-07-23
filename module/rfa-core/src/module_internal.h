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

#ifndef COMPONENT_INTERNAL_H
#define COMPONENT_INTERNAL_H

struct module {
    uint8_t component_count;
    component_t *components[RFA_MODULE_COMPONENTS_MAX];
};

#endif /* MODULE_INTERNAL_H */

