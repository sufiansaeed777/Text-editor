#include "TextEditor.h"
#include <iostream>
#include <conio.h>
using namespace std;
#include<windows.h>
#include<math.h>
#include <time.h>

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
TextEditor::TextEditor(const string& fname)
{
	Doc = new Document(fname);
	Doc->PrintDocument();
}
void TextEditor::Editing()
{
	//Lines Aline;
	int d;
	cr = 0, cc = 0;
	gotoRowCol(cr, cc);

	char ch;
	while (true)
	{
		if (_kbhit())
		{
			d = _getch();
			if (d == 224)
			{
				d = _getch();
				if (d == 72)
				{
					if (cr > 0)
					{
						cr--;
					}
					
					if (Doc->Ls[cr].Size-1 < cc)
					{
						cc = Doc->Ls[cr].Size;
					}
				}
				else if (d == 80)
				{
					if (Doc->NOLs -1!= cr)
					{
						cr++;
					}
					
					if (Doc->Ls[cr].Size < cc)
					{
						cc = Doc->Ls[cr].Size;
					}
				}
				else if (d == 77)
				{
					cc++;
					if (cc == Doc->Ls[cr].Size + 1)
					{
						cc = 0;
						cr++;
					}
				}
				else if (d == 75)
				{
					cc--;
					if (cc == -1)
					{
						cr--;
						cc = Doc->Ls[cr].Size;
					}
				}

			}
			else if (d == 13)
			{
				Doc->InsertANewLineAt(cr, cc);
				cr++;
				cc = 0;
				Doc->PrintDocument();

			}
			else if (d == 8)
			{
				Doc->DeleteACharacter(cr, cc);
				Doc->PrintDocument();
				cc--;
			}
			else
			{
				ch = char(d);
				//cout << ch;
				//Aline.InsertCharAt_i(cc, ch);
				Doc->InsertACharacter(ch,cr, cc);
				Doc->PrintDocument();
				cc++;
			}
			
			gotoRowCol(cr, cc);
		}
		
	}
}