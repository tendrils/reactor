/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   service.h
 * Author: Tendril
 *
 * Created on March 26, 2018, 9:01 AM
 */

#ifndef REACTOR_SERVICE_H
#define REACTOR_SERVICE_H

#ifndef REACTOR_H
#   error "REACTOR_H must be included before " __FILE__
#endif

component_t *rfa_service_component_get(const service_t *service);

service_state_t rfa_service_state_get(const service_t *service);

bool rfa_service_is_active(const service_t *service);

rfa_result_t rfa_service_activate(service_t *service);

#endif /* REACTOR_SERVICE_H */
