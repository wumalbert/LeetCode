class Solution {
private:
    bool DFS(vector<vector<char> >& board, int row, int col, string& word, int index, vector<vector<bool> >& visited)
    {
        if (visited[row][col] || board[row][col] != word[index]) return false;
        
        if (word.length()-1 == index) return true;
        
        visited[row][col] = true;
        
        // right
        if (col < board[0].size()-1 && DFS(board, row, col+1, word, index+1, visited)) return true; 
        // down
        if (row < board.size()-1 && DFS(board, row+1, col, word, index+1, visited)) return true;
        // left
        if (row > 0 && DFS(board, row-1, col, word, index+1, visited)) return true;
        // up
        if (col > 0 && DFS(board, row, col-1, word, index+1, visited)) return true;
        
        visited[row][col] = false;
        
        return false;
    }
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty()) return false;
        int m = board.size();
        if (board[0].empty()) return false;
        int n = board[0].size();
        
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (DFS(board, i, j, word, 0, visited)) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (board.empty() || board[0].empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
    }
private:
    bool dfs(vector<vector<char> > &board, const string &word, int row, int col, int index) {
        static const int dx[] = {1, 0, -1,  0};  // the column increment
        static const int dy[] = {0, 1,  0, -1};  // the row increment
        if (board[row][col] != word[index]) return false;
        if (word.length()-1 == index) return true;
        board[row][col] = '#';
        for (int i = 0; i < 4; ++i) {
            int x = row + dx[i], y = col + dy[i];
            if (inboard(board.size(), board[0].size(), x, y) && dfs(board, word, x, y, index+1)) return true;
        }
        board[row][col] = word[index];
        return false;
    }
    bool inboard(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};