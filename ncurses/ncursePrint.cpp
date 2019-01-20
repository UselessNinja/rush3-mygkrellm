/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ncursePrint
*/

#include "ncurses.hpp"

void printUser(MonitorDisplay &moni)
{
    WINDOW *Cwindow;
	Cwindow = subwin(stdscr, 7, 50, 1, 4);
	if (moni.getModUser()->isEnable()) {
		box(Cwindow, ACS_VLINE, ACS_HLINE);
        wattron(Cwindow, A_BOLD);
		mvwprintw(Cwindow, 2, 20," %s", moni.getModUser()->getUserName().c_str(), moni.getModUser()->getHostName().c_str());
		mvwprintw(Cwindow, 4, 14," %s", moni.getModUser()->getHostName().c_str());	
        wattroff(Cwindow, A_BOLD);
		wrefresh(Cwindow);
	} else {
		wbkgd(Cwindow, COLOR_PAIR(2));
		wrefresh(Cwindow);
	}
}

void printDate(MonitorDisplay &moni)
{
    WINDOW *Cwindow;
	Cwindow = subwin(stdscr, 5, 50, 8, 4);
	start_color();
	if (moni.getTime()->isEnable() == true) {
		box(Cwindow, ACS_VLINE, ACS_HLINE);
		mvwprintw(Cwindow, 2, 12," %s",  moni.getTime()->getTime().c_str());
		wrefresh(Cwindow);
	} else {
		wbkgd(Cwindow, COLOR_PAIR(2));
		wrefresh(Cwindow);
	}
}

void printOs(MonitorDisplay &moni)
{
    WINDOW *Cwindow;
	Cwindow = subwin(stdscr, 7, 50, 13, 4);
	start_color();
	if (moni.getOsMod()->isEnable() == true) {
		box(Cwindow, ACS_VLINE, ACS_HLINE);
		mvwprintw(Cwindow, 2, 18," %s",  moni.getOsMod()->getOs().c_str());
		mvwprintw(Cwindow, 4, 13," %s",  moni.getOsMod()->getKernel().c_str());
		wrefresh(Cwindow);
	}  else {
		wbkgd(Cwindow, COLOR_PAIR(2));
		wrefresh(Cwindow);
	}
}

void printCpu(MonitorDisplay &moni)
{
    WINDOW *Cwindow;
    int j;
    bool over = false;
    Cwindow = subwin(stdscr, 20, 50, 20, 4);

	if (moni.getCPU()->isEnable() == true) {
	    int value = std::stoi(moni.getCPU()->getZMap()["Frequency"]);
        int size = (value * 100) / 2700;
		box(Cwindow, ACS_VLINE, ACS_HLINE);
		mvwprintw(Cwindow, 2, 4," %s ",   moni.getCPU()->getZMap()["ModelName"].c_str());
		std::string temp = (std::atof(moni.getCPU()->getZMap()["Frequency"].c_str()) < 1000) ? (" " + moni.getCPU()->getZMap()["Frequency"]) : moni.getCPU()->getZMap()["Frequency"];
	    mvwprintw(Cwindow, 4, 4,"CPU %s [",   moni.getCPU()->getZMap()["Name"].c_str());
        for (j = 0; j < size / 5; j++)
            if (j > 19)
                over = true;
        if (over) {
            wattron(Cwindow, COLOR_PAIR(10));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "#");
            wattroff(Cwindow, COLOR_PAIR(10));
        } else {
            wattron(Cwindow, COLOR_PAIR(11));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "=");
            wattroff(Cwindow, COLOR_PAIR(11));
        }
        for (int k = j; k < 20; k++)
                waddstr(Cwindow, " ");
        waddstr(Cwindow, "]");
        mvwprintw(Cwindow, 4, 33,"%03d%%", size);
		mvwprintw(Cwindow, 6, 10,"Core: %s", moni.getCPU()->getZMap()["Name"].c_str());
	    mvwprintw(Cwindow, 8, 4,"CPU %s [",   moni.getCPU()->getFMap()["Name"].c_str());
        value = std::stoi(moni.getCPU()->getFMap()["Frequency"]);
        size = (value * 100) / 2700;
        for (j = 0; j < size / 5; j++)
            if (j > 19)
                over = true;
        if (over) {
            wattron(Cwindow, COLOR_PAIR(10));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "#");
            wattroff(Cwindow, COLOR_PAIR(10));
        } else {
            wattron(Cwindow, COLOR_PAIR(11));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "=");
            wattroff(Cwindow, COLOR_PAIR(11));
        }
        for (int k = j; k < 20; k++)
                waddstr(Cwindow, " ");
        waddstr(Cwindow, "]");
        mvwprintw(Cwindow, 8, 33,"%03d%%", size);
		mvwprintw(Cwindow, 6, 25," %s MHZ", temp.c_str());
        temp = (std::atof(moni.getCPU()->getFMap()["Frequency"].c_str()) < 1000) ? (" " + moni.getCPU()->getFMap()["Frequency"]) : moni.getCPU()->getFMap()["Frequency"];
		mvwprintw(Cwindow, 10, 10,"Core: %s", moni.getCPU()->getFMap()["nbCore"].c_str());
		mvwprintw(Cwindow, 10, 25," %s MHZ", temp.c_str());
		temp = (std::atof(moni.getCPU()->getSMap()["Frequency"].c_str()) < 1000) ? (" " + moni.getCPU()->getSMap()["Frequency"]) : moni.getCPU()->getSMap()["Frequency"];
	    mvwprintw(Cwindow, 12, 4,"CPU %s [",   moni.getCPU()->getSMap()["Name"].c_str());
        value = std::stoi(moni.getCPU()->getSMap()["Frequency"]);
        size = (value * 100) / 2700;
        for (j = 0; j < size / 5; j++)
            if (j > 19)
                over = true;
        if (over) {
            wattron(Cwindow, COLOR_PAIR(10));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "#");
            wattroff(Cwindow, COLOR_PAIR(10));
        } else {
            wattron(Cwindow, COLOR_PAIR(11));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "=");
            wattroff(Cwindow, COLOR_PAIR(11));
        }
        for (int k = j; k < 20; k++)
                waddstr(Cwindow, " ");
        waddstr(Cwindow, "]");
        mvwprintw(Cwindow, 12, 33,"%03d%%", size);
		mvwprintw(Cwindow, 14, 10,"Core: %s", moni.getCPU()->getSMap()["nbCore"].c_str());
		mvwprintw(Cwindow, 14, 25," %s MHZ", temp.c_str());
        temp = (std::atof(moni.getCPU()->getTMap()["Frequency"].c_str()) < 1000) ? (" " + moni.getCPU()->getTMap()["Frequency"]) : moni.getCPU()->getTMap()["Frequency"];
		mvwprintw(Cwindow, 16, 4,"CPU %s [",   moni.getCPU()->getTMap()["Name"].c_str());
        value = std::stoi(moni.getCPU()->getTMap()["Frequency"]);
        size = (value * 100) / 2700;
        for (j = 0; j < size / 5; j++)
            if (j > 19)
                over = true;
        if (over) {
            wattron(Cwindow, COLOR_PAIR(10));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "#");
            wattroff(Cwindow, COLOR_PAIR(10));
        } else {
            wattron(Cwindow, COLOR_PAIR(11));
            for (j = 0; j < size / 5; j++)
                if (j < 20)
                    waddstr(Cwindow, "=");
            wattroff(Cwindow, COLOR_PAIR(11));
        }
        for (int k = j; k < 20; k++)
                waddstr(Cwindow, " ");
        waddstr(Cwindow, "]");
        mvwprintw(Cwindow, 16, 33,"%03d%%", size);
		mvwprintw(Cwindow, 18, 10,"Core: %s", moni.getCPU()->getTMap()["nbCore"].c_str());
		mvwprintw(Cwindow, 18, 25," %s MHZ", temp.c_str());
		wrefresh(Cwindow);
	} else {
		wbkgd(Cwindow, COLOR_PAIR(2));
		wrefresh(Cwindow);
	}
}

void printRam(MonitorDisplay &moni)
{
    WINDOW *Cwindow;
    int j;
	Cwindow = subwin(stdscr, 7, 50, 40, 4);

	if (moni.getModMemory()->isEnable() == true) {
		box(Cwindow, ACS_VLINE, ACS_HLINE);
		start_color();
    	std::stringstream tmp;
    	tmp << std::fixed << std::setprecision(4) << moni.getModMemory()->getMemoryUsed();
		mvwprintw(Cwindow, 2, 4,"RAM: %s%% [", tmp.str().c_str());
        wattron(Cwindow, COLOR_PAIR(11));
    	for (j = 0; j < (atoi(tmp.str().c_str()) / 4); j++)
			waddstr(Cwindow, "=");
		for (int k = j; k < 25; k++)
			waddstr(Cwindow, " ");
        wattroff(Cwindow, COLOR_PAIR(11));
    	waddstr(Cwindow, "]");
    	std::stringstream temp;
    	temp << std::fixed << std::setprecision(4) << moni.getModMemory()->getSwapUsed();
		mvwprintw(Cwindow, 4, 4,"SWP: %s%% [", temp.str().c_str());
        wattron(Cwindow, COLOR_PAIR(11));
		for (j = 0; j < (atoi(temp.str().c_str())/4); j++)
			waddstr(Cwindow, "=");
		for (int k = j; k < 25; k++)
			waddstr(Cwindow, " ");
        wattroff(Cwindow, COLOR_PAIR(11));
    	waddstr(Cwindow, "]");
		wrefresh(Cwindow);
	} else {
		wbkgd(Cwindow, COLOR_PAIR(2));
		wrefresh(Cwindow);
	}
}

void printHelp()
{
    WINDOW *Cwindow;
	start_color();
	Cwindow = subwin(stdscr, 15, 30, 15, 60);
	box(Cwindow, ACS_VLINE, ACS_HLINE);
	mvwprintw(Cwindow, 2, 4, "%s", "Hide User data:\t'u'");
	mvwprintw(Cwindow, 4, 4, "%s", "Hide Time:\t\t'd'");
	mvwprintw(Cwindow, 6, 4, "%s", "Hide Os data:\t'o'");
	mvwprintw(Cwindow, 8, 4, "%s", "Hide CPU data:\t'c'");
	mvwprintw(Cwindow, 10, 4, "%s", "Hide RAM data:\t'r'");
	mvwprintw(Cwindow, 12, 4, "%s", "Hide Network data:\t'n'");
	wrefresh(Cwindow);
}

void printNetwork(MonitorDisplay &moni)
{
    WINDOW *Cwindow;
    Cwindow = subwin(stdscr, 7, 50, 47, 4);

    if (moni.getModNetwork()->isEnable() == true) {
        int up = moni.getModNetwork()->getUp() / 1048576;
        box(Cwindow, ACS_VLINE, ACS_HLINE);
        start_color();
        mvwprintw(Cwindow, 2, 4,"UPLOAD: %d MB/s", up);
        up = moni.getModNetwork()->getDown() / 1048576;
        mvwprintw(Cwindow, 4, 4,"DOWNLOAD: %d MB/s", up);
	    wrefresh(Cwindow);
    } else {
        wbkgd(Cwindow, COLOR_PAIR(2));
		wrefresh(Cwindow);
    }
}