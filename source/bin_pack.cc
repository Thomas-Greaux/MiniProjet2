#include "bin_pack.h"

BinPack::BinPack(const int& bin_pack_size)
        : bin_pack_size(bin_pack_size)
{

}

bool BinPack::can_fill(const int& size) const
{
    return (bin_pack_size - current_size) >= size;
}

void BinPack::fill(const int& size)
{
    current_size += size;
}

int BinPack::get_current_size() const
{
    return current_size;
}

int BinPack::get_remaining_size() const
{
    return bin_pack_size - current_size;
}