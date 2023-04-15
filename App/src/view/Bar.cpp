#include "../../include/view/Bar.hpp"

Bar::Bar(void) : Bar(10, 10, sf::Vector2f {10, 10}) {}

Bar::Bar(size_t width, size_t height, sf::Vector2f position) {
    this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
    this->shape->setFillColor(sf::Color::White);
    this->shape->setOutlineColor(sf::Color::Black);
    this->shape->setOutlineThickness(1);
    this->width = width;
    this->height = height;
    this->shape->setPosition(position);
    this->shape->rotate(180);
}

Bar::~Bar(void) {
    delete this->shape;
}

sf::RectangleShape* Bar::getShape(void) {
    return this->shape;
}

void Bar::move(sf::Vector2f position) {
    this->shape->setPosition(this->shape->getPosition() + position);
}

void Bar::setPos(sf::Vector2f position) {
    this->shape->setPosition(position);
}

void Bar::setFillColor(sf::Color color) {
    this->shape->setFillColor(color);
}

std::ostream& operator<<(std::ostream& os, const Bar& bar) {
    os << "Bar: " << bar.width << "x" << bar.height;
    return os;
}