/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include <SFML/Graphics.hpp>
#include <zconf.h>
#include "../core/MonitorDisplay.hpp"
#include "sfml.hpp"
#include "mySFML.hpp"

void refreshAllMod(MonitorDisplay &monitorDisplay)
{
    monitorDisplay.getModMemory()->refresh();
    monitorDisplay.getModNetwork()->refresh();
    monitorDisplay.getOsMod()->refresh();
    monitorDisplay.getCPU()->refresh();
    monitorDisplay.getTime()->refresh();
    monitorDisplay.getModUser()->refresh();
}

void displaySFML(MonitorDisplay &monitor)
{
    mySFML *dispWindow = new mySFML();

    sf::Clock clock2;
    sf::Time time;

    refreshAllMod(monitor);
    dispWindow->window.setFramerateLimit(30);
    while (dispWindow->window.isOpen())
    {
        while (dispWindow->window.pollEvent(dispWindow->event))
        {
            if (dispWindow->event.type == sf::Event::Closed)
                dispWindow->window.close();
            if (dispWindow->event.type == sf::Event::KeyReleased) {
                if (dispWindow->event.key.code == sf::Keyboard::C) {
                    if (monitor.getCPU()->isEnable())
                        monitor.getCPU()->setModule(false);
                    else if (monitor.getCPU()->isEnable() == false)
                        monitor.getCPU()->setModule(true);
                }
                if (dispWindow->event.key.code == sf::Keyboard::M) {
                    if (monitor.getModMemory()->isEnable())
                        monitor.getModMemory()->setModule(false);
                    else if (monitor.getModMemory()->isEnable() == false)
                        monitor.getModMemory()->setModule(true);
                }
                if (dispWindow->event.key.code == sf::Keyboard::N) {
                    if (monitor.getModNetwork()->isEnable())
                        monitor.getModNetwork()->setModule(false);
                    else if (monitor.getModNetwork()->isEnable() == false)
                        monitor.getModNetwork()->setModule(true);
                }
            }
        }
        dispWindow->window.clear(sf::Color(50, 50, 50));
        time = clock2.getElapsedTime();
        if (time.asSeconds() >= 1) {
            refreshAllMod(monitor);
            clock2.restart();
        }
        drawShap(dispWindow);
        dispModUser(monitor, dispWindow);
        dispModTime(monitor, dispWindow);
        dispModOS(monitor, dispWindow);
        dispModRam(monitor, dispWindow);
        dispModNetwork(monitor, dispWindow);
        DispModCPU(monitor, dispWindow);
        dispWindow->window.display();
    }
}
