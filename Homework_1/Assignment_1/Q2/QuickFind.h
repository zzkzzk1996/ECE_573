//
// Created by Zekun Zhang on 2019-02-18.
//

#ifndef HOMEWOR_1_2_QUICKFIND_H
#define HOMEWOR_1_2_QUICKFIND_H

#include <iostream>
//  some codes are original from the tutorial slides
class QuickFind {
public:
    //constructor and destructor
    QuickFind(int N, int MAX);
    virtual ~QuickFind();
    bool connected(int p, int q);
    void Union(int p, int q);



private:
    int length;
    int *id;
};


#endif //HOMEWOR_1_2_QUICKFIND_H
