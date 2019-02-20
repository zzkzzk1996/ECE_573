//
// Created by Zekun Zhang on 2019-02-17.
//

#include "FileReader.h"

FileReader::FileReader() {}

FileReader::~FileReader() {

}

vector<vector<int>> FileReader::Reader() {
    vector<vector<int> > dataList; // all data container initialize
    vector<int> datap; // data container initialize
    vector<int> dataq;
    try {
        ifstream ifs;
        string line;
        int databitp;
        int databitq;
        string preFileName = "../hw1-2.data/";
        string postFileName = "pair.txt";
        vector<int> fileList = {8, 32, 128, 512, 1024, 4096, 8192};
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
                    stringstream ss(line);
                    string pstr, qstr;
                    getline(ss, pstr, ' ');
                    getline(ss, qstr);
                    databitp = stoi(pstr);   //change the data format from string to integer
                    databitq = stoi(qstr);
//                cout << databitp << endl;    //this print is used for debugging
//                cout << databitq << endl;
                    datap.push_back(databitp);    //add data to the vector container
                    dataq.push_back(databitq);
                }
                dataList.push_back(datap);   //add data to datalist which contains all data
                dataList.push_back(dataq);
//                for (int i = 0; i < datap.size(); i++) {    //this for loop is for debugging
//                    cout << datap[i] << " " << dataq[i] << " ";
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
