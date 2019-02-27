//
// Created by Zekun Zhang on 2019-02-25.
//

#ifndef HOMEWORK_2_4_MERGESORT_H
#define HOMEWORK_2_4_MERGESORT_H

#include <assert.h>
#include <vector>
#include <iostream>
#include "Checker.h"
using namespace std;

class MergeSort {
public:
    // constructor and destructor
    MergeSort(const vector<int> &data);

    virtual ~MergeSort();

    vector<int> Sort();

    void BUSort();

private:
    // vector container for data and auxiliary data
    vector<int> data;
    vector<int> data_aux;
    // comparision times
    int comparison;

    void Merge(int l, int mid, int r);

    void Dosort(int l, int r);

    bool Less(int i, int j);

public:
    int getComparison() const;
};


#endif //HOMEWORK_2_4_MERGESORT_H
