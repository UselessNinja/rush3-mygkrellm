/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/
#ifndef RUSH3_MEMORY_HPP
#define RUSH3_MEMORY_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <iterator>
#include "Memory.hpp"
#include "IMonitorModule.hpp"

class Memory : public IMonitorModule
{
    public:
    Memory();
    ~Memory() override;

    void setModule(bool) override;
    bool isEnable() override;
    bool refresh() override;

    float getMemoryUsed();
    float getSwapUsed();


    private:
    bool enable;
    std::map<std::string, int> data;
    float memTotal;
    float memFree;
    float swapTotal;
    float swapFree;
    float memUsed;
    float swapUsed;
};

#endif //RUSH3_MEMORY_HPP
