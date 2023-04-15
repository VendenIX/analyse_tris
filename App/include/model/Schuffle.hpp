#pragma once

#include <iostream>
#include <vector>
#include "Sorting.hpp"

template <typename T>
class Schuffle {
    private:

    protected:

    public:
        static void reverse(Sorting<T>* s) {
            for (size_t i = 0; i < s->getSize() / 2; i++) {
                s->swapBlend(i, s->getSize() - i - 1);
            }
        }

        static void oneTwo(Sorting<T>* s) {
            for (size_t i = 0; i < s->getSize(); i += 2) {
                s->swapBlend(i, i + 1);
            } 
        }

        static void random(Sorting<T>* s) {
            srand(time(nullptr));
            int seed = rand();
            for (size_t i = 0; i < (std::rand() % s->getSize()) * 2; i++) {
                size_t index1 = std::rand() % s->getSize();
                size_t index2 = std::rand() % s->getSize();
                s->swapBlend(index1, index2);
            }
        }

        static void end25(Sorting<T>* s) {
            srand(time(NULL));
            int seed = rand();
            size_t end = (s->getSize() * 3) / 4;
            for (size_t i = end; i < s->getSize(); i ++) {
                size_t index1 = (std::rand() % (s->getSize() - end)) + end;
                size_t index2 = (std::rand() % (s->getSize() - end)) + end;
                s->swapBlend(index1, index2);
            } 
        }

        static void start25(Sorting<T>* s) {
            srand(time(NULL));
            int seed = rand();
            size_t start = s->getSize() / 4;
            for (size_t i = 0; i < start; i ++) {
                size_t index1 = std::rand() % start;
                size_t index2 = std::rand() % start;
                s->swapBlend(index1, index2);
            } 
        }

        static void start50(Sorting<T>* s) {
            srand(time(NULL));
            int seed = rand();
            size_t start = s->getSize() / 2;
            for (size_t i = 0; i < start; i ++) {
                size_t index1 = std::rand() % start;
                size_t index2 = std::rand() % start;
                s->swapBlend(index1, index2);
            } 
        }

        static void end50(Sorting<T>* s) {
            srand(time(NULL));
            int seed = rand();
            size_t end = s->getSize() / 2;
            for (size_t i = end; i < s->getSize(); i ++) {
                size_t index1 = (std::rand() % (s->getSize() - end)) + end;
                size_t index2 = (std::rand() % (s->getSize() - end)) + end;
                s->swapBlend(index1, index2);
            } 
        }
};