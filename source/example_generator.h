#ifndef _EXAMPLE_GENERATOR_H
#define _EXAMPLE_GENERATOR_H

#include <string>

using std::string;

enum Distribution
{
    Uniform, Geometric, ExtremeValue, Binomial, NegativeBinomial
};

class ExampleGenerator
{
private:
    Distribution distribution;
public:
    ExampleGenerator(Distribution d = Uniform);
    string get_distribution(void) const;
};
#endif
