#include"FileLoader.h"
using namespace std;
FileLoader::FileLoader(const char* path)
{
	fs = fstream(path);
	if (!fs.is_open())
	{
		cout << "û��" << endl;
	}	
	fs.close();
	this->filepath = path;
}

vector<Word_And_Sentence> * FileLoader::getAllWords(int max, int master)
{
	ifstream ifs(filepath);
	bool wordFinded = false;
	bool originFinded = false;
	bool paraphraseFinded = false;
	bool masteredFinded = false;
	string line;
	vector<Word_And_Sentence> * result = new vector<Word_And_Sentence>();

	Word_And_Sentence word;
	unsigned int lineCount = 0;
	unsigned int wordCount = 0;
	while (getline(ifs,line) && wordCount < max)
	{
		lineCount++;
		//Ѱ�ҵ��ʱ�ǩ
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

		//���ֱ�ǩ
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

		//�����ǩ
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

		//�Ƿ����ձ�ǩ
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

vector<Word_And_Sentence> * FileLoader::getAllMasteredWords(int master)
{
	ifstream ifs(filepath);
	bool wordFinded = false;
	bool originFinded = false;
	bool paraphraseFinded = false;
	bool masteredFinded = false;
	string line;
	vector<Word_And_Sentence> * result = new vector<Word_And_Sentence>();

	Word_And_Sentence word;
	unsigned int lineCount = 0;

	while (getline(ifs, line))
	{
		lineCount++;
		//Ѱ�ҵ��ʱ�ǩ
		if (line == "<word>")
		{
			wordFinded = true;
			word.startLine = lineCount;
			continue;
		}

		if (line == "</word>")
		{
			word.lineCount = lineCount - word.startLine + 1;
			if (word.mastered >= master && word.type == language)
			{
				result->push_back(word);
			}

			wordFinded = false;
			originFinded = false;
			paraphraseFinded = false;
			masteredFinded = false;
			word.paraphrase.clear();
		}

		//���ֱ�ǩ
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

		//�����ǩ
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

		//�Ƿ����ձ�ǩ
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

vector<Word_And_Sentence> * FileLoader::getAllSentences(int max, int master)
{
	ifstream ifs(filepath);
	bool sentenceFinded = false;
	bool originFinded = false;
	bool paraphraseFinded = false;
	bool masteredFinded = false;

	string line;
	vector<Word_And_Sentence> * result = new vector<Word_And_Sentence>();

	Word_And_Sentence sentence;
	unsigned int lineCount = 0;
	unsigned int sentCount = 0;
	while (getline(ifs, line) && sentCount < max)
	{
		lineCount++;
		//Ѱ�ҵ��ʱ�ǩ
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

		//���ֱ�ǩ
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

		//�����ǩ
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


		//�Ƿ����ձ�ǩ
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

vector<Word_And_Sentence> * FileLoader::getAllMasteredSentences(int master)
{
	ifstream ifs(filepath);
	bool sentenceFinded = false;
	bool originFinded = false;
	bool paraphraseFinded = false;
	bool masteredFinded = false;

	string line;
	vector<Word_And_Sentence> * result = new vector<Word_And_Sentence>();

	Word_And_Sentence sentence;
	unsigned int lineCount = 0;

	while (getline(ifs, line))
	{
		lineCount++;
		//Ѱ�ҵ��ʱ�ǩ
		if (line == "<sentence>")
		{
			sentenceFinded = true;
			sentence.startLine = lineCount;
			continue;
		}

		if (line == "</sentence>")
		{
			sentence.lineCount = lineCount - sentence.startLine + 1;
			if (sentence.mastered >= master && sentence.type == language)
			{
				result->push_back(sentence);
			}

			sentenceFinded = false;
			originFinded = false;
			paraphraseFinded = false;
			masteredFinded = false;
			sentence.paraphrase.clear();
		}

		//���ֱ�ǩ
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

		//�����ǩ
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


		//�Ƿ����ձ�ǩ
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

void FileLoader::addWord(Word_And_Sentence word)
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

void FileLoader::addSentence(Word_And_Sentence sentence)
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

void FileLoader::ConfirmSettings(Setting settings)
{
	ifstream ifs(".\\userdata\\config.txt");
	string buffer;
	int lineCount = 0;
	while (getline(ifs, buffer))
	{
		lineCount++;
		vector<string> keyPair = split(buffer, ":");
		if (keyPair[0] == "BatchSize(word)" || keyPair[0] == "BatchSize(sentence)")
		{
			ModifyLineData(lineCount, "BatchSize(word):"+ to_string(settings.BatchSize_word), ".\\userdata\\config.txt");
		}
		if (keyPair[0] == "BatchSize(sentence)")
		{
			ModifyLineData(lineCount, "BatchSize(sentence):" + to_string(settings.BatchSize_sentence), ".\\userdata\\config.txt");
		}
		if (keyPair[0] == "Master(word)" || keyPair[0] == "Master(sentence)")
		{
			ModifyLineData(lineCount, "Master(word):" + to_string(settings.Master_word), ".\\userdata\\config.txt");
		}
	}
	ifs.close();
}


void FileLoader::ModifyLineData(int lineNum, string lineData, string filepath)
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
	//д���ļ�
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
	string line = "";//�ݴ�һ�е�����
	string strFileData = "";//�ݴ�ɾ����֮ǰ���е�����
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

void FileLoader::delete_(vector<Word_And_Sentence *>* deleteList)
{
	//�������ļ��е�λ�ý�������,��������ɾ����������ִ���
	sort(deleteList->begin(),deleteList->end(),GreaterSort);
	for (Word_And_Sentence* iter : *deleteList)
	{
		//TODO
	}
}

string FileLoader::loadOption(string key)
{
	ifstream ifs(cfg_filepath);
	string buffer;
	while (getline(ifs,buffer))
	{
		vector<string> keyPair = split(buffer, ":");
		if (key == keyPair[0])
		{
			return keyPair[1];
		}
	}
	return "ERR";
}

void FileLoader::changeOption(string key, string value)
{
	ifstream ifs(cfg_filepath);
	string buffer;
	int lineCount = 0;
	while (getline(ifs, buffer))
	{
		lineCount++;
		vector<string> keyPair = split(buffer, ":");
		if (key == keyPair[0])
		{
			ModifyLineData(lineCount,keyPair[0]+":"+ value , cfg_filepath);
		}
	}
}

vector<string> FileLoader::split(const string& str, const string& delim)
{
	vector<string> res;
	if ("" == str) return res;
	//�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����
	char * strs = new char[str.length() + 1]; //��Ҫ����
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p; //�ָ�õ����ַ���ת��Ϊstring����
		res.push_back(s); //����������
		p = strtok(NULL, d);
	}
	delete strs;
	delete d;
	delete p;
	return res;
}

void FileLoader::test()
{
	
}