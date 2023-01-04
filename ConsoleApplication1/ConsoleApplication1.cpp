// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SFML/graphics.hpp"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "VisualDSA");
    window.setFramerateLimit(60);
    sf::Event event;

    sf::RectangleShape rect;
    sf::Vector2f rectPosition(400, 300);
    rect.setPosition(rectPosition);
    rect.setSize(sf::Vector2f(30, 30));

    float xVelocity = 3;
    float yVelocity = 3;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        // Physics
        if (rectPosition.x < 0 || rectPosition.x > 800 - 100) {
            xVelocity *= -1;
        }
        if (rectPosition.y < 0 || rectPosition.y > 600 - 100) {
            yVelocity *= -1;
        }
        rectPosition.x += xVelocity;
        rectPosition.y += yVelocity;
        rect.setPosition(rectPosition);

        // Render
        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}
