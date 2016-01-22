#include "FrequencyCharacteristic.h"

void initArray(int **array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = new int[size]();
    }
}


void printArray(int **array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << array[i][j] << " ";
        }

        std::cout << "\n";
    }
}

void deleteArray(int **array, int size) {
    for (int i = 0; i < size; i++) {
        delete [] array[i];
    }

    delete array;
}