//
// Created by shniu on 18-8-27.
//

#include "essential.h"

int main(int argc, char** argv) {
    // chapter1::demo1();
    // chapter1::demo2();
    // chapter1::demo2_cstyle();
    // chapter1::demo3();
    // chapter1::file_op();

    /// ---
    vector<int> pent;
    const string title("Pentagonal Numeric Series: ");

    /*if (chapter2::calc_elements(pent, 0)) {
        chapter2::display_elem(pent, title);
    }

    if (chapter2::calc_elements(pent, 10)) {
        chapter2::display_elem(pent, title);
    }*/

    // with inline
    /*if (chapter2::calc_elems(pent, 12)) {
        chapter2::display_elem(pent, title);
    }

    if (chapter2::calc_elems(pent, 10)) {
        chapter2::display_elem(pent, title);
    }*/

    /*int elem;
    if (chapter2::find_elem(128, elem)) {
        cout << elem << endl;
    }*/

    chapter2::max(1, 2);
    chapter2::max2(3, 2);

}