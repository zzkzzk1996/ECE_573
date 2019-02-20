//
// Created by Zekun Zhang on 2019-02-17.
//

#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "Timer.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Algorithm {
public:
    Algorithm();    //constructor and destructor
    virtual ~Algorithm();
    void Naive3Sum(vector<int> data);
    void Sophi3Sum(vector<int> data);
};


#endif //ALGORITHM_H
