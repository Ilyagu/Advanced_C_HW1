// Copyright 2021 Nagdimaev Ilyagu

#ifndef ADVANCED_PROGRAMMING_C_IT1_INCLUDE_MAIN_H_
#define ADVANCED_PROGRAMMING_C_IT1_INCLUDE_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Road {
    size_t length;
    char type[100];
    char quality[100];
    size_t lanes;
} Road;

size_t load_data(Road * all_roads);
char * decrypt(size_t n);
void input_lanes(size_t *n);
void input_type(char * str);
size_t find_quality(char * quality);
char * qual(Road * all_roads, size_t added_roads, char * type, size_t lanes);
size_t push_back(Road * all_roads, size_t new_road,
                 size_t length, char type[100], char quality[100], size_t lanes);

#endif  // ADVANCED_PROGRAMMING_C_IT1_INCLUDE_MAIN_H_
