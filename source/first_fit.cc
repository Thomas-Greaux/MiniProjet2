#include "first_fit.h"

FirstFit::FirstFit(const int& bin_pack_size, queue<int>& objects_list)
    : Algorithm(bin_pack_size, objects_list)
{

}

void FirstFit::run(void)
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    int next;
    bool hasPopped = false;
    while (!objects_list.empty()) {
        next = objects_list.front();
        for(BinPack* bin_pack : bins) {
            if (bin_pack->can_fill(next)) {
                bin_pack->fill(next);
                objects_list.pop();
                hasPopped = true;
                break;
            }
        }
        if (!hasPopped) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(next);
            objects_list.pop();
        } else {
            hasPopped = false;
        }
    }
    for_each(bins.begin(), bins.end(), [](BinPack* bp){ delete bp; });
}