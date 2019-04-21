/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor_core.h
 * 
 */

#ifndef KETL_CORE_H
#define KETL_CORE_H

#ifdef __cplusplus
extern "C" {
#endif
    
ketl_result_t ketl_core_init();

// module element descriptors
module_t *ketl_core_moddesc_get();

component_t *ketl_core_sensor_cmpdesc_get();
component_t *ketl_core_display_cmpdesc_get();
component_t *ketl_core_relay_cmpdesc_get();

service_t *ketl_core_sensor_svcdesc_get();
service_t *ketl_core_display_svcdesc_get();
service_t *ketl_core_relay_svcdesc_get();

#ifdef __cplusplus
}
#endif

#endif /* KETL_CORE_H */
