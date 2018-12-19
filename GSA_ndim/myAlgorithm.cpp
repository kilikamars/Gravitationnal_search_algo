#include "myAlgorithm.h"


Solution::Solution(const Problem& pbm):_solution{},_pbm{},_current_fitness{}
{}

Solution::Solution(const Solution& sol):_solution{sol._solution},_pbm{},_current_fitness{}
{}

void Solution::initialize()
{

}
