//
// Created by Zekun Zhang on 2019-02-25.
//

#include "DataCreator.h"

DataCreator::DataCreator() {}

DataCreator::~DataCreator() {

}
/* data creator */
vector<int> DataCreator::Creator() {
    vector<int> data;
    for(int i = 0; i<1024; i++){
        data.push_back(1);
    }
    for(int i = 0; i<2048; i++){
        data.push_back(11);
    }
    for(int i = 0; i<4096; i++){
        data.push_back(111);
    }
    for(int i = 0; i<1024; i++){
        data.push_back(1111);
    }
    return data;
}
