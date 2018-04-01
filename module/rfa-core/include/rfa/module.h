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

#ifndef RFA_MODULE_H
#define RFA_MODULE_H

#ifndef RFA_H
#   error "rfa.h must be included before" __FILE__
#endif

size_t rfa_module_size(void);

void rfa_module_define(firmware_t *app, module_t *module);

#endif /* RFA_MODULE_H */

