#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct info{
	string head;
	int number;
	string ori_num;
	string tail;
};

vector<struct info>vec;

string to_lower(string str)
{
	string ret;
	for (int i = 0;i<str.size();i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		ret[i] = str[i];
	}
	return (ret);
}

bool compare(struct info &a, struct info &b)
{
	string str_a = to_lower(a.head);
	string str_b = to_lower(b.head);

	if (str_a == str_b)
	{
		if (a.number == b.number)
			return false;
		return a.number < b.number;
	}
	else if (str_a < str_b)
		return false;
	else
		return true;
}

void div(string &str)
{
	struct info input;
	int ret = 0;

	while (str[ret] < '0' || str[ret] > '9')
		ret++;
	input.head = str.substr(0,ret);
	str = str.substr(ret);
	ret = 0;
	while (str[ret] >= '0' && str[ret] <= '9')
		ret++;
	input.ori_num = str.substr(0, ret);
	input.number = stoi(str.substr(0, ret));
	str = str.substr(ret);
	input.tail = str;
	vec.push_back(input);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

	for (int i=0;i<files.size();i++)
	{
		div(files[i]);
		cout<<vec[i].head<<endl;
	}
	sort(vec.begin(),vec.end(),compare);
	for (int i=0;i<vec.size();i++)
	{
		string tmp = vec[i].head;
		tmp += vec[i].ori_num;
		tmp += vec[i].tail;
		answer.push_back(tmp);
	}
    return answer;
}
