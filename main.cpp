#include <iostream>
#include<fstream>
#include <random>
#include <ctime>
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
        myfile << distribution1(generator1);
        myfile <<"\n";
    }
    myfile.close();
    return 1;
}

int calculation() {
    return 1;
}

int main() {

    writeFile();

    cout << "Hello, World!" << endl;

    return 0;
}