//
// Created by Zekun Zhang on 2019-02-25.
//

#include "FileReader.h"
#include "Checker.h"
#include "MergeSort.h"
#include "FileWriter.h"
#include <iostream>

using namespace std;

int main() {
    FileReader fileReader;
    /* read all data into a 2 dimension vector, in which each row contains data from one file */
    vector<vector<int> > data = fileReader.Reader();
    vector<vector<int> > temp = data;
    // this vector contains the size corresponding to each file
    vector<int> size = {1024, 2048, 4096, 8192, 16384, 32768};

    // vector container for times for merge sort
    vector<int> count1;
    // vector container for times for bottom-up merge sort
    vector<int> count2;

    // file writer for merge sort
    FileWriter fileWriter1("Merge1");
    // file writer for bottom-up merge sort
    FileWriter fileWriter2("BPMerge1");

    /* merge sort */
    for (int i = 0; i < temp.size(); i++) {
        MergeSort mergeSort(temp[i]);
        temp[i] = mergeSort.Sort();
        int times = mergeSort.getComparison();
        //push times to vector container for displaying on the console
        count1.push_back(times);
        //write the result to a csv file
        fileWriter1.Write(size[i], times);
    }
    /* this part is for displaying the times comparision take */
    for (int i = 0; i < data.size(); i++) {
        cout << count1[i] << " ";
    }
    cout << endl;

    // refresh temp
    temp = data;

    /* bottom-up merge sort */
    for(int i = 0; i < temp.size(); i++)
    {
        MergeSort mergeSort(temp[i]);
        mergeSort.BUSort();
        int times = mergeSort.getComparison();
        //push times to vector container for displaying on the console
        count2.push_back(times);
        //write the result to a csv file
        fileWriter2.Write(size[i], times);
    }
    /* this part is for displaying the times comparision take */
    for(int i = 0; i < data.size(); i++)
    {
        cout << count2[i] << " ";
    }
    return 0;
}