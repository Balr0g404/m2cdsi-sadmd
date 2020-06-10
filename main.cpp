#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <iterator>

#include "headers/data.hpp"
#include "headers/parse.hpp"
#include "headers/print.hpp"
#include "headers/solution.hpp"

using namespace std;

Solution constructiveSolution(Data instance)
/* 
Construit une solution faisable de manière constructive.
On séléctionne les objets de manière aléatoire, 
On essaie d'ajouter chaque objet. Si l'objet dépasse une des contrainte
De ressources, on le passe.
Une fois cela fait pour tous les objets, on vérifie si la solution respecte les contraintes de demande.
Si ce n'est pas le cas, on repart de 0,
Sinon, on renvoie la solution.
*/
{
    //Initialisation
    const int n = instance.get_n();
    const int m = instance.get_m();
    const int q = instance.get_q();
    int* bound = instance.get_ressources();
    int* min = instance.get_demandes();
    int** poids_ressources = instance.get_poids_r();
    int** poids_demandes = instance.get_poids_d();
    bool init[n] = {0};
    Solution s(n, instance.get_profits());
    
    bool added = true;
    bool feasible = false;
    int i = 0;
    int count = 0;
    vector<int> rng;
    //Fin initialisation

    //Main loop
    while (feasible == false)
    {
        count++;
        cout << "Nombre d'itération : " << count << endl; //For testing purpose
        
        s.set_variables(init); //On met la solution à 0
        int ressources[m] = {0}; //On initialise les tableaux des contraintes
        int demandes[q] = {0};

        //Randomisation des objets
        for (int i = 0; i < n; i++)
        {
            rng.push_back(i);
        }
        random_device rd;
        mt19937 g(rd());
        shuffle(rng.begin(), rng.end(), g);
        //Fin randomisation

        for (int k = 0; k < n; k++)//On itère sur les objets
        {
            i = rng[k]; //Mais dans le désordre
            added = true;//boolean controllant le fait qu'un objet est ajouté ou non.

            for (int j = 0; j < m; j++)//On itère sur les contraintes de ressources
            {
                
                if (ressources[j] + poids_ressources[j][i] > bound[j]) //Si on dépasse une des contraintes de ressources
                {
                    s.set_variables(i, false); //On ne prend pas l'objet
                    added = false;
                    break; //On termine la boucle
                }

                else //Sinon
                {
                    s.set_variables(i, true); //On prend l'objet
                    ressources[j] += poids_ressources[j][i];
                }
                
            }

            if (added == false) //Si l'objet n'a pas été pris, on passe au suivant
            {
                continue;
            }

            else //Sinon on vérifie la contrainte de demande
            {
                for (int j = 0; j < q; j++)
                {
                    demandes[j] += poids_demandes[j][i];
                }    
            }
            
            
        }

        for (int k = 0; k < q; k++)
        {
            if (demandes[k] < min[k]) //Si la contrainte de demande n'est pas respectée
            {
                feasible = false; //La solution n'est pas faisable
                break; //On la jette et on recommence depuis le début
            }
            else
            {
                feasible = true; //Sinon on la garde.
            }
                        
        }

    }
    //Fin main loop

    //s.print_s(); //On affiche la solution
    cout << s.objective_fonction(); //On affiche la valeur objective de la solution
    
    return s;
    
}

int main()
{

    //string path = "data/n=100,m=5-20200416/100Md5_1_1_mixte.txt";
    string path = "data/n=100,m=5-20200416/100Md5_15_5_pos.txt";
    //string path = "data/n=250,m=30-20200416/250Md30_15_30_mixte.txt"; // Trop gros pour l'algoritme.

    vector<int> donnees = readData(path);
    Data instance(donnees);

    Solution s = constructiveSolution(donnees);

    return 0;
}