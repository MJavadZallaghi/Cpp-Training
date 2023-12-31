#ifndef RATE_LIMITER_H
#define RATE_LIMITER_H
#endif // RATE_LIMITER_H

class RateLimiter {
    private:
        double maxChangePerCycle;
        double lastValue;
        double newValue;
        double limitedValue;
    public:
        RateLimiter(double maxChangePerCycle_def);
        void init_lastValue();
        void init_limitedValue();
        void get_newValue(double newValue_get);
        void update_lastValue();
        double limitChange(double currentSignalVal_get);
};
