//
// Created by Zekun Zhang on 2019-02-18.
//

#ifndef HOMEWOR_1_2_WEIGHTEDQUICKUNION_H
#define HOMEWOR_1_2_WEIGHTEDQUICKUNION_H

#include <iostream>
//  some codes are original from the tutorial slides
class WeightedQuickUnion {
public:
    WeightedQuickUnion(int N, int MAX);
    virtual ~WeightedQuickUnion();
    bool connected(int p, int q);
    void Union(int p, int q);

private:
    int root(int i);
    int *id;
    int *sz;
};


#endif //HOMEWOR_1_2_WEIGHTEDQUICKUNION_H
