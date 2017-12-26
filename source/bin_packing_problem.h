#ifndef _BIN_PACKING_PROBLEM_H
#define _BIN_PACKING_PROBLEM_H

#include <vector>
#include <iostream>

using std::vector;
using std::istream;
using std::ostream;

class BinPackingProblem
{
private:
    int bin_pack_size = 0;
    vector<int> objects_list;

public:
    BinPackingProblem() = default;

    //Getters
    int get_bin_pack_size(void) const;
    vector<int> get_objects_list(void) const;
    int get_sum_objects(void) const;

    //Setters
    void set_bin_pack_size(int new_bps);
    void add_object(int object);

    friend istream& operator>> (istream& is, BinPackingProblem& bpp); //Parsing
    friend ostream& operator<< (ostream& os, const BinPackingProblem& bpp); //Output
};

#endif
