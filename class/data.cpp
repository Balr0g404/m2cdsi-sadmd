#include "../headers/data.hpp"

using namespace std;

Data::Data(vector<int> donnees) : n(donnees[0]), m(donnees[1]), q(donnees[2]), profits(0), ressources(0), demandes(0), poids_r(0), poids_d(0)
{
    //INITIALISATION
    profits = new int[n]; //Retourne un tableau, car en c++, un tableau n'est rien d'autre qu'un pointeur.
    ressources = new int[m];
    demandes = new int[q];

    int offset = 3; //offset de lecture du fichier, initialisé à 3 car on a déjà lu trois valeurs

    poids_r = new int*[m]; 
    poids_d = new int*[q]; 

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
        profits[i] = donnees[i+offset];
    }

    offset += n;

    //On récupère les m ressources
    for (int i=0; i < m; i++)
    {
        ressources[i] = donnees[i+offset];
    }

    offset += m;

    //On récupère les n demandes
    for (int i=0; i < q; i++)
    {
        demandes[i] = donnees[i+offset];
    }

    offset += q;

    //On récupère les m*n poids pour les contraintes de ressources
    for (int i=0; i < m; i++)
    {
        for (int j=0; j < n; j++)
        {
            poids_r[i][j] = donnees[(i*n+j)+offset];
        }
    }

    offset += n*m;

    //On récupère les q*n poids pour les contraintes de demandes
    for (int i=0; i < q; i++)
    {
        for (int j=0; j < n; j++)
        {
            poids_d[i][j] = donnees[(i*n+j)+offset];
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

int* Data::get_profits() const
{   
    return profits;
}

int* Data::get_ressources() const
{
    return ressources;
}

int* Data::get_demandes() const
{
    return demandes;
}

int** Data::get_poids_r() const
{
    return poids_r;
}

int** Data::get_poids_d() const
{
    return poids_d;
}