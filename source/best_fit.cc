#include "best_fit.h"

BestFit::BestFit(const int& bin_pack_size, vector<int>& objects_list)
        : Algorithm(bin_pack_size, objects_list)
{

}

void BestFit::run()
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    unsigned int best_index = 0;
    bool hasBest;
    for (int& object : objects_list) {
        best_index = 0;
        hasBest = false;
        for (unsigned int index = 0; index < nb_bin_pack_used; index++) {
            if (bins.at(index)->can_fill(object)) {
                if (!hasBest) {
                    best_index = index;
                    hasBest = true;
                } else if (bins.at(best_index)->get_remaining_size() > bins.at(index)->get_remaining_size()) {
                    best_index = index;
                }
            }
        }
        if (!hasBest) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(object);
        } else {
            bins.at(best_index)->fill(object);
        }
    }
    for_each(bins.begin(), bins.end(), [](BinPack* bp) { delete bp; });
}
