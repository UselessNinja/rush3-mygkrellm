/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Processor
*/

#include "Processor.hpp"

Processor::Processor() 
{
    _module = true;
}

Processor::~Processor() {}

void Processor::setModule(bool b)
{
    _module = b;
}

bool Processor::isEnable() {
    return _module;
}

bool Processor::refresh()
{
    std::string str_tmp;
    if (!this->_module)
        return false;
    std::ifstream inputFile;
    std::string name;
    std::string value;
    std::string line;

    inputFile.open("/proc/cpuinfo");
    if (!inputFile.is_open())
        return false;
    for (int i = 0; getline(inputFile, line); i++) {
        if (i == 0)
            _zProc["Name"] = &line[12];
        if (i == 3)
            _zProc["Model"] = &line[9];
        if (i == 4)
            _zProc["ModelName"] = &line[13];
        if (i == 7)
            _zProc["Frequency"] = &line[11];
        if (i == 12)
            _zProc["nbCore"] = &line[12];

        if (i == 27)
            _fProc["Name"] = &line[12];
        if (i == 30)
            _fProc["Model"] = &line[9];
        if (i == 31)
            _fProc["ModelName"] = &line[13];
        if (i == 34)
            _fProc["Frequency"] = &line[11];
        if (i == 39)
            _fProc["nbCore"] = &line[12];

        if (i == 54)
            _sProc["Name"] = &line[12];
        if (i == 57)
            _sProc["Model"] = &line[9];
        if (i == 58)
            _sProc["ModelName"] = &line[13];
        if (i == 61)
            _sProc["Frequency"] = &line[11];
        if (i == 66)
            _sProc["nbCore"] = &line[12];
        
        if (i == 81)
            _tProc["Name"] = &line[12];
        if (i == 84)
            _tProc["Model"] = &line[9];
        if (i == 85)
            _tProc["ModelName"] = &line[13];
        if (i == 88)
            _tProc["Frequency"] = &line[11];
        if (i == 93)
            _tProc["nbCore"] = &line[12];
    }
    inputFile.close();
    return true;
}

std::map<std::string, std::string> Processor::getZMap() const
{
    return _zProc;
}

std::map<std::string, std::string> Processor::getFMap() const
{
    return _fProc;
}

std::map<std::string, std::string> Processor::getSMap() const
{
    return _sProc;
}

std::map<std::string, std::string> Processor::getTMap() const
{
    return _tProc;
}