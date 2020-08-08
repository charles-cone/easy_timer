#ifndef EASY_TIMER_EASY_TIMER_H
#define EASY_TIMER_EASY_TIMER_H

#include <vector>
#include <stack>
#include <ctime>

namespace ez_t {
    class timer {
    public:
        static timer &getInstance();

        timer(timer const &) = delete;
        void operator=(timer const &) = delete;

        int createNewTimer();
        int getMillisFromTimer(int t_index);
        int getMillisAndStopTimer(int t_index);
        int getMillisAndResetTimer(int t_index);

    private:
        timer() = default;
        static int ticks_to_millis(clock_t t);

        std::vector<clock_t> starts;
        std::stack<int> open_indexes;

    };
}
#endif //EASY_TIMER_EASY_TIMER_H