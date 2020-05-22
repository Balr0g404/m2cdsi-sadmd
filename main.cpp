#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

#include "headers/data.hpp"
#include "headers/parse.hpp"
#include "headers/print.hpp"

using namespace std;

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

    int* profits = instance.get_profits();
    int* ressources = instance.get_ressources();
    int* demandes = instance.get_demandes();

    int** poids_demandes = instance.get_poids_d();
    int ** poids_ressources = instance.get_poids_r();

    printArr(profits, n);

    return 0;
}