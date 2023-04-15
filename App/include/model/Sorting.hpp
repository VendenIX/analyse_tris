#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <map>

template <typename T>
class Sorting {
    private:
        unsigned long long count = 0;
        unsigned long long comparisons = 0;
        std::vector<std::vector<size_t>> switches;
        std::vector<std::vector<size_t>> blends;

    protected:
        T* liste;
        size_t size;

    public:
        Sorting(void) : Sorting(nullptr, 0) {}

        Sorting(T* Liste, size_t size) {
            this->size = size;
            this->liste = new T[size];
            for (size_t i = 0; i < size; i++) {
                this->liste[i] = Liste[i];
            }
        }

        virtual ~Sorting(void) {
            delete[] this->liste;
        }

        unsigned long long getComparisons(void) const {
            return this->comparisons;
        }

        void resetComparisons(void) {
            this->comparisons = 0;
        }

        void incrementComparisons(void) {
            this->comparisons++;
        }

        size_t getSize(void) const {
            return this->size;
        }

        T get(size_t index) const {
            return this->liste[index];
        }

        void resetCount(void) {
            this->count = 0;
        }

        unsigned long long getCount(void) const {
            return this->count;
        }

        void incrementCount(void) {
            this->count++;
        }

        void setSize(size_t size) {
            this->size = size;
            delete[] this->liste;
            this->liste = new int[size];
            this->init();
        }

        std::vector<std::vector<size_t>> getSwitches(void) const {
            return this->switches;
        }

        void swap(size_t index1, size_t index2) {
            T temp = this->liste[index1];
            this->liste[index1] = this->liste[index2];
            this->liste[index2] = temp;
            this->switches.push_back({index1, index2});
            this->incrementCount();
        }

        std::vector<std::vector<size_t>> getBlends(void) const {
            return this->blends;
        }

        void swapBlend(size_t index1, size_t index2) {
            T temp = this->liste[index1];
            this->liste[index1] = this->liste[index2];
            this->liste[index2] = temp;
            this->blends.push_back({index1, index2});
        }

        Sorting<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream &os, const Sorting<T> &s) {
            std::cout << "Sorting = [";
            size_t size = s.size;
            for (size_t i = 0; i < size; i++) {
                os << s.liste[i];
                if (i + 1 != size) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        bool isSorted(void) const {
            for (size_t i = 0; i < this->size - 1; i++) {
                if (this->liste[i] > this->liste[i + 1]) {
                    return false;
                }
            }
            return true;
        }

        T* getList(void) const {
            return this->liste;
        }

        size_t find(T value) const {
            for (size_t i = 0; i < this->size; i++) {
                if (this->liste[i] == value) {
                    return i;
                }
            }
            return -1;
        }

        Sorting<T>& operator=(const Sorting<T> &s) {
            this->size = s.size;
            delete[] this->liste;
            this->liste = new T[this->size];
            for (size_t i = 0; i < this->size; i++) {
                this->liste[i] = s.liste[i];
            }
            return *this;
        }

        virtual void schuffle(size_t seed, int count) {
            std::cout << "Schuffle not implemented" << std::endl;
            std::cout << "Seed: " << seed << std::endl;
            std::cout << "Count: " << count << std::endl;
        }

        virtual void sort(void) {
            std::cout << "Sort not implemented" << std::endl;
        }

        void extractData(std::string file) {
            std::cout << "Extracting data to " << file << std::endl;
        }

        std::vector<std::vector<size_t>> getSwitchs(void) const {
            return this->listSwitch;
        }
};
