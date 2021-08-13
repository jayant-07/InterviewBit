  int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    int n,m;
void dfs(int x,int y,vector<string> &A,vector<vector<bool>>&visited)
{
    visited[x][y]=true;
   for(int k=0;k<4;++k)
   {
      int  newx=x+dx[k];
      int newy=y+dy[k];
       if(newx<0||newx>=n||newy<0||newy>=m)
       continue;
       if(visited[newx][newy]||A[newx][newy]=='O')
       continue;
           dfs(newx,newy,A,visited);
       
   }

   
}
int Solution::black(vector<string>&A) {
 n=A.size();
    m=A[0].size();
    int ans=0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));

    for(int i=0;i<n;i++)
    { for(int j=0;j<m;j++)
        {
         if(!visited[i][j]&&A[i][j]=='X')
         {
         dfs(i,j,A,visited);
         ans++;
         }
        }
    }
  
    
    return ans;
}

