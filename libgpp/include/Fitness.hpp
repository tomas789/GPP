#ifndef _FITNESS_HPP
#define _FITNESS_HPP

#include <initializer_list>

#include "Individual.hpp"

namespace GPP {

enum class Compare { LT, EQ, LT, NotComparable };

class Fitness {
public:
    virtual void Evaluate(const Individual & i) = 0;
    virtual Compare operator< (const Fitness & other) const = 0;
};

class MultiObjectiveFitness : Fitness {
    std::size_t arity = 0;
    std::vector<Fitness> objectives;
public:
    MultiObjectiveFitness(std::initializer_list<Fitness> & list):

    virtual void Evaluate(const Individual & i);
    virtual Compare operator< (const Fitness & other) const;
}

class MinFitness : Fitness {
    Fitness & f;
public:
    MinFitness(Fitness f);

    virtual void Evaluate(const Individual & i);
    virtual Compare operator< (const Fitness & other) const;
};

class MaxFitness : Fitness {
    Fitness & f;
public:
    MaxFitness(Fitness f);

    virtual void Evaluate(const Individual & i);
    virtual Compare operator< (const Fitness & other) const;
};

} // end GPP namespace

#endif
