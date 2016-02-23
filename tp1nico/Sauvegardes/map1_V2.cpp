//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      map1.cpp
//
// \brief     TP1: map1.cpp
//
// \author    Doens Nicolas
//
//////////////////////////////////////////////////////////////////////////////////
// header-log
//
// $Author$
// $Date$
// $Revision$
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//
//
// Compiled with g++ 5.3.0 (MSYS2 project)
//
// g++ -std=c++14 -O3 -o histogram histogram.cpp

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>

using std::string;

//Fonction affichage (debug):
template<typename Map>
void print_map(Map& m){
   std::cout << '{';
   for(auto& p: m)
        std::cout << p.first << ':' << p.second << ' ';
   std::cout << "}\n";
}

// Read from a file a set of ID (string format) and value (double format)
// Split ID and value
// Ask user a ID and return the associate value.
//
int main(int argc, char *argv[]) {

  string file_name{argv[1]};                    //On récupère le nom du fichier;
  std::ifstream fin(file_name, std::ios::in);   //Ouverture en mode LECTURE.

  string line,id,val;
  auto value=0.0;
  std::map<string, double> map1; 

  while (std::getline(fin, line)) {       //Parcour du fichier ligne par ligne; 
    std::istringstream stream(line);      
    stream >> id >> val;                  //Séparation de l'ID et de la valeur
    value = std::stod(val);               

    map1[id] = value;
  }
  print_map(map1);
}
