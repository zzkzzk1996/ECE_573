//
// Created by Zekun Zhang on 2019-02-16.
//

#include "FileReader.h"
#include "Algorithm.h"
#include <iostream>

using namespace std;

int main() {
    FileReader fileReader;
    Algorithm algorithm;
    vector<vector<int> > temp;
    temp =
            fileReader.Reader();     //read all data into a 2 dimension vector, in which each row contains data from one file
    for (int i = 0; i < temp.size(); i++) {
        algorithm.Naive3Sum(temp[i]);
        algorithm.Sophi3Sum(temp[i]);
    }
    return 0;
}