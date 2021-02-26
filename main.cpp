#include "CSVParser.h"

int main() {
    CSVReader afm_csv("../input/force_curve.csv", ';');
    
    afm_csv.readData();
    afm_csv.dumpData2Console(5);
    afm_csv.FilterMovingAvg(50);
    afm_csv.plotData();
    
    return 0;
}