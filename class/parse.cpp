#include "../headers/parse.hpp"

using namespace std;

vector<int> extractIntegerWord(string str)
//permet d'extraire tous les entiers d'une string
{
    stringstream ss;
    vector<int> extract;
    ss << str;

    string temp;
    int found;
    while (!ss.eof())
    {
        ss >> temp;
        
        if (stringstream(temp) >> found)
        {
            extract.push_back(found);

        }
    temp = "";
    }

    return extract;
}

vector<int> readData(string path)
//Extrait chaque int des données d'entrée en un vecteur par ligne
{
    vector<int> extracted;
    vector<int> fichier;
 
    ifstream file(path);
    if (file)
    {
        string line;

        while(getline(file, line))
        {
            extracted = extractIntegerWord(line);
            for (int i=0; i < extracted.size(); i++)
            {
                if (extracted[i] != ' ' && extracted[i] != '\n' )
                {
                    fichier.push_back(extracted[i]);
                }
            }
        }
    }
    else
    {
        cout << "Erreur de lecture du fichier" << endl;
    }

    int i = 0;

    // while(i < fichier.size()) //Retire les lignes vides
    // {
    //     if (fichier[i].size() == 0)
    //     {
    //         fichier.erase(fichier.begin() + i);
    //         i = 0;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
   
    return fichier;
}