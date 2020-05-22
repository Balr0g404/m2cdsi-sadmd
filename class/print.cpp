#include <iostream>
#include <vector>

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