/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/service.h>

#include "service_internal.h"

component_t *rfa_service_component_get(service_t *service) {
    return service->component;
}

rfa_result_t rfa_service_activate(firmware_t *context, service_t *service) {
    service_state_t old_state = service->state;
    
    if(old_state == SERVICE_INACTIVE) {
        service->state = SERVICE_INIT;
        service->init(context, service);
        service->state = SERVICE_ACTIVE;
    }
    
    return RFA_RES_OK;
}

service_state_t rfa_service_state_get(service_t *service) {
    return service->state;
}

bool rfa_service_is_active(service_t *service) {
    return (service->state == SERVICE_ACTIVE);
}
