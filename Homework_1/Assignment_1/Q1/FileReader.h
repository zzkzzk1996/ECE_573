//
// Created by Zekun Zhang on 2019-02-16.
//

#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class FileReader {
public:
    // constructor & destructor
    FileReader();
    virtual ~FileReader();
    vector<vector<int>> Reader();

};


#endif //FILEREADER_H
