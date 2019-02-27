//
// Created by Zekun Zhang on 2019-02-24.
//

#ifndef HOMEWORK_2_1_CHECKER_H
#define HOMEWORK_2_1_CHECKER_H

#include <iostream>
#include <vector>

using namespace std;

/* check whether the data is sorted */
class Checker {
public:
    // constructor and destructor
    Checker();

    virtual ~Checker();

    bool Check(vector<int> data, int order);
};


#endif //HOMEWORK_2_1_CHECKER_H
