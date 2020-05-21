#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

#include "headers/data.hpp"
#include "headers/parse.hpp"

using namespace std;

void printVect(vector<int> vect)
{
    for (int i=0; i < vect.size(); i++)
    {
        cout << "{" << vect[i] << "}";
    }
    cout << endl;
}

void printArr(int arr[], int taille)
{
    for (int i=0; i < taille; i++)
    {
        cout << "{" << arr[i] << "}";
    }
    cout << endl;
}

int main()
{

    string path = "data/n=100,m=5-20200416/100Md5_1_1_mixte.txt";
    //string path = "data/n=100,m=5-20200416/100Md5_15_5_pos.txt";
    //string path = "data/n=250,m=30-20200416/250Md30_15_30_mixte.txt";
    vector<int> donnees = readData(path);

    Data instance(donnees);
    const int n = instance.get_n();
    const int m = instance.get_m();
    const int q = instance.get_q();

    int profits[n];
    int ressources[m];
    int demandes[q];

    //Il est possible de récupérer les tableaux comme ça :
    //int* arr = instance.get_profits();
    //Cependant, cela implique que chaque modification du tableau
    //dans ce code modifiera l'attribut.
    //On préfère donc le copier

    copy(instance.get_profits(), instance.get_profits()+n, profits);
    copy(instance.get_ressources(), instance.get_ressources()+m, ressources);
    copy(instance.get_demandes(), instance.get_demandes()+q, ressources);

    // printArr(profits, n);
    // cout << endl;
    // printArr(ressources, m);
    // cout << endl;
    // printArr(demandes, q);
    


    //printVect(donnees);   

    return 0;
}