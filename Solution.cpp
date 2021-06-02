#include <vector>
#include <string>

using namespace std;

class wordSearch{
    bool search(vector<vector<char>> & grid, int i, int j, string & word,int idx,vector<vector<bool>>& visited){
        if(idx == word.length() -1) 
            return true;
        visited[i][j] = true;
        if(i > 0 && !visited[i-1][j] && grid[i-1][j] == word[idx+1] && search(grid,i-1,j,word,idx+1,visited))
            return true;
        if(j > 0 && !visited[i][j-1] && grid[i][j -1] == word[idx+1] && search(grid,i,j -1,word,idx+1,visited))
            return true;
        if(i <  grid.size() - 1 && !visited[i + 1][j] && grid[i + 1][j] == word[idx+1] && search(grid,i + 1,j,word,idx+1,visited))
            return true;
        if(j <  grid.size() && !visited[i][j+1] && grid[i][j+1] == word[idx+1] && search(grid,i,j+1,word,idx+1,visited))
            return true;

        visited[i][j] == false;
        return false;
        
    }
public:
    bool checkExistence(vector<vector<char>>& grid,string word)
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i = 0; i<r; ++i)
            for (int j = 0; j< c; ++j)
             if(grid[i][j] == word[0] && search(grid,i,j,word,0,visited)) 
                return true;
            return false;

    }
};

int main()
{
wordSearch C1();

vector<vector<char>> grid_vector{{"A","B","C","D"},{"S","D","E","A"},{"A","N","S","E"}};
C1.checkExistence(grid_vector,"ASA");
return(0);
}