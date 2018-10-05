/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor/platform/scheduler.h
 * Author: Tendril
 *
 * Created on March 29, 2018, 11:28 AM
 */

#ifndef REACTOR_MEMORY_H
#define REACTOR_MEMORY_H

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
    void* rfa_platform_malloc(size_t length);
    void rfa_platform_free(void *object);
    size_t rfa_platform_get_free_heap_size();
#endif

#endif /* REACTOR_MEMORY_H */

