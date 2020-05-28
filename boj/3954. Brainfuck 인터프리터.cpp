//12 : 50
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector<int> arr;
string code, input;

int jump_code_A[4097];
int sm, sc, si;
bool flag = false;
int pointer = 0;
int s_val, e_val;

void jump_set()
{
	vector<int> vec;

	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] == '[')
			vec.push_back(i);
		else if (code[i] == ']')
		{
			jump_code_A[vec[vec.size() - 1]] = i;
			jump_code_A[i] = vec[vec.size() - 1];
			vec.pop_back();
		}
	}
}

void Input()
{
	string value;
	cin >> sm >> sc >> si;
	for (int i = 0; i < sm; i++)
		arr.push_back(0);
	cin >> code;
	jump_set();
	cin >> input;
}

void Reset()
{
	pointer = 0;
	flag = false;
	arr.clear();
	memset(jump_code_A, 0, sizeof(jump_code_A));
}

bool flow(int p)
{
	if (p >= arr.size() || p < 0)
		return false;
	return true;
}

void Solve()
{
	int f = false;
	int input_cnt = 0;
	int repeat = 0;
	s_val = 0;
	e_val = 0;

	for (int i = 0; i < code.size(); i++)
	{
		if (repeat >= 50000000)
		{
			flag = true;
			s_val = jump_code_A[e_val];
			break;
		}
		repeat++;
		if (!flow(pointer))
			return;
		switch (code[i])
		{
		case '-':
			arr[pointer]--;
			break;
		case '+':
			arr[pointer]++;
			break;
		case '<':
			pointer--;
			if (pointer == -1)
				pointer = arr.size() - 1;
			break;
		case '>':
			pointer++;
			if (pointer >= arr.size())
				pointer = 0;
			break;
		case '[':
			if (arr[pointer] == 0)
				i = jump_code_A[i];
			break;
		case ']':
			if (e_val == i)
				repeat++;
			else
			{
				e_val = i;
				repeat = 1;
			}
			if (arr[pointer] != 0)
				i = jump_code_A[i];
			break;
		case '.':
			break;
		case ',':
			if (input_cnt == input.size())
				arr[pointer] = 255;
			else
			{
				arr[pointer] = input[input_cnt];
				input_cnt++;
			}
			break;
		default:
			break;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		Input();
		Solve();
		if (!flag)
			cout << "Terminates\n";
		else
			cout << "Loops " << s_val << " " << e_val << "\n";
		Reset();
	}
}
