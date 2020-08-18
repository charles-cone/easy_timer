#include "easy_timer.h"

ez_t::timer &ez_t::timer::getInstance() {
    static timer instance;
    return instance;
}

int ez_t::timer::createNewTimer() {
    int index;
    if(open_indexes.empty()) {
        starts.push_back(NULL);
        index = starts.size()-1;
    } else {
       index = open_indexes.top();
       open_indexes.pop();
    }
    starts[index] = clock();
    return index;
}

int ez_t::timer::getMillisFromTimer(int t_index) {
    clock_t t = clock();
    t -= starts[t_index];
    return ticks_to_millis(t);
}

int ez_t::timer::getMillisAndStopTimer(int t_index) {
    clock_t t = clock();
    t -= starts[t_index];

    if(t_index == starts.size()-1){
        starts.pop_back();
    } else {
        open_indexes.push(t_index);
    }

    return ticks_to_millis(t);
}

int ez_t::timer::getMillisAndResetTimer(int t_index) {
    clock_t t = clock();
    t -= starts[t_index];

    starts[t_index] = clock();

    return ticks_to_millis(t);
}

int ez_t::timer::ticks_to_millis(clock_t t) {
    return t * (CLOCKS_PER_SEC/1000);
}

void ez_t::timer::printTicsPerSecond() {
    std::cout << CLOCKS_PER_SEC << std::endl;
}

