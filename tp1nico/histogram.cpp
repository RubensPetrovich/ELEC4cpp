//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      histogram.cpp
//
// \brief     TP1 histogram
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
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;


// Read from a file a set of numbers (double format)
// compute a running mean value
// compute the median after sort
//
int main(int argc, char *argv[]) {

  string file_name{argv[1]};                    //On récupère le nom du fichier;
  vector<double> buf;                           //Vecteur qui va contenir les valeurs lus dans le fichier (doubles);
  std::ifstream fin(file_name, std::ios::in);   //Ouverture en mode LECTURE.

  string line;
  auto mean = 0.0;  //Moyenne

  while (std::getline(fin, line)) {                                   //Parcour du fichier ligne par ligne;
    auto d = std::stod(line);                                         //String => double;
    buf.push_back(d);                                                 //Ajout de la valeur a la fin du vecteur;
    mean = (buf.size() == 1) ? d : mean + (d - mean) / buf.size();    //Calcul de la moyenne.
  }

  std::sort(buf.begin(), buf.end());    //Triage du vecteur

  auto mid = buf.size() / 2;                                                      //Calcul de la mediane
  double median = (buf.size() % 2) ? buf[mid] : (buf[mid - 1] + buf[mid]) / 2;    //

  std::cout << "number of elements = " << buf.size()
       << ", median = " << median << ", mean = " << mean << std::endl;


  //Histogramme :
}
