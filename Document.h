#include <string>
#include <iostream>
#include<fstream>
using namespace std;
#include "Lines.h"
#pragma once
void gotoRowCol(int rpos, int cpos);
class Document {
	friend class TextEditor;
	friend class Lines;
	Lines* Ls;
	int NOLs;
	string DName;
	int dri = 0, dci = 0;
	void Deepcopy(Lines& NLs, const Lines& L);
public:
	/*Document()
	{
		
	}*/
	
	void InsertACharacter(int ch, int li, int ci)
	{
		Ls[li].InsertCharAt_i(ci, ch);
	}
	void DeleteACharacter(int li, int ci)
	{
		Ls[li].DeleteACharAt(ci - 1);
	}
	void PrintDocument()
	{
		system("cls");
		gotoRowCol(0, 0);
		ofstream wrt("D.txt");
		for (int i = 0; i < NOLs; i++)
		{
			wrt << Ls[i].Cs << endl;
			cout<< Ls[i].Cs << endl;
		}
	}
	void InsertANewLineAt(int li,int ci)
	{
		Lines L1, L2;
		int lfi = 0;
		for (int i = 0; i < ci; i++)
		{
			L1.InsertCharAt_i(lfi, Ls[li].Cs[i]);
			lfi++;
		}
		int lni = 0;
		for (int i = ci; i < Ls[li].Size; i++)
		{
			L2.InsertCharAt_i(lni, Ls[li].Cs[i]);
			lni++;
		}
		Lines* HLs = new Lines[NOLs + 1];
		for (int i = 0, hi = 0; i < NOLs; i++,hi++)
		{
			if (i == li)
			{
				HLs[hi] = L1;
				hi++;
				HLs[hi] = L2;
				
			}
			else
			{
				HLs[hi] = Ls[i];
			}
			
			
		}
		delete[]Ls;
		Ls = HLs;
		NOLs++;
	}
	Document(const string& fname)
	{
		NOLs = 0;
		Load(fname);
		
	}

	void Load(string Fname)
	{
		/*Ls = new Lines[1];
		NOLs = 1;*/
		DName = Fname;
		ifstream rdr(Fname);
		rdr >> NOLs; rdr.ignore();
		Ls = new Lines[NOLs];
		int ri = 0, ci = 0; char ch;
		while (true)
		{
			ch = rdr.get();
			if (!rdr)
			{
				break;
			}
			if (ch == '\n')
			{
				ri++;
				ci = 0;
			}
			else
			{
				InsertACharacter(ch,ri, ci);
				ci++;
			}

		}
	}
	void LoadEncodedFile(string Fname);
	void SimpleUpdater();
	void UpdaterEncodedFiles();
	void Enter_AddNewLine(int ri, int ci);
	void BackSpace_LineRemover(int Ln);
	void BackSpace_Concat(int Ln);
	void FindCaseSens(string Tofind);
	void FindInCaseSens(string Tofind);
	double AvgWordLen();
	int SmallestWordLen();
	int LargestWordLength();
	int WordCount();
	int SpecialCharCount();
	int SentencesCount();
	int ParagraphCount();
	void FindAllSubStrings(string toFind);
	void Prefix(string Tofind, string PreFix);
	void PostFix(string Tofind, string PostFix);
	void FindAndReplaceFirst(string tofind, string toreplace);
	void FindAndReplaceAll(string tofind, string toreplace);
	void FindReplaceNext(string find, string replace, int cr, int cc);
	void FindReplaceAllNext(string find, string replace, int cr, int cc);
	void FindReplacePrev(string find, string replace, int cr, int cc);
	void FindReplaceAllPrev(string find, string replace, int cr, int cc);
	void FindAndReplaceMenu(int cr, int cc) 
	{
		cout << "Ctrl + N to find and replace only the next word." << endl;
		cout << "Ctrl + Q to find and replace All next words." << endl;
		cout << "Ctrl + P to find and replace only the previous 1 word." << endl;
		cout << "Ctrl + O to find and replace all of the previous words." << endl;
		//You can use any Shortcut keys.
	}
	void FindingSentence();
	void WordGame(int& cr, int& cc); //Feature no. 16
	//void PrintDocument();
	void ExitDocument();
};


