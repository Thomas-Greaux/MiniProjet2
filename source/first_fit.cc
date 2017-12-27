#include "first_fit.h"

FirstFit::FirstFit(const int& bin_pack_size, vector<int>& objects_list)
    : Algorithm(bin_pack_size, objects_list)
{

}

void FirstFit::run()
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    bool hasFilled;
    for (int &it : objects_list) {
        hasFilled = false;
        for(BinPack* bin_pack : bins) {
            if (bin_pack->can_fill(it)) {
                bin_pack->fill(it);
                hasFilled = true;
                break;
            }
        }
        if (!hasFilled) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(it);
        }
    }
    for_each(bins.begin(), bins.end(), [](BinPack* bp){ delete bp; });
}
