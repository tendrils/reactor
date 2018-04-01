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

#ifndef RFA_SERVICE_H
#define RFA_SERVICE_H

#ifndef RFA_H
#   error "RFA_H must be included before" __FILE__
#endif

size_t rfa_service_size(void);

component_t *rfa_service_component_get(service_t *service);

#endif /* RFA_SERVICE_H */

