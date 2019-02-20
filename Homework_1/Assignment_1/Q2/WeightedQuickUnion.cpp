//
// Created by Zekun Zhang on 2019-02-18.
//

#include "WeightedQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(int N, int MAX) {
    try {   //if N is larger than MAX throw error out
        if (N > MAX) {
            throw "Excess the limit!";
        }
    } catch (char const *error) {
        std::cout << error << std::endl;
    }
    id = new int[N];
    sz = new int[N];
    for (int i = 0; i < N; i++) {   //initialize array id and set id each object to itself and sz to 1
        id[i] = i;
        sz[i] = 1;
    }
}

WeightedQuickUnion::~WeightedQuickUnion() { //delete array to free memory
    delete[] id;
    delete[] sz;
}

int WeightedQuickUnion::root(int i) {   //chase parent pointers until reach the root
    while (i != id[i]) {
        i = id[i];
    }
    return i;
}

bool WeightedQuickUnion::connected(int p, int q) {  //check if p and q have the same root
    return root(p) == root(q);
}

void WeightedQuickUnion::Union(int p, int q) {  //change small root to point to large root and update sz
    int i = root(p);
    int j = root(q);
    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }

}

