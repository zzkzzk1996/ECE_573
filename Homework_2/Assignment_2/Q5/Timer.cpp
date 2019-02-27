//
// Created by Zekun Zhang on 2019-02-26.
//

#include "Timer.h"

Timer::Timer() {
    start = clock();    //when a object of timer is created, the timer starts working
}

Timer::~Timer() {

}

double Timer::Counter() {
    end = clock();
    double time = end - start;
    return time / CLOCKS_PER_SEC * 1000;   //return a time with millisecond
}
