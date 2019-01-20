/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#ifndef CPP_RUSH3_2018_MY_SFML_HPP
#define CPP_RUSH3_2018_MY_SFML_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <SFML/Graphics.hpp>

class mySFML
{
    public:
    mySFML();
    ~mySFML();

    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;
    sf::Time time;
    sf::Font font;
    sf::Text text;
    int **GraphRam;

    private:
};

#endif //CPP_RUSH3_2018_MY_SFML_HPP
