//
// Created by Zekun Zhang on 2019-02-17.
//

#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {

}

//The "naive" implementation whose time complexity is (O(N^3))

void Algorithm::Naive3Sum(vector<int> data) {
    Timer time;
    int count = 0;
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            for (int k = j + 1; k < data.size(); k++) {
                if (data[i] + data[j] + data[k] == 0) {
                    count++;
                }
            }

        }
    }
    double cost = time.Counter();
    cout << "The cost of the program is " << cost << " ms" << endl;
    cout << "The number of 3-sum is " << count << endl;

//    ofstream out("data.csv");   //open a csv file named'data.csv'
//    out << "Naive 3 Sum" << endl;   //print the title for the following outputs
//    out.close();
//    out <<
}

// The "sophisticated" implementation whose time complexity is (O(N^2(logN)))

void Algorithm::Sophi3Sum(vector<int> data) {
    Timer time;
    int count = 0;
    sort(data.begin(), data.end());     //use STL sort, whose time complexity is (O(N(logN)))
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            //since binary_search in cpp STL only get a boolean return value, just directly use it in an 'if'
            if (binary_search(data.begin() + j + 1, data.end(), -(data[i] + data[j]))) {
                count++;
            }
        }
    }
    double cost = time.Counter();
    cout << "The cost of the program is " << cost << " ms" << endl;
    cout << "The number of 3-sum is " << count << endl;
}
