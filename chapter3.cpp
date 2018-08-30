//
// Created by shniu on 18-8-30.
//

#include "essential.h"

void chapter3::main() {
    cout << "Welcome to chapter3." << endl;
    word_counts();
}

inline void chapter3::initialize_exclude_set(set<string> &exclude_set) {
    static string exclude_words[] = {
            "a", "an", "or", "the", "and", "but"
    };
    exclude_set.insert(exclude_words, exclude_words + sizeof(exclude_words) / sizeof(*exclude_words));
    // set<string> exclude_set(filter_str_array, filter_str_array + sizeof(filter_str_array) / sizeof(*filter_str_array));
    /*cout << sizeof(filter_str_array) << endl;
    cout << filter_str_array << endl;
    cout << sizeof(*filter_str_array) << endl;
    cout << *filter_str_array << endl;
    cout << sizeof(filter_str_array) / sizeof(*filter_str_array) << endl;
    cout << filter_sets.size() << endl;*/
}

inline void chapter3::process_file(map<string, int> &word_count,
                            const set<string> &exclude_set,
                            ifstream &ifile) {
    string word;
    while (ifile >> word) {
        if(exclude_set.count(word)) {
            continue;
        }

        word_count[word]++;
    }
}

inline void chapter3::display_word_count(map<string, int> &word_count, ostream &os) {
    map<string, int>::const_iterator
            itr = word_count.begin(),
            end = word_count.end();

    os << "Word count:\n";
    while (itr != end) {
        os << "\t"
           << itr->first
           << ": "
           << itr->second
           << endl;
        ++itr;
    }
    os << endl;
}

inline void chapter3::user_query(const map<string, int> &word_count) {
    string search_word;
    cout << "Please enter a word to search (q to quit): ";
    cin >> search_word;

    while (search_word != "q" && search_word.size()) {
        map<string, int>::const_iterator itr;
        if ((itr = word_count.find(search_word)) != word_count.end()) {
            cout << "Found "
                 << itr->first
                 << " "
                 << itr-> second
                 << " times" << endl;
        } else {
            cout << "Not found!" << endl;
        }

        cout << "Another search (q to quit): ";
        cin >> search_word;
    }
}

void chapter3::word_counts() {
    // filter word
    set<string> exclude_set;
    initialize_exclude_set(exclude_set);

    // read file
    ifstream ifile("/tmp/a.txt");
    if (!ifile) {
        cerr << "Oops! Cant't open the input file." << endl;
        exit(1);
    }

    // process word count
    map<string, int> word_count;
    process_file(word_count, exclude_set, ifile);

    // query
    user_query(word_count);

    // display
    display_word_count(word_count);
}


