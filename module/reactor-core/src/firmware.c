/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/firmware.h>
#include "firmware_internal.h"
#include "module_internal.h"

firmware_t* rfa_firmware_root() {
    return _rootfw;
}

size_t rfa_firmware_size(void)
    {
    return sizeof (firmware_t);
    }

rfa_result_t rfa_firmware_module_define(firmware_t *app, module_t *module)
    {
    if (app->module_count < REACTOR_FIRMWARE_MODULES_MAX &&
        (app->component_count + module->component_count) <= REACTOR_FIRMWARE_COMPONENTS_MAX)
        {
        app->modules[app->module_count++] = module;
        for (int i = 0; i < module->component_count; i++)
            {
            app->components[app->component_count++] = module->components[i];
            }
        return REACTOR_RES_OK;
        }
    return REACTOR_RES_FAIL;
    }

uint8_t rfa_firmware_module_count(firmware_t *app) {
    return app->module_count;
    }

module_t* rfa_firmware_module_get(firmware_t *app, uint8_t idx) {
    return app->modules[idx];
    }

uint8_t rfa_firmware_service_count(firmware_t *app) {
    return app->service_count;
    }

service_t* rfa_firmware_service_get(firmware_t *app, uint8_t idx) {
    return app->services[idx];
    }

// initialize services + subsystems
rfa_result_t rfa_firmware_load(firmware_t *firmware) {
    return REACTOR_RES_OK;
}

// start message queues, pass control to scheduler/runloop
rfa_result_t rfa_firmware_run(firmware_t *firmware) {
    return REACTOR_RES_OK;
}