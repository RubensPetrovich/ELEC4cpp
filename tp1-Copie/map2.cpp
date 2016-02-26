//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      map2.cpp
//
// \brief     TP_Introduction: map2.cpp
//
// \author    Doens Nicolas
//            Petrovich Rubens
//
// \Copyright 2016 Doens Nicolas
//                 Petrovich Rubens
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
// g++ -std=c++14 -O3 -o map2 map2.cpp

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <windows.h>

using std::string;


// Read from a file a set of ID (string format) and value (double format)
// Split ID and value
// Build map.
std::map<string, double> mapping(string file) {
  string file_name{file};                        // On récupère le nom du fichier;
  std::ifstream fin(file_name, std::ios::in);    // Ouverture en mode LECTURE.

  string line, id, val;
  auto value = 0.0;
  std::map<string, double> map2;

  while (std::getline(fin, line)) {       // Parcour du fichier ligne par ligne;
    std::istringstream stream(line);
    stream >> id >> val;                  // Séparation de l'ID et de la valeur
    value = std::stod(val);

    map2[id] = value;
  }
  return(map2);
}

// Ask user a ID or value (begin by '+') and return the associate value and ID
// Using function mapping
int main(int argc, char *argv[]) {
  std::map<string, double> map2;
  bool found;                     // found = 1 Si l'ID est trouvée dans le map
      ULARGE_INTEGER tbegin,tend;
      FILETIME ttmp={0,0};                    // temporary variable
      double texec=0.;

  map2 = mapping(argv[1]);

  string userIn = "";               // ID ou valeur demandé par l'utilisateur.
  double value;

  while (userIn != "END") {
    std::cout << "query> ";
    std::cin >> userIn;
//TIIMMMMMEEEEE
      ::GetSystemTimeAsFileTime(&ttmp);       // store current time in ttmp structure
      tbegin.HighPart=ttmp.dwHighDateTime;    // convert ttmp to two int32
      tbegin.LowPart=ttmp.dwLowDateTime;
//TIIMMMMEEEEEE
    found = false;

    if (userIn[0] == '+') {
      value = std::stod(userIn.substr(1));
      for (auto& p : map2) {
        if ( p.second > value*0.99 && p.second < value*1.01 ) {
          found = true;
          std::cout << "value[" << p.first << "] = " << p.second << '\n';
        }
      }
      if (userIn == "END") {
        std::cout << "Bye..." << std::endl;
      } else if (!found) {
       std::cout << "This value does not exists \n";
      }
    } else {
      for (auto& p : map2) {        // On parcourt le map  =>  p.first = ID; p.second = Valeur
        if (userIn == p.first) {
          found = true;
          std::cout << "value[" << p.first << "] = " << p.second << '\n';
          break;
        }
      }
      if (userIn == "END") {
        std::cout << "Bye..." << std::endl;
      } else if (!found) {
        std::cout << "This ID does not exists \n";
      }
    }
    //TIIMMMMEEEEEE
    ::GetSystemTimeAsFileTime(&ttmp);       // store current time in ttmp structure
      tend.HighPart=ttmp.dwHighDateTime;      // convert ttmp to two int32
      tend.LowPart=ttmp.dwLowDateTime;
      // Compute execution time
      texec=((double)((tend.QuadPart-tbegin.QuadPart)/10000))/1000.;

    //TIIMMMMEEEEEE
    std::cout << "time : " << texec << std::endl ;
  }
}
