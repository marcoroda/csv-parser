#ifndef CSVREADER_H_
#define CSVREADER_H_

#include <iostream>
#include <utility>
#include <vector>

class CSVReader {
  public:
    CSVReader() = default;
    CSVReader(std::string fileName, char delimiter)
        : fileName(std::move(fileName)), delimiter(delimiter) { }
    std::string get_fileName() { return fileName; };
    void set_fileName(std::string fileName) { CSVReader::fileName = std::move(fileName); }
    std::vector<double> getX() { return this->x; };
    std::vector<double> getY() { return this->y; };
    void readData();
    void plotData();
    void dumpData2Console(std::uint32_t num);
    void FilterMovingAvg(std::uint32_t window_size);
  
  private:
    std::string fileName{};
    char delimiter{};
    std::vector<std::string> raw_row{};
    std::vector<double> x{};
    std::vector<double> y{};
    std::vector<double> x_avg{};
    std::vector<double> y_avg{};
};

#endif /* CSVREADER_H_ */