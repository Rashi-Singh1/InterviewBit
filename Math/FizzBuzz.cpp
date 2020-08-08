vector<string> Solution::fizzBuzz(int A) {
    vector<string> ans(A,"");
    for(int i = 1; i<= A; i++){
        if(i%15 == 0) ans[i-1] = "FizzBuzz";
        else if(i%3 == 0) ans[i-1] = "Fizz";
        else if(i%5 == 0) ans[i-1] = "Buzz";
        else ans[i-1] = std::to_string(i);
    }
    return ans;
}
