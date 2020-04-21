                


                /***********CAN MODIFY THIS APPROACH FOR ANY SIMILAR TYPE OF QUES************/

/*
    here triplets so maintain 3 numbers, if sum in range return, if not :-
    if sum is larger, replace largest with the next number(if the next number comes out to be smaller)
    if sum is smaller, replace the smallest numb with the next numb (if the next number comes out to be larger)
    do not forget to check the sum once again affter the loop finishes
*/

//O(n) time and O(1) space sol
int Solution::solve(vector<string> &A) {
    if(A.size() < 3) return 0;
    else{
        vector<float> ar = {stof(A[0]), stof(A[1]), stof(A[2])};
        sort(ar.begin(), ar.end());
        for(int i = 3; i < A.size() ; i++){
            double sum = (double)ar[0] + (double)ar[1] + (double)ar[2];
            if(1.000000 < sum && sum < 2.000000) return 1;
            else if(sum > 2.000000) {
                ar[2] = min(stof(A[i]), ar[2]);
                sort(ar.begin(), ar.end());
            } 
            else{
                ar[0] = max(ar[0], stof(A[i]));
                sort(ar.begin(), ar.end());
            }
        }
        double sum = (double)ar[0] + (double)ar[1] + (double)ar[2];
        if(1.000000 < sum && sum < 2.000000) return 1;
    }
    return 0;
}

int Solution::solve(vector<string> &A) {
    if(A.size()<=2) return 0;
    double a,b,c;
    string s1 = A[0],s2 = A[1],s3 = A[2];
    a = stof(A[0]);
    b = stof(A[1]);
    c = stof(A[2]);
    if(a+b+c <2 && a+b+c >1) return 1;
    for(int i = 3;i<A.size();i++)
    {
        double temp;
        temp = stof(A[i]);
        //cout<<a+b+c<<endl;
        if(a+b+c > 2) {
            if(a>b)
            {
                if(a > c)
                {
                    if(temp < a) a = temp;
                }else{
                    if(temp < c) c = temp;
                }
            }else{
                if(b > c)
                {
                    if(temp < b) b = temp;
                }else{
                    if(temp < c) c = temp;
                }
            }
        }else if(a+b+c < 1)
        {
             if(a<b)
            {
                if(a < c)
                {
                    if(temp > a) a = temp;
                }else{
                    if(temp > c) c = temp;
                }
            }else{
                if(b < c)
                {
                    if(temp > b) b = temp;
                }else{
                    if(temp > c) c = temp;
                }
            }
        }else{
            return 1;
        }
    }
    if(a+b+c < 2 && a+b+c >1) return 1;
    return 0;
}

//after reset
int Solution::solve(vector<string> &A) {
    if(A.size() < 3) return 0;
    else{
        vector<float> array;
        array.push_back(stof(A[0]));
        array.push_back(stof(A[1]));
        array.push_back(stof(A[2]));
        sort(array.begin(),array.end());
        for(int i = 3;i<A.size();i++)
        {
            float temp = array[0]+array[1]+array[2];
            if(temp < 2.000000 && temp > 1.000000) return 1;
            else if(temp >= 2.000000 )
            {
                if(stof(A[i]) < array[2])
                {
                    array[2] = stof(A[i]);
                    sort(array.begin(),array.end());
                }
            }
            else
            {
                if(stof(A[i]) > array[0])
                {
                    array[0] = stof(A[i]);
                    sort(array.begin(),array.end());
                }
            }
        }
        float temp = array[0]+array[1]+array[2];
        if(temp < 2.000000 && temp > 1.000000) return 1;
    }
    return 0;
}
