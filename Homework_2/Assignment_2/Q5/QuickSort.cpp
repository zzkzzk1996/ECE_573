//
// Created by Zekun Zhang on 2019-02-26.
//

#include "QuickSort.h"


/* for part of the core algorithm is borrowed from the code in the slides */

QuickSort::QuickSort(const vector<int> &data) : data(data) {
    // set comparision times to zero
    comparison = 0;
}

QuickSort::~QuickSort() {
    //free this memory
    vector<int>().swap(this->data);
}

/* this function is the entry of the quick sort */
void QuickSort::Sort() {

    Dosort(0, this->data.size() - 1);
    Checker checker;
    assert(checker.Check(this->data, 0, this->data.size() - 1, 0));

}

/* this function is the entry of the quick sort for median of 3 */
void QuickSort::Sort_MedianOf3() {
    Dosort_mo3(0, this->data.size() - 1);
    Checker checker;
    assert(checker.Check(this->data, 0, this->data.size() - 1, 0));
}

/* this function is the entry of the quick sort with cut off */
void QuickSort::Sort_Cutoff(int cutoff) {
    Dosort_cutoff(0, this->data.size() - 1, cutoff);
    Checker checker;
    assert(checker.Check(this->data, 0, this->data.size() - 1, 0));
}

/* recursively do partition */
void QuickSort::Dosort(int l, int r) {
    if (r <= l) return;
    int j = Partition(l, r);
    Dosort(l, j - 1);
    Dosort(j + 1, r);
}

/* recursively do partition for median of 3 */
void QuickSort::Dosort_mo3(int l, int r) {
    if (r <= l) return;
    int m = MedianOf3(l, r);
    Swap(l, m);
    int j = Partition(l, r);
    Dosort_mo3(l, j - 1);
    Dosort_mo3(j + 1, r);
}

void QuickSort::Dosort_cutoff(int l, int r, int cutoff) {
    if (r <= l) return;
    if (r - l <= cutoff) {
        InsertionSort(l, r);
        return;
    }

    int m = MedianOf3(l, r);
    Swap(l, m);

    int j = Partition(l, r);
    Dosort_cutoff(l, j - 1, cutoff);
    Dosort_cutoff(j + 1, r, cutoff);
}

/* this function is for partition */
int QuickSort::Partition(int l, int r) {
    int i = l, j = r + 1;
    while (true) {
        while (Less(this->data[++i], this->data[l])) {
            if (i == r) break;
        }

        while (Less(this->data[l], this->data[--j])) {
            if (j == l) break;
        }

        // when two pointers meet, break
        if (i >= j) break;

        Swap(i, j);
    }
    Swap(l, j);

    return j;
}

/* Get the median of three of the array, changing the array as you do */
int QuickSort::MedianOf3(int l, int r) {
    int mid = l + (r - l) / 2;
    if (this->data[r] < this->data[l]) {
        swap(l, r);
    }
    if (this->data[mid] < this->data[l]) {
        swap(mid, l);
    }
    if (this->data[r] < this->data[mid]) {
        swap(r, mid);
    }

    return mid;
}

/* this function is to do comparision which is easy for us to track the times of comparision */
bool QuickSort::Less(int i, int j) {
    return i < j;
}

/* this function is to do the exchange */
void QuickSort::Swap(int i, int j) {
    int temp;
    temp = this->data[i];
    this->data[i] = this->data[j];
    this->data[j] = temp;
}

/* this function is insertion sort which used in quick sort with cut off*/
void QuickSort::InsertionSort(int l, int r) {
    for (int i = l; i <= r; i++) {
        for (int j = i; j > l; j--) {
            if (Less(this->data[j], this->data[j - 1])) {
                Swap(j, j - 1);
            } else
                break;
        }
    }
}
