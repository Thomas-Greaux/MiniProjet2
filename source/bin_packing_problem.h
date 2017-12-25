#ifndef _BIN_PACKING_PROBLEM_H
#define _BIN_PACKING_PROBLEM_H

#include <queue>
#include <iostream>

using std::queue;
using std::istream;

class BinPackingProblem
{
private:
    int bin_pack_size = 0;
    queue<int> objects_list;

public:
    BinPackingProblem() = default;
    int get_bin_pack_size(void) const;
    queue<int> get_objects_list(void) const;
    friend istream& operator>> (istream& is, BinPackingProblem& bpp);
};

#endif
