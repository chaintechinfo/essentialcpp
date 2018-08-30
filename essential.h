//
// Created by shniu on 18-8-27.
//

#ifndef ESSENTIALCPP_ESSENTIAL_H
#define ESSENTIALCPP_ESSENTIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

namespace chapter1 {
    void demo1();

    void demo2();
    void demo2_cstyle();

    void demo3();

    void file_op();
}

namespace chapter2 {

    // Calculate pentagonal seq
    bool calc_elements(vector<int> &ivec, int pos);

    // Display elements
    void display_elem(vector<int> &ivec, const string &title, ostream &os=cout);

    bool calc_elems(vector<int> &, int);
    inline void really_calc_elems(vector<int> &, int);

    // function ptr
    const vector<int> * pent_series(int pos);
    bool find_elem(int pos, int &elem);

    // function overload
    int max(int, int);
    float max(float, float);
    string max(string &, string &);
    int max(vector<int> &);
    float max(vector<float> &);
    string max(vector<string> &);
    int max(const int *, int size);
    float max(const float *, int size);
    string max(const string *, int size);

    template <typename T>
    T max2(T t1, T t2) {
        return t1 > t2 ? t1 : t2;
    };

    template <typename T>
    T max2(vector<T> &vec) {
        return *max_element(vec.begin(), vec.end());
    }

    template <typename T>
    T max2(const T *parray, int size) {
        return *max_element(parray, parray + size);
    }
}

// Related to STL
namespace chapter3 {
    using namespace std;

    // Word counts
    inline void initialize_exclude_set(set<string> &exclude_set);
    inline void process_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile);
    inline void display_word_count(map<string, int> &word_count, ostream &os = cout);
    inline void user_query(const map<string, int> &word_count);
    void word_counts();

    void main();
}

#endif //ESSENTIALCPP_ESSENTIAL_H
