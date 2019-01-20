/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#ifndef CPP_RUSH3_2018_SFML_HPP
#define CPP_RUSH3_2018_SFML_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "mySFML.hpp"

void displaySFML(MonitorDisplay &monitor);

void drawShap(mySFML *mySFML);
void dispModNetwork(MonitorDisplay &monitorDisplay, mySFML *mySFML);
void dispModUser(MonitorDisplay &monitorDisplay, mySFML *mySFML);
void dispModTime(MonitorDisplay &monitorDisplay, mySFML *mySFML);
void dispModOS(MonitorDisplay &monitorDisplay, mySFML *mySFML);
void DispModCPU(MonitorDisplay &monitorDisplay, mySFML *mySFML);

void dispModRam(MonitorDisplay &monitorDisplay, mySFML *mySFML);


#endif //CPP_RUSH3_2018_SFML_HPP
