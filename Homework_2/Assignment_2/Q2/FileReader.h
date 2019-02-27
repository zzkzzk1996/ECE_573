//
// Created by Zekun Zhang on 2019-02-25.
//

#ifndef HOMEWORK_2_2_FILEREADER_H
#define HOMEWORK_2_2_FILEREADER_H

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

    vector<vector<int>> Reader(int dataset);

};
#endif //HOMEWORK_2_2_FILEREADER_H