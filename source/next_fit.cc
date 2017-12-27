#include "next_fit.h"

NextFit::NextFit(const int& bin_pack_size, vector<int>& objects_list)
    : Algorithm(bin_pack_size, objects_list)
{

}

void NextFit::run()
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    unsigned int next_index = 0;
    bool hasFilled;
    for (int &it : objects_list) {
        hasFilled = false;
        for(unsigned int index = 0; index < nb_bin_pack_used; index++, next_index++) {
            if (next_index > nb_bin_pack_used - 1) {
                next_index = 0;
            }
            if (bins.at(next_index)->can_fill(it)) {
                bins.at(next_index++)->fill(it);
                hasFilled = true;
                break;
            }
        }
        if (!hasFilled) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            next_index = 0;
            bins.back()->fill(it);
        }
    }
    for_each(bins.begin(), bins.end(), [](BinPack* bp){ delete bp; });
}
