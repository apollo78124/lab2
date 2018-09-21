#include <iostream>
#include <iomanip>
#include<fstream>
#include <random>
#include <ctime>
#include <algorithm>
#include "header.hpp"

using namespace std;

int writeFile() {
    int random = 0;
    ofstream myfile;
    myfile.open ("Readings.txt");

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(512, 1024);
    random = distribution(generator);

    default_random_engine generator1(time(0));
    uniform_real_distribution<double> distribution1(50.000, 90.000);

    for (int i = 0; i < random; i++) {
        myfile << i << " ";
        myfile << fixed << setprecision(3) << distribution1(generator1);
        myfile <<"\n";
    }
    myfile.close();
    return 1;
}

double median1(vector<double> dVector) {
    size_t size = dVector.size();

    if (size == 0)
    {
        return 0;  // Undefined, really.
    }
    else
    {
        sort(dVector.begin(), dVector.end());
        if (size % 2 == 0)
        {
            return (dVector[size / 2 - 1] + dVector[size / 2]) / 2;
        }
        else
        {
            return dVector[size / 2];
        }
    }
}

int calculation() {

    ifstream myfile;
    myfile.open ("Readings.txt");
    std::string line;
    int a = 0;
    double sum = 0;
    double dTemp = 0;
    double max = 0;
    double min = 0;
    vector <double> dVec;
    string word;
    while (myfile >> word)
    {
        dTemp = stod(word);

        if (a % 2 != 0) {
            dVec.push_back(dTemp);
            sum += dTemp;
            if (a == 1)
                min = dTemp;
            if (dTemp < min)
                min = dTemp;
            if (dTemp > max)
                max = dTemp;
        }

        a++;
    }
    double medianVal = median1(dVec);
    int reading = a / 2;
    cout <<"There are " << reading << " readings in the file."<<endl;
    cout <<"The average reading is "<< fixed << setprecision(3) << (sum / reading) << endl;
    cout <<"The highest reading is "<< fixed << setprecision(3) << max << endl;
    cout <<"The lowest reading is "<< fixed << setprecision(3) << min << endl;
    cout <<"The median reading is "<< medianVal << endl;
    myfile.close();
    return 1;
}



int main() {

    writeFile();
    calculation();

    cout << "Lab2 Set 3A Eunhak (David) Lee A01026056" << endl;

    return 0;
}