//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      histogram.cpp
//
// \brief     This file belongs to the C++ tutorial project
//            exercice 1
// \author    Rubens PETROVICH
//            Nicolas Doens
//
// \copyright Copyright ng2goodies 2015
//            Distributed under the MIT License
//            See http://opensource.org/licenses/MIT
//
//////////////////////////////////////////////////////////////////////////////////
// header-log
//
//
// Date 17/02/2016
// version  3.2
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//
// C++ version
// compiled with g++ 5.3.0
//          0 error
// cpplint: 0 error
//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using std::string;
using std::vector;

// Read from a file a set of numbers (double format)
// compute a running mean value
// compute the median after sort
// compute the histogram
int main(int argc, char *argv[]) {
  string file_name{argv[1]};
  vector<double> buf;
  std::ifstream fin(file_name, std::ios::in);

  string line;
  auto mean = 0.0;

  while (std::getline(fin, line)) {
    auto d = std::stod(line);
    buf.push_back(d);
    mean = (buf.size() == 1) ? d : mean + (d - mean) / buf.size();
  }
  // On trie le tableau
  std::sort(buf.begin(), buf.end());

  auto mid = buf.size() / 2;
  double median = (buf.size() % 2) ? buf[mid] :
                                     (buf[mid - 1] + buf[mid]) / 2;

  std::cout << "\nnumber of elements = " << buf.size()
           << ", median = " << median << ", mean = " << mean << std::endl;

//////////////////////////////////////////////////////////////////////////////
//  Histogramme //
//////////////////////////////////////////////////////////////////////////////

// On créer un vecteur donc l'indice corespond à la centième du bin
// Et la valeurs correspond au nombre de valeurs dans se bin
// Pour pouvoir ensuite bien répartire les 60 *
  vector<int> occurence;
  auto cnt = 0;             // Permet de compter les valeurs
  auto centieme = 0;        // Permet de changer de bin
  for (unsigned int i = 0; i < buf.size(); i++) {
    if (std::floor(buf[i]/100) > centieme) {
      occurence.push_back(cnt);
      centieme++;
      while ( std::floor(buf[i]/100) > centieme ) {
        occurence.push_back(0);
        centieme++;
        }
      cnt = 0;
    } cnt++;
  }
  occurence.push_back(cnt);
  auto occurence_max = std::distance(occurence.begin(),
                std::max_element(occurence.begin(), occurence.end()));

// On affiche l'histogramme en parcourant le tableu trié

  centieme = 0;

  auto nb_etoile = 0;


  for (unsigned int i = 0; i < occurence.size(); ++i) {
    std::cout << '\n' << std::setw(6) << i*100 << std::setw(6) << occurence[i] << ' ';
    nb_etoile = 60 * occurence[i] / occurence[occurence_max];
    for (int j = 0; j < nb_etoile; j++) {
      std::cout << '*';
    }
  }
}
