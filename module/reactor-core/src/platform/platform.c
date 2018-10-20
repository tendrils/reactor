/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/platform.h>

#include "platform_internal.h"

rfa_result_t rfa_platform_scheduler_start()
    {
    return rpi_scheduler_start();
    }

rfa_result_t rfa_platform_scheduler_pause()
    {
    return rpi_scheduler_pause();
    }

scheduler_state_t rfa_platform_scheduler_state_get()
    {
    return rpi_scheduler_state_get();
    }

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rfa_platform_queue_create(queue_t **out, uint8_t cell_size, uint8_t cell_count)
    {
    rfa_result_t res;
    queue_t *queue = rfa_platform_malloc(sizeof(queue_t));
    
    res = rpi_queue_create(&queue->handle, cell_size, cell_count);
    }

rfa_result_t rfa_platform_queue_destroy(queue_t *queue)
    {
    return rpi_queue_destroy(queue);
    }
#endif

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
    void* rfa_platform_malloc(size_t length)
        {
        return rpi_malloc(length);
        }
    
    void rfa_platform_free(void *object)
        {
        rpi_free(object);
        }
    
    size_t rfa_platform_get_free_heap_size()
        {
        return rpi_get_free_heap_size();
        }
#endif

#if(REACTOR_DYNAMIC_MEMORY_ENABLED == 1)
rfa_result_t rfa_platform_task_create(task_t **out)
    {
    task_t *task;
    
    if((task = rpi_malloc(sizeof(task_t))) == NULL)
    {
        return RFA_RES_FAIL;
    }
    
    if(rpi_task_create(RPI_taskfunc_t function, const char * const name, unsigned short stack_depth,
        void *pvParameters, RPI_prio_t uxPriority, &task->handle))
    {
        *out = task;
        return RFA_RES_OK;
    }
    else
    {
        rpi_free(task);
        return RFA_RES_FAIL;
    }
    }
#endif

rfa_result_t rfa_platform_task_init(task_t *task)
{
    return rpi_task_create_static(task);
}

rfa_result_t rfa_platform_task_destroy(task_t *task)
    {
    return rpi_task_destroy(task);
    }

rfa_result_t rfa_platform_task_start(task_t *task)
    {
    return rpi_task_start(task);
    }

rfa_result_t rfa_platform_task_stop(task_t *task)
    {
    return rpi_task_stop(task);
    }
