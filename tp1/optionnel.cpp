//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      optionnel.cpp
//
// \brief     TP_Introduction: optionnel.cpp
//
// \author    Doens Nicolas
//            Petrovich Rubens
//
// \Copyright 2016 Doens Nicolas
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
// g++ -std=c++14 -O3 -o optionnel optionnel.cpp

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>

using std::string;

// Crée un fichier avec n valeur (double).
// Lors de l'appel a la fonction le premier argument correspond au nombres de lignes du fichier,
// le 2ieme argument correspond au nom du fichier.
int main(int argc, char *argv[]) {
  double val;
  int n = atoi(argv[1]);
  double mean = atoi(argv[2]);
  double sigma = atoi(argv[3]);

  string file_name{argv[4]};                     // On récupère le nom du fichier;
  std::ofstream fin(file_name, std::ios::out);   // Ouverture en mode Ecriture.
  std::normal_distribution<double> r(mean, sigma);    // Permet de générer un double aléatoire
  std::default_random_engine randEng;                     // entre 0 et 7999.99.

  for (int i = 0; i < n; i++) {     // Ecriture des valeurs dans le fichier
    val = r(randEng);
    fin << val << '\n';
  }
}
