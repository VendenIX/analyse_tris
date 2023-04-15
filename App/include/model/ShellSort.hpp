
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class ShellSort : public Sorting<T> {
    private:

    protected:

    public:
        ShellSort(void) : ShellSort(nullptr, 0) {}
        ShellSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~ShellSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            std::cout << "ShellSort::sort(void)" << std::endl;
            for (size_t gap = this->size / 2; gap > 0; gap /= 2) {
                for (size_t i = gap; i < this->size; i++) {
                    T temp = this->liste[i];
                    size_t j;
                    this->incrementComparisons();
                    for (j = i; j >= gap && this->liste[j - gap] > temp; j -= gap) {
                        this->swap(j, j - gap);
                    }
                    this->liste[j] = temp;
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "ShellSort::schuffle(size_t seed, int count)" << std::endl;
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

        ShellSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const ShellSort<T>& s) {
            std::cout << "Shell Sort = [";
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