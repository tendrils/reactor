/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kernel.h
 * Author: Tendril
 *
 * Created on June 10, 2018, 6:17 PM
 */

#ifndef KERNEL_H
#define KERNEL_H

#ifdef __cplusplus
extern "C" {
#endif

#if (RFAPORT_KERNEL == RFAPORT_KERNEL_FREERTOS)
#   include "kernel/freertos.h"
#else
#   error "No task scheduler selected"
#endif



#ifdef __cplusplus
}
#endif

#endif /* KERNEL_H */

