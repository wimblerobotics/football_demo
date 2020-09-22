#pragma once

#include <pthread.h>

class PauseableTimer {
public:
    PauseableTimer(__uint16_t seconds_remaining);
    ~PauseableTimer();

    // Get the remaining time.
    __uint16_t getRemainingTime();

    // Reset the timer.
    void resetTimer(uint16_t seconds_remaining);

    // Start the timer.
    void start();

    // Stop/pause the timer.
    void stop();

protected:
    PauseableTimer() {} // Cannot create via the empty constructor.

private:
    // The thread to do the timing.
    static void* timerThread(void* class_instance);

    // Flag to stop the timer.
    bool timer_is_suspended_;

    // Seconds remaining on the timer.
	uint16_t seconds_remaining_;

    // Conditional variable to suspend the timer;
    pthread_cond_t suspend_timer_conditional_;

    // Thread for timer.
    pthread_t timer_thread_;

    // Mutex to protect threaded access to state.
    pthread_mutex_t instance_mutex_;

};