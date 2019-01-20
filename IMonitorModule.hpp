/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

class IMonitorModule {
	public:
	virtual ~IMonitorModule() = default;;

	virtual void setModule(bool) = 0;
	virtual bool isEnable() = 0;
	virtual bool refresh() = 0;

	protected:
	private:
};

#endif /* !IMONITORMODULE_HPP_ */
