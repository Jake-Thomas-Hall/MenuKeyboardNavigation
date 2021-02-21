#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "Utilities.h"

#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
class InputValidator {
private:
	// Private constructor as a reminder to myself to not create instances ;)
	InputValidator();
public:
	static bool GetControlChar(KEY_EVENT_RECORD& keyRec, HANDLE& hConsole);
};
#endif