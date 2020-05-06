#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<char>vec;

string change_value(int n, int val){
	//n 진법, val 원본 값
	string ret;

	while (val)
	{
		int tmp = val % n;
		if (tmp >= 10)
			ret += 10 - tmp + 'A';
		else
			ret += tmp + '0';
		val /= n;
	}
	reverse(ret.begin(), ret.end());
	for (int i=0;i<ret.size();i++)
		vec.push_back(ret[i]);
	return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
	int cnt = 1;

	while (vec.size() >= m * t)
	{
		change_value(n, cnt);
		cnt++;
	}
    return answer;
}
