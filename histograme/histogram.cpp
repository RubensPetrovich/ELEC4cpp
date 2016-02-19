//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      histogram.cpp
//
// \brief     This file belongs to the C++ tutorial project
//            exercice 1
// \author    Rubens PETROVICH
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
// version  2.1
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

// On calcule le nombre d'occurence maximum dans un bin de 100
// Pour pouvoir ensuite bien répartire les 60 *
  auto max_occurence = 0;
  auto cnt = 0;
  auto centieme = 0;
  for (unsigned i = 0; i < buf.size(); i++) {
    cnt++;
    if (buf[i]/100 > centieme) {
      centieme++;
      if (cnt > max_occurence) max_occurence = cnt;
      cnt = 0;
    }
  }
  if (max_occurence < cnt) max_occurence = cnt;

// On affiche l'histogramme en parcourant le tableu trié
//
  float count = 0.0;
  centieme = 0;

  float echelon =  60.0/max_occurence;
  float nb_etoile = 1.0 ;

  

  for (unsigned int i = 0 ; i < buf.size() ; i++) {
//On sort du bin
    if (buf[i]/100 > centieme) {
      for (int j = centieme; j < buf[i]/100; j++) {
        std::cout << "\n" << std::setw(6) << std::right << 100*j << " " ;
        centieme++ ;
      }

//      std::cout << nb_etoile;
      count = echelon;
      nb_etoile = 0.0;
      centieme++;
    }
//buf[i] < centiem : on est dans le bin
    else {
      if ( count >= nb_etoile ){
        std::cout << "*";
        nb_etoile += 1.0;
      }
      count += echelon;
    //  std::cout << "cnt" << count ;
    }
  }
}
