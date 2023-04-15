
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class InsertionSort : public Sorting<T> {
    private:

    protected:

    public:
        InsertionSort(void) : InsertionSort(nullptr, 0) {}
        InsertionSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~InsertionSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            for (size_t i = 1; i < this->size; i++) {
                T key = this->liste[i];
                long long j = (long long)i - 1;
                this->incrementComparisons();
                while (j >= 0 && this->liste[j] > key) {
                    this->incrementComparisons();
                    this->swap(j, j + 1);
                    j--;
                }
                this->liste[j + 1] = key;
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "InsertionSort::schuffle(size_t seed, int count)" << std::endl;
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

        InsertionSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const InsertionSort<T>& s) {
            std::cout << "Insertion Sort = [";
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