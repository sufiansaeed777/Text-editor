#pragma once
class Lines {
	friend class TextEditor;
	friend class Document;
	char* Cs;
	int Size;
	static bool isChar(char c);
	static bool islower(char c);
	static bool isupper(char c);
public:
	Lines()
	{
		Cs = new char[1] {};
		Size = 0;
	}
	Lines(const Lines& A)
	{
		Cs = new char[A.Size + 1];
		Size = A.Size;
		for (int i = 0; i < A.Size; i++)
		{
			Cs[i] = A.Cs[i];
		}
	}
	void InsertCharAt_i(int i, char ch)
	{
		char* HA = new char[Size + 2];
		for (int ci = 0; ci < i; ci++)
		{
			HA[ci] = Cs[ci];
		}
		HA[i] = ch;
		for (int ci = i; ci <= Size; ci++)
		{
			HA[ci + 1] = Cs[ci];
		}
		delete[]Cs;
		Cs = HA;
		Size++;
	}
	void DeleteACharAt(int i)
	{
		char* HA = new char[Size];
		for (int ci = 0, hi = 0; ci <= Size; ci++,hi++)
		{
			if (ci == i)
			{
				ci++;
			}
			HA[hi] = Cs[ci];
		}
		delete[]Cs;
		Cs = HA;
		Size--;
	}
	//void CharRemoverAt_i(int i);
	//void ToUpper(int li, int ci);
	//void ToLower(int li, int ci);
	////— SubStrings(string Tofind);
	//void AddPrefix(string ToFind, string Prefix);
	//void AddPostfix(string toFind, string PostFix);
	//bool Replacefirst(string toFind, string toReplace);
	//void ReplaceAll(string toFind, string toReplace);
	/*______ FindNextOnly(----);
	______ FindPrevOnly(----);
	______ FindNextAll(----);
	______ FindPrevAll(----);

	______  FindAndReplaceNextOnly(----);
	______  FindAndReplacePrevOnly(----);
	void FindAndReplaceNextAll(----);
	void FindAndReplacePrevAll(----);

	void PrintLine(----);*/
	//void Writer(ofstream& wtr);
	~Lines()
	{
		//delete[] Cs;
	}
};


