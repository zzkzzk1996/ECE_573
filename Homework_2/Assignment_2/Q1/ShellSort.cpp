//
// Created by Zekun Zhang on 2019-02-24.
//

/* for part of the core algorithm is borrowed from the code in the slides */

#include "ShellSort.h"

ShellSort::ShellSort(const vector<int> &data) : data(data) {
    // set comparision times to zero
    comparision = 0;
}

ShellSort::~ShellSort() {
    //free this memory
    vector<int>().swap(this->data);
}

// this function is to achieve insertion sort with different steps
vector<int> ShellSort::InsertionSort(int h) {
    for (int i = h; i < this->data.size(); i++) {
        for (int j = i; j >= h; j -= h) {
            comparision++;
            if (Less(this->data[j], this->data[j - h])) {
                Swap(j, j - h);
            } else
                break;
        }
    }
    /* this part below is for debugging */
//    for(int i :this->data)
//    {
//        cout << i << " ";
//    }
    return this->data;
}

/* this function is to do comparision which is easy for us to track the times of comparision */
bool ShellSort::Less(int i, int j) {
    return i < j;
}

/* this function is to do the exchange */
void ShellSort::Swap(int i, int j) {
    int temp = 0;
    temp = this->data[i];
    this->data[i] = this->data[j];
    this->data[j] = temp;
}

/* getter for comparision times */
int ShellSort::getComparision() const {
    return comparision;
}



