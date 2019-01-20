/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include "MonitorDisplay.hpp"

MonitorDisplay::MonitorDisplay(enumLibGraph Graph) : libGraph(Graph)
{

}

MonitorDisplay::~MonitorDisplay()
{

}

void MonitorDisplay::setModMemory(Memory &mod)
{
    this->modMemory = &mod;
}

Memory* MonitorDisplay::getModMemory()
{
    return this->modMemory;
}

MonitorDisplay::MonitorDisplay() : libGraph(NCURSES)
{

}

void MonitorDisplay::setModNetwork(Network &mod)
{
    this->modNet = &mod;
}

Network* MonitorDisplay::getModNetwork()
{
    return this->modNet;
}

enumLibGraph MonitorDisplay::getLibGraph() const {
    return libGraph;
}

void MonitorDisplay::setModUser(User &mod)
{
    this->modUser = &mod;
}

User *MonitorDisplay::getModUser()
{
    return this->modUser;
}

void MonitorDisplay::setCPU(Processor &mod)
{
    this->CPU = &mod;
}

Processor *MonitorDisplay::getCPU()
{
    return this->CPU;
}

void MonitorDisplay::setTime(Time &mod)
{
    this->modTime = &mod;
}

Time *MonitorDisplay::getTime() {
    return this->modTime;
}

void MonitorDisplay::setOs(Os &mod)
{
    this->modOs = &mod;
}

Os *MonitorDisplay::getOsMod()
{
    return this->modOs;
}

