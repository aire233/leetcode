class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            int row[9] = {0}, col[9] = {0}, box[9] = {0};
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && row[board[i][j] - '1']++)
                    return false;
                if (board[j][i] != '.' && col[board[j][i] - '1']++)
                    return false;
                int r = i / 3 * 3 + j / 3, c = i % 3 * 3 + j % 3;
                if (board[r][c] != '.' && box[board[r][c] - '1']++)
                    return false;
            }
        }
        return true;
    }
};