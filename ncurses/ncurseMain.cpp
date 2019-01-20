/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ncurseMain
*/

#include <ncurses.h>
#include <cstring>
#include <iostream>
#include "../core/MonitorDisplay.hpp"
#include "../IMonitorDisplay.hpp"
#include "../core/core.hpp"
#include "ncurses.hpp"

void refreshAll(MonitorDisplay &moni)
{
    moni.getModMemory()->refresh();
    moni.getModNetwork()->refresh();
    moni.getCPU()->refresh();
    moni.getModUser()->refresh();
    moni.getTime()->refresh();
    moni.getOsMod()->refresh();
}

void printModulo(MonitorDisplay &moni)
{
    Curse *data = new Curse();  
    int c;

    c = getch();
    getInput(c, moni);
    getmaxyx(stdscr, data->_row, data->_column);
    printUser(moni);
    printDate(moni);
    printOs(moni);
    printCpu(moni);
    printRam(moni);
    printNetwork(moni);
    printHelp();
}

void getInput(char c, MonitorDisplay &moni)
{
    c = getch();
    if (c == 117) { //User
        if (moni.getModUser()->isEnable()) {
            moni.getModUser()->setModule(false);
        } else if (!moni.getModUser()->isEnable())
            moni.getModUser()->setModule(true);
    }
    if (c == 100) { //Date
        if (moni.getTime()->isEnable() == true)
            moni.getTime()->setModule(false);
        else
            moni.getTime()->setModule(true);
    }
    if (c == 111) { //Os
        if (moni.getOsMod()->isEnable() == true)
            moni.getOsMod()->setModule(false);
        else
            moni.getOsMod()->setModule(true);
    }
    if (c == 99) { //Cpu
        if (moni.getCPU()->isEnable() == true)
            moni.getCPU()->setModule(false);
        else
            moni.getCPU()->setModule(true);
    }
    if (c == 114) { //Ram
        if (moni.getModMemory()->isEnable() == true)
            moni.getModMemory()->setModule(false);
        else
            moni.getModMemory()->setModule(true);
    }
    if (c == 110) { //Network
        if (moni.getModNetwork()->isEnable() == true)
            moni.getModNetwork()->setModule(false);
        else
            moni.getModNetwork()->setModule(true);
    }
}

void textDisplay(MonitorDisplay &moni)
{
    initscr();
    noecho();
    cbreak();
    timeout(400);
    curs_set(0);
    start_color();
    keypad(stdscr, 1);
    use_default_colors();
    init_pair(10, COLOR_RED, -1);
    init_pair(11, COLOR_GREEN, -1);
    while (1) {
        refreshAll(moni);
        printModulo(moni);
        napms(200);
        refresh();
    }
    curs_set(1);
    nocbreak();
    endwin();
}