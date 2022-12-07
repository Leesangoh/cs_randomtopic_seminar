#include "QuadraticProbing.h"
typedef HashTable<int> hash_t;
typedef HashTable<const char *> str_hash_t;
#define SETUP hash_t hash; str_hash_t str_hash;
#define INSERT_INT_INTO_HASH(key, value) hash.insert(key)
#define DELETE_INT_FROM_HASH(key) hash.remove(key);
#define INSERT_STR_INTO_HASH(key, value) str_hash.insert(key)
#define DELETE_STR_FROM_HASH(key) str_hash.remove(key);
#include "template.c"
