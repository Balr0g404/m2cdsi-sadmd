#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "headers/data.hpp"
#include "headers/parse.hpp"

using namespace std;

int main()
{
    // Data test(5,2,3);

    // int *p = test.get_profits();
    // p[0] = 12;
    // p[1] = 8;

    // int **d = test.get_poids_d();

    // d[0][0] = 1;
    // d[0][1] = 13654;

    // for (int i=0; i < test.get_n(); i++)
    // {
    //     cout << p[i] << endl;
    // }

    // for (int i=0; i<test.get_q(); i++)
    // {
    //     for (int j=0; j<test.get_n(); j++)
    //     {
    //         cout << "{" << d[i][j] << "}";
    //     }
    // cout << endl;
    // }

    string path = "data/n=100,m=5-20200416/100Md5_1_1_mixte.txt";
    vector<vector<int>> data = parseData(path);

    cout << data.size() << endl;

        

    return 0;
}