#ifndef _WORST_FIT_H
#define _WORST_FIT_H

#include <iostream>
#include <queue>
#include "algorithm.h"

class WorstFit : public Algorithm {
public:
    //Constructors / Destructor
    WorstFit(const int& bin_pack_size, queue<int>& objects_list);
    ~WorstFit() = default;

    //Functions
    virtual void run(void);

};

#endif //_WORST_FIT_H