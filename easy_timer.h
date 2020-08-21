#ifndef EASY_TIMER_EASY_TIMER_H
#define EASY_TIMER_EASY_TIMER_H

#include <vector>
#include <stack>
#include <ctime>

namespace ez_t {
    enum class interval {
        Millis,
        Seconds,
        Minutes
    };

    class timer {
    public:
        explicit timer(interval i);
        float getTime();

    private:
        static float ticks_to_millis(clock_t t);
        static float ticks_to_seconds(clock_t t);
        static float ticks_to_minutes(clock_t t);

        interval _mode;
        clock_t _start;
    };
}
#endif //EASY_TIMER_EASY_TIMER_H