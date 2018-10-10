//
// Created by shniu on 18-10-9.
//
// https://github.com/jamesroutley/write-a-hash-table/tree/master/05-methods

#ifndef ESSENTIALCPP_HASH_TABLE_H
#define ESSENTIALCPP_HASH_TABLE_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define HT_INITIAL_BASE_SIZE 40
#define HT_PRIME_1 10
#define HT_PRIME_2 11

// hash table struct
typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int base_size;
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

static ht_item HT_DELETED_ITEM = {nullptr, nullptr};
//ht_item a = {
//        .key = nullptr,
//        .value = nullptr
//};

// static function
static ht_item* ht_new_item(const char* k, const char* v);
static void ht_del_item(ht_item* item);
static int ht_hash(const char* s, int a, int num_buckets);

// resize
static ht_hash_table* ht_new_sized(const int);
static void ht_resize(ht_hash_table* ht, const int base_size);
static void ht_resize_up(ht_hash_table* ht);
static void ht_resize_down(ht_hash_table* ht);
ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);

// API
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
void ht_delete(ht_hash_table* ht, const char* key);
char* ht_search(ht_hash_table* ht, const char* key);

#endif //ESSENTIALCPP_HASH_TABLE_H
