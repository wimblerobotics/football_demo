#include <pthread.h>
#include <stdexcept>
#include <unistd.h>                  /*  for sleep()  */


#include "pauseable_timer.h"

PauseableTimer::PauseableTimer(__uint16_t seconds_remaining) 
    : seconds_remaining_(seconds_remaining)
    , timer_is_suspended_(false)
    {
    if (pthread_mutex_init(&instance_mutex_, NULL) != 0) {
        throw std::logic_error("[PauseableTimer] mutex instance_mutex_ failed");
    }

    int fail = pthread_create(&timer_thread_, NULL, &PauseableTimer::timerThread, this);
    if (fail) {
        throw std::logic_error("[PauseableTimer] pthread_create failed");
    }

    pthread_detach(timer_thread_);

}

PauseableTimer::~PauseableTimer() {
    pthread_mutex_destroy(&instance_mutex_);
}

uint16_t PauseableTimer::getRemainingTime() {
    pthread_mutex_lock(&instance_mutex_);
    uint16_t seconds_remaining = seconds_remaining_;
    pthread_mutex_unlock(&instance_mutex_);
    return seconds_remaining;
}

void PauseableTimer::resetTimer(uint16_t seconds_remaining) {
    pthread_mutex_lock(&instance_mutex_);
    seconds_remaining_ = seconds_remaining;
    pthread_mutex_unlock(&instance_mutex_);
}

void PauseableTimer::start() {
    pthread_mutex_lock(&instance_mutex_);
    timer_is_suspended_ = false;
    pthread_cond_signal(&suspend_timer_conditional_);
    pthread_mutex_unlock(&instance_mutex_);
}

void PauseableTimer::stop() {
    pthread_mutex_lock(&instance_mutex_);
    timer_is_suspended_ = true;
    pthread_mutex_unlock(&instance_mutex_);
}

void* PauseableTimer::timerThread(void* class_instance) {
    PauseableTimer* pausable_timer_instance = (PauseableTimer*) class_instance;
    pausable_timer_instance->stop();
    while (true) {
        pthread_mutex_lock(&pausable_timer_instance->instance_mutex_);
        while (pausable_timer_instance->timer_is_suspended_) pthread_cond_wait(&pausable_timer_instance->suspend_timer_conditional_, &pausable_timer_instance->instance_mutex_);
        pausable_timer_instance->seconds_remaining_--;
        pthread_mutex_unlock(&pausable_timer_instance->instance_mutex_);
        sleep(1);
    }

    return NULL;
}

