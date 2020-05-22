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

void print2dArr (int* arr[], int taille1, int taille2)
{
    for (int i = 0; i < taille1; i++)
    {
        for (int j = 0; i < taille2; j++)
        {
            cout << "{" << arr[i][j] << "}";
        }
        cout << endl;
    }
    cout << endl;
}