#ifndef PREDATOR_H
#define PREDATOR_H
#include "organism.h"

class Predator : public Organism
{

public:
    Predator();
    /*
     * Before calling these virtual, target has to be already defined */
    virtual void breed(Organism* &target);
    virtual void evolve();

    virtual void move(Organism* &target);
    virtual bool breedReady() const;
    virtual bool isStarved() const;
    virtual ~Predator();

};

#endif // PREDATOR_H
