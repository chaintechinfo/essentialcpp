//
// Created by shniu on 18-10-9.
//

#include "prime.h"
#include "hash_table.h"

// new hash table item
// k: key, v: value
static ht_item* ht_new_item(const char* k, const char* v) {
    auto item = static_cast<ht_item *>(malloc(sizeof(ht_item)));
    item->key = strdup(k);
    item->value = strdup(v);
    return item;
}

static ht_hash_table* ht_new_sized(const int base_size) {
    // xmalloc & xcalloc ?
    auto * ht = static_cast<ht_hash_table *>(malloc(sizeof(ht_hash_table)));
    ht->base_size = base_size;
    ht->size = next_prime(base_size);
    ht->count = 0;
    ht->items = static_cast<ht_item **>(calloc((size_t)ht->size, sizeof(ht_item*)));
    return ht;
}

// initial hash table array
ht_hash_table* ht_new() {
    /*auto * ht = static_cast<ht_hash_table *>(malloc(sizeof(ht_hash_table)));
    ht->size = 53;
    ht->count = 0;
    ht->items = static_cast<ht_item **>(calloc((size_t)ht->size, sizeof(ht_item*)));*/
    auto ht = ht_new_sized(HT_INITIAL_BASE_SIZE);
    std::cout << "new a hash table" << std::endl;
    return ht;
}

// resize, up or down
static void ht_resize(ht_hash_table* ht, const int base_size) {
    if (base_size < HT_INITIAL_BASE_SIZE) {
        return;
    }

    ht_hash_table* new_ht = ht_new_sized(base_size);
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (item != nullptr && item != &HT_DELETED_ITEM) {
            ht_insert(new_ht, item->key, item->value);
        }
    }

    ht->base_size = new_ht->base_size;
    ht->count = new_ht->count;

    const int tmp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = tmp_size;

    ht_item** tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;
    ht_del_hash_table(new_ht);
}

static void ht_resize_up(ht_hash_table* ht) {
    const int new_size = ht->base_size * 2;
    ht_resize(ht, new_size);
}

static void ht_resize_down(ht_hash_table* ht) {
    const int new_size = ht->base_size / 2;
    ht_resize(ht, new_size);
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
        if (item == &HT_DELETED_ITEM) {
            item = nullptr;
            // free(item);
        } else if (item != nullptr) {
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
static int ht_get_hash(const char* s, int num_buckets, int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// API
void ht_insert(ht_hash_table* ht, const char* key, const char* value) {

    // load
    const int load = ht->count * 100 / ht->size;
    if (load > 70) {
        ht_resize_up(ht);
    }

    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != nullptr) {
        if (cur_item != &HT_DELETED_ITEM) {
            if (strcmp(cur_item->key, key) == 0) {
                ht_del_item(cur_item);
                ht->items[index] = item;
                return;
            }
        }
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
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                return item->value;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return nullptr;
}

// Deleting from an open addressed hash table is more complicated than inserting or searching.
// The item we wish to delete may be part of a collision chain.
// Removing it from the table will break that chain, and will make finding items in the tail of the chain
// impossible. To solve this, instead of deleting the item, we simply mark it as deleted.
void ht_delete(ht_hash_table* ht, const char* key) {

    // load
    const int load = ht->count * 100 / ht->size;
    if (load < 10) {
        ht_resize_down(ht);
    }

    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != nullptr) {
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                // mark it as deleted
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
                ht->count--;
                return;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    // ht->count--;  // ?
}
