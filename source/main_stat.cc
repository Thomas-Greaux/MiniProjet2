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
        case Uniform: d = Uniform; break;
        case Geometric: d = Geometric; break;
        case Poisson: d = Poisson; break;
        case Binomial: d = Binomial; break;
        case NegativeBinomial: d = NegativeBinomial; break;
    }

    ExampleGenerator eg = {bps, nb_obj, d};
    eg.generate_example();

    ofstream ofs("./exemples/generated.txt");

    ofs << eg.get_bpp();

    cout << "Resultat : " << endl << endl;
    cout << eg.get_bpp();
    return 0;
}
