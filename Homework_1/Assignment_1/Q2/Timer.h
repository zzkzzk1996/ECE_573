//
// Created by Zekun Zhang on 2019-02-17.
//

#ifndef HOMEWOR_1_2_TIMER_H
#define HOMEWOR_1_2_TIMER_H
#include <time.h>

class Timer {
public:
    Timer();    //constructor and destructor
    virtual ~Timer();
    double Counter();

private:
    clock_t start, end; //initialize start, end as type clock_t
};


#endif //HOMEWOR_1_2_TIMER_H
