#ifndef parse_hpp
#define parse_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

std::vector<int> extractIntegerWord(std::string str);
std::vector<std::vector<int>> parseData(std::string path); 

#endif