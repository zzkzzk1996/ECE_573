//
// Created by Zekun Zhang on 2019-02-18.
//

#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {

}

//double Algorithm::ToAbsolute(double origin) {
//    if (origin < 0) {
//        origin = -origin;
//    }
//    return origin;
//}

// finding max and min to finish this problem, whose time complexity is (O(N))

void Algorithm::FindMostDifference(vector<double> data) {
//    int l = 0, r = data.size() - 1;
//    while (l < r) {
//        if (ToAbsolute(data[l] - data[r]) < ToAbsolute(data[l + 1] - data[r])) {
//            l++;
//        } else {
//            r--;
//        }
//
//    }
    double max = DBL_MIN;
    double min = DBL_MAX;
    Timer time;
    for (double i : data) {     //traversal the whole array find out the maximum and minimum then do the calculate
        if (i > max) {
            max = i;
        }
        if (i < min) {
            min = i;
        }
    }
    double res = max - min;
    double cost = time.Counter();
    cout << "The max absolute difference is " << res << endl;
    cout << "The cost of this program is " << cost << " ms" << endl;
    cout << "The pair for this result is " << max << "," << min << endl;
}
