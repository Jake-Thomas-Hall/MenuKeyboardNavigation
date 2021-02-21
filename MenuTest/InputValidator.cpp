#include "InputValidator.h"

bool InputValidator::GetControlChar(KEY_EVENT_RECORD& keyRec, HANDLE& hConsole) {
	DWORD cc;
	INPUT_RECORD irec;

	if (hConsole == NULL)
	{
		return false; // console not found
	}

	for (; ; )
	{
		ReadConsoleInput(hConsole, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)
		{
			keyRec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false;
}