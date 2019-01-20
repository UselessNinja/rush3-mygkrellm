/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** main
*/

#include <iostream>
#include "IMonitorModule.hpp"
#include "modules/Memory.hpp"
#include "core/MonitorDisplay.hpp"
#include "core/core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "./MyGKrellm [-g][-n][-help]\n\t-g :\tdisplay in graphical mode\n\t-n : \tdisplay in text mode\n\t-help : \tdisplay help\n";
        return (84);
    }
    std::string re = std::string(av[1]);
    core(re);
    return (0);
}