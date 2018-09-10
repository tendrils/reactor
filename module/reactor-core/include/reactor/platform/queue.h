/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor/platform/queue.h
 * Author: Tendril
 *
 * Created on March 29, 2018, 11:28 AM
 */

#ifndef REACTOR_QUEUE_H
#define REACTOR_QUEUE_H

size_t rfa_platform_queue_size(queue_t *queue);

queue_t *rfa_platform_queue_alloc(uint8_t cell_size, uint8_t cell_count);

#endif /* REACTOR_KERNEL_H */

