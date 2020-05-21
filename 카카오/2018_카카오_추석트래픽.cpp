//18 : 53
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct info
{

} info;

void div(string str)
{
	int hh;
	int mm;
	double ss;
	double es;

	int year = stoi(str.substr(0, 4));
	str = str.substr(5);
	int month = stoi(str.substr(0, 2));
	str = str.substr(3);
	int day = stoi(str.substr(0, 2));
	str = str.substr(3);
	hh = stoi(str.substr(0, 2));
	str = str.substr(3);
	mm = stoi(str.substr(0, 2));
	str = str.substr(3);
	ss = stoi(str.substr(0, 2));
	str = str.substr(3);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			ss = ss + (double)pow(0.1, i) * stoi(str.substr(0, i));
			str = str.substr(i + 1);
			break;
		}
	}
	es = stoi(str.substr(0, 1));
	str = str.substr(1);
	if (str[0] != 's')
	{
		str = str.substr(1);
		es = es + (double)pow(0.1, str.size() - 1) * stoi(str.substr(0, str.size() - 1));
	}
	cout << ss - es << endl;
}

int solution(vector<string> lines)
{
	int answer = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		div(lines[i]);
		cout << endl;
	}
	return answer;
}
