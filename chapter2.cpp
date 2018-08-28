//
// Created by shniu on 18-8-27.
//

#include <algorithm>
#include "essential.h"

namespace chapter2 {

    bool calc_elements(vector<int> &ivec, int pos) {
        if (pos < 0 || pos > 64) {
            cerr << "Sorry, invalid position." << pos << endl;
            return false;
        }

        for (int ix = static_cast<int>(ivec.size() + 1); ix <= pos; ++ix) {
            ivec.push_back(ix * (3 * ix - 1) / 2);
        }

        return true;
    }

    void display_elem(vector<int> &ivec, const string &title, ostream &os) {
        os << title << '\n';
        for (int ix = 0; ix < ivec.size(); ++ix) {
            os << ivec[ix] << ' ';
        }

        os << endl;
    }

    bool calc_elems(vector<int> &ivec, int pos) {
        if (pos < 0 || pos > 64) {
            cerr << "Sorry, invalid position." << pos << endl;
            return false;
        }

        if (ivec.size() < pos) {
            really_calc_elems(ivec, pos);
        }
        return true;
    }

    inline void really_calc_elems(vector<int> &ivec, int pos) {
        for (int ix = static_cast<int>(ivec.size() + 1); ix <= pos; ++ix) {
            ivec.push_back(ix * (3 * ix - 1) / 2);
        }
    }

    inline bool check_validity(int pos) {
        return !(pos < 0 || pos > 64);
    }

    const vector<int> * pent_series(int pos) {
        static vector<int> elem;
        if (check_validity(pos) && pos > elem.size()) {
            for (int ix = static_cast<int>(elem.size() + 1); ix <= pos; ++ix) {
                elem.push_back(ix * (3 * ix - 1) / 2);
            }
        }

        return &elem;
    }

    bool find_elem(int pos, int &elem) {
        if (!check_validity(pos)) {
            cerr << "Sorry, Invalid position." << pos << endl;
            elem = 0;
            return false;
        }

        const vector<int> * ptr = pent_series(pos);
        elem = (*ptr)[pos - 1];
        return true;
    }

    int max(int t1, int t2) {
        return t1 > t2 ? t1 : t2;
    }
    float max(float t1, float t2) {
        return t1 > t2 ? t1 : t2;
    }
    string max(string &t1, string &t2) {
        return t1 > t2 ? t1 : t2;
    }
    int max(vector<int> &vec) {
        return *max_element(vec.begin(), vec.end());
    }
    float max(vector<float> &vec) {
        return *max_element(vec.begin(), vec.end());
    }
    string max(vector<string> &vec) {
        return *max_element(vec.begin(), vec.end());
    }
    int max(const int *parray, int size) {
        return *max_element(parray, parray + size);
    }
    float max(const float *parray, int size) {
        return *max_element(parray, parray + size);
    }
    string max(const string *parray, int size) {
        return *max_element(parray, parray + size);
    }

}
