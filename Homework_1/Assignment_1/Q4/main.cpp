//
// Created by Zekun Zhang on 2019-02-18.
//

#include "Algorithm.h"
#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    FileReader fileReader;
    Algorithm algorithm;
    vector<vector<double> > temp;
    temp = fileReader.Reader();     //read all data into a 2 dimension vector, in which each row contains data from one file
    for (int i = 0; i < temp.size(); i++) {
        algorithm.FindMostDifference(temp[i]);
    }
    return 0;
}