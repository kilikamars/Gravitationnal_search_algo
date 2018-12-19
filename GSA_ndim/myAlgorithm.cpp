#include "myAlgorithm.h"

Problem::Problem():_dimension{},LowerLimit{},UpperLimit{}
{}


Problem::Problem(int dim,double LoLim,double UpLim):_dimension{dim},LowerLimit{LoLim},UpperLimit{UpLim}
{}

Problem::~Problem()
{}


int Problem::dimension() const
{
    return _dimension;
}

double Problem::func(const vector<double>& ind,int dim) const
{
    double so=0;
    for(int i=0;i<_dimension;i++)
    {
        so+=ind[i];
    }
    return so;
}

//=============================================

Solution::Solution(const Problem& pbm):_solution{},_pbm{},_current_fitness{}
{}

Solution::Solution(const Solution& sol):_solution{sol._solution},_pbm{},_current_fitness{}
{}

double Solution::get_fitness() const
{
    return _current_fitness;
}

double Solution::fitness()
{
    double d =_pbm.func(_solution,_pbm.dimension());
    return d;
}
void Solution::initialize()
{
    int dim=_pbm.dimension();
    _solution.resize(dim);
    for(int i=0;i<dim;i++)
    {
        do{
            _solution[i]= pow(-1.0, rand() * 2 / RAND_MAX)*rand() * 100 / RAND_MAX;
        }
        while(_solution[i]<_pbm.UpperLimit && _solution[i]>_pbm.LowerLimit);
    }
    _current_fitness=fitness();
}
//=======================================================

SetUpParams::SetUpParams():_independent_runs{},_nb_evolution_steps{},_population_size{},_solution_size{}
{}

const unsigned int SetUpParams::independent_runs() const
{
    return _independent_runs;
}

const unsigned int   SetUpParams::nb_evolution_steps() const
{
    return _nb_evolution_steps;
}

const unsigned int   SetUpParams::population_size() const
{
    return _population_size;
}

const unsigned int   SetUpParams::solution_size() const
{
    return _solution_size;
}

//===================================================

MyAlgorithm::MyAlgorithm(const Problem& pbm,const SetUpParams& setup):_solutions{},_setup{setup},_fitness_values{},_upper_cost{},_lower_cost{}
{
    _solutions.resize(_setup.population_size());
    for(int i=0;i<_setup.population_size();i++)
    {
        _solutions[i]=new Solution(pbm);
        _solutions[i]->initialize();
    }
}

void MyAlgorithm::initialize()
{
    _fitness_values.resize(_setup.population_size());
    for(int i =0; i<_setup.population_size();i++)
    {
        _fitness_values[i].fitness=_solutions[i]->get_fitness();
        _fitness_values[i].index=i;
    }
}

unsigned int MyAlgorithm::upper_cost() const
{
    return _upper_cost;
}
unsigned int MyAlgorithm::lower_cost() const
{
    return _lower_cost;
}

const SetUpParams& MyAlgorithm::setup() const
{
    return _setup;
}
vector<struct particle>& MyAlgorithm::fitness_values()
{
    return _fitness_values;
}

const vector<Solution*>& MyAlgorithm::solutions() const
{
    return _solutions;
}
