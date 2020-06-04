#ifndef solution_hpp
#define solution_hpp

#include <iostream>

class Solution
//Classe représentant une solution, sous forme d'un vecteur binaire
{
    private:
    int size;
    bool* variables; //Tableau de boolean représentant les objets pris
    int objective; //Valeur de la fonction objective
    int* profits; //Profits des objets de l'instance


    public:
    Solution(int, int*); //Constructeur
    Solution(int, int*, bool*); //Constructeur
    ~Solution(); //Destructeur

    void set_variables(int, bool);//setter
    void set_variables(bool*);//surchage du setter pour l'initialiser avec un tableau
    bool* get_variables(); //getter - Récupère les variables dans un tableau
    void print_s(); //Affiche proprement la solution
    void print_s(int); //Affiche l'indice donné

    int objective_fonction(); //calcule la qualité de la solution

};

#endif