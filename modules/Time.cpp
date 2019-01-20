/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Time
*/

#include <ctime>
#include <chrono>
#include "Time.hpp"

Time::Time() : _enable(true)
{
}

Time::~Time()
{
}

void Time::setTime(std::string times)
{
    _time = times;
}

std::string Time::getTime() const
{
    return (_time);
}

bool Time::refresh()
{
    if (!this->_enable)
        return false;
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);
    std::string timetemp = std::ctime(&timeNow);
    timetemp.erase(std::remove(timetemp.begin(), timetemp.end(), '\n'), timetemp.end());
    this->setTime(timetemp);
    return (true);
}

bool Time::isEnable()
{
    return (_enable);
}

void Time::setModule(bool stat)
{
    _enable = stat;
}
