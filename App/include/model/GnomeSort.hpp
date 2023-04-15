
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class GnomeSort : public Sorting<T> {
    private:

    protected:

    public:
        GnomeSort(void) : GnomeSort(nullptr, 0) {}
        GnomeSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~GnomeSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            std::cout << "GnomeSort::sort(void)" << std::endl;
            size_t index = 0;
            while (index < this->size) {
                if (index == 0) {
                    index++;
                }
                this->incrementComparisons();
                if (this->liste[index] >= this->liste[index - 1]) {
                    index++;
                } else {
                    this->swap(index, index - 1);
                    index--;
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "GnomeSort::schuffle(size_t seed, int count)" << std::endl;
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

        GnomeSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const GnomeSort<T>& s) {
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