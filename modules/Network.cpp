/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Network
*/

#include "Network.hpp"

Network::Network() : enable(true), _up(0), _down(0)
{
}

Network::~Network()
{
}

void Network::setDown(int down)
{
    _down = down;
}

void Network::setUp(int up)
{
    _up = up;
}

int Network::getDown() const
{
    return (_down);
}

int Network::getUp() const
{
    return (_up);
}

bool Network::refresh()
{
    int i = 0;
    int a = 0;
    std::string tmp;
    std::string line;
    std::ifstream file("/proc/net/dev", std::ios::in);

    if (!this->enable)
        return false;

    while (std::getline(file, line)) {
        if ((a = line.find(":")) != -1) {
            a++;
            for (;line[a] == ' '; a++);
            for (;line[a] != ' '; a++)
                tmp += line[a];
            if (std::stoi(tmp) > 0) {
                _up = (stoi(tmp));
                tmp.erase();
                for (; i != 7; i++) {
                    for (; line[a] == ' '; a++);
                    for (; line[a] != ' '; a++);
                }
                i = 0;
                for (; line[a] == ' '; a++);
                for (; line[a] != ' '; a++)
                    tmp += line[a];
                _down = (std::stoi(tmp));
            }
        }
        tmp.erase();
    }
    file.close();
    return (true);
}

bool Network::isEnable()
{
    return (enable);
}

void Network::setModule(bool stat)
{
    enable = stat;
}
