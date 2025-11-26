#include "DynamicArray.cpp"
#include <algorithm>
#include <vector>

class NewMethods : public DynamicArray {
public:
    using DynamicArray::DynamicArray;

    double average() const {
        if (getSize() == 0) {
            throw std::runtime_error("Невозможно вычислить среднее значение для пустого массива");
        }
        double sum = 0;
        for (int i = 0; i < getSize(); i++) {
            sum += getValue(i);
        }
        return sum / getSize();
    }

    double median() {
        if (getSize() == 0) {
            throw std::runtime_error("Невозможно вычислить медиану для пустого массива");
        }

        std::vector<int> sortedData(getSize());
        for (int i = 0; i < getSize(); i++) {
            sortedData[i] = getValue(i);
        }

        std::sort(sortedData.begin(), sortedData.end());

        int middle = getSize() / 2;
        if (getSize() % 2 == 0) {
            return (sortedData[middle - 1] + sortedData[middle]) / 2.0;
        } else {
            return sortedData[middle];
        }
    }

    int getMinValue() const {
        if (getSize() == 0) {
            throw std::runtime_error("Невозможно найти минимальное значение для пустого массива");
        }

        int minVal = getValue(0);
        for (int i = 1; i < getSize(); i++) {
            if (getValue(i) < minVal) {
                minVal = getValue(i);
            }
        }
        return minVal;
    }

    int getMaxValue() const {
        if (getSize() == 0) {
            throw std::runtime_error("Невозможно найти максимальное значение для пустого массива");
        }

        int maxVal = getValue(0);
        for (int i = 1; i < getSize(); i++) {
            if (getValue(i) > maxVal) {
                maxVal = getValue(i);
            }
        }
        return maxVal;
    }
};
