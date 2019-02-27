//
// Created by Zekun Zhang on 2019-02-25.
//


#include "FileReader.h"

FileReader::FileReader() {}

FileReader::~FileReader() {

}

vector<vector<int>> FileReader::Reader() {
    vector<vector<int> > dataList; // all data container initialize
    try {
        ifstream ifs;
        string line;
        int databit;
        /* this part below is to create file name */
        string preFileName = "../dataset-problem2-hw2/";      ////for this part you can just comment this code snippet
        string postFileName0 = "data0.";            ////for this part you can just comment this code snippet
        string postFileName1 = "data1.";            ////for this part you can just comment this code snippet
        vector<int> fileList = {1024, 2048, 4096, 8192, 16384,
                                32768};       ////this line you can keep it, it would be meaningless if you comment others
        // file name 1024, 2048, 4096, 8192, 16384, 32768
        for (int i = 0; i < fileList.size(); i++) {
            vector<int> data; // data container initialize
            string file = postFileName1 +
                          to_string(fileList[i]);        ////for this part you can just comment this code snippet
            string fileName = preFileName + file;       ////you can just change the file name to change the input

            ifs.open(fileName, ios_base::in);

            if (!ifs.is_open() ||
                ifs.fail()) {     //if there's something wrong with the text file opening throw error out
                throw "Error: Can't open the text file !";
            } else {
                while (getline(ifs, line))   //use while loop to get all data from the corresponding text
                {
                    databit = stoi(line);   //change the data format from string to integer
//                    cout << databit << endl;    //this print is used for debugging
                    data.push_back(databit);    //add data to the vector container

                }
                dataList.push_back(data);   //add data to datalist which contains all data
//                for (int i : data) {    //this for loop is for debugging
//                    cout << i << " ";
//                }
                ifs.close();
            }
        }

    } catch (char const *error)    //catch error and print the error message out
    {
        cout << error << endl;
    }
    return dataList;
}