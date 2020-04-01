#include <string>
#include <vector>

using namespace std;

vector<int> box;
int ans = 0;

void box_move(int doll)
{
    if (box.empty())
        box.push_back(doll);
    else
    {
        if (box.back() == doll)
        {
            ans++;
            box.pop_back();
        }
        else
            box.push_back(doll);
    }
}

void up(int number, vector<vector<int>> &board)
{
    for (int y = 0; y < board.size(); y++)
    {
        if (board[y][number - 1] != 0)
        {
            box_move(board[y][number - 1]);
            board[y][number - 1] = 0;
            return;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        up(moves[i], board);
    }
    answer = ans;
    return answer;
}