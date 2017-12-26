#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "first_fit.h"
#include "worst_fit.h"
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

    cout << "Sum of objects: " << parser.get_sum_objects() << endl;

    algo = new FirstFit(bin_pack_size, objects_list);
    algo->run();
    cout << "First Fit bins used: " << algo->get_nb_bin_pack_used() << endl;

    algo = new WorstFit(bin_pack_size, objects_list);
    algo->run();
    cout << "Worst Fit bins used: " << algo->get_nb_bin_pack_used() << '\n' << endl;
}

int main()
{
    execute_example("exemples/exemple100.txt");
    execute_example("exemples/exemple500.txt");
    execute_example("exemples/exemple1000.txt");
    execute_example("exemples/monexemple.txt");

    return 0;
}
