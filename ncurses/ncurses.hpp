/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <cstring>
#include <iostream>
#include "../core/MonitorDisplay.hpp"

class Curse {
    public:
        Curse() : _row(0), _column(0) {};
        ~Curse() {}; 
        int _row;
        int _column;
};

void printUser(MonitorDisplay &moni);
void printDate(MonitorDisplay &moni);
void printOs(MonitorDisplay &moni);
void textDisplay(MonitorDisplay &mino);
void printCpu(MonitorDisplay &moni);
void printRam(MonitorDisplay &moni);
void getInput(char , MonitorDisplay &);
void refreshAll(MonitorDisplay &);
void printHelp(void);
void printNetwork(MonitorDisplay &moni);


#endif /* !NCURSES_HPP_ */
