//
// Created by Zekun Zhang on 2019-02-18.
//

#include "QuickUnion.h"

QuickUnion::QuickUnion(int N, int MAX) {
    try {   //if N is larger than MAX throw error out
        if (N > MAX) {
            throw "Excess the limit!";
        }
    } catch (char const *error) {
        std::cout << error << std::endl;
    }
    id = new int[N];    //initialize array id
    for (int i = 0; i < N; i++)  //set id each object to itself
    {
        id[i] = i;
    }
}

QuickUnion::~QuickUnion() { //delete array to free memory
    delete[] id;
}

int QuickUnion::root(int i) {   //chase parent pointers until reach the root
    while (i != id[i]) {
        i = id[i];
    }
    return i;
}

bool QuickUnion::connected(int p, int q) {  //check if p and q have the same root
    return root(p) == root(q);
}

void QuickUnion::Union(int p, int q) {  //change root of p to point to root of q
    int i = root(p);
    int j = root(q);
    id[i] = j;
}
