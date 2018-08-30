//
// Created by shniu on 18-8-30.
//

#include "Stack.h"

inline bool MyStack::empty() {
    return _stack.empty();
}

bool MyStack::full() {
    return _stack.size() == _stack.max_size();
}

bool MyStack::push(const string &elem) {
    if (full()) {
        return false;
    }

    _stack.push_back(elem);
    return true;
}

bool MyStack::peek(string &elem) {
    if (empty()) {
        return false;
    }

    elem = _stack.back();
    return true;
}

bool MyStack::pop(string &elem) {
    if (empty()) {
        return false;
    }

    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool MyStack::find(const string &elem) {
    if (empty()) {
        return false;
    }

    vector<string>::const_iterator iter = _stack.begin();
    while (iter != _stack.end()) {
        if (*iter == elem) {
            return true;
        }
    }
    return false;
}
