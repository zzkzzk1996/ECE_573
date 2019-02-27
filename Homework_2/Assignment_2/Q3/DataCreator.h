//
// Created by Zekun Zhang on 2019-02-25.
//

#ifndef HOMEWORK_2_3_DATACREATOR_H
#define HOMEWORK_2_3_DATACREATOR_H

#include <vector>
#include <iostream>

using namespace std;

class DataCreator {
public:
    /* constructor and destructor */
    DataCreator();

    virtual ~DataCreator();

    vector<int> Creator();
};


#endif //HOMEWORK_2_3_DATACREATOR_H
