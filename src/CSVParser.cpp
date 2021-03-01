#include "CSVParser.h"

#include <fstream>
#include <iostream>
#include <sstream>

void CSVReader::readData() {
  std::ifstream myFile(fileName);
  if (!myFile.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  std::string line;
  while (getline(myFile, line)) {
    std::istringstream iss{line};
    std::string elem;
    while (getline(iss, elem, delimiter)) {
      raw_row.emplace_back(elem);
    }
  }

  for (uint32_t i = 0; i < raw_row.size(); i++) {
    if (i % 2 == 0) {
      x.emplace_back(stod(raw_row[i]));
    } else {
      y.emplace_back(stod(raw_row[i]));
    }
  }

  std::cout << "Reading Data completed." << std::endl;
}

void CSVReader::plotData() {
  std::cout << "Printing Data ... " << std::endl;
  // TODO implement Plotting with matplot++ lib
}

void CSVReader::dumpData2Console(uint32_t num) {
  std::cout << "Printing " << num << "(x,y) points ..." << std::endl;
  for (uint32_t iVect = 0; iVect < num; iVect++) {
    std::cout << "x : " << x.at(iVect) << ", y: " << y.at(iVect) << std::endl;
  }
  std::cout << "Printing completed." << std::endl;
}

void CSVReader::FilterMovingAvg(uint32_t window_size) {
  double sum_x, sum_y = 0.0;
  std::cout << "Performing filtering ..." << std::endl;
  for (uint32_t i = 0; i < (x.size() - window_size); i++) {
    sum_x = 0.0;
    sum_y = 0.0;
    for (uint32_t j = i; j < (i + window_size); j++) {
      sum_x += x[j];
      sum_y += y[j];
    }

    x_avg.emplace_back(sum_x / window_size);
    y_avg.emplace_back(sum_y / window_size);
  }
}