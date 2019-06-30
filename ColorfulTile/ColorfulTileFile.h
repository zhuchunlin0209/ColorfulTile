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
	// Square150x150Logo & Square70x70Logo �Ĳ��� (��ѡ)
	struct SquareLogo {
		string Square150x150Logo;
		string Square70x70Logo;
	} logo;

	// ��������ļ���һ��
	struct aboutFile {
		string path;									// �ļ���·��
		string fileName;							// �ļ�����
		string xmlFilePath;						// xml �ļ�·��
		string xmlFileName;						// xml �ļ�����

		vector<string> xmlFileContent;	// xml �ļ����� ÿһ��Ԫ��Ϊһ��
	} file;

	string _color;										// ������ɫ����
	bool _Foreground;							// ������ɫ true = light   false = dark

	void endXml();									// ��β xml �ļ�
	void pushLine(const string&);			// �� xml �ļ��½�һ��

	void getAboutXml(string& filePath);	// �����ļ�·�������ƺ� xml �ļ�

	friend class ShowTile;
public:
	ColorfulTileFile(string& filePath,		// �ļ�·��
		string& color, bool Foreground);

	void generateXml();							// �༭ xml �ļ�����

	// ���� SquareLogo
	void set150x150logo(string& logo150x150);
	void set70x70logo(string& logo70x70);
	void setForeground(bool foreground);

	string getXmlContent();						// ȡ�� xml �ļ�����
	fstream getXmlFile();							// �õ� xml �� fstream ����
};
