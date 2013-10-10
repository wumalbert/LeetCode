class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        if(m <= 1 || n <= 1) return;
        // up
        for (int i = 0; i < n; ++i)
            if ('O' == board[0][i])
                solve(board, 0, i);
        // right
        for (int i = 1; i < m; ++i)
            if ('O' == board[i][n-1])
                solve(board, i, n-1);
        // bottom         
        for (int i = n-2; i >= 0; --i)
            if ('O' == board[m-1][i])
                solve(board, m-1, i);
        // left      
        for (int i = m-2; i > 0; --i)
            if ('O' == board[i][0])
                solve(board, i, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = (board[i][j] == '.' ? 'O' : 'X');
            }
        }
    }
private:
    void solve(vector<vector<char> > &board, int row, int col) {
        int m = board.size(), n = board[0].size();
        queue<int> visit_queue;
        visit_queue.push(row*n + col);
        board[row][col] = '.';
        while (!visit_queue.empty()) {
            int index = visit_queue.front();
            visit_queue.pop();
            int r = index / n, c = index % n;
            if (r > 0 && 'O' == board[r-1][c]) {
                board[r-1][c] = '.';
                visit_queue.push(index-n);
            }
            if (c < n-1 && 'O' == board[r][c+1]) {
                board[r][c+1] = '.';
                visit_queue.push(index+1);
            }
            if (r < m-1 && 'O' == board[r+1][c]) {
                board[r+1][c] = '.';
                visit_queue.push(index+n);
            }
            if (c > 0 && 'O' == board[r][c-1]) {
                board[r][c-1] = '.';
                visit_queue.push(index-1);
            }
        }
    }
};