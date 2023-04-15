#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Bar.hpp"

template <typename T>
class Bars {
    private:
        Bar** bars;
        size_t size;
        T* listOrder;

        long long pos1 = -1;
        long long pos2 = -1;

        size_t widthWindow;
        size_t heightWindow;

    protected:

    public:
        Bars(void) : Bars(0, nullptr, 800, 600) {}

        Bars(size_t size, T* listOrder, size_t widthWindow, size_t heightWindow) {
            std::cout << "Bars(size_t size, T* listOrder, size_t widthWindow, size_t heightWindow)" << std::endl;
            std::cout << "size = " << size << std::endl;
            std::cout << "widthWindow = " << widthWindow << std::endl;
            std::cout << "heightWindow = " << heightWindow << std::endl;
            this->size = size;
            this->bars = new Bar*[size];
            this->listOrder = new T[size];
            for (size_t i = 0; i < size; i++) {
                this->listOrder[i] = listOrder[i];
            }

            this->widthWindow = widthWindow;
            this->heightWindow = heightWindow;

            float widthUnit = widthWindow / size;
            float heightUnit = heightWindow / size;

            for (size_t i = 0; i < size; i++) {
                sf::Vector2f position = sf::Vector2f(widthUnit * i, heightWindow);
                this->bars[i] = new Bar(widthUnit, heightUnit * (i + 1), position);
            }
            std::cout << "premier affichage";
            std::cout << *this << std::endl;
        }

        ~Bars(void) {
            for (size_t i = 0; i < this->size; i++) {
                delete this->bars[i];
            }
            delete[] this->bars;
            delete[] this->listOrder;
        }

        Bar** getBars(void) {
            return this->bars;
        }

        size_t getSize(void) {
            return this->size;
        }

        int* getListOrder(void) {
            return this->listOrder;
        }

        Bar* getBar(size_t index) {
            return this->bars[index];
        }

        void switchTwoBars(size_t index1, size_t index2) {
            if (this->pos1 != -1 || this->pos2 != -1) {
                this->bars[this->pos1]->setFillColor(sf::Color::White);
                this->bars[this->pos2]->setFillColor(sf::Color::White);
            }
            this->pos1 = index1;
            this->pos2 = index2;
            this->bars[index1]->setFillColor(sf::Color::Red);
            this->bars[index2]->setFillColor(sf::Color::Red);
            sf::Vector2f position1 = this->bars[index1]->getShape()->getPosition();
            sf::Vector2f position2 = this->bars[index2]->getShape()->getPosition();
            this->bars[index1]->setPos(position2);
            this->bars[index2]->setPos(position1);
            T temp = this->listOrder[index1];
            this->listOrder[index1] = this->listOrder[index2];
            this->listOrder[index2] = temp;
        }

        Bars<T>& get(void) {
            return *this;
        }

        T get(size_t index) {
            return this->listOrder[index];
        }

        friend std::ostream& operator<<(std::ostream& os, const Bars& bars) {
            os << "Bars = [";
            for (size_t i = 0; i < bars.size; i++) {
                os << bars.listOrder[i] << " ";
            }
            os << "]";
            return os;
        }

};