#pragma once

#include "Sorting.hpp"

#include <iostream>

template <typename T>
class QuickSort : public Sorting<T> {
private:

    int partition(int low, int high) {
        int pivot = this->liste[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            this->incrementComparisons();
            if (this->liste[j] < pivot) {
                i++;
                this->swap(i, j);
            }
        }
        this->swap(i + 1, high);
        return (i + 1);
    }

    void quick(int low, int high) {
        if (low < high) {
            int pi = this->partition(low, high);
            this->quick(low, pi - 1);
            this->quick(pi + 1, high);
        }
    }

public:
    QuickSort(void) : QuickSort(nullptr, 0) {};
    QuickSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {};
    ~QuickSort(void) {};
    
    void sort(void) {
        std::cout << "QuickSort::sort()" << std::endl;
        this->resetComparisons();
        this->resetCount();
        int s = this->size - 1;
        this->quick(0, s);
    }

    void schuffle(size_t seed, int count) {
            std::cout << "LinearSort::schuffle(size_t seed, int count)" << std::endl;
            if (count == -1) {
                count = this->size;
            }
            std::srand(seed);
            for (int i = 0; i < count; i++) {
                size_t index1 = std::rand() % this->size;
                size_t index2 = std::rand() % this->size;
                T switch1 = this->liste[index1];
                T switch2 = this->liste[index2];
                this->liste[index1] = switch2;
                this->liste[index2] = switch1;
            }
        }

        QuickSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const QuickSort<T>& s) {
            std::cout << "Quick Sort = [";
            for (size_t i = 0; i < s.size; i++) {
                os << s.liste[i];
                if (i != s.size - 1) {
                    os << ", ";
                }
            }
            os << "]" << std::endl;
            return os;
        }
};