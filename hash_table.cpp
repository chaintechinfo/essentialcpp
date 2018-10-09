//
// Created by shniu on 18-10-9.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
//#include <string>

#include "hash_table.h"

// new hash table item
// k: key, v: value
static ht_item* ht_new_item(const char* k, const char* v) {
    auto item = static_cast<ht_item *>(malloc(sizeof(ht_item)));
    item->key = strdup(k);
    item->value = strdup(v);
    return item;
}

// initial hash table array
ht_hash_table* ht_new() {
    auto * ht = static_cast<ht_hash_table *>(malloc(sizeof(ht_hash_table)));
    ht->size = 53;
    ht->count = 0;
    ht->items = static_cast<ht_item **>(calloc((size_t)ht->size, sizeof(ht_item*)));

    std::cout << "new a hash table" << std::endl;
    return ht;
}

// delete
static void ht_del_item(ht_item* item) {
    free(item->key);
    free(item->value);
    free(item);
}

void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != nullptr) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
    std::cout << "delete a hash table" << std::endl;
}

// hash function
static int ht_hash(const char* s, const int a, const int num_buckets) {
    long hash = 0;
    auto len_s = static_cast<const int>(strlen(s));
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - i - 1) * s[i];
        hash = hash % num_buckets;
    }
    return static_cast<int>(hash);
}

// Handling collisions
int ht_get_hash(const char* s, int num_buckets, int attempt) {
    // todo
}

// API
void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != nullptr) {
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != nullptr) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return nullptr;
}

void ht_delete(ht_hash_table* ht, const char* key) {

}
