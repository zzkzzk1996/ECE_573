//
// Created by Zekun Zhang on 2019-02-18.
//

#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {

}

// using two pointer approach to achieve this algorithm, whose time complexity is O(N^2)

void Algorithm::Fastest3Sum(vector<int> data) {
    vector<vector<int>> res;    //result container
    sort(data.begin(),
         data.end());     //first sort the array with STL sort whose time complexity is (O(N(LogN)))

    Timer time;
    for (int k = 0; k < data.size(); k++) {
        //        if (data[k] > 0) break;   //this line would be efficiently prune this function
        if (k > 0 && data[k] == data[k - 1]) {  //if there's same data just skip it
            continue;
        }
        int target = 0 - data[k];
        int i = k + 1, j = data.size() - 1;     //define two pointers
        while (i < j) {
            if (data[i] + data[j] == target) {
                res.push_back({data[k], data[i], data[j]});
                while (i < j && data[i] == data[i + 1]) ++i;    //if there's same data just skip it
                while (i < j && data[j] == data[j - 1]) --j;    //if there's same data just skip it
                ++i;
                --j;
            } else if (data[i] + data[j] < target) ++i;
            else --j;
        }
    }
    double cost = time.Counter();

    cout << "The time cost is " << cost << endl;
    if (res.empty()) {      //if res is empty which means there's no result for this data array
//        cout << " Can't find 3sum result " << endl;
    } else {
        for (int i = 0; i < res.size(); i++) {
            cout << "The result pairs of data are " << res[i][0] << ", " << res[i][1] << ", " << res[i][2] << endl;
        }
    }
}
