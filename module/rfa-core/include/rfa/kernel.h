/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kernel.h
 * Author: Tendril
 *
 * Created on March 29, 2018, 11:28 AM
 */

#ifndef RFA_KERNEL_H
#define RFA_KERNEL_H

void rfa_kernel_if_size(kernel_if_t *ki);

os_queue_t rfa_kernel_queue_alloc(kernel_if_t *ki, uint8_t cell_size, uint8_t cell_count);

#endif /* RFA_KERNEL_H */

