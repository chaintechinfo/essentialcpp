//
// Created by shniu on 18-10-9.
//

#ifndef ESSENTIALCPP_HASH_TABLE_H
#define ESSENTIALCPP_HASH_TABLE_H

// hash table struct
typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

// static function
static ht_item* ht_new_item(const char* k, const char* v);
static void ht_del_item(ht_item* item);
static int ht_hash(const char* s, int a, int num_buckets);

ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);

// API
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
void ht_delete(ht_hash_table* ht, const char* key);
char* ht_search(ht_hash_table* ht, const char* key);

#endif //ESSENTIALCPP_HASH_TABLE_H
