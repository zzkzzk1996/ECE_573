//
// Created by Zekun Zhang on 2019-02-16.
//

#include "FileReader.h"
#include "QuickFind.h"
#include "QuickUnion.h"
#include "WeightedQuickUnion.h"
#include "Timer.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    FileReader fileReader;
    vector<vector<int> > temp;
    vector<int> fileList = {8, 32, 128, 512, 1024, 4096, 8192};
    temp = fileReader.Reader();     //read all data into a 2 dimension vector, in which each row contains data from one file
    for (int i = 0; i < fileList.size(); i++) {
        vector<int> p = temp[i * 2];    //extract every file's p & q
        vector<int> q = temp[i * 2 + 1];
//        for (int i = 0; i < p.size(); i++) {    //this for loop is for debugging
//            cout << p[i] << " " << q[i] << " ";
//        }
        const int MAX = 8192;
        int N = fileList[i];

        //QuickFind
        QuickFind quickFind(N, MAX);
        Timer time1;
        for(int j = 0; j < N; j++)
        {
            if(!quickFind.connected(p[j], q[j]))
            {
                quickFind.Union(p[j], q[j]);
            }
        }
        double cost1 = time1.Counter();
        cout << "The cost of QuickFind is " << cost1 << " ms" << endl;

        //QuickUnion
        QuickUnion quickUnion(N, MAX);
        Timer time2;
        for(int j = 0; j < N; j++)
        {
            if(!quickUnion.connected(p[j], q[j]))
            {
                quickUnion.Union(p[j], q[j]);
            }
        }
        double cost2 = time2.Counter();
        cout << "The cost of QuickUnion is " << cost2 << " ms" << endl;

        //WeightedQuickUnion
        WeightedQuickUnion weightedQuickUnion(N, MAX);
        Timer time3;
        for(int j = 0; j < N; j++)
        {
            if(weightedQuickUnion.connected(p[j], q[j]))
            {
                weightedQuickUnion.Union(p[j], q[j]);
            }
        }
        double cost3 = time3.Counter();
        cout << "The cost of WeightedQuickUnion is " << cost3 << " ms" << endl;
    }

    return 0;
}