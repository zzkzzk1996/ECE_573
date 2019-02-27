//
// Created by Zekun Zhang on 2019-02-25.
//

#ifndef HOMEWORK_2_2_TIMER_H
#define HOMEWORK_2_2_TIMER_H

#include <time.h>

class Timer {
public:
    Timer();    //constructor and destructor
    virtual ~Timer();

    double Counter();

private:
    clock_t start, end; //initialize start, end as type clock_t
};


#endif //HOMEWORK_2_2_TIMER_H
