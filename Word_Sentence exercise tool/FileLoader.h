#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<istream>
#include <string>
#include <algorithm>
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
}Word_And_Sentence;

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
	vector<Word_And_Sentence> * getAllWords(int max, int master);//��ȡָ�������������ȵ���master�����е���
	vector<Word_And_Sentence> * getAllSentences(int max, int master);//��ȡָ�������������ȵ���master�����о���
	vector<Word_And_Sentence> * getAllMasteredWords(int master);//��ȡָ�������������ȸ���master�����е���
	vector<Word_And_Sentence> * getAllMasteredSentences(int master);//��ȡָ�������������ȸ���master�����о���
	string filepath;//�ʿ�·��
	string cfg_filepath;//�����ļ�·��
	void addWord(Word_And_Sentence word);
	void addSentence(Word_And_Sentence sentence);
	void delete_(int startLine, int lineCount);//ɾ������
	void delete_(vector<Word_And_Sentence *>* deleteList);//����ɾ��
	void test();
	//void ModifyLineData(int lineNum, string lineData);
	void ModifyLineData(int lineNum, string lineData, string filepath);
	void ConfirmSettings(Setting settings);
	string loadOption(string key);//��ȡconfig�ļ���key���ֵ
	void changeOption(string key, string value); //�޸�config�ļ���key���ֵ
	vector<string> split(const string& str, const string& delim);
	int language = JP;
private:
	//����vector��������
	bool GreaterSort(Word_And_Sentence * a, Word_And_Sentence * b) { return(a->startLine > b->startLine); };
	ifstream ifs;
	ofstream ofs;
	fstream fs;
};