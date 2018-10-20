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

#ifndef REACTOR_SEMAPHORE_H
#define REACTOR_SEMAPHORE_H

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rfa_platform_mutex_alloc(queue_t **out);
#endif

rfa_result_t rfa_platform_mutex_destroy(queue_t *queue);

#endif /* REACTOR_SEMAPHORE_H */

