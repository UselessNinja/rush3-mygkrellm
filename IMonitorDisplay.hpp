/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "IMonitorModule.hpp"
#include "modules/Memory.hpp"
#include "modules/Network.hpp"
#include "modules/User.hpp"
#include "modules/Processor.hpp"
#include "modules/Time.hpp"
#include "modules/Os.hpp"

class IMonitorDisplay {
	public:
		virtual ~IMonitorDisplay() = default;

		virtual void setModMemory(Memory &mod) = 0;
		virtual Memory *getModMemory() = 0;

		virtual void setModNetwork(Network &mod) = 0;
		virtual Network *getModNetwork() = 0;

		virtual void setModUser(User &mod) = 0;
		virtual User *getModUser() = 0;

		virtual void setCPU(Processor &mod) = 0;
		virtual Processor *getCPU() = 0;

		virtual void setTime(Time &mod) = 0;
		virtual Time *getTime() = 0;

		virtual void setOs(Os &mod) = 0;
		virtual Os *getOsMod() = 0;
	protected:
	private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
