#include "../headers/data.hpp"

using namespace std;

Data::Data(int parsed_n, int parsed_m, int parsed_q) : n(parsed_n), m(parsed_m), q(parsed_q), profits(0), ressources(0), demandes(0), poids_r(0), poids_d(0)
{
    profits = new int[n]; //Retourne un tableau, car en c++, un tableau n'est rien d'autre qu'un pointeur.
    ressources = new int[m];
    demandes = new int[q];

    poids_r = new int*[m]; //Déclare un pointeur vers un pointeur d'entier, pour un tableau à deux dimensions
    poids_d = new int*[q]; //Soit un pointeur vers un tableau.

    for (int i=0; i < m; i++) //création des tableaux à deux dimensions
    {
        poids_r[i] = new int[n]; //Pour chaque case du tableau, on crée un nouveau tableau afin d'obtenir la deuxième dimension
    }

    for (int i=0; i < q; i++)
    {
        poids_d[i] = new int[n];
    }

}

Data::~Data()
//Il faut bien penser à deleter chaque allocation faite avec new
//pour éviter les fuites de mémoire.
{
    delete profits;
    delete ressources;
    delete demandes;

    for (int i=0; i<m; i++)
    {
        delete[] poids_r[i]; //delete[] permet de désalouer un tableau
    }

    for (int i=0; i<q; i++)
    {
        delete[] poids_d[i];
    }

    delete[] poids_d;
    delete[] poids_r;
}

//GETTERS
int Data::get_n()
{
    return n;
}

int Data::get_m()
{
    return m;
}

int Data::get_q()
{
    return q;
}

int* Data::get_profits()
{   
    return profits;
}

int* Data::get_ressources()
{
    return ressources;
}

int* Data::get_demandes()
{
    return demandes;
}

int** Data::get_poids_r()
{
    return poids_r;
}

int** Data::get_poids_d()
{
    return poids_d;
}