#ifndef _BIN_PACKING_PROBLEM_H
#define _BIN_PACKING_PROBLEM_H

#include <iostream>
#include <string>
#include <vector>

using std::istream;
using std::ostream;
using std::endl;
using std::string;
using std::vector;

class BinPackingProblem
{
private:
    int bin_pack_size = 0;
    vector<int> objects_list;

public:
    BinPackingProblem() = default;

    //Functions
    void add_object(int object);
    friend istream& operator>> (istream& is, BinPackingProblem& bpp); //Parsing
    friend ostream& operator<< (ostream& os, const BinPackingProblem& bpp); //Output

    //Getters
    int get_bin_pack_size() const;
    vector<int> get_objects_list() const;
    int get_sum_objects() const;

    //Setters
    void set_bin_pack_size(int new_bps);

};

#endif
