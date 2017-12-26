#include "example_generator.h"

ExampleGenerator::ExampleGenerator(Distribution d): distribution(d)
{

}

string ExampleGenerator::get_distribution(void) const
{
    switch (distribution) {
        case Uniform: return "Uniform";
        case Geometric: return "Geometric";
        case ExtremeValue: return "ExtremeValue";
        case Binomial: return "Binomial";
        case NegativeBinomial: return "NegativeBinomial";
        default: return "";
    }
}
