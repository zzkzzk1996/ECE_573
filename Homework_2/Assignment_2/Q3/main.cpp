//
// Created by Zekun Zhang on 2019-02-25.
//

#include "DataCreator.h"
#include "Checker.h"
#include <iostream>
#include <assert.h>

using namespace std;

/* bubble sort algorithm */
void BubbleSort(vector<int> data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                /* do swap */
                int temp;
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    /* create dataset for sorting */
    DataCreator dataCreator;
    vector<int> data = dataCreator.Creator();

    /* compress original dataset */
    vector<int> big_data;
    for (int i = 0; i < data.size(); i += 1024) {
        big_data.push_back(data[i]);
    }

    /* sorting */
    int n_big_data = big_data.size();
    BubbleSort(big_data, n_big_data);

    /* recreate data */
    vector<int> new_data;
    for (int i = 0; i < n_big_data; ++i) {
        for (int j = 0; j < 1024; ++j) {
            new_data.push_back(big_data[i]);
        }
    }

    /* check if the data set is sorted */
    Checker checker;
    assert(checker.Check(new_data, 0, new_data.size() - 1, 0));

    /* display what's in the new dataset */
    for (int i : new_data) {
        cout << i << " ";
    }

    return 0;
}