#ifndef _ALMOST_WORST_FIT_H
#define _ALMOST_WORST_FIT_H

#include <iostream>
#include <queue>
#include "algorithm.h"

class AlmostWorstFit : public Algorithm {
public:
    //Constructors / Destructor
    AlmostWorstFit(const int& bin_pack_size, vector<int>& objects_list);
    ~AlmostWorstFit() = default;

    //Functions
    virtual void run(void);

};

#endif //_ALMOST_WORST_FIT_H
