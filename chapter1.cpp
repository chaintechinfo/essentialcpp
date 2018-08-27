//
// Created by shniu on 18-8-27.
//

#include <iomanip>
#include <cstring>
#include "essential.h"

namespace chapter1 {

    using namespace std;

    void demo1() {
        string user_name;
        string last_name;
        cout << "Please input your user name: ";
        cin >> user_name;
        cout << "Please input your last name: ";
        cin >> last_name;
        cout << user_name
             << " & "
             << last_name
             << endl;
    }

    void demo2() {

        string user_name;

        cout << "Please enter your name: ";
        // noskipws 不忽略空白字符
        cin >> noskipws >> user_name;

        switch (user_name.size()) {
            case 0:
                cout << "The user with no name" << endl;
                break;
            case 1:
                cout << "The name is too short" << endl;
                break;
            default:
                cout << "Your name is: "
                     << user_name
                     << endl;
                break;
        }
    }

    void demo2_cstyle() {
        const int size = 10;
        char user_name[size];

        cout << "Please enter your name: ";
        cin >> noskipws >> setw(size) >> user_name;

        switch (strlen(user_name)) {
            case 0:
                cout << "The user with no name" << endl;
                break;
            case 1:
                cout << "The name is too short" << endl;
                break;
            case 9:
                cout << "Too big\n";
            default:
                cout << "Hello, "
                     << user_name
                     << endl;
                break;
        }
    }

    void demo3() {
        // vector
        vector<int> ivec;
        int ival;

        while (cin >> ival) {
            ivec.push_back(ival);
        }
        // cin.clear();
        int sum = 0;
        for (int ix = 0; ix < ivec.size(); ++ix) {
            sum += ivec[ix];
        }

        int average = static_cast<int>(sum / ivec.size());

        cout << "Sum is: "
             << sum
             << ", average is: "
             << average
             << endl;
    }
}

