
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class CombSort : public Sorting<T> {
    private:
        size_t getNextGap(size_t gap) {
            gap = (gap * 10) / 13;
            if (gap < 1) {
                return 1;
            }
            return gap;
        }

    protected:

    public:
        CombSort(void) : CombSort(nullptr, 0) {}
        CombSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~CombSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            std::cout << "CombSort::sort(void)" << std::endl;
            size_t gap = this->size;
            bool swapped = true;
            while (gap != 1 || swapped == true) {
                gap = this->getNextGap(gap);
                swapped = false;
                for (size_t i = 0; i < this->size - gap; i++) {
                    this->incrementComparisons();
                    if (this->liste[i] > this->liste[i + gap]) {
                        this->swap(i, i + gap);
                        swapped = true;
                    }
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "CombSort::schuffle(size_t seed, int count)" << std::endl;
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

        CombSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const CombSort<T>& s) {
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