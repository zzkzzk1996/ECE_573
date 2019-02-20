//
// Created by Zekun Zhang on 2019-02-18.
//

#ifndef HOMEWORK_1_5_TIMER_H
#define HOMEWORK_1_5_TIMER_H


#include <time.h>

class Timer {
public:
    Timer();    //constructor and destructor
    virtual ~Timer();

    double Counter();

private:
    clock_t start, end; //initialize start, end as type clock_t
};

#endif //HOMEWORK_1_5_TIMER_H
