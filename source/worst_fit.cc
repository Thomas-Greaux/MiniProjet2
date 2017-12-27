#include "worst_fit.h"

WorstFit::WorstFit(const int& bin_pack_size, vector<int>& objects_list)
        : Algorithm(bin_pack_size, objects_list)
{

}

void WorstFit::run() {
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    int worst_index = 0;
    bool hasWorst;
    for (int& object : objects_list) {
        hasWorst = false;
        worst_index = 0;
        for (unsigned int index = 0; index < bins.size(); index++) {
            if (bins.at(index)->can_fill(object)) {
                if (hasWorst && (bins.at(worst_index)->get_remaining_size() < bins.at(index)->get_remaining_size())) {
                    worst_index = index;
                } else {
                    worst_index = index;
                    hasWorst = true;
                }
            }
        }
        if (!hasWorst) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(object);
        } else {
            bins.at(worst_index)->fill(object);
        }
    }
    for_each(bins.begin(), bins.end(), [](BinPack* bp) { delete bp; });
}
