#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int vectorToInt(vector<string> vect)
{
    string temp(vect.begin(), vect.end());
    int number = stoi(temp);

    return number;
}


int main()
{
    string path = "../data/n=100,m=5-20200416/100Md5_1_1_mixte.txt";
    ifstream file(path);

    if(file)
    {
        string line;
        getline(file, line);

        vector<char> n;
        vector<char> m;
        vector<char> q;

        int parser = 0;

        for(int i; i < line.size(); i++)
        {
            if(isspace(line[i]))
            {
                parser++;
                continue;
            }
            else
            {
                if(parser == 0)
                {
                    n.push_back(line[i]);
                }
                if(parser == 1)
                {
                    m.push_back(line[i]);
                }
                if(parser == 2)
                {
                    q.push_back(line[i]);
                }
                
            }
        }

    cout << vectorToInt(n);

        // while(getline(file, line))
        // {
        //     cout << line << endl;
        // }
    }

    return 0;
}