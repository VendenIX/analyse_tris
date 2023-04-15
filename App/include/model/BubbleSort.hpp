
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class BubbleSort : public Sorting<T> {
    private:

    protected:

    public:
        BubbleSort(void) : BubbleSort(nullptr, 0) {}
        BubbleSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~BubbleSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            for (size_t i = 0; i < this->size; i++) {
                for (size_t j = 0; j < this->size - 1; j++) {
                    this->incrementComparisons();
                    if (this->liste[j] > this->liste[j + 1]) {
                        this->swap(j, j + 1);
                    }
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "BubbleSort::schuffle(size_t seed, int count)" << std::endl;
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

        BubbleSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const BubbleSort<T>& s) {
            std::cout << "Bubble Sort = [";
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