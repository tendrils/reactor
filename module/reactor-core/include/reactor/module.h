/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: rfa/module.h
 * Author: Tendril
 * 
 */

#ifndef REACTOR_MODULE_H
#define REACTOR_MODULE_H

#ifndef REACTOR_H
#   error "rfa.h must be included before" __FILE__
#endif

size_t rfa_module_size(void);

void rfa_module_define(module_t *module);

#endif /* REACTOR_MODULE_H */

