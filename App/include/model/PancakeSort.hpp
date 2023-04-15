
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class PancakeSort : public Sorting<T> {
    private:
        void flip(size_t size) {
            size_t start = 0;
            size_t end = size - 1;
            while (start < end) {
                this->swap(start, end);
                start++;
                end--;
            }
        }

        size_t findMax(T* liste, size_t size) {
            size_t max = 0;
            for (size_t i = 0; i < size; i++) {
                if (liste[i] > liste[max]) {
                    max = i;
                }
            }
            return max;
        }

    protected:

    public:
        PancakeSort(void) : PancakeSort(nullptr, 0) {}
        PancakeSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~PancakeSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            std::cout << "PancakeSort::sort(void)" << std::endl;
            for (size_t curr_size = this->size; curr_size > 1; curr_size--) {
                size_t max = this->findMax(this->liste, curr_size);
                if (max != curr_size - 1) {
                    this->flip(max + 1);
                    this->flip(curr_size);
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "PancakeSort::schuffle(size_t seed, int count)" << std::endl;
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

        PancakeSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const PancakeSort<T>& s) {
            std::cout << "Bucket Sort = [";
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