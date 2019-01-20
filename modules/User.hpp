/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** User
*/

#ifndef USER_HPP_
#define USER_HPP_

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sys/utsname.h>
#include <stdio.h>
#include "IMonitorModule.hpp"

class User : public IMonitorModule {
    public:
        User(void);
        ~User(void) override;

        void setModule(bool) override;
        bool isEnable(void) override;
        bool refresh(void) override;

        std::string getUserName(void) const;
        std::string getHostName(void) const;
        void setUserName(std::string userName);
        void setHostName(std::string userName);

    private:
        std::string _userName;
        std::string _hostName;
        bool _enable;
};


#endif /* !USER_HPP_ */
