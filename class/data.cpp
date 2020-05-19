#include "../headers/data.hpp"

using namespace std;

Data::Data(int parsed_n, int parsed_m, int parsed_q) : n(parsed_n), m(parsed_m), q(parsed_q), profits(0), ressources(0), demandes(0)
{
    profits = new int[n]; //Retourne un pointeur vers un tableau
    ressources = new int[m];
    demandes = new int[q];

    // poids_r = new int[m][n];
    // poids_d = new int[m][n];

}

Data::~Data()
{
    delete profits;
    delete ressources;
    delete demandes;

    // delete poids_r;
    // delete poids_d;
}

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

int main()
{
    Data test(5,2,3);
    
    int *p = test.get_profits();

    cout << *p << endl;
        

    return 0;
}