#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Bar {
    private:
        sf::RectangleShape* shape;
        size_t width;
        size_t height;
    
    protected:

    public:
        Bar(void);
        Bar(size_t width, size_t height, sf::Vector2f position);
        ~Bar(void);

        sf::RectangleShape* getShape(void);
        void move(sf::Vector2f position);
        void setPos(sf::Vector2f position);
        void setFillColor(sf::Color color);

        friend std::ostream& operator<<(std::ostream& os, const Bar& bar);
};