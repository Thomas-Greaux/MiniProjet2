#include "bin_pack.h"

BinPack::BinPack(const int& bin_pack_size)
    : bin_pack_size(bin_pack_size)
{

}

bool BinPack::can_fill(const int& size) const
{
    if ((bin_pack_size - current_size) >= size) {
        return true;
    }
    return false;
}

void BinPack::fill(const int& size)
{
    current_size += size;
}

int BinPack::get_current_size(void) const
{
    return current_size;
}