#include "example_generator.h"

#include <random>

using std::default_random_engine;

using std::uniform_int_distribution;
using std::geometric_distribution;
using std::poisson_distribution;
using std::binomial_distribution;
using std::negative_binomial_distribution;

ExampleGenerator::ExampleGenerator(int bps, int nb_obj, Distribution d): bin_pack_size(bps), nb_objects(nb_obj), distribution(d)
{

}

void ExampleGenerator::generate_example()
{
    generated_bpp.set_bin_pack_size(bin_pack_size);

    default_random_engine generator((unsigned int)time(0));
    uniform_int_distribution<int> u_distribution(0, bin_pack_size); //no objects w/o weight, no objects that cannot fit
    geometric_distribution<int> g_distribution(0.3);
    poisson_distribution<int> p_distribution(bin_pack_size/2);
    binomial_distribution<int> b_distribution(bin_pack_size/2, 0.5);
    negative_binomial_distribution<int> nb_distribution(bin_pack_size/2, 0.5);

    int generated_obj;

    for(int i = 0; i<nb_objects; i++)
    {
        switch (distribution)
        {
            case Uniform: generated_obj = u_distribution(generator); break;
            case Geometric: generated_obj = g_distribution(generator); break;
            case Poisson: generated_obj = p_distribution(generator); break;
            case Binomial: generated_obj = b_distribution(generator); break;
            case NegativeBinomial: generated_obj = nb_distribution(generator); break;
            default: generated_obj = 0; break;
        }

        if(generated_obj > bin_pack_size) generated_obj = bin_pack_size;
        if(generated_obj < 0)             generated_obj = 0;
        generated_bpp.add_object(generated_obj);
    }
}

BinPackingProblem ExampleGenerator::get_bpp(void) const
{
    return generated_bpp;
}

string ExampleGenerator::get_distribution() const
{
    switch (distribution) {
        case Uniform: return "Uniform";
        case Geometric: return "Geometric";
        case Poisson: return "Poisson";
        case Binomial: return "Binomial";
        case NegativeBinomial: return "NegativeBinomial";
        default: return "";
    }
}
