//
// Created by Zekun Zhang on 2019-02-18.
//

#include "QuickFind.h"

QuickFind::QuickFind(int N, int MAX) {

    try {   //if N is larger than MAX throw error out
        if (N > MAX) {
            throw "Excess the limit!";
        }
    } catch (char const *error) {
        std::cout << error << std::endl;
    }
    length = N;
    id = new int[N];   //initialize array id
    for (int i = 0; i < N; i++)  //set id each object to itself
    {
        id[i] = i;
    }
}

QuickFind::~QuickFind() {   //delete array to free memory
    delete[] id;
}

bool QuickFind::connected(int p, int q) {   //check whether p and q are in the same components
    return id[p] == id[q];
}

void QuickFind::Union(int p, int q) {   //change all entries from id[p] to id[q]
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < length; i++) {
        if (id[i] == pid) {
            id[i] = qid;
        }
    }

}

