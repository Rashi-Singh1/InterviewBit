stack<int> m, mi;

MinStack::MinStack() {
    while(!m.empty()) m.pop();
    while(!mi.empty()) mi.pop();
}

void MinStack::push(int x) {
    m.push(x);
    if(mi.empty() || mi.top() >= x) mi.push(x);
}

void MinStack::pop() {
    if(m.empty()) return;
    int top = m.top();
    m.pop();
    if(!mi.empty() && mi.top() == top) mi.pop();
}

int MinStack::top() {
    return (m.empty() == true ? -1 : m.top());
}

int MinStack::getMin() {
    return (mi.empty() == true ? -1 : mi.top());
}