//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      map1.cpp
//
// \brief     TP_Introduction: map1.cpp
//
// \author    Doens Nicolas
//            Petrovich Rubens
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

// Fonction affichage (debug):
// void print_map(Map& m){
   // std::cout << '{';
   // for(auto& p: m)
        // std::cout << p.first << ':' << p.second << ' ';
   // std::cout << "}\n";
// }

// Read from a file a set of ID (string format) and value (double format)
// Split ID and value
// Build map.
std::map<string, double> mapping(string file){
  string file_name{file};                        // On récupère le nom du fichier;
  std::ifstream fin(file_name, std::ios::in);    // Ouverture en mode LECTURE.

  string line,id,val;
  auto value=0.0;
  std::map<string, double> map1; 

  while (std::getline(fin, line)) {       // Parcour du fichier ligne par ligne; 
    std::istringstream stream(line);      
    stream >> id >> val;                  // Séparation de l'ID et de la valeur
    value = std::stod(val);               

    map1[id] = value;
  }
  return(map1);
}

// Ask user a ID and return the associate value
// Using function mapping and print_map.
int main(int argc, char *argv[]) {
  std::map<string, double> map1;
  bool found;

  map1=mapping(argv[1]);
  // print_map(map1);

  string userIn="";
  double value ;
  while(userIn!="END"){
     std::cout << "query> ";
     std::cin >> userIn;
    found=false;

     if (userIn[0] == '+') {
      value = std::stod(userIn.substr(1)) ;
      for(auto& p: map1){
        if( p.second > value*0.99 && p.second < value*1.01 ){
          found=true;
          std::cout << "value[" << p.first << "] = " << p.second << '\n';
        }
      }
      if(!found){
       std::cout << "This value does not exists \n";
     }
     } else {
       for(auto& p: map1){
        if(userIn==p.first){
          found=true;
          std::cout << "value[" << p.first << "] = " << p.second << '\n';
         break;
        }
      }
      if(!found){
       std::cout << "This ID does not exists \n";
     }
    }
     if(userIn=="END"){
      std::cout << "Bye..." << std::endl;
     }     
  }
}
