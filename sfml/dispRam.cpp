/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include <SFML/Graphics.hpp>
#include "../core/MonitorDisplay.hpp"
#include "mySFML.hpp"

void drawGraphRam(float value, mySFML *mySFML)
{
    float size = (value * 300) / 100;
    sf::RectangleShape rectangle(sf::Vector2f(size, 50.f));
    sf::RectangleShape rectangle2(sf::Vector2f(310.f, 70.f));
    rectangle.setFillColor(sf::Color(0, 250, 0));
    rectangle2.setFillColor(sf::Color(60, 60, 60));
    rectangle.setPosition(50.f, 180.f);
    rectangle2.setPosition(40.f, 170.f);

    mySFML->window.draw(rectangle2);
    mySFML->window.draw(rectangle);
}

void dispModRam(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    if (!monitorDisplay.getModMemory()->isEnable())
        return;
    mySFML->text.setString("MEMORY");
    mySFML->text.setCharacterSize(25);
    mySFML->text.setFillColor(sf::Color::White);
    mySFML->text.setPosition(150.f, 80.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setCharacterSize(20);
    mySFML->text.setPosition(150.f, 120.f);
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << monitorDisplay.getModMemory()
    ->getMemoryUsed();
    std::string memUsed = ss.str();
    mySFML->text.setString(memUsed + " %");
    mySFML->window.draw(mySFML->text);
    drawGraphRam(monitorDisplay.getModMemory()->getMemoryUsed(), mySFML);
}


