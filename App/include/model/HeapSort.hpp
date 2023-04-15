
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class HeapSort : public Sorting<T> {
    private:
        void heapify(size_t size, size_t index) {
            size_t largest = index;
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            this->incrementComparisons();
            if (left < size && this->liste[left] > this->liste[largest]) {
                largest = left;
            }
            this->incrementComparisons();
            if (right < size && this->liste[right] > this->liste[largest]) {
                largest = right;
            }
            this->incrementComparisons();
            if (largest != index) {
                this->swap(index, largest);
                this->heapify(size, largest);
            }
        }

    protected:

    public:
        HeapSort(void) : HeapSort(nullptr, 0) {}
        HeapSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~HeapSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            std::cout << "HeapSort::sort(void)" << std::endl;
            for (int i = this->size / 2 - 1; i >= 0; i--) {
                this->heapify(this->size, i);
            }
            for (int i = this->size - 1; i >= 0; i--) {
                this->swap(0, i);
                this->heapify(i, 0);
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "HeapSort::schuffle(size_t seed, int count)" << std::endl;
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

        HeapSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const HeapSort<T>& s) {
            std::cout << "Heap Sort = [";
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