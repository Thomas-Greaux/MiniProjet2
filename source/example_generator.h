#ifndef _EXAMPLE_GENERATOR_H
#define _EXAMPLE_GENERATOR_H

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
};
#endif
