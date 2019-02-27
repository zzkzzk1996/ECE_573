//
// Created by Zekun Zhang on 2019-02-25.
//

#include <iostream>
#include "Timer.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "MergeSort.h"

using namespace std;

int main() {
    FileReader fileReader0;
    FileReader fileReader1;
    /* read all data from two different dataset into a 2 dimension vector, in which each row contains data from one file */
    vector<vector<int> > data0 = fileReader0.Reader(0);
    vector<vector<int> > data1 = fileReader1.Reader(1);
    // this vector contains the size corresponding to each file
    vector<int> size = {1024, 2048, 4096, 8192, 16384, 32768};
    // vector container for distance and time for merge sort
    vector<int> distance;
    vector<double> time;
    // file writer for Kendall Tau distance
    FileWriter fileWriter1("Kendall_Tau_distance");
    // file writer for execution time
    FileWriter fileWriter2("Time");

    /* **********************************************************************
     * for part of the core algorithm is borrowed from the following websites
     * https://shmilyaw-hotmail-com.iteye.com/blog/2275113
     * https://shmilyaw-hotmail-com.iteye.com/blog/1769047
     * http://algs4.cs.princeton.edu/25applications/KendallTau.java.html
     * ********************************************************************** */


    for (int i = 0; i < data0.size(); i++) {
        int length = data0[i].size();
        vector<int> DataSet0Index;
        vector<int> DataSet1Index;

        DataSet0Index.resize(length);
        DataSet1Index.resize(length);
        // start counting time
        Timer t;

        for (int j = 0; j < data0.size(); j++) {
            DataSet0Index[data1[i][j]] = j;
        }

        for (int j = 0; j < data0.size(); j++) {
            DataSet1Index[j] = DataSet0Index[data1[i][j]];
        }

        MergeSort mergeSort(DataSet1Index);
        mergeSort.Sort();
        double cost = t.Counter();
        //push time cost to vector container for displaying on the console
        time.push_back(cost);
        int dis = mergeSort.getComparison();
        //push distance to vector container for displaying on the console
        distance.push_back(dis);

        //write the result to a csv file
        fileWriter1.Write(size[i], dis);
        fileWriter2.WriteD(size[i], cost);
        // free the memory
        vector <int >().swap(DataSet0Index);
        vector <int >().swap(DataSet0Index);
    }
    /* this part is for displaying the distance take */
    for(int i = 0; i < data0.size(); i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
    /* this part is for displaying the time cost */
    for(int i = 0; i < data0.size(); i++)
    {
        cout << time[i] << " ";
    }


    return 0;
}