//
// Created by dldms on 9/21/2018.
//

#ifndef LAB2_HEADER_HPP
#define LAB2_HEADER_HPP
#include <iostream>
#include <iomanip>
#include<fstream>
#include <random>
#include <ctime>
#include <algorithm>
#endif //LAB2_HEADER_HPP

class header {
    // Make a list on the file.
// RETURN : int 1 to indicate the run completion.
    int writeFile();

// Calculate the median value of the list.
// PRE : dVector is a list of double
// POST : a and b are unchanged
// RETURN : Median value in the dVector list.
    double median1(std::vector<double> dVector);

// Calculate the average, highest, lowest, median value in the Readings.txt
// RETURN : int 1 to indicate the run completion.
    int calculation();


};

