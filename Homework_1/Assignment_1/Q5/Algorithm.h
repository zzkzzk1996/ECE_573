//
// Created by Zekun Zhang on 2019-02-18.
//

#ifndef HOMEWORK_1_5_ALGORITHM_H
#define HOMEWORK_1_5_ALGORITHM_H

#include "Timer.h"
#include <iostream>
#include <vector>

using namespace std;

class Algorithm {
public:
    Algorithm();

    virtual ~Algorithm();

    void Fastest3Sum(vector<int> data);
};


#endif //HOMEWORK_1_5_ALGORITHM_H
