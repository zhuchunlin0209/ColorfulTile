#include "ShowOnStartMenu.h"

ShowOnStartMenu::ShowOnStartMenu(bool isPrivate, ColorfulTileFile& FileClass) : fileClass(FileClass)
{
	if (isPrivate) {
		if (!getLnkFilePath()) {
			if (MessageBox(GetForegroundWindow(), "δȡ���û���\n�Ƿ��ֶ�����?", "����", MB_YESNO | MB_ICONWARNING) == IDYES) {
				string name;
				while (1) {
					cout << "�������û���: ";
					getline(cin, name);
					cout << endl;

					path = "C:\\Users\\";
					path += name;
					path += "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\";

					if (fileClass.CheckFolderExist(path))
						break;
				} 
			} 
		}
	}
}

void ShowOnStartMenu::show()
{

}

bool ShowOnStartMenu::getLnkFilePath() {
	char name[256];
	DWORD dwSize = 256;
	if (GetUserName(name, &dwSize)) {
		path = "C:\\Users\\";
		path += name;
		path += "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\";
		return true;
	}

	return false;
}
