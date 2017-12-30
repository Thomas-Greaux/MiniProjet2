#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "almost_worst_fit.h"
#include "best_fit.h"
#include "first_fit.h"
#include "next_fit.h"
#include "worst_fit.h"
#include "bin_packing_problem.h"

using namespace std;

void execute_example(const string& example_file_path)
{
    int bin_pack_size;
    vector<int> objects_list;
    BinPackingProblem parser;
    ifstream ifs(example_file_path);
    ifs >> parser; // parsing
    bin_pack_size = parser.get_bin_pack_size();
    objects_list = parser.get_objects_list();

    cout << "Sum of objects: " << parser.get_sum_objects() << endl;

    AlmostWorstFit awf = AlmostWorstFit(bin_pack_size, objects_list);
    awf.run();
    cout << "Almost Worst Fit bins used: " << awf.get_nb_bin_pack_used() << endl;

    BestFit bf = BestFit(bin_pack_size, objects_list);
    bf.run();
    cout << "Best Fit bins used: " << bf.get_nb_bin_pack_used() << endl;

    FirstFit ff = FirstFit(bin_pack_size, objects_list);
    ff.run();
    cout << "First Fit bins used: " << ff.get_nb_bin_pack_used() << endl;

    NextFit nf = NextFit(bin_pack_size, objects_list);
    nf.run();
    cout << "Next Fit bins used: " << nf.get_nb_bin_pack_used() << endl;

    WorstFit wf = WorstFit(bin_pack_size, objects_list);
    wf.run();
    cout << "Worst Fit bins used: " << wf.get_nb_bin_pack_used() << '\n' << endl;
}

int main()
{
    execute_example("exemples/exemple100.txt");
    execute_example("exemples/exemple500.txt");
    execute_example("exemples/exemple1000.txt");
    execute_example("exemples/monexemple.txt");

    return 0;
}
