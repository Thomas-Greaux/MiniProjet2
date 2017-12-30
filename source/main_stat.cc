#include <iostream>
#include <fstream>

#include "example_generator.h"

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

    cout << "Entree le nombre de problemes" << endl;
    cin >> nb_bpp;

    BinPackingProblem bpp;
    vector<BinPackingProblem> bpps;

    for(int i = 0; i < nb_bpp; i++)
    {
        eg.generate_example();
        bpp = eg.get_bpp();
        bpps.push_back(bpp);
        cout << bpp << endl;
    }

    return 0;
}
