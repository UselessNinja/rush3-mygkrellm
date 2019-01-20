/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Processor
*/

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <iterator>
#include "IMonitorModule.hpp"

class Processor : public IMonitorModule
{
    public:
    Processor();
    ~Processor() override;
    void setModule(bool) override;
	bool isEnable() override;
	bool refresh() override;
    std::map<std::string, std::string> getZMap() const;
    std::map<std::string, std::string> getFMap() const;
    std::map<std::string, std::string> getSMap() const;
    std::map<std::string, std::string> getTMap() const;

    private:
    bool _module;
    std::map<std::string, std::string> _zProc;
    std::map<std::string, std::string> _fProc;
    std::map<std::string, std::string> _sProc;
    std::map<std::string, std::string> _tProc;
};

#endif
