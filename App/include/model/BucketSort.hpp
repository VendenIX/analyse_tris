
#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class BucketSort : public Sorting<T> {
    private:

    protected:

    public:
        BucketSort(void) : BucketSort(nullptr, 0) {}
        BucketSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~BucketSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            T liste[this->size];
            for (size_t i = 0; i < this->size; i++) {
                this->incrementComparisons();
                liste[i] = this->liste[i];
            }
            std::map<T, size_t> map;
            for (size_t i = 0; i < this->size; i++) {
                this->incrementComparisons();
                map[liste[i]]++;
            }
            size_t index = 0;
            for (auto it = map.begin(); it != map.end(); it++) {
                for (size_t i = 0; i < it->second; i++) {
                    this->swap(index, this->find(it->first));
                    index++;
                }
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "BucketSort::schuffle(size_t seed, int count)" << std::endl;
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

        BucketSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const BucketSort<T>& s) {
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