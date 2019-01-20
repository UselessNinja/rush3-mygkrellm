/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include "../modules/Memory.hpp"
#include "../IMonitorModule.hpp"
#include "../IMonitorDisplay.hpp"
#include "MonitorDisplay.hpp"
#include "../modules/Network.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include "../ncurses/ncurses.hpp"
#include "../modules/Processor.hpp"
#include "../sfml/sfml.hpp"
#include <map>
#include "../modules/Os.hpp"

MonitorDisplay *initModule(std::string s)
{
    MonitorDisplay *monitorDisplay;
    Memory *memory = new Memory();
    Network *net = new Network();
    User *user = new User();
    Processor *CPU = new Processor();
    Time *modTime = new Time();
    Os *modOs = new Os();

    if (s == "-n") {
        monitorDisplay = new MonitorDisplay(NCURSES);
    } else if (s == "-g"){
        monitorDisplay = new MonitorDisplay(SFML);
    } else if (s == "-help") {
        std::cout << "./MyGKrellm [-g][-n][-help]\n\t-g :\tdisplay in graphical mode\n\t-n : \tdisplay in text mode\n\t-help : \tdisplay help\n";
        monitorDisplay = new MonitorDisplay(OTHER);
    } else
        monitorDisplay = new MonitorDisplay(OTHER);
    monitorDisplay->setModMemory(*memory);
    monitorDisplay->setModNetwork(*net);
    monitorDisplay->setModUser(*user);
    monitorDisplay->setCPU(*CPU);
    monitorDisplay->setTime(*modTime);
    monitorDisplay->setOs(*modOs);
    return (monitorDisplay);
}

void core(std::string s)
{
    MonitorDisplay *modDisplay = initModule(s);

    if (modDisplay->getLibGraph() == NCURSES) {
        textDisplay(*modDisplay);
    } else if (modDisplay->getLibGraph() == SFML) {
        displaySFML(*modDisplay);
    } else {
        return;
    }
}