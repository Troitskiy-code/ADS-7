// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    std::ofstream out("result/data.csv");
    out << "n,all_off,all_on,random_avg\n";

    const int MAX_N = 100;
    const int RANDOM_TRIALS = 20;

    std::srand(static_cast<unsigned>(std::time(0)));

    for (int n = 2; n <= MAX_N; ++n) {
        Train offTrain;
        for (int i = 0; i < n; ++i)
            offTrain.addCar(false);
        offTrain.getLength();
        int opsOff = offTrain.getOpCount();

        Train onTrain;
        for (int i = 0; i < n; ++i)
            onTrain.addCar(true);
        onTrain.getLength();
        int opsOn = onTrain.getOpCount();

        long long sumRand = 0;
        for (int t = 0; t < RANDOM_TRIALS; ++t) {
            Train randTrain;
            for (int i = 0; i < n; ++i)
                randTrain.addCar(std::rand() % 2 == 1);
            randTrain.getLength();
            sumRand += randTrain.getOpCount();
        }
        double avgRand = static_cast<double>(sumRand) / RANDOM_TRIALS;

        out << n << "," << opsOff << "," << opsOn << "," << avgRand << "\n";
    }
    out.close();
    std::cout << "Experiment finished. Data saved to result/data.csv" << std::endl;
    return 0;
}
