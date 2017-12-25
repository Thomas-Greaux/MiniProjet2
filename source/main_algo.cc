#include <iostream>
#include "algorithm.h"
#include "first_fit.h"
#include "parser.h"
#include "bin_packing_problem.h"

using namespace std;

void execute_example(string example_file_path)
{
    Algorithm* algo;
    int bin_pack_size;
    vector<int> objects_list;
    BinPackingProblem parser;
    ifstream ifs(example_file_path);
    ifs >> parser; // parsing
    bin_pack_size = parser.get_bin_pack_size();
    objects_list = parser.get_objects_list();
    algo = new FirstFit(bin_pack_size, objects_list);
    algo->run();
    cout << "First Fit bins used: " << algo->get_nb_bin_pack_used() << endl;
}

int main()
{
    execute_example("exemples/exemple100.txt");
    execute_example("exemples/exemple500.txt");
    execute_example("exemples/exemple1000.txt");

    return 0;
}
