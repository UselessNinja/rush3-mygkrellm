/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include "IMonitorModule.hpp"

class Time : public IMonitorModule {
	public:
		Time();
		~Time() override;
        void setModule(bool) override;
        bool isEnable() override;
        bool refresh() override;
        void setTime(std::string time);
        std::string getTime(void) const;

	protected:
	private:
        std::string _time;
        bool _enable;
};

#endif /* !TIME_HPP_ */
