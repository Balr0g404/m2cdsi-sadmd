class Solution; //Pour le chargement de la classe
#include "../headers/solution.hpp"

using namespace std;

Solution::Solution(int taille, int* narr) : size(taille), objective(0) //Constructeur par défaut
{
    variables = new bool[size]; //tableau de boolean de taille size
    profits = new int[size]; //tableau des profits

     for (int i = 0; i < size; i++)
    {
        profits[i] = narr[i];
    }

    for (int i = 0; i < size; i++)
    {
        variables[i] = false;
    }


}

Solution::Solution(int taille, int* narr, bool* barr) : size(taille), objective(0) //Constructeur avec copie de tableau
{
    variables = new bool[size]; //tableau de boolean de taille size
    profits = new int[size]; //tableau des profits
    
    for (int i = 0; i < size; i++)
    {
        profits[i] = narr[i];
    }

      for (int i = 0; i < size; i++)
    {
        variables[i] = barr[i];
    }


}

Solution::~Solution()
{
    delete[] variables;
    delete[] profits;
}

void Solution::set_variables(int index, bool value)
{
    variables[index] = value;
}

void Solution::set_variables(bool* values)
{
    for (int i = 0; i < size; i++)
    {
        variables[i] = values[i];
    }
}

bool* Solution::get_variables()
{
    return variables;
}
void Solution::print_s()
{
    cout << "{";
    for (int i = 0; i < size-1; i++)
    {
        cout << variables[i] << ", ";
    }
    cout << variables[size - 1] << "}";
}

void Solution::print_s(int index)
{
    cout << variables[index] << endl;
}

int Solution::objective_fonction()
{
    objective = 0;

    for (int i = 0; i < size; i++)
    {
        objective += variables[i]*profits[i];
    }
    return objective;
}