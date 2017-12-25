#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "bin_pack.h"

using std::for_each;
using std::queue;
using std::vector;

class Algorithm {
public:
    //Constructors / Destructor
    Algorithm(const int& bin_pack_size, vector<int>& objects_list);
    ~Algorithm() = default;

    //Functions
    virtual void run() = 0;

    //Getters / Setters
    int get_nb_bin_pack_used(void) const;

protected:
    int nb_bin_pack_used = 1;
    const int bin_pack_size;
    vector<int> objects_list;

};

#endif //_ALGORITHM_H
