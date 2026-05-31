// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(0) {}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    newCar->next = 0;
    newCar->prev = 0;
    if (first == 0) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* tail = first->prev;
        newCar->next = first;
        newCar->prev = tail;
        tail->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    first->light = true;

    while (true) {
        int steps = 0;
        do {
            first = first->next;
            ++countOp;
            ++steps;
        } while (first->light == false);

        first->light = false;

        for (int i = 0; i < steps; ++i) {
            first = first->prev;
            ++countOp;
        }

        if (first->light == false) {
            return steps;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
