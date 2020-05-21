#include "../headers/data.hpp"

using namespace std;

Data::Data(vector<vector<int>> donnees) : n(donnees[0][0]), m(donnees[0][1]), q(donnees[0][2]), profits(0), ressources(0), demandes(0), poids_r(0), poids_d(0)
{
    //INITIALISATION
    profits = new int[n]; //Retourne un tableau, car en c++, un tableau n'est rien d'autre qu'un pointeur.
    ressources = new int[m];
    demandes = new int[q];

    cout << "test 1 " << endl;

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

    int starting_line = 1;
    int current_line = 1;

    cout << "test 2 " << endl;

    for (int i = 0; i < (n/10); i++)//Les profits sont rangés par ligne de 10
    //On itère à partir de la deuxième
    {
        for (int j = 0; j < 10; j++)//On récupère les 10 profits de chaques lignes
        {
            //cout << "ligne : " << i << " colone : " << j << " case : " << j+10*(i-1) << endl;
            profits[j+10*i] = donnees[current_line][j];
        }
        current_line++; //On passe à la ligne suivante
    }  

    cout << "test 3 " << endl;

    //On récupère les capacités des m contraintes
    //Pour faciliter et optimiser le code, on utilise également le fait que 
    //m ne peut prendre que les valeurs 5, 10 ou 30

    if (m < 10) //Si les valeurs de m sont sur une seule ligne
    {
        cout << "test 4 " << endl;
        for (int j = 0; j < m; j++)
        {
            ressources[j] = donnees[current_line][j];
        }
        current_line++;
    }
    else //Si les valeurs de m sont sur plusieurs lignes
    {
        cout << "test 5 " << endl;
        cout << (m/10) << endl;
        cout << current_line << endl;

        for (int i=0; i < (m/10); i++)
        {
            for (int j = 0; i < m; j++)
            {
                ressources[j+10*i] = donnees[current_line][j];
            }
            current_line++;
        }
    }
    
    cout << "test 6 " << endl;
    
    //On récupère les demandes des q contraintes
    // for (int i = 0, i < q; i++)
    // {
    //     demandes[i] = donnees[1+(n/10)+1]
    // }
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