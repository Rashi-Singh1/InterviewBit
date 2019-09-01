int Solution::isValidSudoku(const vector<string> &A) {
    vector< unordered_set<int> > arrayCol(9);
    vector< vector< unordered_set<int> > > arrayBlock;
    for(int i = 0;i<3;i++)
    {
        vector<unordered_set<int> > temp(3);
        arrayBlock.push_back(temp);
    }
    for(int i = 0;i<A.size();i++)
    {
        unordered_set<int>array;
        for(int j = 0;j<A[i].size();j++)
        {
            if(A[i][j] == '.') continue;
            else{
                int temp = (int)(A[i][j]-'0');
                if(array.find(temp) == array.end()) array.insert(temp);
                else return 0;
                if(arrayCol[j].find(temp) == arrayCol[j].end()) arrayCol[j].insert(temp);
                else return 0;
                if(arrayBlock[i/3][j/3].find(temp) == arrayBlock[i/3][j/3].end()) arrayBlock[i/3][j/3].insert(temp);
                else return 0;
            }
        }
    }
    return 1;
}


//Damn found a mind boggling solution in youtube leetcode video, which i'll type tomorrow