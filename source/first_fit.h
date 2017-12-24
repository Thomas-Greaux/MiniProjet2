#ifndef _FIRST_FIT_H
#define _FIRST_FIT_H

#include <iostream>
#include <queue>
#include "algorithm.h"

class FirstFit : public Algorithm {
public:
    //Constructors / Destructor
    FirstFit(const int& bin_pack_size, queue<int>& objects_list);
    ~FirstFit() = default;

    //Functions
    virtual void run(void);

};

#endif //_FIRST_FIT_H