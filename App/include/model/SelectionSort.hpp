
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class SelectionSort : public Sorting<T> {
    private:

    protected:

    public:
        SelectionSort(void) : SelectionSort(nullptr, 0) {}
        SelectionSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~SelectionSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            for (size_t i = 0; i < this->size; i++) {
                size_t min = i;
                for (size_t j = i + 1; j < this->size; j++) {
                    this->incrementComparisons();
                    if (this->liste[j] < this->liste[min]) {
                        min = j;
                    }
                }
                if (min != i) {
                    this->swap(i, min);
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "SelectionSort::schuffle(size_t seed, int count)" << std::endl;
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

        SelectionSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const SelectionSort<T>& s) {
            std::cout << "Selection Sort = [";
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