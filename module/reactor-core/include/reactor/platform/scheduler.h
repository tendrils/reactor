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

#ifndef REACTOR_SCHEDULER_H
#define REACTOR_SCHEDULER_H

rfa_result_t rfa_platform_scheduler_start();

rfa_result_t rfa_platform_scheduler_pause();

scheduler_state_t rfa_platform_scheduler_state_get();

#endif /* REACTOR_SCHEDULER_H */

