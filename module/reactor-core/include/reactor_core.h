/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor_core.h
 * 
 */

#ifndef REACTOR_CORE_H
#define REACTOR_CORE_H

#ifdef __cplusplus
extern "C" {
#endif
    
rfa_result_t rfa_core_init();

// module element descriptors
module_t *rfa_core_moddesc_get();

component_t *rfa_core_lifecycle_cmpdesc_get();
component_t *rfa_core_busmgr_cmpdesc_get();

service_t *rfa_core_lifecycle_root_svcdesc_get();
service_t *rfa_core_busmgr_root_svcdesc_get();

#ifdef __cplusplus
}
#endif

#endif /* REACTOR_CORE_H */

