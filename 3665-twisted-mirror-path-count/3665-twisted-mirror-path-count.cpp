class Solution {
public:
const int mod=1e9+7;
int helper(vector<vector<int>>&grid,vector<vector<vector<int>>>&v,int i,int j,int p)
{
    if(i==grid.size()-1&&j==grid[0].size()-1)
    {
        return 1;
    }
    if(v[i][j][p]!=-1)
    {
        return v[i][j][p];
    }
    int ans=0;
    if(grid[i][j]==1)
    {
        if(p==1)
        {
            if(j+1<grid[0].size())
            {
                ans=helper(grid,v,i,j+1,2);
            }
        }
        else if(p==2)
        {
            if(i+1<grid.size())
            {
                ans=helper(grid,v,i+1,j,1);
            }
        }
    }
    else if(grid[i][j]==0){
        int ans1=0;int ans2=0;
        if(i+1<grid.size())
        {
            ans1=helper(grid,v,i+1,j,1);
        }
        if(j+1<grid[0].size())
        {
            ans2=helper(grid,v,i,j+1,2);
        }
        ans=(ans1+ans2)%mod;
    }
    return v[i][j][p]=ans;
}
    int uniquePaths(vector<vector<int>>& grid) {
       vector<vector<vector<int>>> v(
    grid.size(),
    vector<vector<int>>(
        grid[0].size(),
        vector<int>(3, -1)
    )
);
        helper(grid,v,0,0,0);
        return v[0][0][0];
    }
};