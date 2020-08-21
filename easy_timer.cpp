#include "easy_timer.h"

ez_t::timer::timer(ez_t::interval i) {
    _mode = i;
    _start = clock();
}

float ez_t::timer::getTime() {
    clock_t time = clock() - _start;
    switch (_mode) {
        case interval::Millis:
            return ticks_to_millis(time);
        case interval::Seconds:
            return ticks_to_seconds(time);
        case interval::Minutes:
            return ticks_to_minutes(time);
    }
}

float ez_t::timer::ticks_to_seconds(clock_t t) {
    return t / (float)CLOCKS_PER_SEC;
}

float ez_t::timer::ticks_to_minutes(clock_t t) {
    return t / ((float)CLOCKS_PER_SEC*60);
}

float ez_t::timer::ticks_to_millis(clock_t t) {
    return (t / (float)CLOCKS_PER_SEC)*1000;
}
