#ifndef INC_METAHEURISTIC
#define INC_METAHEURISTIC
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
  struct particle // index of a particle in the swarm and its fitness
  {
        int index;
        double fitness;
  };

  struct Direction
  {
      bool dir;
  };

//=======================================================================
  class Problem //stockage de la fonction objective
  {
	public:
		Problem();
		Problem(int num);
		~Problem();

		friend ostream& operator<< (ostream& os, const Problem& pbm);
		friend istream& operator>> (istream& is, Problem& pbm);
		double func (const vector<double>& ind,int dim) const;

		Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;

		string nom() const;//nom fonction objective
		int numero()const;//numero fonction objective
		int direction () const; //Maximize=0 or Minimize=1
		int dimension() const;
		double LowerLimit() const;  //restriction minimale
		double UpperLimit()const ;   // restriction maximale
		void LowerLimits(double LowLim);
		void UpperLimits(double UpLim);
		void directions(int direct);
		void dimensions(int dim);
		void noms(string Nom);
		void numeros(int num);

	private:

		int _dimension,_num;
		string _nom;
		double _LowerLimit,_UpperLimit;
		int _direction;
  };
//=======================================================================
class Solution
  {
	//contient la déclaration d'une solution
	public:
		Solution (const Problem& pbm);
		Solution (const Solution& sol);
		~Solution();

 		friend ostream& operator<< (ostream& os, const Solution& sol);
		friend istream& operator>> (istream& is, Solution& sol);

		const Problem& pbm() const;

		Solution& operator=  (const Solution& sol);
		bool operator== (const Solution& sol) const;
		bool operator!= (const Solution& sol) const;

		void initialize();
		double fitness();
		double get_fitness() const;

		unsigned int size() const;

		vector<double>& solution();

		double& position(const int index); //retournera une position du tableau _solution
        void  position(const int index, const double value);


	private:
        	vector<double> _solution; //individu
        	double _current_fitness;
            const Problem& _pbm;
  };

  //=======================================================================

   class SetUpParams
  {
  	//ici vous devez mettre quelques paramètres tels que :

	private:
		unsigned int   _independent_runs;       //number of independent runs
		unsigned int   _nb_evolution_steps;     // number of iterations per run
		unsigned int   _population_size;	// number of solutions in the population
		unsigned int   _solution_size;	        // size of each particle

	public:
		SetUpParams ();
		SetUpParams(int runs=30,int evolution=0,int population=40,int solution=20);

 		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		friend istream& operator>> (istream& is, SetUpParams& setup);

		const unsigned int   independent_runs() const;
		const unsigned int   nb_evolution_steps() const;
		const unsigned int   population_size() const;
		const unsigned int   solution_size() const;
		void independent_runs(const unsigned int val);
		void nb_evolution_steps(const unsigned int val);
		void population_size(const unsigned int val);
		void solution_size(const unsigned int val);

		~SetUpParams();
  };
  //=======================================================================


  class MyAlgorithm
  {
	private:
		//vector<Solution*> _solutions;     // individuals in population
		vector<struct particle> _fitness_values;
       /* const SetUpParams& _setup;
        int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population
        const Problem& _pbm;*/
        	std::vector<Solution*> _solutions;     // individuals in population
    int _upper_cost, _lower_cost; // lower and upper fitness of individuals in population
	Solution *_best_Solution_overall;

	Problem &_pbm;
	SetUpParams &_setup;

	double _g;


	public:
		MyAlgorithm( Problem& pbm, SetUpParams& setup);
		~MyAlgorithm();

		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
		const SetUpParams& setup() const;
	  	void initialize();
		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();

	 	const vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		Solution& solution(const unsigned int index) const;
        vector<struct particle>&  fitness_values();
		double fitness(const unsigned int index) const;

		double best_cost() const;
		double worst_cost() const;
		Solution& best_solution() const; //meilleure solution
		Solution& worst_solution() const;// pire solution
		void evolution(int iter); /*makes an evolution step*/


  };

#endif
