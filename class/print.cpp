#include <iostream>
#include <vector>

using namespace std;

void printVect(vector<int> vect) //Affiche un vect
{
    for (int i=0; i < vect.size(); i++)
    {
        cout << "{" << vect[i] << "}";
    }
    cout << endl;
}

void printArr(int arr[], int taille) //Affiche un tableau
{
    for (int i=0; i < taille; i++)
    {
        cout << "{" << arr[i] << "}";
    }
    cout << endl;
}

int* arrCopy (int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr2[i];
    }
    
}