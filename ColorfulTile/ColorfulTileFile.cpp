#include "ColorfulTileFile.h"
ColorfulTileFile::ColorfulTileFile(string& filePath, string& color, bool Foreground)
{
	getAboutXml(filePath);
	_Foreground = Foreground;
	if (strstr(_color.c_str(), "#") == NULL) {
		_color = "#";
		_color += color;
	}
	else {
		_color = color;
	}
}

ColorfulTileFile::ColorfulTileFile(ColorfulTileFile& fileClass)
{
	_color = fileClass._color;
	_Foreground = fileClass._Foreground;
	logo = fileClass.logo;
	file = fileClass.file;
}

void ColorfulTileFile::generateXml()
{
	pushLine("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	pushLine("<Application xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance""\">");
	pushLine("<VisualElements");
	pushLine("ShowNameOnSquare150x150Logo=\"on\"");
	pushLine("ForegroundText=");
	if (_Foreground)
		file.xmlFileContent[4] += "\"light\"";
	else
		file.xmlFileContent[4] += "\"dark\"";

	pushLine("BackgroundColor=");
	file.xmlFileContent[5] += "\"";
	file.xmlFileContent[5] += _color;
	file.xmlFileContent[5] += "\"";
	int temp = 6;
	if (!logo.Square150x150Logo.empty()) {
		pushLine("Square150x150Logo='");
		file.xmlFileContent[temp] += logo.Square150x150Logo;
		file.xmlFileContent[temp] += "'";
		temp++;
	}

	if (!logo.Square70x70Logo.empty()) {
		pushLine("Square70x70Logo='");
		file.xmlFileContent[temp] += logo.Square70x70Logo;
		file.xmlFileContent[temp] += "'";
	}

	endXml();
}
	
void ColorfulTileFile::getAboutXml(string& filePath)
{
	string xmlFileName = filePath, path;
	string temp;
	do {
		temp = filePath[filePath.size() - 1];
		filePath.pop_back();
	} while (temp != "\\");

	file.path = filePath;
	xmlFileName.erase(0, filePath.size() + 1);

	file.fileName = xmlFileName;
	xmlFileName = xmlFileName.substr(0, xmlFileName.size() - 3);
	xmlFileName += "VisualElementsManifest.xml";

	file.xmlFileName = xmlFileName;
	path = filePath;
	path += "\\";
	path += xmlFileName;
	file.xmlFilePath = path;
}

fstream ColorfulTileFile::getXmlFile()
{
	fstream xmlFile;
	xmlFile.open(file.xmlFilePath, ios::out | ios::binary);
	return xmlFile;
}

string ColorfulTileFile::getXmlContent()
{
	string content = "";
	for (auto temp : file.xmlFileContent) {
		content += temp;
		content += "\n";
	}
	return content;
}

bool ColorfulTileFile::CheckFolderExist(const string& strPath)
{
	WIN32_FIND_DATA  wfd;
	bool rValue = false;
	HANDLE hFind = FindFirstFile(strPath.c_str(), &wfd);
	if ((hFind != INVALID_HANDLE_VALUE) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		rValue = true;

	FindClose(hFind);
	return rValue;
}

void ColorfulTileFile::setForeground(bool foreground) {
	_Foreground = foreground;
}

void ColorfulTileFile::endXml() {
	pushLine("></VisualElements>");
	pushLine("</Application>");
	pushLine("");
}

void ColorfulTileFile::pushLine(const string& content) {
	file.xmlFileContent.push_back(content);
}

void ColorfulTileFile::set150x150logo(string& logo150x150) {
	logo.Square150x150Logo = logo150x150;
}

void ColorfulTileFile::set70x70logo(string& logo70x70) {
	logo.Square70x70Logo = logo70x70;
}
