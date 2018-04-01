/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "rfa.h"
#include "rfa/firmware.h"
#include "firmware_internal.h"
#include "module_internal.h"

size_t rfa_firmware_size(void)
    {
    return sizeof (firmware_t);
    }

rfa_result_t rfa_firmware_module_define(firmware_t *app, module_t *module)
    {
    if (app->module_count < RFA_FIRMWARE_MODULES_MAX &&
        (app->component_count + module->component_count) <= RFA_FIRMWARE_COMPONENTS_MAX)
        {
        app->modules[app->module_count++] = module;
        for (int i = 0; i < module->component_count; i++)
            {
            app->components[app->component_count++] = module->components[i];
            }
        return RFA_RES_OK;
        }
    return RFA_RES_FAIL;
    }
