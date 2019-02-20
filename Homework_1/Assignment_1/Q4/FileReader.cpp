//
// Created by Zekun Zhang on 2019-02-18.
//

#include "FileReader.h"

FileReader::FileReader() {}

FileReader::~FileReader() {

}

vector<vector<double>> FileReader::Reader() {
    vector<vector<double> > dataList; // all data container initialize
    vector<double> data; // data container initialize
    try {
        ifstream ifs;
        string line;
        double databit;
        string preFileName = "../hw1-1.data/";
        string postFileName = "int.txt";
        vector<int> fileList = {8, 32, 128, 512, 1024, 4096, 4192, 8192};
        for (int i = 0; i < fileList.size(); i++) {
            string file = to_string(fileList[i]) + postFileName;
            string fileName = preFileName + file;
            ifs.open(fileName, ios_base::in);

            if (!ifs.is_open() ||
                ifs.fail()) {     //if there's something wrong with the text file opening throw error out
                throw "Error: Can't open the text file !";
            } else {
                while (getline(ifs, line))   //use while loop to get all data from the corresponding text
                {
                    databit = stod(line);   //change the data format from string to integer
//                cout << databit << endl;    //this print is used for debugging
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
