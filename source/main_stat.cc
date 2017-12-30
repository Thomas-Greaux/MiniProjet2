#include <iostream>
#include <fstream>

#include "example_generator.h"
#include "algorithm.h"
#include "almost_worst_fit.h"
#include "best_fit.h"
#include "first_fit.h"
#include "next_fit.h"
#include "worst_fit.h"

using namespace std;

int main()
{
    // Info for generating a bpp
    int bps;
    int nb_obj;
    int distribution;
    Distribution d;

    // Info for how many bpp we must generate
    int nb_bpp;

    cout << "Entree la taille des sacs" << endl;
    cin >> bps;

    cout << endl << "Entree le nombre d'objets" << endl;
    cin >> nb_obj;

    do {
        cout << endl << "Entree la distribution des objets" << endl;
        cout << " 1 - Uniforme" << endl;
        cout << " 2 - Geometrique" << endl;
        cout << " 3 - Poisson" << endl;
        cout << " 4 - Binomiale" << endl;
        cout << " 5 - Binomiale negative" << endl;
        cin >> distribution;
    } while( distribution > 5 || distribution < 0);


    switch (distribution) {
        case 1: d = Uniform; break;
        case 2: d = Geometric; break;
        case 3: d = Poisson; break;
        case 4: d = Binomial; break;
        case 5: d = NegativeBinomial; break;
    }

    ExampleGenerator eg = {bps, nb_obj, d};

    cout << endl << "Entree le nombre de problemes" << endl;
    cin >> nb_bpp;

    BinPackingProblem bpp;
    vector<BinPackingProblem> bpps;

    for(int i = 0; i < nb_bpp; i++)
    {
        eg.generate_example();
        bpp = eg.get_bpp();
        bpps.push_back(bpp);
        cout << endl << bpp << endl;
    }

    cout << endl << endl;

    Algorithm* algo;
    int bin_pack_size;
    vector<int> objects_list;
    for(vector<BinPackingProblem>::iterator it = bpps.begin(); it != bpps.end(); it++)
    {
        bin_pack_size = it->get_bin_pack_size();
        objects_list = it->get_objects_list();

        algo = new AlmostWorstFit(bin_pack_size, objects_list);
        algo->run();
        cout << "Almost Worst Fit bins used: " << algo->get_nb_bin_pack_used() << endl;
        delete algo;

        algo = new BestFit(bin_pack_size, objects_list);
        algo->run();
        cout << "Best Fit bins used: " << algo->get_nb_bin_pack_used() << endl;
        delete algo;

        algo = new FirstFit(bin_pack_size, objects_list);
        algo->run();
        cout << "First Fit bins used: " << algo->get_nb_bin_pack_used() << endl;
        delete algo;

        algo = new NextFit(bin_pack_size, objects_list);
        algo->run();
        cout << "Next Fit bins used: " << algo->get_nb_bin_pack_used() << endl;
        delete algo;

        algo = new WorstFit(bin_pack_size, objects_list);
        algo->run();
        cout << "Worst Fit bins used: " << algo->get_nb_bin_pack_used() << '\n' << endl;
        delete algo;
    }

    return 0;
}
