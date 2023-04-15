#pragma once

#include <iostream>

#include "Sorting.hpp"

template <typename T>
class BingoSort : public Sorting<T> {
    private:
        void maxMin(T& min, T& max) {
            max = this->liste[0];
            min = this->liste[0];
            for (size_t i = 1; i < this->size; i++) {
                this->incrementComparisons();
                if (this->liste[i] > max) {
                    max = this->liste[i];
                }
                this->incrementComparisons();
                if (this->liste[i] < min) {
                    min = this->liste[i];
                }
            }
        }

    protected:

    public:
        BingoSort(void) : BingoSort(nullptr, 0) {}
        BingoSort(T* Liste, size_t size) : Sorting<T>(Liste, size) {}
        
        ~BingoSort(void) {}

        void sort(void) {
            this->resetComparisons();
            this->resetCount();
            std::cout << "BingoSort::sort(void)" << std::endl;
            T bingo = this->liste[0];
            T nextBingo = this->liste[0];
            this->maxMin(bingo, nextBingo);
            T largestEle = nextBingo;
            size_t nextElePos = 0;
            while (bingo < nextBingo) {
                size_t startPos = nextElePos;
                for (size_t i = startPos; i < this->size; i++) {
                    this->incrementComparisons();
                    if (this->liste[i] == bingo) {
                        this->swap(i, nextElePos);
                        nextElePos++;
                    } else {
                        this->incrementComparisons();
                        if (this->liste[i] < nextBingo) {
                            nextBingo = this->liste[i];
                        }
                    }
                }
                bingo = nextBingo;
                nextBingo = largestEle;
            }
        }
        
        void schuffle(size_t seed, int count) {
            std::cout << "BingoSort::schuffle(size_t seed, int count)" << std::endl;
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

        BingoSort<T>& get(void) {
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const BingoSort<T>& s) {
            std::cout << "Bingo Sort = [";
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