#ifndef _NEXT_FIT_H
#define _NEXT_FIT_H

#include <iostream>
#include <queue>
#include "algorithm.h"

class NextFit : public Algorithm {
public:
    //Constructors / Destructor
    NextFit(const int& bin_pack_size, queue<int>& objects_list);
    ~NextFit() = default;

    //Functions
    virtual void run(void);

};

#endif //_NEXT_FIT_H