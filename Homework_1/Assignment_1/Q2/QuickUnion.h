//
// Created by Zekun Zhang on 2019-02-18.
//

#ifndef HOMEWOR_1_2_QUICKUNION_H
#define HOMEWOR_1_2_QUICKUNION_H

#include <iostream>
//  some codes are original from the tutorial slides
class QuickUnion {
public:
    QuickUnion(int N, int MAX);
    virtual ~QuickUnion();
    bool connected(int p, int q);
    void Union(int p, int q);

private:
    int root(int i);
    int *id;
};


#endif //HOMEWOR_1_2_QUICKUNION_H
