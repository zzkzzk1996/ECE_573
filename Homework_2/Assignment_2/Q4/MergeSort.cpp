//
// Created by Zekun Zhang on 2019-02-25.
//

#include "MergeSort.h"

/* for part of the core algorithm is borrowed from the code in the slides */

MergeSort::MergeSort(const vector<int> &data) : data(data) {
    // set comparision times to zero
    comparison = 0;
}

MergeSort::~MergeSort() {
    //free this memory
    vector<int>().swap(this->data);
}

/* this function is the start of the recursive division */
vector<int> MergeSort::Sort() {
    this->data_aux = this->data;
    Dosort(0, this->data.size() - 1);
    return this->data;
}

/* for this function is doing the bottom-up merge sort */
void MergeSort::BUSort() {
    int N = this->data.size();
    this->data_aux = this->data;
    for (int sz = 1; sz < N; sz += sz) {
        for (int l = 0; l < N - sz; l += sz + sz) {
            Merge(l, l + sz - 1, min(l + sz + sz - 1, N - 1));
        }
    }

}

void MergeSort::Merge(int l, int mid, int r) {
    // check the precondition that the left part and right part are both sorted
    Checker checker;
    assert(checker.Check(this->data, l, mid, 0));
    assert(checker.Check(this->data, mid + 1, r, 0));

    // copy elements from l to r
    for (int k = l; k <= r; k++) {
        this->data_aux[k] = this->data[k];
    }

    // do merge from l to r
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            this->data[k] = this->data_aux[j++];
        } else if (j > r) {
            this->data[k] = this->data_aux[i++];
        } else if (Less(this->data_aux[j], this->data_aux[i])) { // only these two operation below do the comparison
            comparison++;
            this->data[k] = this->data_aux[j++];
        } else {
            comparison++;
            this->data[k] = this->data_aux[i++];
        }
    }

    // to check whether the whole data is sorted
    assert(checker.Check(this->data, l, r, 0));
}

/* recursively divide the dataset until there's only one data in every part, then merge starts  */
void MergeSort::Dosort(int l, int r) {
    // if there is only one element in every part return
    if (l >= r)
        return;
    // define the very mid element
    int mid = l + (r - l) / 2;
    // divide them into two parts
    Dosort(l, mid);
    Dosort(mid + 1, r);
    //pruning part
//    if(!Less(this->data[mid + 1], this->data[mid]))
//        return;
    // do merge
    Merge(l, mid, r);
}

/* this function is to do comparision which is easy for us to track the times of comparision */
bool MergeSort::Less(int i, int j) {
    return i < j;
}

/* getter for comparision times */
int MergeSort::getComparison() const {
    return comparison;
}


