#include "Menu.h"
#include "Utilities.h"
#include "InputValidator.h"

MenuContainer::MenuContainer(std::string const& text) : _strText(text), _vecMenuItems()
{
	_boolExitMenu = false; 
	_iHighlightedIndex = 0;
	_hOutputConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_hInputConsole = GetStdHandle(STD_INPUT_HANDLE);
}

void MenuContainer::Execute()
{
	KEY_EVENT_RECORD key{};

	while (key.wVirtualKeyCode != VK_RETURN) {
		system("cls");
		std::cout << _strText << "\n";
		util::for_each_iterator(_vecMenuItems.begin(), _vecMenuItems.end(), 0, [&](int index, std::unique_ptr<MenuItem> const& item) {
			if (_iHighlightedIndex == index) {
				SetConsoleTextAttribute(_hOutputConsole, BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
				std::cout << "\t" << item->ItemText() << "\n";
				SetConsoleTextAttribute(_hOutputConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else {
				std::cout << "\t" << item->ItemText() << "\n";
			}
			});
		InputValidator::GetControlChar(key, _hInputConsole);
		if (key.wVirtualKeyCode == VK_DOWN) {
			if (_iHighlightedIndex < (int)_vecMenuItems.size() - 1) _iHighlightedIndex++;
		}
		else if (key.wVirtualKeyCode == VK_UP) {
			if (_iHighlightedIndex > 0) _iHighlightedIndex--;
		}
	}

	if ((int)_vecMenuItems.size() > _iHighlightedIndex && _iHighlightedIndex >= 0) {
		_vecMenuItems[_iHighlightedIndex]->Execute();
	}
	else {
		std::cout << "Not a valid option, please try again.\n";
		util::Pause();
	}
};

void MenuContainer::AddMenuItem(std::unique_ptr<MenuItem> item) {
	_vecMenuItems.push_back(std::move(item));
};

GeneralMenuItem::GeneralMenuItem(std::string output)
{
	_output = output;
};

void DummyMenu::Execute() {
	system("cls");
	std::cout << "Dummy menu option was entered...\n";
	util::Pause();
}

void SubMenuExample::Execute() {
	MenuContainer objMenuContainer = MenuContainer("Sub menu example.\nChoose one of the below options.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new DummyMenu("Example item 1")));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new DummyMenu("Example item 2")));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return", &objMenuContainer)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}
}

MenuExit::MenuExit(std::string output, MenuContainer* menuContainer) : GeneralMenuItem(output) {
	_ptrMenuContainer = menuContainer;
};

void MenuExit::Execute() {
	_ptrMenuContainer->SetExitMenu(true);
};