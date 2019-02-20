//
// Created by Zekun Zhang on 2019-02-18.
//

#ifndef HOMEWORK_1_4_ALGORITHM_H
#define HOMEWORK_1_4_ALGORITHM_H

#include "Timer.h"
#include <iostream>
#include <vector>
#include <float.h>

using namespace std;

class Algorithm {
public:
    Algorithm();

    virtual ~Algorithm();
    void FindMostDifference(vector<double> data);
//    double ToAbsolute(double origin);
};


#endif //HOMEWORK_1_4_ALGORITHM_H
