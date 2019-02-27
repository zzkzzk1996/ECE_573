//
// Created by Zekun Zhang on 2019-02-26.
//

#include "FileReader.h"
#include "FileWriter.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "Timer.h"
#include <iostream>

using namespace std;

int main() {
    FileReader fileReader;
    /* read all data into a 2 dimension vector, in which each row contains data from one file */
    vector<vector<int> > data = fileReader.Reader();
    vector<vector<int> > temp = data;
    // this vector contains the size corresponding to each file
    vector<int> size = {1024, 2048, 4096, 8192, 16384, 32768};
    // vector container for the execution time for merge sort
    vector<double> time1;
    // vector container for the execution for quick sort
    vector<double> time2;
    // vector container for the execution for quick sort with cut off
    vector<double> time3;

    // file writer for merge sort
    FileWriter fileWriter1("Merge1");
    // file writer for quick sort
    FileWriter fileWriter2("Quick1");
    // file writer for quick sort with cutoff
    FileWriter fileWriter3("QuickCut1");


    /* merge sort */
    for (int i = 0; i < temp.size(); i++) {
        Timer t1;
        MergeSort mergeSort(temp[i]);
        mergeSort.Sort();
        double cost1 = t1.Counter();
        //push cost to vector container for displaying on the console
        time1.push_back(cost1);
        //write the result to a csv file
        fileWriter1.Write(size[i], cost1);
    }
    /* this part is for displaying the execution time cost */
    for (int i = 0; i < data.size(); i++) {
        cout << time1[i] << " ";
    }
    cout << endl;
    // refresh data
    temp = data;

    /* quick sort */
    for (int i = 0; i < temp.size(); i++) {
        Timer t2;
        QuickSort quickSort(temp[i]);
        quickSort.Sort_MedianOf3();
        double cost2 = t2.Counter();
        //push cost to vector container for displaying on the console
        time2.push_back(cost2);
        //write the result to a csv file
        fileWriter2.Write(size[i], cost2);
    }
    /* this part is for displaying the execution time cost */
    for (int i = 0; i < data.size(); i++) {
        cout << time2[i] << " ";
    }
    cout << endl;
    // refresh data
    temp = data;

    /* quick sort with cutoff = 7 */
    for (int i = 0; i < temp.size(); i++) {
        Timer t3;
        QuickSort quickSort(temp[i]);
        quickSort.Sort_Cutoff(7);
        double cost3 = t3.Counter();
        //push cost to vector container for displaying on the console
        time3.push_back(cost3);
        //write the result to a csv file
        fileWriter3.Write(size[i], cost3);
    }
    /* this part is for displaying the execution time cost */
    for (int i = 0; i < data.size(); i++) {
        cout << time3[i] << " ";
    }
    cout << endl;
    // refresh data
    temp = data;

    /* this part is testing the different cut-off input */
    vector<double> time4;
    for(int i = 0; i < 10; i++)
    {
        Timer t4;
        QuickSort quickSort(temp[4]);
        quickSort.Sort_Cutoff(i);
        double cost4 = t4.Counter();
        //push cost to vector container for displaying on the console
        time4.push_back(cost4);
        temp = data;
    }

    for (int i = 0; i < time4.size(); i++) {
        cout << time4[i] << " ";
    }

    return 0;
}