//
// Created by Zekun Zhang on 2019-02-24.
//

#ifndef HOMEWORK_2_1_SHELLSORT_H
#define HOMEWORK_2_1_SHELLSORT_H

#include <vector>
#include <iostream>

using namespace std;

class ShellSort {
public:
    // constructor and destructor
    ShellSort(const vector<int> &data);
    virtual ~ShellSort();
    vector<int> InsertionSort(int h);
    int getComparision() const;

private:
    bool Less(int i, int j);
    void Swap(int i, int j);
    // vector container for data
    vector<int> data;
    // comparision times
    int comparision;
};


#endif //HOMEWORK_2_1_SHELLSORT_H
