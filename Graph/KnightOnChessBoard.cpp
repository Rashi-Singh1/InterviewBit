vector<int> Left = {-1,1,2,2,1,-1,-2,-2};
vector<int> Right ={2,2,1,-1,-2,-2,-1,1};

bool valid(int x, int y, int row, int col,vector<vector<bool> >& visited)
{
    if(x >=0 && y>=0 && x< row && y<col && visited[x][y] == false) return true;
    else return false;
}

int Solution::knight(int row, int col, int sx, int sy, int dx, int dy) {
    if(row == 0 || col == 0) return -1;
    sx--;    sy--;    dx--;    dy--;
    queue<pair< pair<int,int> , int > > q; //pos, steps
    
    vector<vector<bool> > visited(row,vector<bool> (col,false));
    if(valid(sx,sy,row,col,visited)){
        q.push(make_pair(make_pair(sx,sy),0));
        while(!q.empty())
        {
            int curX = q.front().first.first;
            int curY = q.front().first.second;
            visited[curX][curY] = true;
            int steps = q.front().second;
            q.pop();
            if(curX == dx && curY == dy) return steps;
            for(int i = 0;i<Left.size();i++)
            {
                int newX = curX+Left[i];
                int newY = curY+Right[i];
                if(valid(newX,newY,row,col,visited)) q.push(make_pair(make_pair(newX,newY),steps+1));
            }
        }
    }else return -1;
    return -1;
}
