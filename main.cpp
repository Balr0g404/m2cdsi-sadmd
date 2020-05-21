#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

#include "headers/data.hpp"
#include "headers/parse.hpp"

using namespace std;

int main()
{

    string path = "data/n=100,m=5-20200416/100Md5_1_1_mixte.txt";
    //string path = "data/n=100,m=5-20200416/100Md5_15_5_pos.txt";
    //string path = "data/n=250,m=30-20200416/250Md30_15_30_mixte.txt";
    vector<vector<int>> donnees = readData(path);

    int n = donnees[0][0];
    int m = donnees[0][1];
    int q = donnees[0][2];

    // for (int i=0; i<donnees.size(); i++) 
    // {
    //     for (int j=0; j<donnees[i].size(); j++)
    //     {
    //         cout << "{" << donnees[i][j] << "}";
    //     }
    // cout << endl; 
    // }

   vector<int> test;

   for (int i=0; i<donnees.size(); i++)
   {
       for (int j=0; j<donnees[i].size(); j++)
       {
           test.push_back(donnees[i][j]);
       }
   }

   for (int i = 0; i < test.size(); i++)
   {
       cout << "{" << test[i] << "}"; 
   }
   




    // Data test(donnees);

    // int* profits = test.get_profits();
    // int* ressources = test.get_ressources();
    // int n = test.get_n();
    // int m = test.get_m();

    // for (int i = 0; i < m; i++)
    // {
    //     cout << "{" << ressources[i] << "}"; 
    // }      

    return 0;
}