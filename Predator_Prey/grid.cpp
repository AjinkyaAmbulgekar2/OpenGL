#include "grid.h"


grid::grid(): creature(NULL)
{
}

grid::grid(Organism *newCreature) : creature(newCreature)
{
}

void grid::RandomBreed()
{
    int breed = rand() % 3;
    if(breed == 0) // 0 for Prey, 1 for Predator
        PreyBreed();
    else if (breed == 1)
        PredatorBreed();
    //if breed == 2, do nothing, the tile will be NULL
}

void grid::PreyBreed()
{
    if(creature)
        qDebug() << "Error : Hey, there is creature here.\n";
    else
        creature = new Prey;
}

void grid::PredatorBreed()
{
    if(creature)
        qDebug() << "Error : Hey, there is creature here.\n";
    else
        creature = new Predator;
}

void grid::kill()
{
    if(creature) {
        delete creature;
        creature = NULL;
    }
}

int grid::Status() const {
    /* If not occupied, return 0, if Prey is there return 1,
     *                            if Predator is there return 2.
     */
    if(!creature)
        return 0;
    if(creature->Genotype == 'O')
        return 1;
    else if(creature->Genotype == 'X')
        return 2;

    qDebug() << "Status() grid.cpp no Status returned";
    return 0;
}
void grid::print()
{
    if(creature)
        creature->print();
    else
        cout << "No creature in this cell";
    cout << endl;
}

grid grid::operator<<(grid &from)
{
    from.creature->move(this->creature); //move pointer memory from "from" to "this"
                                        //this-> creature memory will get deleted
    from.creature = NULL;
}

const Organism& grid::operator ++()
{
    (*creature).advance();
}

const Organism &grid::operator *()
{
    return *creature;
}

grid::~grid()
{
    cout << "Deleting ...";
    print();
    delete creature;
}
