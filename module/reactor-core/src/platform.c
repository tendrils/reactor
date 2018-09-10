/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/platform.h>

#include "platform_internal.h"

rfa_result_t rfa_platform_scheduler_start() {
    return RPI_scheduler_start();
}

rfa_result_t rfa_platform_scheduler_pause() {
    return RPI_scheduler_pause();
}

scheduler_state_t rfa_platform_scheduler_state_get() {
    return RPI_scheduler_state_get();
}

size_t rfa_platform_queue_size(queue_t *queue) {
    return RPI_queue_size(queue);
}

queue_t *rfa_platform_queue_alloc(uint8_t cell_size, uint8_t cell_count) {
    return RPI_queue_alloc(cell_size, cell_count);
}

rfa_result_t rfa_platform_queue_destroy(queue_t *queue) {
    return RPI_queue_destroy(queue);
}

size_t rfa_platform_task_size() {
    return RPI_task_size();
}
rfa_result_t rfa_platform_task_create(task_t *task) {
    return RPI_task_create(task);
}

rfa_result_t rfa_platform_task_destroy(task_t *task) {
    return RPI_task_destroy(task);
}

rfa_result_t rfa_platform_task_start(task_t *task) {
    return RPI_task_start(task);
}

rfa_result_t rfa_platform_task_stop(task_t *task) {
    return RPI_task_stop(task);
}
