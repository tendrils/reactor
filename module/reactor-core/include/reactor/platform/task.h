/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor/platform/task.h
 * 
 *         system-level concurrent task abstraction
 */

#ifndef REACTOR_TASK_H
#define REACTOR_TASK_H

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rfa_platform_task_create(taskfunc_t function,
        const char *name, unsigned short stack_depth,
        void *params, taskprio_t uxPriority, task_t **out);

rfa_result_t rfa_platform_task_destroy(task_t *task);
#endif

rfa_result_t rfa_platform_task_create_static(task_t *task, taskfunc_t function,
        const char *name, unsigned short stack_depth,
        void *params, taskprio_t uxPriority);

rfa_result_t rfa_platform_task_start(task_t *task);

rfa_result_t rfa_platform_task_stop(task_t *task);

#endif /* REACTOR_TASK_H */

