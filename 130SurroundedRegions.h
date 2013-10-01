class Solution {
private:
    void solve(const vector<vector<char> > &board, vector<vector<bool> > &visited, int row, int col)
    {
        int m = board.size();
        int n = board[0].size();
        
        queue<int> visitQueue;
        visited[row][col] = true;
        visitQueue.push(row*n + col);
        
        while (!visitQueue.empty())
        {
            int index = visitQueue.front();
            visitQueue.pop();
            
            int r = index / n;
            int c = index % n;
            
            if (r > 0 && 'O' == board[r-1][c] && !visited[r-1][c])
            {
                visited[r-1][c] = true;
                visitQueue.push(index-n);
            }
            if (c < n-1 && 'O' == board[r][c+1] && !visited[r][c+1])
            {
                visited[r][c+1] = true;
                visitQueue.push(index+1);
            }
            if (r < m-1 && 'O' == board[r+1][c] && !visited[r+1][c])
            {
                visited[r+1][c] = true;
                visitQueue.push(index+n);
            }
            if (c > 0 && 'O' == board[r][c-1] && !visited[r][c-1])
            {
                visited[r][c-1] = true;
                visitQueue.push(index-1);
            }
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        
        if(m <= 1 || n <= 1) return;
        
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        
        // up
        for (int i = 0; i < n; ++i)
            if ('O' == board[0][i] && !visited[0][i])
                solve(board, visited, 0, i);
        // right        
        for (int i = 1; i < m; ++i)
            if ('O' == board[i][n-1] && !visited[i][n-1])
                solve(board, visited, i, n-1);
        // bottom         
        for (int i = n-2; i >= 0; --i)
            if ('O' == board[m-1][i] && !visited[m-1][i])
                solve(board, visited, m-1, i);
        // left      
        for (int i = m-2; i > 0; --i)
            if ('O' == board[i][0] && !visited[i][0])
                solve(board, visited, i, 0);
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};