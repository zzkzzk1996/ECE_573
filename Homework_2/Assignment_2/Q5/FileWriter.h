//
// Created by Zekun Zhang on 2019-02-26.
//

#ifndef HOMEWORK_2_5_FILEWRITER_H
#define HOMEWORK_2_5_FILEWRITER_H


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FileWriter {
public:
    // constructor and destructor
    FileWriter(string filename);

    virtual ~FileWriter();

    void Write(int size, double times);

private:
    string filename;

};

#endif //HOMEWORK_2_5_FILEWRITER_H
