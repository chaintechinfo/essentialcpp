//
// Created by shniu on 18-8-30.
//

#include "essential.h"

void chapter3::main() {
    cout << "Welcome to chapter3." << endl;
    // word_counts();
    // vector_sort();
    // query_families();
    stream_iterator();
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

void chapter3::file_to_vector(vector<string> &vec, ifstream &ifile) {
    string word;
    while (ifile >> word) {
        vec.push_back(word);
    }
}

// vector sort
void chapter3::vector_sort() {
    // read file
    ifstream ifile("/tmp/a.txt");
    if (!ifile) {
        cerr << "Oops! Cant't open the input file." << endl;
        exit(1);
    }

    vector<string> vec;
    file_to_vector(vec, ifile);

    sort(vec.begin(), vec.end(), LessThan());
    display_vector(vec);
}

// name is a file stream, we get the name from it.
// name's style as bellow:
//     surname1 child11 child12 ... child1N
//     surname2 child21 child22 ... child2N
void chapter3::populate_map(ifstream &name, map<string, vector<string>> &families) {

    string textline;
    // Parse a line per time
    while (getline(name, textline)) {
        string fam_name;
        vector<string> child;

        string::size_type pos = 0, prev_pos = 0, text_size = textline.size();

        // Parse a word per time, and ++pos to skip blank string
        while ((pos = textline.find_first_of(' ', pos)) != string::npos) {
            string::size_type end_pos = pos - prev_pos;

            // substr
            string item = textline.substr(prev_pos, end_pos);
            if (!prev_pos) {
                fam_name = item;
            } else {
                child.push_back(item);
            }

            prev_pos = ++pos;
        }

        if (prev_pos < text_size) {
            child.push_back(textline.substr(prev_pos, text_size - prev_pos));
        }

        if (!families.count(fam_name)) {
            families[fam_name] = child;
        } else {
            cerr << "Oops! we already have a family name"
                 << fam_name
                 << " in our family map"
                 << endl;
        }
    }
}

void chapter3::query_map(const map<string, vector<string>> &families, const string query_name) {
    map<string, vector<string>>::const_iterator it = families.find(query_name);

    if (it == families.end()) {
        cout << "Sorry, the " << query_name
             << " is not currently entered." << endl;
        return;
    }

    cout << "The " << query_name;
    if (!it->second.size()) {
        cout << " has no children.\n";
    } else {
        vector<string>::const_iterator viter = it->second.begin(), vend_iter = it->second.end();

        cout << " has " << it->second.size() << " children: ";
        while (viter != vend_iter) {
            cout << *viter << " ";
            ++viter;
        }
        cout << endl;
    }
}

void chapter3::display_families(map<string, vector<string>> &families, ostream &os) {
    map<string, vector<string>>::const_iterator
            iter = families.begin(),
            end_iter = families.end();

    while (iter != end_iter) {
        os << "The " << iter->first << " family ";
        if (iter->second.empty()) {
            os << "has no children.\n";
        } else {
            os << "has " << iter->second.size() << " children: ";
            vector<string>::const_iterator viter = iter->second.begin(), vend_iter = iter->second.end();

            while (viter != vend_iter) {
                os << *viter << " ";
                ++viter;
            }
            os << endl;
        }

        ++iter;
    }
}

void chapter3::query_families() {
    map<string, vector<string>> families;
    ifstream name_file("/tmp/families.txt");
    if (!name_file) {
        cerr << "Oops! Cant't open the input file." << endl;
        exit(1);
    }

    populate_map(name_file, families);

    // query
    string fam_name;
    while (true) {
        cout << "Please enter a family name or q to quit: ";
        cin >> fam_name;

        if (fam_name == "q") {
            break;
        }

        query_map(families, fam_name);
    }

    // display
    display_families(families);
}

void chapter3::stream_iterator() {
    istream_iterator<string> in( cin >> noskipws ), eof;
    vector<string> text;

    copy(in, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os( cout, " ");
    copy(text.begin(), text.end(), os);
}
