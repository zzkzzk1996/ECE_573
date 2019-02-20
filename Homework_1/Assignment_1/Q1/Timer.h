//
// Created by Zekun Zhang on 2019-02-17.
//

#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer {
public:
    Timer();    //constructor and destructor
    virtual ~Timer();

    double Counter();

private:
    clock_t start, end; //initialize start, end as type clock_t
};

#endif //TIMER_H
