#ifndef _BIN_PACK_H
#define _BIN_PACK_H

#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

class BinPack {
public:
    //Constructors / Destructor
    BinPack(const int& bin_pack_size);
    ~BinPack() = default;

    //Functions
    bool can_fill(const int& size) const;
    void fill(const int& size);

    //Getters / Setters
    int get_current_size(void) const;

private:
    const int& bin_pack_size;
    int current_size = 0;

};

#endif //_BIN_PACK_H