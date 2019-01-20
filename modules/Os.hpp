/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** Os
*/

#ifndef OS_HPP_
#define OS_HPP_

#include "IMonitorModule.hpp"
#include <cstring>
#include <fstream>
#include <sys/utsname.h>

class Os : public IMonitorModule {
	public:
		Os();
		~Os() override;
        void setModule(bool) override;
        bool isEnable() override;
        bool refresh() override;
        std::string getOs(void) const;
        std::string getKernel(void) const;
        void setOs(std::string os);
        void setKernel(std::string kernel);
    protected:
	private:
        bool enable;
        std::string _kernel;
        std::string _os;
};

#endif /* !OS_HPP_ */
