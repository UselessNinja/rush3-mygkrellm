/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include "mySFML.hpp"

mySFML::mySFML() : window(sf::VideoMode(1000, 800), "Kreog")
{
    this->font.loadFromFile("sfml/font.ttf");
    this->text.setFont(this->font);
}

mySFML::~mySFML()
{

}