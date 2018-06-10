/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   port.h
 * Author: Tendril
 *
 * Created on June 9, 2018, 1:40 PM
 */

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C" {
#endif

#   if(RFAPORT_KERNEL == FREERTOS_10_0)
    #define RFAPORT_kernel_if_size(ki) rfaport_freertos_10_0_kernel_if_size(ki)
#   endif

#ifdef __cplusplus
}
#endif

#endif /* PORT_H */

