/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/service.h>

#include "service_internal.h"

size_t rfa_service_size(void)
    {
    return sizeof (struct service);
    }

component_t const *rfa_service_component_get(service_t const *service)
    {
    return service->component;
    }

rfa_result_t rfa_service_activate(service_t const *service)
    {
    // TODO schedule service task for execution
    return REACTOR_RES_OK;
    }
