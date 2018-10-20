/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor_core.c
 * 
 * main file for the Reactor Core (reactor_core) module
 * 
 */

#include <reactor.h>
#include <reactor_core.h>
#include <reactor/firmware.h>
#include <reactor/module.h>
#include <reactor/component.h>
#include <reactor/component/lifecycle.h>

#include "module_internal.h"
#include "component_internal.h"

const struct module _mod_rfa_core;
const struct component _cmp_lifecycle;
const struct component _cmp_busmgr;
const struct service _svc_lifecycle_root;
const struct service _svc_busmgr_root;

__module const module_t const *mod_rfa_core = &_mod_rfa_core;

const struct module _mod_rfa_core = {
    2,
    {
        &_cmp_lifecycle,
        &_cmp_busmgr,
    }
};
const struct component _cmp_lifecycle = {
    &_mod_rfa_core,
};
const struct component _cmp_busmgr = {
    &_mod_rfa_core,
};
const struct service _svc_lifecycle_root;
const struct service _svc_busmgr_root;

#ifdef REACTOR_CORE_CUSTOM_LAUNCHER
extern int main(int argc, char** argv);
#else
int main(int argc, char** argv)
    {
    firmware_t const *rootfw = rfa_firmware_root();
    
    rfa_firmware_load(rootfw);
    rfa_firmware_run(rootfw);
    
    return 1;
    }
#endif

/*
 * 
 */
__preload void rfa_core_boot()
    {
    rfa_module_define((module_t *) &_mod_rfa_core);
    }

rfa_result_t rfa_core_init()
    {
    return RFA_RES_OK;
    }

module_t *rfa_core_moddesc_get()
    {
    return (module_t *) &_mod_rfa_core;
    }

component_t *rfa_core_lifecycle_cmpdesc_get()
    {
    return (component_t *) &_cmp_lifecycle;
    }
component_t *rfa_core_busmgr_cmpdesc_get()
    {
    return (component_t *) &_cmp_busmgr;
    }

service_t *rfa_core_lifecycle_root_svcdesc_get()
    {
    return (service_t *) &_svc_lifecycle_root;
    }

service_t *rfa_core_busmgr_root_svcdesc_get()
    {
    return (service_t *) &_svc_busmgr_root;
    }