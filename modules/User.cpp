/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** file_to_open description:
** User
*/

#include "User.hpp"
#include <iostream>

User::User()
{
    this->_enable = true;
}

User::~User()
{
    this->_enable = false;
}

bool User::isEnable()
{
    return (this->_enable);
}

void User::setModule(bool status)
{
    this->_enable = status;
}

void User::setUserName(std::string userName)
{
    _userName = userName;
}

void User::setHostName(std::string hostName)
{
    _hostName = hostName;
}

std::string User::getUserName() const
{
    return (_userName);
}

std::string User::getHostName() const
{
    return (_hostName);
}

bool User::refresh(void)
{
    if (!this->_enable)
        return (false);
    const char *env_var[2] = {"USER", "HOSTNAME"};
    char *env_val[2];
    for (int i = 0; i < 2; ++i) {
        env_val[i] = getenv(env_var[i]);
        if (env_val[i] == NULL)
            env_val[i] = (char *)"ERROR";
    } 
    setUserName(env_val[0]);
    setHostName(env_val[1]);
    return (true);
}