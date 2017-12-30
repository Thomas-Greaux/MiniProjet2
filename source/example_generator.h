#ifndef _EXAMPLE_GENERATOR_H
#define _EXAMPLE_GENERATOR_H

#include <string>
#include "bin_packing_problem.h"

using std::string;

enum Distribution
{
    Uniform, Geometric, Poisson, Binomial, NegativeBinomial
};

class ExampleGenerator
{
private:
    int bin_pack_size;
    int nb_objects;
    Distribution distribution;
    BinPackingProblem generated_bpp;

public:
    ExampleGenerator(int bps = 100, int nb_obj = 10, Distribution d = Uniform);
    void generate_example();
    BinPackingProblem get_bpp() const;
    string get_distribution() const;

};
#endif
