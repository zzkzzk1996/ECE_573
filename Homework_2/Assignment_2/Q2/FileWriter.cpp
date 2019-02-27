//
// Created by Zekun Zhang on 2019-02-25.
//

#include "FileWriter.h"

/* first initialize the file */
FileWriter::FileWriter(string filename) {
    //open a csv file named'.csv' with discarding whatever it contains before
    string type = ".csv";
    filename += type;
    //give the value to the private variant
    this->filename = filename;
    ofstream out(filename, ios_base::trunc);
    //print the title for the following outputs
    out << "Size" << "," << "Times" << endl;
    //close the file
    out.close();
}

FileWriter::~FileWriter() {

}

/* write int type data to the csv file */
void FileWriter::Write(int size, int distance){
    //open the csv file
    ofstream out(this->filename, ios_base::app);
    //print the following outputs
    out << size << "," << distance << endl;
    //close the file
    out.close();
}

/* write double type data to the csv file */
void FileWriter::WriteD(int size, double cost) {
    //open the csv file
    ofstream out(this->filename, ios_base::app);
    //print the following outputs
    out << size << "," << cost << endl;
    //close the file
    out.close();

}
