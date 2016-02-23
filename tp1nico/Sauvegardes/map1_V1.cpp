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

using std::string;

// Read from a file a set of numbers (double format)
// compute a running mean value
// compute the median after sort
//
int main(int argc, char *argv[]) {

  string file_name{argv[1]};                    //On récupère le nom du fichier;
  std::ifstream fin(file_name, std::ios::in);   //Ouverture en mode LECTURE.

  string line,id,val;
  auto value=0.0;

  while (std::getline(fin, line)) {                                   //Parcour du fichier ligne par ligne;
    std::istringstream stream(line);
    stream >> id >> val;
    value = std::stod(val);
    std::cout << "id=" << id << '\n';
    std::cout << "val=" << value << '\n';
  }
}
