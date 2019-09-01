vector<string> Solution::fizzBuzz(int A) {
    vector<string> array;
    for(int i = 1;i<=A;i++)
    {
        if(i%3 == 0 && i%5!=0)
        {
            array.push_back("Fizz");
        }
        else if(i%5==0 && i%3!=0)
        {
            array.push_back("Buzz");
        }
        else if(i%3==0 && i%5==0)
        {
            array.push_back("FizzBuzz");
        }
        else{
            array.push_back(to_string(i));
        }
    }
    return array;
}