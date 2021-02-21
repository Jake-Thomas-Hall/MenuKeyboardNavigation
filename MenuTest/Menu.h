#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <Windows.h>

#ifndef MENU_H
#define MENU_H
class MenuItem {
public:
    virtual ~MenuItem() {}
    virtual std::string ItemText() const = 0;
    virtual void Execute() = 0;
};

class MenuContainer {
private:
    std::string _strText;
    std::vector<std::unique_ptr<MenuItem>> _vecMenuItems;
    bool _boolExitMenu;
    int _iHighlightedIndex;
    HANDLE _hOutputConsole;
    HANDLE _hInputConsole;
public:
    MenuContainer(std::string const& text);
    void AddMenuItem(std::unique_ptr<MenuItem> item);
    void Execute();
    bool GetExitMenu() { return _boolExitMenu; }
    void SetExitMenu(bool exitMenu) { _boolExitMenu = exitMenu; }
};

class GeneralMenuItem : public MenuItem {
private:
    std::string _output;
public:
    GeneralMenuItem(std::string output);
    std::string ItemText() const { return _output; }
};

class DummyMenu : public GeneralMenuItem {
public:
    DummyMenu(std::string output) : GeneralMenuItem(output) {};
    void Execute();
};

class SubMenuExample : public GeneralMenuItem {
public:
    SubMenuExample(std::string output) : GeneralMenuItem(output) {};
    void Execute();
};

class MenuExit : public GeneralMenuItem {
private:
    MenuContainer* _ptrMenuContainer;
public:
    MenuExit(std::string output, MenuContainer* menuContainer);
    void Execute();
};
#endif

