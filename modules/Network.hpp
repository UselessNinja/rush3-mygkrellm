/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <string>
#include <fstream>
#include <iostream>
#include "Network.hpp"
#include "IMonitorModule.hpp"

class Network : public IMonitorModule {
	public:
		Network();
		~Network() override;

                void setModule(bool) override;
                bool isEnable() override;
                bool refresh() override;

                void setUp(int up);
                void setDown(int down);
                int getUp() const;
                int getDown() const;

	protected:
	private:
                bool enable;
                int _up;
                int _down;
};

#endif /* !NETWORK_HPP_ */
