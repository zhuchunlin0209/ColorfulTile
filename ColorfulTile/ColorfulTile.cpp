// ColorfulTile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 未完待续...

#include "ColorfulTileFile.h"

using namespace std;

void Main();
bool compare(string&);
void endXml(ColorfulTileFile tileFile);

int main(int argc, char* args[])
{
	SetConsoleTitle("ColorfulTile - Star sea");
	HWND hwnd = GetForegroundWindow();

	if (argc < 2) {
		Main();
		return 0;
	}

	string filePath = args[1], color = args[2];
	bool foreground = true;
	if (strstr(args[3], "light") == NULL)
		foreground = false;

	ColorfulTileFile tileFile(filePath, color, true);
	endXml(tileFile);
	return 0;
}

void Main()
{
	string path;
	int temp = 0;
	bool flag = true;
	cout << "请输入文件路径: ";
	while (flag)
	{
		if (temp > 0)
			cout << "\n不是有效的文件后缀!\n请重新输入: ";
		getline(cin, path);
		flag = (strstr(path.c_str(), ".exe") == NULL || compare(path));
		temp++;
		cout << endl;
	}

	string color;
	cout << "请输入 16 进制颜色 ID : ";
	cin >> color;
	cout << endl;

	int foreground;
	cout << "文字颜色为 (0.黑   1.白): ";
	cin >> foreground;
	cout << endl;

	ColorfulTileFile tileFile(path, color, foreground);

	string str, logo;
	cout << "是否设置 logo ? (Y/N)";
	cin >> str;
	cout << endl;
	if ((str == "Y") || (str == "y"))
	{
		cout << "Square150x150Logo = ";
		getchar();
		getline(cin, logo);
		tileFile.set150x150logo(logo);

		cout << "Square70x70Logo = ";
		getline(cin, logo);
		tileFile.set70x70logo(logo);
		cout << endl;
	}

	endXml(tileFile);
}

void endXml(ColorfulTileFile tileFile)
{
	cout << "正在生成..." << endl;
	tileFile.generateXml();

	cout << "正在输出文件..." << endl;
	fstream xmlFile = tileFile.getXmlFile();
	string ch = tileFile.getXmlContent();
	xmlFile.write(ch.c_str(), ch.size());
	xmlFile.close();
	cout << "完成!" << endl;
}

bool compare(string& str)
{
	const char* ch = str.c_str();
	if (strstr(ch, ".Exe") != NULL || strstr(ch, ".eXe") != NULL || strstr(ch, ".exE") != NULL ||
		strstr(ch, ".EXe") != NULL || strstr(ch, ".eXE") != NULL || strstr(ch, ".EXE") != NULL)
		return true;
}
