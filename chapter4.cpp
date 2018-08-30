//
// Created by shniu on 18-8-30.
//

#include "essential.h"

void chapter4::main() {
    MyStack stack;
    stack.push("123");
    stack.push("abc");
    cout << stack.size() << endl;
    string elem;
    stack.pop(elem);
    cout << elem << endl;

    stack.peek(elem);
    cout << elem << endl;
    cout << stack.size() << endl;
    cout << stack.find("123") <<endl;
}
