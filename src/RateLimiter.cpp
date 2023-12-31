#include "RateLimiter.hpp"
#include <math.h>

RateLimiter::RateLimiter(double maxChangePerCycle_def) {
    maxChangePerCycle = maxChangePerCycle_def;
    RateLimiter::init_lastValue();
    RateLimiter::init_limitedValue();
}

void RateLimiter::init_lastValue() {
    lastValue = 0;
}

void RateLimiter::init_limitedValue() {
    limitedValue = 0;
}

void RateLimiter::get_newValue(double newValue_get) {
    newValue = newValue_get;
}

void RateLimiter::update_lastValue(){
    lastValue = limitedValue;
}

double RateLimiter::limitChange(double currentSignalVal_get) {
    RateLimiter::get_newValue(currentSignalVal_get);
    double signal_change = newValue - lastValue;
    if (signal_change >= 0) {
        if (signal_change >= maxChangePerCycle) {
            limitedValue = lastValue + maxChangePerCycle;
        }
        else {
            limitedValue = newValue;
        }
    }
    else {
        if (abs(signal_change) >= maxChangePerCycle) {
            limitedValue = lastValue - maxChangePerCycle;
        }
        else {
            limitedValue = newValue;
        }
    }
    RateLimiter::update_lastValue();
    return limitedValue;
}