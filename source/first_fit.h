#ifndef _FIRST_FIT_H
#define _FIRST_FIT_H

#include <iostream>
#include <vector>
#include "algorithm.h"

using std::vector;

class FirstFit : public Algorithm {
public:
    //Constructors / Destructor
    FirstFit(const int& bin_pack_size, vector<int>& objects_list);
    ~FirstFit() = default;

    //Functions
    virtual void run();

};

#endif //_FIRST_FIT_H
