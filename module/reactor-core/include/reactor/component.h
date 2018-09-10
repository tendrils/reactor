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

rfa_result_t rfa_component_initialize(component_t *component);

#endif /* REACTOR_COMPONENT_H */

