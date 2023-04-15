#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Bars.hpp"
#include "../Model.hpp"

template <typename T>
class Window {
    private:
        size_t width;
        size_t height;
        sf::RenderWindow *window;
        sf::Event event;
        sf::VideoMode videoMode;

        sf::Music* music;

        std::string nameAudioFile = "include/view/Duck.wav";

        Bars<T>* bars;

        int speed; 

        const std::string name = "Sorting Visualizer";

        void clear(void) {
            this->window->clear();
        }

        void display(void) {
            this->window->display();
        }

        void drawBar(Bar* bar) {
            this->window->draw(*bar->getShape());
        }
        
        void eventHandler(void) {
            if (this->event.type == sf::Event::Closed) {
                this->window->close();
            } else if (this->event.type == sf::Event::KeyPressed) {
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                } else if (this->event.key.code == sf::Keyboard::Space) {
                    if (!this->start) {
                        this->start = true;
                    }
                }
            } else if (this->event.type == sf::Event::Resized) {
                this->width = this->event.size.width;
                this->height = this->event.size.height;
                this->window->setView(sf::View(sf::FloatRect(0, 0, this->width, this->height)));
            } else if (this->event.type == sf::Event::MouseButtonPressed) {
                if (this->event.mouseButton.button == sf::Mouse::Left) {
                } else if (this->event.mouseButton.button == sf::Mouse::Right) {
                }
            } else if (this->event.type == sf::Event::MouseButtonReleased) {
                if (this->event.mouseButton.button == sf::Mouse::Left) {
                } else if (this->event.mouseButton.button == sf::Mouse::Right) {
                }
            } else if (this->event.type == sf::Event::MouseMoved) {
            } else if (this->event.type == sf::Event::MouseWheelScrolled) {
                if (this->event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                } else if (this->event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
                }
            } else if (this->event.type == sf::Event::MouseWheelMoved) {
            } else if (this->event.type == sf::Event::MouseEntered) {
            } else if (this->event.type == sf::Event::MouseLeft) {
            }
        }

        Sorting<T>* sorting;
        bool start = false;
    
    protected:

    public:
        Window(void) : Window(800, 600, nullptr, 60) {
            std::cout << "Window()" << std::endl;
        }

        Window(size_t width, size_t height, Sorting<T>* liste, int speed) {
            std::cout << "Window(size_t, size_t, Sorting<T>)" << std::endl;
            this->width = width;
            this->height = height;
            this->speed = speed;
            this->window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), this->name);
            this->sorting = liste;
            this->bars = new Bars<T>(liste->getSize(), liste->getList(), this->width, this->height);
            this->window->setFramerateLimit(speed);
            this->music = new sf::Music();
            this->music->openFromFile(this->nameAudioFile);
            this->music->play();
        }

        ~Window(void) {
            std::cout << "~Window()" << std::endl;
            std::cout << this->bars->get() << std::endl;
            this->window->close();
            delete this->window;
            delete this->bars;
        }

        void schuffled(Sorting<T>* liste) {
            std::cout << "schuffled(Sorting<T>)\n-------------------" << std::endl;
            std::cout << this->bars->get() << std::endl;
            std::cout << "1" << std::endl;
            std::cout << liste->get() << std::endl;
            std::cout << "2" << std::endl;
            std::vector<std::vector<size_t>> blends = liste->getBlends();
            std::cout << "3" << std::endl;
            for (size_t i = 0; i < blends.size(); i++) {
                this->bars->switchTwoBars(blends[i][0], blends[i][1]);
            }
            std::cout << "4" << std::endl;
            std::cout << this->bars->get() << std::endl;
            std::cout << "---------------------" << std::endl;
        }

        bool isStart(void) {
            return this->start;
        }

        bool isOpen(void) {
            return this->window->isOpen();
        }

        void pollEvent(void) {
            while (this->window->pollEvent(this->event)) {
                this->eventHandler();
            }
        }

        void update(void) {
            this->clear();
            for (size_t i = 0; i < this->bars->getSize(); i++) {
                this->drawBar(this->bars->getBar(i));
            }
            this->display();
        }


        void update(size_t i, size_t j) {
            if (!this->start) {
                return;
            }
            this->bars->switchTwoBars(i, j);
            this->clear();
            for (size_t i = 0; i < this->bars->getSize(); i++) {
                this->drawBar(this->bars->getBar(i));
            }
            this->display();
        }

        void update(std::vector<std::vector<size_t>> switches) {
            for (size_t i = 0; i < switches.size(); i++) {
                this->update(switches[i][0], switches[i][1]);
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Window& window) {
            os << "Window: " << window.width << " x " << window.height << " px" << std::endl;
            return os;
        }
};