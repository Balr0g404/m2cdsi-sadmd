#include "../headers/data.hpp"

using namespace std;

Data::Data(vector<int> donnees) : n(donnees[0]), m(donnees[1]), q(donnees[2]), profits(0), ressources(0), demandes(0), poids_r(0), poids_d(0)
{
    //INITIALISATION
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

    //On récupère les n profits

    for (int i=0; i < n; i++)
    {
        profits[i] = donnees[i+3];
    }

    //On récupère les m ressources
    for (int i=0; i < m; i++)
    {
        ressources[i] = donnees[i+n+3];
    }

    //On récupère les n demandes
    for (int i=0; i < q; i++)
    {
        demandes[i] = donnees[i+n+m+3];
    }

    //On récupère les m*n poids pour les contraintes de ressources
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < n; j++)
        {
            poids_r[i][j] = donnees[(i*n+j)+n+m+3];
        }
    }

    //On récupère les q*n poids pour les contraintes de demandes
    for (int i=0; i < q; i++)
    {
        for (int j=0; j < n; j++)
        {
            poids_d[i][j] = donnees[(i*n+j)+(n*m)+n+m+3];
        }
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

//Les attributs sont privés, mais comme les getters retournent des pointeurs
//on risque de modifier l'attribut dans le main.
//Pour éviter ça, on copiera le retour du getter dans le main.

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