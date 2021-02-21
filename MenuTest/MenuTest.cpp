#include <iostream>
#include "Menu.h"

int main()
{
	MenuContainer objMenuContainer = MenuContainer("Test navigation menu.\nChoose one of the below options.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new DummyMenu("Example item 1")));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new DummyMenu("Example item 2")));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new DummyMenu("Example item 3")));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuExample("Sub menu example")));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Exit menu", &objMenuContainer)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}
}
