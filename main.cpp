//
// Created by shniu on 18-8-27.
//

#include "essential.h"
#include "hash_table.h"

int main(int argc, char** argv) {
    // chapter1::demo1();
    // chapter1::demo2();
    // chapter1::demo2_cstyle();
    // chapter1::demo3();
    // chapter1::file_op();

    /// ---
    // vector<int> pent;
    // const string title("Pentagonal Numeric Series: ");

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

    // chapter2::max(1, 2);
    // chapter2::max2(3, 2);


    /// ---
    // chapter3::main();

    // chapter4::main();

    /// test for hash table
    ht_hash_table* ht = ht_new();
    auto k = const_cast<char *>("abc");
    auto v = const_cast<char *>("123");
    ht_insert(ht, k, v);
    char* v2 = ht_search(ht, k);
    std::cout << "find value: " << v2 << std::endl;
    ht_delete(ht, k);
    std::cout << "hash table size: " << ht->count << std::endl;
    ht_del_hash_table(ht);
}