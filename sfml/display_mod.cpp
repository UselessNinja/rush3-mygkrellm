/*
** EPITECH PROJECT, 2018
** project
** File description:
** definition
*/

#include <SFML/Graphics.hpp>
#include "../core/MonitorDisplay.hpp"
#include "mySFML.hpp"

void drawShap(mySFML *mySFML)
{
    sf::RectangleShape rectangle(sf::Vector2f(1000.f, 80.f));
    sf::RectangleShape rectangle2(sf::Vector2f(500.f, 200.f));
    sf::RectangleShape rectangle3(sf::Vector2f(500.f, 200.f));
    sf::RectangleShape rectangle4(sf::Vector2f(1000.f, 620.f));
    sf::RectangleShape rectangle5(sf::Vector2f(500.f, 257.f));
    sf::RectangleShape rectangle6(sf::Vector2f(500.f, 257.f));
    sf::RectangleShape rectangle7(sf::Vector2f(500.f, 260.f));
    sf::RectangleShape rectangle8(sf::Vector2f(500.f, 260.f));

    rectangle.setFillColor(sf::Color(50, 50, 50));
    rectangle2.setFillColor(sf::Color(50, 50, 50));
    rectangle3.setFillColor(sf::Color(50, 50, 50));
    rectangle4.setFillColor(sf::Color(50, 50, 50));
    rectangle5.setFillColor(sf::Color(50, 50, 50));
    rectangle6.setFillColor(sf::Color(50, 50, 50));
    rectangle7.setFillColor(sf::Color(50, 50, 50));
    rectangle8.setFillColor(sf::Color(50, 50, 50));

    rectangle.setOutlineThickness(-3);
    rectangle2.setOutlineThickness(-3);
    rectangle3.setOutlineThickness(-3);
    rectangle4.setOutlineThickness(-3);
    rectangle5.setOutlineThickness(-1);
    rectangle6.setOutlineThickness(-1);
    rectangle7.setOutlineThickness(-1);
    rectangle8.setOutlineThickness(-1);

    rectangle.setOutlineColor(sf::Color(200, 200, 200));
    rectangle2.setOutlineColor(sf::Color(200, 200, 200));
    rectangle3.setOutlineColor(sf::Color(200, 200, 200));
    rectangle4.setOutlineColor(sf::Color(200, 200, 200));
    rectangle5.setOutlineColor(sf::Color(250, 0, 0));
    rectangle6.setOutlineColor(sf::Color(0, 250, 0));
    rectangle7.setOutlineColor(sf::Color(0, 0, 250));
    rectangle8.setOutlineColor(sf::Color(250, 0, 250));

    rectangle.setPosition(0.f, 0.f);
    rectangle2.setPosition(0.f, 80.f);
    rectangle3.setPosition(500.f, 80.f);
    rectangle4.setPosition(0.f, 280.f);
    rectangle5.setPosition(0.f, 283.f);
    rectangle6.setPosition(500.f, 283.f);
    rectangle7.setPosition(0.f, 540.f);
    rectangle8.setPosition(500.f, 540.f);

    mySFML->window.draw(rectangle);
    mySFML->window.draw(rectangle2);
    mySFML->window.draw(rectangle3);
    mySFML->window.draw(rectangle4);
    mySFML->window.draw(rectangle5);
    mySFML->window.draw(rectangle6);
    mySFML->window.draw(rectangle7);
    mySFML->window.draw(rectangle8);
}

void dispModNetwork(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    if (!monitorDisplay.getModNetwork()->isEnable())
        return;
    int up = monitorDisplay.getModNetwork()->getUp() / 1048576;
    mySFML->text.setCharacterSize(25);
    mySFML->text.setString("NETWORK");
    mySFML->text.setPosition(700.f, 80.f);
    mySFML->window.draw(mySFML->text);

    mySFML->text.setCharacterSize(21);
    mySFML->text.setPosition(690.f, 140.f);
    std::stringstream ss;
    ss << std::fixed << up;
    std::string memUsed = ss.str();
    mySFML->text.setString("Debit montant :" + memUsed + " Mb/s");
    mySFML->window.draw(mySFML->text);

    up = monitorDisplay.getModNetwork()->getDown() / 1048576;
    mySFML->text.setCharacterSize(21);
    mySFML->text.setPosition(690.f, 180.f);
    std::stringstream sss;
    sss << std::fixed << up;
    memUsed = sss.str();
    mySFML->text.setString("Debit descendant :" + memUsed + " Mb/s");
    mySFML->window.draw(mySFML->text);

}

void dispModUser(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    if (!monitorDisplay.getModUser()->isEnable())
        return;
    mySFML->text.setString(monitorDisplay.getModUser()->getUserName());
    mySFML->text.setCharacterSize(16);
    mySFML->text.setFillColor(sf::Color::White);
    mySFML->text.setPosition(20.f, 5.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getModUser()->getHostName());
    mySFML->text.setPosition(20.f, 20.f);
    mySFML->window.draw(mySFML->text);
}

void dispModTime(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    if (!monitorDisplay.getTime()->isEnable())
        return;
    mySFML->text.setCharacterSize(20);
    mySFML->text.setString(monitorDisplay.getTime()->getTime());
    mySFML->text.setPosition(350.f, 5.f);
    mySFML->window.draw(mySFML->text);
}

void dispModOS(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    if (!monitorDisplay.getOsMod()->isEnable())
        return;
    std::string part1 = monitorDisplay.getOsMod()->getOs();
    std::string part2 = "OS : ";
    mySFML->text.setCharacterSize(16);
    mySFML->text.setString(part2 + part1);
    mySFML->text.setPosition(750.f, 5.f);
    mySFML->window.draw(mySFML->text);
    part2 = "Kernel : ";
    part1 = monitorDisplay.getOsMod()->getKernel();
    mySFML->text.setString(part2 + part1);
    mySFML->text.setPosition(750.f, 20.f);
    mySFML->window.draw(mySFML->text);
}

void DispGraphCPU4(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    int value = 0;

    value = std::stoi(monitorDisplay.getCPU()->getSMap()["Frequency"]);
    float size = (value * 100) / 2700;
    size = (size * 300) / 100;

    sf::RectangleShape rectangle1Back(sf::Vector2f(310.f, 70.f));
    rectangle1Back.setFillColor(sf::Color(60, 60, 60));
    rectangle1Back.setPosition(550.f, 650.f);
    mySFML->window.draw(rectangle1Back);
    if (size >= 300) {
        sf::RectangleShape rectangle1Max(sf::Vector2f(300, 50.f));
        rectangle1Max.setFillColor(sf::Color(250, 0, 0));
        rectangle1Max.setPosition(555.f, 660.f);
        mySFML->window.draw(rectangle1Max);
    } else {

        sf::RectangleShape rectangle1(sf::Vector2f(size, 50.f));
        rectangle1.setFillColor(sf::Color(0, 250, 0));
        if (size >= 200 )
            rectangle1.setFillColor(sf::Color(230, 20, 20));
        rectangle1.setPosition(555.f, 660.f);
        mySFML->window.draw(rectangle1);
    }
}

void DispGraphCPU3(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    int value = 0;

    value = std::stoi(monitorDisplay.getCPU()->getSMap()["Frequency"]);
    float size = (value * 100) / 2700;
    size = (size * 300) / 100;

    sf::RectangleShape rectangle1Back(sf::Vector2f(310.f, 70.f));
    rectangle1Back.setFillColor(sf::Color(60, 60, 60));
    rectangle1Back.setPosition(550.f, 400.f);
    mySFML->window.draw(rectangle1Back);
    if (size >= 300) {
        sf::RectangleShape rectangle1Max(sf::Vector2f(300, 50.f));
        rectangle1Max.setFillColor(sf::Color(250, 0, 0));
        rectangle1Max.setPosition(555.f, 410.f);
        mySFML->window.draw(rectangle1Max);
    } else {

        sf::RectangleShape rectangle1(sf::Vector2f(size, 50.f));
        rectangle1.setFillColor(sf::Color(0, 250, 0));
        if (size >= 200 )
            rectangle1.setFillColor(sf::Color(230, 20, 20));
        rectangle1.setPosition(555.f, 410.f);
        mySFML->window.draw(rectangle1);
    }
    DispGraphCPU4(monitorDisplay, mySFML);
}

void DispGraphCPU2(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    int value = 0;

    value = std::stoi(monitorDisplay.getCPU()->getFMap()["Frequency"]);
    float size = (value * 100) / 2700;
    size = (size * 300) / 100;

    sf::RectangleShape rectangle1Back(sf::Vector2f(310.f, 70.f));
    rectangle1Back.setFillColor(sf::Color(60, 60, 60));
    rectangle1Back.setPosition(40.f, 650.f);
    mySFML->window.draw(rectangle1Back);
    if (size >= 300) {
        sf::RectangleShape rectangle1Max(sf::Vector2f(300, 50.f));
        rectangle1Max.setFillColor(sf::Color(250, 0, 0));
        rectangle1Max.setPosition(45.f, 660.f);
        mySFML->window.draw(rectangle1Max);
    } else {

        sf::RectangleShape rectangle1(sf::Vector2f(size, 50.f));
        rectangle1.setFillColor(sf::Color(0, 250, 0));
        if (size >= 200 )
            rectangle1.setFillColor(sf::Color(230, 20, 20));
        rectangle1.setPosition(45.f, 660.f);
        mySFML->window.draw(rectangle1);
    }
    DispGraphCPU3(monitorDisplay, mySFML);
}

void DispGraphCPU(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    int value = 0;

    value = std::stoi(monitorDisplay.getCPU()->getZMap()["Frequency"]);
    float size = (value * 100) / 2700;
    size = (size * 300) / 100;

    sf::RectangleShape rectangle1Back(sf::Vector2f(310.f, 70.f));
    rectangle1Back.setFillColor(sf::Color(60, 60, 60));
    rectangle1Back.setPosition(40.f, 400.f);
    mySFML->window.draw(rectangle1Back);
    if (size >= 300) {
        sf::RectangleShape rectangle1Max(sf::Vector2f(300, 50.f));
        rectangle1Max.setFillColor(sf::Color(250, 0, 0));
        rectangle1Max.setPosition(45.f, 410.f);
        mySFML->window.draw(rectangle1Max);
    } else {

        sf::RectangleShape rectangle1(sf::Vector2f(size, 50.f));
        rectangle1.setFillColor(sf::Color(0, 250, 0));
        if (size >= 200 )
            rectangle1.setFillColor(sf::Color(230, 20, 20));
        rectangle1.setPosition(45.f, 410.f);
        mySFML->window.draw(rectangle1);
    }
    DispGraphCPU2(monitorDisplay, mySFML);
}

void DispModCPU(MonitorDisplay &monitorDisplay, mySFML *mySFML)
{
    if (!monitorDisplay.getCPU()->isEnable())
        return;

    mySFML->text.setCharacterSize(16);
    mySFML->text.setString("CPU " + monitorDisplay.getCPU()->getZMap()["Name"]);
    mySFML->text.setPosition(20.f, 300.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Cores " + monitorDisplay.getCPU()->getZMap()["nbCore"]);
    mySFML->text.setPosition(80.f, 300.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Model " + monitorDisplay.getCPU()->getZMap()["Model"]);
    mySFML->text.setPosition(20.f, 320.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getZMap()["ModelName"]);
    mySFML->text.setPosition(20.f, 340.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getZMap()["Frequency"] + " MHz");
    mySFML->text.setPosition(20.f, 360.f);
    mySFML->window.draw(mySFML->text);

    mySFML->text.setString("CPU " + monitorDisplay.getCPU()->getFMap()["Name"]);
    mySFML->text.setPosition(20.f, 550.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Cores " + monitorDisplay.getCPU()->getFMap()["nbCore"]);
    mySFML->text.setPosition(80.f, 550.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Model " + monitorDisplay.getCPU()->getFMap()["Model"]);
    mySFML->text.setPosition(20.f, 570.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getFMap()["ModelName"]);
    mySFML->text.setPosition(20.f, 590.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getFMap()["Frequency"] + " MHz");
    mySFML->text.setPosition(20.f, 610.f);
    mySFML->window.draw(mySFML->text);

    mySFML->text.setCharacterSize(16);
    mySFML->text.setString("CPU " + monitorDisplay.getCPU()->getSMap()["Name"]);
    mySFML->text.setPosition(600.f, 300.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Cores " + monitorDisplay.getCPU()->getSMap()["nbCore"]);
    mySFML->text.setPosition(660.f, 300.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Model " + monitorDisplay.getCPU()->getSMap()["Model"]);
    mySFML->text.setPosition(600.f, 320.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getSMap()["ModelName"]);
    mySFML->text.setPosition(600.f, 340.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getSMap()["Frequency"] + " MHz");
    mySFML->text.setPosition(600.f, 360.f);
    mySFML->window.draw(mySFML->text);

    mySFML->text.setString("CPU " + monitorDisplay.getCPU()->getTMap()["Name"]);
    mySFML->text.setPosition(600.f, 550.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Cores " + monitorDisplay.getCPU()->getTMap()["nbCore"]);
    mySFML->text.setPosition(660.f, 550.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString("Model " + monitorDisplay.getCPU()->getTMap()["Model"]);
    mySFML->text.setPosition(600.f, 570.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getTMap()["ModelName"]);
    mySFML->text.setPosition(600.f, 590.f);
    mySFML->window.draw(mySFML->text);
    mySFML->text.setString(monitorDisplay.getCPU()->getTMap()["Frequency"] + " MHz");
    mySFML->text.setPosition(600.f, 610.f);
    mySFML->window.draw(mySFML->text);

    DispGraphCPU(monitorDisplay, mySFML);
}