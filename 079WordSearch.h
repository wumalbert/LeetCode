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