#include "Document.h"
#pragma once
//struct Line
//{
//	int size;
//	char* Cs;
//};
void gotoRowCol(int rpos, int cpos);
class TextEditor
{
	friend class Document;
	friend class Lines;
	int cr = 0, cc = 0, NODs, CDoci;
	
	Document* Doc;
public:
	TextEditor(const string& fname);
	TextEditor()
	{

	}
	void Editing();
	
	void Run();
	void PrintShortcuts();
	void CommandModeShortcutsPrinter();
	void CommandMode();
	void MergeDocuments(string Fname1, string Fname2);
	//void OpenMultipleDocs(_____);
};


