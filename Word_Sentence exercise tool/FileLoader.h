#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<istream>
#include <string>
#define	JP 1
#define EN 0

using namespace std;

typedef struct
{
	unsigned type;	//0en 1jp
	string origin = "";
	vector<string> paraphrase; 
	int mastered = 0;
	int masteredThisBatch = 0;
	unsigned int mastered_tag_line;
	unsigned int startLine;
	unsigned int lineCount;
}Word;

typedef struct
{
	unsigned type;
	string origin = "";
	vector<string> paraphrase;
	int mastered = 0;
	int masteredThisBatch = 0;
	unsigned int mastered_tag_line;
	unsigned int startLine;
	unsigned int lineCount;
}Sentence;

typedef struct
{
	int BatchSize_word = 0;
	int BatchSize_sentence = 0;
	int Master_word = 0;
	int Master_sentence = 0;
}Setting;

class FileLoader
{
public:
	FileLoader(const char* path);
	vector<Word> * getAllWords(int max, int master);//获取指定语种且熟练度低于master的所有单词
	vector<Sentence> * getAllSentences(int max, int master);//获取指定语种且熟练度低于master的所有句子
	vector<Word> * getAllMasteredWords(int master);//获取指定语种且熟练度高于master的所有单词
	vector<Sentence> * getAllMasteredSentences(int master);//获取指定语种且熟练度高于master的所有句子
	string filepath;//词库路径
	string cfg_filepath;//配置文件路径
	void addWord(Word word);
	void addSentence(Sentence sentence);
	void delete_(int startLine, int lineCount);
	void test();
	//void ModifyLineData(int lineNum, string lineData);
	void ModifyLineData(int lineNum, string lineData, string filepath);
	void ConfirmSettings(Setting settings);
	string loadOption(string key);//读取config文件中key项的值
	void changeOption(string key, string value); //修改config文件中key项的值
	vector<string> split(const string& str, const string& delim);
	int language = JP;
private:

	ifstream ifs;
	ofstream ofs;
	fstream fs;
};