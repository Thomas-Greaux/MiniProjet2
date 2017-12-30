#include "almost_worst_fit.h"

AlmostWorstFit::AlmostWorstFit(const int& bin_pack_size, vector<int>& objects_list)
        : Algorithm(bin_pack_size, objects_list)
{

}

void AlmostWorstFit::run()
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    unsigned int almost_worst_index = 0;
    unsigned int worst_index = 0;
    bool hasAlmostWorst;
    for (int& object : objects_list) {
        almost_worst_index = 0;
        worst_index = 0;
        hasAlmostWorst = false;
        for (unsigned int index = 0; index < nb_bin_pack_used; index++) {
            if (bins.at(index)->can_fill(object)) {
                if (!hasAlmostWorst) {
                    almost_worst_index = index;
                    worst_index = almost_worst_index;
                    hasAlmostWorst = true;
                } else if (bins.at(worst_index)->get_remaining_size() < bins.at(index)->get_remaining_size()) {
                    almost_worst_index = worst_index;
                    worst_index = index;
                }
            }
        }
        if (!hasAlmostWorst) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(object);
        } else {
            bins.at(almost_worst_index)->fill(object);
        }
    }
    for_each(bins.begin(), bins.end(), [](BinPack* bp) { delete bp; });
}
