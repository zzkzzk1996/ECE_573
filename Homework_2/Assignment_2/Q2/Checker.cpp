//
// Created by Zekun Zhang on 2019-02-25.
//

#include "Checker.h"

Checker::Checker() {}

Checker::~Checker() {

}

/* if it's an ascend array the order is 0, and if it's a descend array the order is 1 */
bool Checker::Check(vector<int> data, int l, int r, int order) {
    // if there's only one data in this dataset it must be sorted
    if(data.size() == 1)
        return true;

    if (order == 1) {
        for (int i = 0; i < data.size() - 1; i++) {
            if (data[i] < data[i + 1])
                return false;
        }
    } else if (order == 0) {
        for (int i = l; i < r; i++) {
            if (data[i] > data[i + 1])
                return false;
        }
    } else
        return false;

    return true;

}