/******************************************************************************
 * Copyright (C) 2022 by Ricardo Adao
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Ricardo Adao is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file dict.c 
 * @brief An example code for how to use the heap space to implement a
 *  dictionary data structure
 *
 * @author Ricardo Adao
 * @date October 2, 2022
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CAP_INIT (2)
#define CAP_RESIZE (2)

typedef struct dict_entry_s {
    const char *key;
    int value;
} dict_entry_s;

typedef struct dict_s {
    int len;
    int cap;
    dict_entry_s *entry;
} dict_s, *dict_t;

/**
 * @brief Given a dictionary instance, find the key corresponding to a given
 * input value
 * 
 * Iterates over the dictionary and returns the key string corresponding to the
 * input search value. If the value cannot be found in the dict, it returns the
 * string "none"
 *
 * @param dict Pointer to a dict_s type object
 * @param value Integer value to be searched for in the dictionary
 *
 * @return key string
 */
const char* dict_find_key(dict_t dict, int value) {
    for (int i = 0; i < dict->len; i++)
        if(dict->entry[i].value == value)
            return dict->entry[i].key;
    return "none";
}

/**
 * @brief Given a dictionary instance, find the index of the dict->entry array
 * corresponding to a given input key
 * 
 * Iterates over the dictionary and returns the dict->entry index corresponding
 * to the input search key. If the value cannot be found in the dict, it
 * returns -1
 *
 * @param dict Pointer to a dict_s type object
 * @param key String key to be searched for in the dictionary
 *
 * @return i index
 */
int dict_find_index(dict_t dict, const char *key) {
    for (int i = 0; i < dict->len; i++)
        if (!strcmp(dict->entry[i].key, key))
            return i;
    return -1;
}

/**
 * @brief Given a dictionary instance, find the value corresponding to a given
 * input key
 * 
 * Iterates over the dictionary and returns the int value corresponding to the
 * input search key. If the value cannot be found in the dict, it returns -1
 *
 * @param dict Pointer to a dict_s type object
 * @param key String key to be searched for in the dictionary
 *
 * @return value integer
 */
int dict_find_value(dict_t dict, const char *key, int def) {
    int idx = dict_find_index(dict, key);
    return idx == -1 ? def : dict->entry[idx].value;
}

/**
 * @brief Given a dictionary instance, add a new dict_entry_s to the
 * dict->entry array
 * 
 * Allocates new memory in the heap to accomodate a new dictionary entry. If
 * the key is already present in the dictionary, it does nothing.
 *
 * @param[in/out] dict Pointer to a dict_s type object
 * @param key String key of the entry to be added to the dictionary
 * @param value Integer value to be added to the dictionary
 */
void dict_add(dict_t dict, const char *key, int value) {
   int idx = dict_find_index(dict, key);
   if (idx != -1) {
       dict->entry[idx].value = value;
       return;
   }
   if (dict->len == dict->cap) {
       dict->cap *= CAP_RESIZE;
       dict->entry = realloc(dict->entry, dict->cap * sizeof(dict_entry_s));
   }
   dict->entry[dict->len].key = strdup(key);
   dict->entry[dict->len].value = value;
   dict->len++;
}

/**
 * @brief Create a new dictionary instance
 * 
 * Allocates new memory in the heap to accomodate a new dictionary instance.
 * Returns the pointer to the dictionary heap address
 *
 * @return d Pointer to the new dict_s type object
 */
dict_t dict_new(void) {
    dict_s proto = {0, CAP_INIT, malloc(CAP_INIT*sizeof(dict_entry_s))};
    dict_t d = malloc(sizeof(dict_s));
    *d = proto;
    return d;
}

/**
 * @brief Erase a dictionary instance
 * 
 * Free the heap memory allocated to an input dictionary instance
 */
void dict_free(dict_t dict) {
    for (int i = 0; i < dict->len; i++)
        free((void *)dict->entry[i].key);
    free(dict->entry);
    free(dict);
}

int main()
{
    /*Create and initialize dictionary*/
    dict_t d = dict_new();
    dict_add(d, "quick", 1);
    dict_add(d, "jumps", 4);
    dict_add(d, "lazy", 7);
    dict_add(d, "brown", 2);
    dict_add(d, "the", 6);
    dict_add(d, "The", 0);
    dict_add(d, "dog", 8);
    dict_add(d, "fox", 3);
    dict_add(d, "over", 5);
    
    /*Example of find value*/
    const char *key = "fox";
    int value_found = dict_find_value(d, key, -1);
    printf("key '%s' holds the value %d\n", key, value_found);
    
    /* Example of find key*/
    int value = 7;
    const char * key_found = dict_find_key(d, value);
    printf("value %d is found in key '%s'\n", value, key_found);
    
    /* Example print full dict*/
    for (int i = 0; i < d->len; i++) {
        printf("%s ", dict_find_key(d, i));
    }
    printf("\n");
    
    return 0;
}