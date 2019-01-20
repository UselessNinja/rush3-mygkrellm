/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Os
*/

#include "Os.hpp"

Os::Os() : enable(true)
{
}

Os::~Os()
{
}

void Os::setModule(bool stat)
{
    enable = stat;
}

bool Os::isEnable()
{
    return (enable);
}

bool Os::refresh()
{
    struct utsname buffer;

    if (!this->enable)
        return false;
    if (uname(&buffer) != 0)
        return (false);
    std::string temp = buffer.sysname;
    temp += (char *)" ";
    temp += buffer.machine;
    setOs(temp);
    setKernel(buffer.release);
    return (true);
}

std::string Os::getOs() const
{
    return (_os);
}

std::string Os::getKernel() const
{
    return (_kernel);
}

void Os::setOs(std::string os)
{
    _os = os;
}

void Os::setKernel(std::string kernel)
{
    _kernel = kernel;
}