#include <iostream>

class DynamicArray {
private:
    int * dynArr;
    size_t sizeArr;

public:
    DynamicArray(size_t sizeArray) {
        sizeArr = sizeArray;
        dynArr = new int[sizeArr];

        for (int i = 0; i < sizeArr; i++) {
            dynArr[i] = 0;
        }

        std::cout << "Массив с размером " << sizeArr << " создан" << std::endl;
    }

    ~DynamicArray() {
        delete[] dynArr;
        std::cout << "Массив был удален" << std::endl;
    }

    DynamicArray(const DynamicArray& other) : sizeArr(other.sizeArr) {
        dynArr = new int[sizeArr];

        for (int i = 0; i < sizeArr; i++) {
            dynArr[i] = other.dynArr[i];
        }

        std::cout << "Массив скопирован" << std::endl;
    }

    DynamicArray& add(const DynamicArray& other) {
        int maxSize = (sizeArr > other.sizeArr) ? sizeArr : other.sizeArr;
        int* result = new int[maxSize];

        for (int i = 0; i < maxSize; i++) {
            int val1 = (i < sizeArr) ? dynArr[i] : 0;
            int val2 = (i < other.sizeArr) ? other.dynArr[i] : 0;
            result[i] = val1 + val2;

            if (result[i] < -100 || result[i] > 100) {
                delete[] result;
                throw std::overflow_error("Результат сложения выходит за диапазон [-100; 100]");
            }
        }
        if (sizeArr < maxSize) {
            delete[] dynArr;
            dynArr = new int[maxSize];
            sizeArr = maxSize;
        }

        for (size_t i = 0; i < maxSize; i++) {
            dynArr[i] = result[i];
        }

        for (size_t i = maxSize; i < sizeArr; i++) {
            dynArr[i] = 0;
        }

        delete[] result;
        return *this;
    }

    DynamicArray& subtract(const DynamicArray& other) {
        size_t maxSize = (sizeArr > other.sizeArr) ? sizeArr : other.sizeArr;

        int* result = new int[maxSize];

        for (size_t i = 0; i < maxSize; i++) {
            int val1 = (i < sizeArr) ? dynArr[i] : 0;
            int val2 = (i < other.sizeArr) ? other.dynArr[i] : 0;
            result[i] = val1 - val2;

            if (result[i] < -100 || result[i] > 100) {
                delete[] result;
                throw std::overflow_error("Результат вычитания выходит за диапазон [-100; 100]");
            }
        }

        if (sizeArr < maxSize) {
            delete[] dynArr;
            dynArr = new int[maxSize];
            sizeArr = maxSize;
        }

        for (size_t i = 0; i < maxSize; i++) {
            dynArr[i] = result[i];
        }

        for (size_t i = maxSize; i < sizeArr; i++) {
            dynArr[i] = 0;
        }
        delete[] result;
        return *this;
    }

    int getSize() const {
        return sizeArr;
    }

    void print() const {
        std::cout << "Элементы массива: ";
        for (int i = 0; i < sizeArr; i++) {
            std::cout << dynArr[i] << " ";
        }
        std::cout << std::endl;
    }

    void addToEndArr(int value) {
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Значение " + std::to_string(value) + " должно быть в диапазоне [-100; 100]");
        }

        size_t newSize = sizeArr + 1;
        int* newDynArr = new int[newSize];

        for (int i = 0; i < sizeArr; i++) {
            newDynArr[i] = dynArr[i];
        }

        newDynArr[sizeArr] = value;

        delete[] dynArr;
        dynArr = newDynArr;
        sizeArr = newSize;
    }

    void setValue(int index, int value) {
        if (index >= sizeArr) {
            throw std::out_of_range("Индекс " + std::to_string(index) + " выходит за границы массива размером " + std::to_string(sizeArr));
        }
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Значение " + std::to_string(value) + " должно быть в диапазоне [-100;100]");
        }

        dynArr[index] = value;
    }

    int getValue(const int index) const {
        if (index >= sizeArr) {
            throw std::out_of_range("Индекс " + std::to_string(index) + " выходит за границы массива размером " + std::to_string(sizeArr));
        }
        return dynArr[index];
    }
};
