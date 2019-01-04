#include "myAlgorithm.h"

Problem::Problem():_dimension{},_LowerLimit{},_UpperLimit{},_num{},_nom{}
{}


Problem::Problem(int num):_num{num}
{
     switch(_num)
  {
    case 1 :
      _nom = "Ackley";
      _LowerLimit = -32.768;
      _UpperLimit = 32.768;
      _direction = 1;
      break;

    case 2 :
      _nom= "Rastrigin";
      _LowerLimit = -5.12;
      _UpperLimit = 5.12;
      _direction = 1;
      break;

    case 3 :
      _nom = "Rosenbrock";
      _LowerLimit = -5;
      _UpperLimit = 10;
      _direction = 1;
      break;
    case 4 :
      _nom = "Schaffer";
      _LowerLimit = -100;
      _UpperLimit = 100;
      _dimension = 2;
      _direction = 1;
      break;

    case 5 :
      _nom = "Schwefel";
      _LowerLimit = -500;
      _UpperLimit = 500;
      _direction = 1;
      break;

    case 6 :
      _nom = "Weierstrass";
      _LowerLimit = -2;
      _UpperLimit = 2;
      _dimension = 1;
      _direction = 1;
      break;
  }
}

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
double Problem::UpperLimit()const
{
    return _UpperLimit;
}
double Problem::LowerLimit()const
{
    return _LowerLimit;
}
int Problem::numero()const
{
    return _num;
}
string Problem::nom()const
{
    return _nom;
}
int Problem::direction()const
{
    return _direction;
}
void Problem::LowerLimits(double LowLim)
{
     _LowerLimit=LowLim;
}
void Problem::UpperLimits(double UpLim)
{
      _UpperLimit=UpLim;
}

void Problem::directions(int direct)
{
    _direction=direct;
}

void Problem::dimensions(int dim)
{
    _dimension=dim;
}
void Problem::numeros(int num)
{
    _num=num;
}
void Problem::noms(string Nom)
{
    _nom=Nom;
}

ostream& operator<<(ostream& os, const Problem& pbm)
{
    os << "Nom du probleme :" << endl;
    if(pbm.direction() == 1)
        os << "Direction :Minimisation" << endl;
    else
        os << "Direction :Maximisation" << endl;
    os << "Limite minimale :" << pbm.LowerLimit() << endl;
    os << "Limite maximale :" << pbm.UpperLimit() << endl;
    os << "Dimension :" << pbm.dimension();

    return os;
}

istream& operator>>(istream& is, Problem& pbm)
{
    cout << "Entrez les valeurs sous la forme (Numero probleme;Direction;Limite minimale;Limite maximale;Dimension)" << endl;

    char c;
    int tmp_1;
    double tmp_2;
    is >> c;

    is >> tmp_1;
        pbm.numeros(tmp_1);
    is >> c;

    is >> tmp_1;
        pbm.directions(tmp_1);
    is >> c;

    is >> tmp_2;
        pbm.LowerLimits(tmp_2);
    is >> c;

    is >> tmp_2;
        pbm.UpperLimits(tmp_2);
    is >> c;

    is >> tmp_1;
        pbm.dimensions(tmp_1);
    is >> c;

    return is;
}


Problem& Problem::operator=(const Problem& pbm)
{
    noms(pbm.nom());
    numeros(pbm.numero());
    directions(pbm.direction());
    LowerLimits(pbm.LowerLimit());
    UpperLimits(pbm.UpperLimit());
    dimensions(pbm.dimension());

    return *this;
}

bool Problem::operator==(const Problem& pbm) const
{
    return (numero() == pbm.numero() && direction() == pbm.direction() && LowerLimit() == pbm.LowerLimit() && UpperLimit() == pbm.UpperLimit() && dimension() == pbm.dimension());
}

bool Problem::operator!= (const Problem& pbm) const
{
    return !(*this==pbm);
}

//=============================================

Solution::Solution(const Problem& pbm):_solution{},_pbm{},_current_fitness{}
{}

Solution::Solution(const Solution& sol):_solution{sol._solution},_pbm{},_current_fitness{}
{}

Solution::~Solution()
{

}

ostream& operator<< (ostream& os, const Solution& sol)
{

}

istream& operator>> (istream& is, Solution& sol)
{

}

const Problem& Solution::pbm() const
{

}

Solution& Solution:: operator=  (const Solution& sol)
{

}

bool Solution::operator== (const Solution& sol) const
{

}

bool Solution::operator!= (const Solution& sol) const
{

}

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
    for(int i=0;i<dim;i++)
    {
            _solution[i]= ((double) rand()/RAND_MAX)*(_pbm.UpperLimit()- _pbm.LowerLimit())+_pbm.LowerLimit();
    }
}

unsigned int Solution::size() const
{

}

vector<double>& Solution::solution()
{

}

double& Solution::position(const int index)
{

}

void  Solution::position(const int index, const double value)
{

}
//=======================================================

SetUpParams::SetUpParams():_independent_runs{},_nb_evolution_steps{},_population_size{},_solution_size{}
{}

SetUpParams::SetUpParams(int runs,int evolution,int population,int solution):_independent_runs{runs},_nb_evolution_steps{evolution},_population_size{population},_solution_size{solution}
{}

ostream& operator<< (ostream& os, const SetUpParams& setup)
{
    os << "Nombre d'execution : " << setup._independent_runs << endl;
    os<< "Nombre d'iteration par execution : " << setup._nb_evolution_steps << endl;
    os<< "Taille de la population : " << setup._population_size << endl;
    os<< "Taille de la solution : " << setup._solution_size << endl;

    return os;
}
istream& operator>> (istream& is, SetUpParams& setup)
{
    is >>  setup._independent_runs ;
    is>> setup._nb_evolution_steps ;
    is>> setup._population_size;
    is>> setup._solution_size ;
    return is;
}

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

void SetUpParams::independent_runs(const unsigned int val)
{
    _independent_runs=val;
}

void SetUpParams::nb_evolution_steps(const unsigned int val)
{
    _nb_evolution_steps=val;
}

void SetUpParams::population_size(const unsigned int val)
{
    _population_size=val;
}

void SetUpParams::solution_size(const unsigned int val)
{
    _solution_size=val;
}

SetUpParams::~SetUpParams()
{}

//===================================================
/*
MyAlgorithm::MyAlgorithm(const Problem& pbm,const SetUpParams& setup):_solutions{nullptr},_fitness_values{},_setup{setup},_upper_cost{pbm.UpperLimit()},_lower_cost{pbm.LowerLimit()}
{

}*/

MyAlgorithm::MyAlgorithm(Problem& pbm, SetUpParams& setup):
    _solutions{}, _upper_cost{NULL}, _lower_cost{NULL},
    _best_Solution_overall{NULL}, _pbm{pbm}, _setup{setup}, _g{0}
{
    for(unsigned int i = 0; i < _setup.population_size(); i++)
        _solutions.push_back(new Solution{_pbm});

    _best_Solution_overall = new Solution{_pbm};
}
MyAlgorithm::~MyAlgorithm()
{}

ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo)
{
	os <<"Algorithme : "<< myAlgo<<endl;
	return os;
}

istream& operator>> (istream& is, MyAlgorithm& myAlgo)
{
	cout <<"Algorithme : ";
	is >> myAlgo;
	return is;
}

MyAlgorithm& MyAlgorithm::operator= (const MyAlgorithm& myAlgo)
{
	for (int i = 0; i < _fitness_values.size(); i++)
	{
		_fitness_values[i] = myAlgo._fitness_values[i];
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
