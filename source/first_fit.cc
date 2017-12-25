#include "first_fit.h"

FirstFit::FirstFit(const int& bin_pack_size, vector<int>& objects_list)
    : Algorithm(bin_pack_size, objects_list)
{

}

void FirstFit::run(void)
{
    vector<BinPack*> bins = vector<BinPack*>();
    bins.push_back(new BinPack(bin_pack_size));
    for (vector<int>::iterator it = objects_list.begin(); it != objects_list.end(); it++)
    {
        bool hasPopped = false;
        for(BinPack* bin_pack : bins) {
            if (bin_pack->can_fill(*it)) {
                bin_pack->fill(*it);
                hasPopped = true;
                break;
            }
        }
        if (!hasPopped) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(*it);
        }
    }
    /*
    for (vector<int>::iterator it = objects_list.begin(); it != objects_list.end(); it++)
    {
        bool hasPopped = false;
        for(BinPack* bin_pack : bins) {
            if (bin_pack->can_fill(*it)) {
                bin_pack->fill(*it);
                objects_list.erase(it);
                hasPopped = true;
                break;
            }
        }
        if (!hasPopped) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(*it);
            objects_list.erase(it);
        }
    }
    */
    /*
    while (!objects_list.empty()) {
        next = objects_list.front();
        for(BinPack* bin_pack : bins) {
            if (bin_pack->can_fill(next)) {
                bin_pack->fill(next);
                objects_list.pop_back();
                hasPopped = true;
                break;
            }
        }
        if (!hasPopped) {
            bins.push_back(new BinPack(bin_pack_size));
            nb_bin_pack_used++;
            bins.back()->fill(next);
            objects_list.pop_back();
        } else {
            hasPopped = false;
        }
    }
    */
    for_each(bins.begin(), bins.end(), [](BinPack* bp){ delete bp; });
}
