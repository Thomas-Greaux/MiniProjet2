#include <iostream>
#include <fstream>

#include "example_generator.h"

using namespace std;

int main()
{
    int bps;
    int nb_obj;
    int distribution;

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

    Distribution d;
    switch (distribution) {
        case 1: d = Uniform; break;
        case 2: d = Geometric; break;
        case 3: d = Poisson; break;
        case 4: d = Binomial; break;
        case 5: d = NegativeBinomial; break;
    }

    ExampleGenerator eg = {bps, nb_obj, d};
    eg.generate_example();
    BinPackingProblem bpp = eg.get_bpp();

    ofstream ofs("./exemples/generated.txt");

    ofs << bpp;

    cout << "Resultat : " << endl << endl;
    cout << bpp << endl;

    cout << endl << "Statistiques : " <<endl;
    bpp.sort();
    cout << "Minimum = " << bpp.get_min() << endl;
    cout << "Maximum = " << bpp.get_max() << endl;
    cout << "Moyenne = " << bpp.get_moy() << endl;
    cout << "Medianne = " << bpp.get_med() << endl;

    return 0;
}
