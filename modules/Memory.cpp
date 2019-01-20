/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include "Memory.hpp"
#include <iterator>
#include <cmath>

Memory::Memory() : enable(true)
{
}

Memory::~Memory()
{
}

bool Memory::refresh()
{
    std::string str_tmp;

    if (!this->enable) {
        return false;
    }
    std::ifstream inputFile;
    std::string name;
    int value;
    std::string line;

    inputFile.open("/proc/meminfo");
    if (!inputFile.is_open())
        return false;
    while (std::getline(inputFile, line)) {
        std::stringstream(line) >> name >> value;
        this->data[name.substr(0, name.length() - 1)] = value;
    }
    this->memTotal = static_cast<float>(this->data["MemTotal"]);
    this->memFree = static_cast<float>(this->data["MemAvailable"]);
    this->swapTotal = static_cast<float>(this->data["SwapTotal"]);
    this->swapFree = static_cast<float>(this->data["SwapFree"]);
    this->memUsed = ((this->memTotal - this->memFree) * 100) / this->memTotal;
    this->swapUsed = (this->swapTotal - this->swapFree) * 100 / this->swapTotal;
    inputFile.close();
    return true;
}


bool Memory::isEnable()
{
    return (this->enable);
}

void Memory::setModule(bool status)
{
    this->enable = status;
}

float Memory::getMemoryUsed()
{
    return memUsed;
}

float Memory::getSwapUsed()
{
    return swapUsed;
}