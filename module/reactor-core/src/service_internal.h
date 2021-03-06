/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   firmware_internal.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 11:39 PM
 */

#ifndef SERVICE_INTERNAL_H
#define SERVICE_INTERNAL_H

struct service {
    service_state_t state;
    const char *name;
    component_t *component;
    rfa_result_t (*init)(
        firmware_t *context,
        service_t *service
    );
};

#endif /* SERVICE_INTERNAL_H */

