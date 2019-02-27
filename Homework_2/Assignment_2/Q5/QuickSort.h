//
// Created by Zekun Zhang on 2019-02-26.
//

#ifndef HOMEWORK_2_5_QUICKSORT_H
#define HOMEWORK_2_5_QUICKSORT_H

#include <iostream>
#include <vector>
#include "Checker.h"

using namespace std;

class QuickSort {
public:
    // constructor and destructor
    QuickSort(const vector<int> &data);

    virtual ~QuickSort();

    void Sort();

    void Sort_MedianOf3();

    void Sort_Cutoff(int cutoff);


private:
    vector<int> data;
    int comparison;
    int Partition(int l, int r);
    bool Less(int i, int j);
    void Swap(int i, int j);
    void Dosort(int l, int r);
    void Dosort_mo3(int l, int r);
    void Dosort_cutoff(int l, int r, int cutoff);
    int MedianOf3(int l, int r);
    void InsertionSort(int l, int r);
};


#endif //HOMEWORK_2_5_QUICKSORT_H
