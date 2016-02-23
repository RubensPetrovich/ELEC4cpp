//
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      mean_and_median.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Bernard
//
// \copyright Copyright ng2goodies 2015
//            Distributed under the MIT License
//            See http://opensource.org/licenses/MIT
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
// g++ -std=c++14 -O3 -o mean_and_median mean_and_median.cpp

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

  std::sort(buf.begin(), buf.end());

  auto mid = buf.size() / 2;
  double median = (buf.size() % 2) ? buf[mid] :
                                     (buf[mid - 1] + buf[mid]) / 2;

  std::cout << "number of elements = " << buf.size()
       << ", median = " << median << ", mean = " << mean << std::endl;
}
