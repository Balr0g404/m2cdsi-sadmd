#ifndef data_hpp
#define data_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Data 
{
    public:

    Data(std::string path);

    int get_n(); //getter
    int get_m(); //getter
    int get_q(); //getter

    //on utilise des vector car il n'est pas possible pour une fonction de renvoyer un tableau statique en C++
    std::vector<int> get_profits(); //getter
    std::vector<int> get_ressources(); //getter
    std::vector<int> get_demandes(); //getter

    std::vector<int> get_poids_r(); //getter
    std::vector<int> get_poids_d(); //getter




    private:
    int n; //Nombre d'objet n dans l'instance
    int m; //Nombre de contraintes de ressources m 
    int q; //Nombre de contraintes de demandes q

    int profits[n]; //profits cj des n objets
    int ressources[m] //capacité des m contraintes
    int demandes[q] //capacité des q demandes

    int poids_r[m][n] //m tableaux contenant chacun les n valeurs des poids associé à la contrainte de ressource 
    int poids_d[q][n] //q tableaux contenant chacun les n valeurs des poids associé à la contrainte de demande

}

#endif