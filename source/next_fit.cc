#include "next_fit.h"

NextFit::NextFit(const int& bin_pack_size, vector<int>& objects_list)
		: Algorithm(bin_pack_size, objects_list)
{

}

void NextFit::run()
{
	vector<BinPack*> bins = vector<BinPack*>();
	bins.push_back(new BinPack(bin_pack_size));
	for (int &it : objects_list) {
		if(bins.back()->can_fill(it)){
			bins.back()->fill(it);
		}
		else{
			bins.push_back(new BinPack(bin_pack_size));
			nb_bin_pack_used++;
			bins.back()->fill(it);
		}
	}
	for_each(bins.begin(), bins.end(), [](BinPack* bp){ delete bp; });
}
