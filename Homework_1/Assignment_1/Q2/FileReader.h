//
// Created by Zekun Zhang on 2019-02-17.
//

#ifndef HOMEWOR_1_2_FILEREADER_H
#define HOMEWOR_1_2_FILEREADER_H


#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class FileReader {
public:
    // constructor & destructor
    FileReader();
    virtual ~FileReader();
    vector<vector<int>> Reader();

};


#endif //HOMEWOR_1_2_FILEREADER_H
