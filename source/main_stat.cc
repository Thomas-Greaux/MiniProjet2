#include <iostream>

#include "example_generator.h"

using namespace std;

int main()
{
    ExampleGenerator eg;
    cout << "distribution: " << eg.get_distribution() << endl;
    ExampleGenerator eg2 = {Binomial};
    cout << "distribution: " << eg2.get_distribution() << endl;
    return 0;
}
