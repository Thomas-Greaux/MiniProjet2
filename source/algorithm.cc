#include "algorithm.h"

Algorithm::Algorithm(const int& bin_pack_size, vector<int>& objects_list)
    : bin_pack_size(bin_pack_size)
    , objects_list(objects_list)
{

}

int Algorithm::get_nb_bin_pack_used(void) const
{
    return nb_bin_pack_used;
}
