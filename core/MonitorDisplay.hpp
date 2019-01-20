/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#ifndef CPP_RUSH3_2018_MONITORDISPLAY_HPP
#define CPP_RUSH3_2018_MONITORDISPLAY_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../IMonitorDisplay.hpp"
#include "../modules/Memory.hpp"
#include "../IMonitorModule.hpp"

enum enumLibGraph{
    SFML,
    NCURSES,
    OTHER
};

class MonitorDisplay : public IMonitorDisplay {

    public:
    MonitorDisplay();
    MonitorDisplay(enumLibGraph);
    ~MonitorDisplay() override;

    void setModMemory(Memory &mod) override;
    Memory *getModMemory() override;

    void setModNetwork(Network &mod) override;
    Network *getModNetwork() override;

    void setModUser(User &mod) override;
    User *getModUser() override;

    void setCPU(Processor &mod) override;
    Processor *getCPU() override;

    void setTime(Time &mod) override;
    Time *getTime() override;

    void setOs(Os &mod) override;
    Os *getOsMod() override;

    enumLibGraph getLibGraph() const;

    private:
    enumLibGraph libGraph;
    Memory *modMemory;
    Network *modNet;
    User *modUser;
    Processor *CPU;
    Time *modTime;
    Os *modOs;
};


#endif //CPP_RUSH3_2018_MONITORDISPLAY_HPP
