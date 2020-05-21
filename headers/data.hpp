#ifndef data_hpp
#define data_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cmath>



class Data 
//Classe représentant les jeux de données
//L'ensemble des données caractéristant l'instance 
//sera résumée dans un objet.
//Il aura les différents poids dans des tableaux qui nous
//permettrons de travailler plus simplement.
{
    public:

    Data(std::vector<int> donnees); //constructeur, les données passées en argument le seront par une fonction de parsing 
    ~Data(); //Destructeur

    int get_n(); //getter
    int get_m(); //getter
    int get_q(); //getter

    //On passe par des pointeurs car il n'est pas possible de renvoyer directement un tableau statique dans une fonction
    int* get_profits(); //getter
    int* get_ressources(); //getter
    int* get_demandes(); //getter

    //Pour créer un tableau à deux dimensions, on utilise un pointeur de pointeur.
    int** get_poids_r(); //getter
    int** get_poids_d(); //getter




    private:
    const int n; //Nombre d'objet n dans l'instance
    const int m; //Nombre de contraintes de ressources m 
    const int q; //Nombre de contraintes de demandes q

    int *profits; //profits cj des n objets
    int *ressources; //capacité des m contraintes
    int *demandes; //capacité des q demandes

    int **poids_r; //m tableaux contenant chacun les n valeurs des poids associé à la contrainte de ressource 
    int **poids_d; //q tableaux contenant chacun les n valeurs des poids associé à la contrainte de demande

};

#endif