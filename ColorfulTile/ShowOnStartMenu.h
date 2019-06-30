#pragma once

#include "ColorfulTileFile.h"

class ShowOnStartMenu
{
private:
	ColorfulTileFile fileClass;
	string path = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\";

	bool getLnkFilePath();
public:
	ShowOnStartMenu(bool isPrivate, ColorfulTileFile& FileClass);
	void show();
};
