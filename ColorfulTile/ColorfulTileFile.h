#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class ColorfulTileFile
{
private:
	// Square150x150Logo & Square70x70Logo 的参数 (可选)
	struct SquareLogo {
		string Square150x150Logo;
		string Square70x70Logo;
	} logo;

	// 储存关于文件的一切
	struct aboutFile {
		string path;									// 文件夹路径
		string fileName;							// 文件名称
		string xmlFilePath;						// xml 文件路径
		string xmlFileName;						// xml 文件名称

		vector<string> xmlFileContent;	// xml 文件内容 每一个元素为一行
	} file;

	string _color;										// 磁贴颜色代码
	bool _Foreground;							// 文字颜色 true = light   false = dark

	void endXml();									// 结尾 xml 文件
	void pushLine(const string&);			// 在 xml 文件新建一行

	void getAboutXml(string& filePath);	// 处理文件路径、名称和 xml 文件

	friend class ShowTile;
public:
	ColorfulTileFile(string& filePath,		// 文件路径
		string& color, bool Foreground);

	void generateXml();							// 编辑 xml 文件内容

	// 设置 SquareLogo
	void set150x150logo(string& logo150x150);
	void set70x70logo(string& logo70x70);
	void setForeground(bool foreground);

	string getXmlContent();						// 取得 xml 文件内容
	fstream getXmlFile();							// 得到 xml 的 fstream 对象
};
