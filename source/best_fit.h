#ifndef _BEST_FIT_H
#define _BEST_FIT_H

#include <iostream>
#include <queue>
#include "algorithm.h"

class BestFit : public Algorithm {
public:
    //Constructors / Destructor
    BestFit(const int& bin_pack_size, vector<int>& objects_list);
    ~BestFit() = default;

    //Functions
    virtual void run();

};

#endif //_BEST_FIT_H
