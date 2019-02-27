//
// Created by Zekun Zhang on 2019-02-24.
//

#include <iostream>
#include "FileReader.h"
#include "ShellSort.h"
#include "Checker.h"
#include "FileWriter.h"

using namespace std;

int main() {
    FileReader fileReader;
    /* read all data into a 2 dimension vector, in which each row contains data from one file */
    vector<vector<int> > data = fileReader.Reader();
    vector<vector<int> > temp = data;
    // this vector contains the size corresponding to each file
    vector<int> size = {1024, 2048, 4096, 8192, 16384, 32768};

    // vector container for times for insertion sort
    vector<int> count1;
    // vector container for times for shell sort
    vector<int> count2;

    // file writer for insertion sort
    FileWriter fileWriter1("Insertion0");
    // file writer for shell sort
    FileWriter fileWriter2("Shell0");

    /* insertion sort */
    for (int i = 0; i < temp.size(); i++) {
        ShellSort shellSort(temp[i]);
        temp[i] = shellSort.InsertionSort(1);
        int times = shellSort.getComparision();
        //push times to vector container for displaying on the console
        count1.push_back(times);
        //write the result to a csv file
        fileWriter1.Write(size[i], times);

        Checker checker;
        if(checker.Check(temp[i], 0))
        {
            cout << " Sorted " << endl;
        } else
            cout << " Not be sorted " << endl;
        /* this part below is for debugging */
//        for(int j : temp[i])
//        {
//            cout << j << " ";
//        }
    }
    /* this part is for displaying the times comparision take */
    for(int i = 0; i < data.size(); i++)
    {
        cout << count1[i] << " ";
    }
    cout << endl;

    // refresh temp
    temp = data;

    /* shell sort with 7, 3, 1-sort */
    for (int i = 0; i < temp.size(); i++) {
        ShellSort shellSort(temp[i]);
        Checker checker;
        temp[i] = shellSort.InsertionSort(7);

        temp[i] = shellSort.InsertionSort(3);

        temp[i] = shellSort.InsertionSort(1);

        int times = shellSort.getComparision();
        //push times to vector container for displaying on the console
        count2.push_back(times);
        //write the result to a csv file
        fileWriter2.Write(size[i], times);

        if(checker.Check(temp[i], 0))
        {
            cout << " Sorted " << endl;
        } else
            cout << " Not be sorted " << endl;
        /* this part below is for debugging */
//        for(int j : temp[i])
//        {
//            cout << j << " ";
//        }
    }
    /* this part is for displaying the times comparision take */
    for(int i = 0; i < data.size(); i++)
    {
        cout << count2[i] << " ";
    }
    return 0;
}