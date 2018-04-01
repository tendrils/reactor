/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "rfa.h"
#include "rfa/kernel.h"
#include "kernel_internal.h"

size_t rfa_kernel_if_size(void)
    {
    return sizeof (kernel_if_t);
    }

os_queue_t rfa_kernel_queue_alloc(kernel_if_t *ki, uint8_t cell_size, uint8_t cell_count)
    {
    
    }
