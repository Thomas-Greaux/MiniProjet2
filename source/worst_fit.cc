#include "worst_fit.h"

WorstFit::WorstFit(const int& bin_pack_size, vector<int>& objects_list)
        : Algorithm(bin_pack_size, objects_list)
{

}

void WorstFit::run()
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    unsigned int worst_index = 0;
    bool hasWorst;
    for (int& object : objects_list) {
        worst_index = 0;
        hasWorst = false;
        for (unsigned int index = 0; index < nb_bin_pack_used; index++) {
            if (bins.at(index)->can_fill(object)) {
                if (!hasWorst) {
                    worst_index = index;
                    hasWorst = true;
                } else if (bins.at(worst_index)->get_remaining_size() < bins.at(index)->get_remaining_size()) {
                    worst_index = index;
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
