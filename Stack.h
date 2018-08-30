//
// Created by shniu on 18-8-30.
//

#ifndef ESSENTIALCPP_STACK_H
#define ESSENTIALCPP_STACK_H

#include <string>
#include <vector>
using namespace std;

class MyStack {
public:
    MyStack(){}

    bool empty();
    bool full();
    bool pop(string &elem);
    bool push(const string &elem);
    bool peek(string &elem);
    bool find(const string &elem);

    int size() {
        return _stack.size();
    };

private:
    vector<string> _stack;
};

#endif //ESSENTIALCPP_STACK_H
