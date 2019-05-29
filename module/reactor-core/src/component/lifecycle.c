/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/firmware.h>
#include <reactor/module.h>
#include <reactor/component.h>
#include <reactor/component/lifecycle.h>
#include <reactor_core.h>

#include "component_internal.h"
#include "component/lifecycle_internal.h"

component_t* rfa_cmp_lifecycle_descriptor()
    {
    return (component_t *)&_cmp_lifecycle;
    }
