stack<int> Minimum;
stack<int> actual;

MinStack::MinStack() {
    while(!Minimum.empty()) Minimum.pop();
    while(!actual.empty()) actual.pop();
}

void MinStack::push(int x) {
    actual.push(x);
    if(Minimum.empty()) Minimum.push(x);
    else{
        if(Minimum.top() >= x) Minimum.push(x);
    }
}

void MinStack::pop() {
    if(!Minimum.empty())
    {
        if(Minimum.top() == actual.top()) Minimum.pop();
        actual.pop();
    }
    else{
        if(!actual.empty()) actual.pop();
    }
}

int MinStack::top() {
    if(!actual.empty()) return actual.top();
    else return -1;
}

int MinStack::getMin() {
    if(!Minimum.empty()) return Minimum.top();
    else return -1;
}

