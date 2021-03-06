#include "bin_packing_problem.h"

#include <algorithm>

void BinPackingProblem::reset()
{
    objects_list.clear();
}

int BinPackingProblem::get_bin_pack_size() const
{
    return bin_pack_size;
}

vector<int> BinPackingProblem::get_objects_list() const
{
    return objects_list;
}

void BinPackingProblem::set_bin_pack_size(int new_bps)
{
    bin_pack_size = new_bps;
}

void BinPackingProblem::add_object(int object)
{
    objects_list.push_back(object);
}

int BinPackingProblem::get_sum_objects() const
{
    int res = 0;
    for(vector<int>::const_iterator it = objects_list.begin(); it != objects_list.end(); it++)
    {
        res += *it;
    }
    return res;
}

void BinPackingProblem::sort()
{
    sorted_objects_list = objects_list;
    std::sort(sorted_objects_list.begin(), sorted_objects_list.end());
}

int BinPackingProblem::get_min() const
{
    return sorted_objects_list.at(0);
}

int BinPackingProblem::get_max() const
{
    return sorted_objects_list.at(sorted_objects_list.size()-1);
}

double BinPackingProblem::get_moy() const
{
    int moy = 0;
    for(vector<int>::const_iterator it = objects_list.begin(); it != objects_list.end(); it++)
    {
        moy += *it;
    }
    moy /= objects_list.size();
    return moy;
}

int BinPackingProblem::get_med() const
{
    return sorted_objects_list.at(sorted_objects_list.size()/2);
}

istream& operator>> (istream& is, BinPackingProblem& bpp)
{
    string str;
    getline(is, str); // "Taille bin"
    is >> bpp.bin_pack_size; // the bins size
    getline(is, str); // the rest of the line
    getline(is, str); // "Objets"
    getline(is, str); // The list of objects

    string delimiter = ", ";
    string object;
    size_t position = 0;

    while((position = str.find(delimiter)) != string::npos)
    {
        object = str.substr(0, position);
        bpp.objects_list.push_back(stoi(str));
        str.erase(0, position + delimiter.length());
    }

    str.pop_back();
    bpp.objects_list.push_back(stoi(str));

    return is;
}

ostream& operator<< (ostream& os, const BinPackingProblem& bpp)
{
    os << "Taille bin" << endl;
    os << bpp.bin_pack_size << endl;
    os << "Objets" << endl;
    bool first = true;
    for(vector<int>::const_iterator it = bpp.objects_list.begin(); it != bpp.objects_list.end(); it++)
    {
        if(first) {os << *it; first = false;}
        else os << ", " << *it;
    }
    os << ".";

    return os;
}
