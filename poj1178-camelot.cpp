#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000;
int king;
vector<int> knight;
int king_dist[64][64], knight_dist[64][64];
int king_x[] = {-1, 1, -1, 1, -1, 1, 0, 0}, king_y[] = {0, 0, -1, -1, 1, 1, -1, 1};
int knight_x[] = {-2, 2, -2, 2, -1, 1, -1, 1}, knight_y[] = {-1, -1, 1, 1, -2, -2, 2, 2};

void
init()
{
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++) king_dist[i][j] = knight_dist[i][j] = INF;
    }
    for (int i = 0; i < 64; i++)
    {
        king_dist[i][i] = knight_dist[i][i] = 0;
        int x = i / 8, y = i % 8;
        for (int j = 0; j < 8; j++)
        {
            int king_nx = x + king_x[j], king_ny = y + king_y[j];
            int knight_nx = x + knight_x[j], knight_ny = y + knight_y[j];
            if (king_nx >= 0 && king_nx < 8 && king_ny >= 0 && king_ny < 8)
            {
                int next_king = king_nx * 8 + king_ny;
                king_dist[i][next_king] = 1;
            }
            if (knight_nx >= 0 && knight_nx < 8 && knight_ny >= 0 && knight_ny < 8)
            {
                int next_knight = knight_nx * 8 + knight_ny;
                knight_dist[i][next_knight] = 1;
            }
        }
    }
}

void
floyd()
{
    for (int k = 0; k < 64; k++)
    {
        for (int i = 0; i < 64; i++)
        {
            for (int j = 0; j < 64; j++)
            {
                if (king_dist[i][j] > king_dist[i][k] + king_dist[k][j])
                {
                    king_dist[i][j] = king_dist[i][k] + king_dist[k][j];
                }
                if (knight_dist[i][j] > knight_dist[i][k] + knight_dist[k][j])
                {
                    knight_dist[i][j] = knight_dist[i][k] + knight_dist[k][j];
                }
            }
        }
    }
}

int
main()
{
    string board;
    cin >> board;
    king = (board[0] - 'A') * 8 + (board[1] - '1');
    for (int i = 2; i < board.size(); i += 2)
    {
        int temp = (board[i] - 'A') * 8 + (board[i + 1] - '1');
        knight.push_back(temp);
    }
    init();
    floyd();
    int res = INF;
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            int dist = 0;
            for (int k = 0; k < knight.size(); k++) dist += knight_dist[knight[k]][i];
            for (int k = 0; k < knight.size(); k++)
            {
                res = min(res, dist - knight_dist[knight[k]][i] + knight_dist[knight[k]][j] + knight_dist[j][i] + king_dist[king][j]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
