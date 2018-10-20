/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/service.h>

#include "service_internal.h"

component_t const *rfa_service_component_get(const service_t *service) {
    return service->component;
}

rfa_result_t rfa_service_activate(service_t *service) {
    // TODO schedule service task for execution
    
    if(service->state 
    
    return REACTOR_RES_OK;
}

service_state_t rfa_service_state_get(const service_t *service) {
    return service->state;
}

bool rfa_service_is_active(const service_t *service) {
    return (service->state == SERVICE_ACTIVE);
}
