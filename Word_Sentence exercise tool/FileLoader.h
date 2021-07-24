#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<istream>
#include <string>
using namespace std;
typedef struct
{
	unsigned type;	//0en 1jp
	string origin = "";
	vector<string> paraphrase;
	int mastered = 0;
	unsigned int mastered_tag_line;
}Word;

typedef struct
{
	unsigned type;
	string origin = "";
	string paraphrase = "";
	vector<string> remarks;
	int mastered = 0;
	unsigned int mastered_tag_line;
}Sentence;

class FileLoader
{
public:
	FileLoader(const char* path);
	vector<Word> * getAllWords(int max, int master);
	vector<Sentence> * getAllSentences(int max, int master);
	void addWord(Word word);
	void addSentence(Sentence sentence);
	void test();
	void ModifyLineData(char * fileName, int lineNum, char* lineData);
private:
	string filepath;
	ifstream ifs;
	ofstream ofs;
	fstream fs;
};