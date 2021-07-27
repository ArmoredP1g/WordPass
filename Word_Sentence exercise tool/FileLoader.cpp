#include"FileLoader.h"
using namespace std;
FileLoader::FileLoader(const char* path)
{
	fs = fstream(path);
	if (!fs.is_open())
	{
		cout << "没打开" << endl;
	}	
	fs.close();
	this->filepath = path;
}

vector<Word> * FileLoader::getAllWords(int max, int master)
{
	ifstream ifs(filepath);
	bool wordFinded = false;
	bool originFinded = false;
	bool paraphraseFinded = false;
	bool masteredFinded = false;
	string line;
	vector<Word> * result = new vector<Word>();

	Word word;
	unsigned int lineCount = 0;
	unsigned int wordCount = 0;
	while (getline(ifs,line) && wordCount < max)
	{
		lineCount++;
		//寻找单词标签
		if (line == "<word>")
		{
			wordFinded = true;
			word.startLine = lineCount;
			continue;
		}

		if (line == "</word>")
		{
			word.lineCount = lineCount - word.startLine + 1;
			if (word.mastered < master && word.type == language)
			{
				result->push_back(word);
				wordCount++;
			}
				
			wordFinded = false;
			originFinded = false;
			paraphraseFinded = false;
			masteredFinded = false;
			word.paraphrase.clear();
		}

		//语种标签
		if (line == "<jp>")
		{
			word.type = JP;
			originFinded = true;
			continue;
		}

		if (line == "<en>")
		{
			word.type = EN;
			originFinded = true;
			continue;
		}

		if (line == "</jp>" || line == "</en>")
		{
			originFinded = false;
			continue;
		}

		//释义标签
		if (line == "<paraphrase>")
		{
			paraphraseFinded = true;
			continue;
		}

		if (line == "</paraphrase>")
		{
			paraphraseFinded = false;
			continue;
		}

		//是否掌握标签
		if (line == "<mastered>")
		{
			masteredFinded = true;
			continue;
		}

		if (line == "</mastered>")
		{
			masteredFinded = false;
			continue;
		}


		if (wordFinded && originFinded)
		{
			word.origin = line;
		}

		if (wordFinded && paraphraseFinded)
		{
			word.paraphrase.push_back(line);
		}

		if (wordFinded && masteredFinded)
		{
			word.mastered_tag_line = lineCount;
			word.mastered = atoi(line.c_str());
		}
	}
	ifs.close();
	return result;
}

vector<Sentence> * FileLoader::getAllSentences(int max, int master)
{
	ifstream ifs(filepath);
	bool sentenceFinded = false;
	bool originFinded = false;
	bool paraphraseFinded = false;
	bool masteredFinded = false;

	string line;
	vector<Sentence> * result = new vector<Sentence>();

	Sentence sentence;
	unsigned int lineCount = 0;
	unsigned int sentCount = 0;
	while (getline(ifs, line) && sentCount < max)
	{
		lineCount++;
		//寻找单词标签
		if (line == "<sentence>")
		{
			sentenceFinded = true;
			sentence.startLine = lineCount;
			continue;
		}

		if (line == "</sentence>")
		{
			sentence.lineCount = lineCount - sentence.startLine + 1;
			if (sentence.mastered < master && sentence.type == language)
			{
				result->push_back(sentence);
				sentCount++;
			}
				
			sentenceFinded = false;
			originFinded = false;
			paraphraseFinded = false;
			masteredFinded = false;
			sentence.paraphrase.clear();
		}

		//语种标签
		if (line == "<jp>")
		{
			sentence.type = JP;
			originFinded = true;
			continue;
		}

		if (line == "<en>")
		{
			sentence.type = EN;
			originFinded = true;
			continue;
		}

		if (line == "</jp>" || line == "</en>")
		{
			originFinded = false;
			continue;
		}

		//释义标签
		if (line == "<paraphrase>")
		{
			paraphraseFinded = true;
			continue;
		}

		if (line == "</paraphrase>")
		{
			paraphraseFinded = false;
			continue;
		}


		//是否掌握标签
		if (line == "<mastered>")
		{
			masteredFinded = true;
			continue;
		}

		if (line == "</mastered>")
		{
			masteredFinded = false;
			continue;
		}


		if (sentenceFinded && originFinded)
		{
			sentence.origin = line;
		}

		if (sentenceFinded && paraphraseFinded)
		{
			sentence.paraphrase.push_back(line);
		}

		if (sentenceFinded && masteredFinded)
		{
			sentence.mastered_tag_line = lineCount;
			sentence.mastered = atoi(line.c_str());
		}
	}
	ifs.close();
	return result;
}

void FileLoader::addWord(Word word)
{
	ofstream ofs(filepath,ios::app);
	ofs << "<word>" << endl;
	switch (word.type)
	{
	case 0:
		ofs << "<en>" << endl;
		break;
	default:
		ofs << "<jp>" << endl;
		break;
	}
	ofs << word.origin << endl;
	switch (word.type)
	{
	case 0:
		ofs << "</en>" << endl;
		break;
	default:
		ofs << "</jp>" << endl;
		break;
	}
	ofs << "<paraphrase>" << endl;
	for (string iter : word.paraphrase)
	{
		ofs << iter << endl;
	}	
	ofs << "</paraphrase>" << endl;
	ofs << "<mastered>" << endl;
	ofs << "0" << endl;
	ofs << "</mastered>" << endl;
	ofs << "</word>" << endl;
	ofs.close();
}

void FileLoader::addSentence(Sentence sentence)
{
	ofstream ofs(filepath, ios::app);
	ofs << "<sentence>" << endl;
	switch (sentence.type)
	{
	case 0:
		ofs << "<en>" << endl;
		break;
	default:
		ofs << "<jp>" << endl;
		break;
	}
	ofs << sentence.origin << endl;
	switch (sentence.type)
	{
	case 0:
		ofs << "</en>" << endl;
		break;
	default:
		ofs << "</jp>" << endl;
		break;
	}
	ofs << "<paraphrase>" << endl;
	for (string iter : sentence.paraphrase)
	{
		ofs << iter << endl;
	}
	ofs << "</paraphrase>" << endl;
	ofs << "<mastered>" << endl;
	ofs << "0" << endl;
	ofs << "</mastered>" << endl;
	ofs << "</sentence>" << endl;
	ofs.close();
}

void FileLoader::ModifyLineData(int lineNum, string lineData)
{
	ifstream in;
	in.open(filepath);
	string strFileData = "";
	int line = 1;
	char tmpLineData[1024] = { 0 };
	while (in.getline(tmpLineData, sizeof(tmpLineData)))
	{
		if (line == lineNum)
		{
			strFileData += string(lineData);
			strFileData += "\n";
		}
		else
		{
			strFileData += string(tmpLineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
	//写入文件
	ofstream out;
	out.open(filepath);
	out.flush();
	out << strFileData;
	out.close();
}

void FileLoader::delete_(int startLine, int lineCount)
{
	ifstream ifs;
	ifs.open(filepath);
	string line = "";//暂存一行的数据
	string strFileData = "";//暂存删除行之前所有的数据
	int lineCount_ = 0;
	while (getline(ifs,line))
	{
		lineCount_++;
		if (lineCount_ >= startLine && lineCount_ <= startLine + lineCount - 1)
		{
			//...
		}
		else
		{
			strFileData += string(line);
			strFileData += "\n";
		}
	}
	ifs.close();
	// write
	ofstream ofs;
	ofs.open(filepath);
	ofs.flush();
	ofs << strFileData;
	ofs.close();
}


void FileLoader::test()
{
	
}