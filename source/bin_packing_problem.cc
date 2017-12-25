#include "bin_packing_problem.h"

#include <string>

using std::string;

int BinPackingProblem::get_bin_pack_size(void) const
{
    return bin_pack_size;
}

queue<int> BinPackingProblem::get_objects_list(void) const
{
    return objects_list;
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
        bpp.objects_list.push(stoi(str));
        str.erase(0, position + delimiter.length());
    }

    str.pop_back();
    bpp.objects_list.push(stoi(str));

    return is;
}
