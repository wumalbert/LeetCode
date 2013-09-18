class Solution {
private:
    static const int size = 9;
    
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<bool> flag(size, false);
        
        // check the row
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
                flag[j] = false;
                
            for(int j = 0; j < size; ++j)
            {
                char c = board[i][j];
                if ('.' == c) continue;
                if (flag[c-'1']) return false;
                else flag[c-'1'] = true;
            }
        }
        
        // check the column
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
                flag[j] = false;
                
            for(int j = 0; j < size; ++j)
            {
                char c = board[j][i];
                if ('.' == c) continue;
                if (flag[c-'1']) return false;
                else flag[c-'1'] = true;
            }
        }
        
        // check the block
        for(int i = 0; i < size; i += size/3)
        {       
            for(int j = 0; j < size; j += size/3)
            {
                for(int k = 0; k < size; ++k)
                    flag[k] = false;
                
                for(int k = 0; k < size; ++k)
                {
                    char c = board[i+k/3][j+k%3];
                    if ('.' == c) continue;
                    if (flag[c-'1']) return false;
                    else flag[c-'1'] = true;
                }
            }
        }
        
        return true;
    }
};