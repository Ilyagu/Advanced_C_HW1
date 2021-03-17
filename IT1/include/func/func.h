// Copyright 2021 Nagdimaev Ilyagu

#ifndef ADVANCED_PROGRAMMING_C_IT1_INCLUDE_MAIN_H_
#define ADVANCED_PROGRAMMING_C_IT1_INCLUDE_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROADS 50
#define PUSH_ERROR -100
#define QUAL_ERROR -300
#define MAX_RATING 100
#define LOAD_ERROR -1
#define EXCELLENT "Отличное"
#define GOOD "Хорошее"
#define BAD "Плохое"
#define TERRIBLE "Ужасное"
#define NOROADS "Таких дорог нет!"
#define ERROR "ERROR"
#define ASPHALT "Асфальт"
#define GROUND "Грунт"

typedef struct Road {
    size_t length;
    char type[100];
    char quality[100];
    size_t lanes;
} Road;

int load_data(Road * all_roads);
size_t input_lanes(size_t *n);
size_t input_type(char * str);
const char * qual(Road * all_roads, size_t added_roads, char * type, size_t lanes);

#endif  // ADVANCED_PROGRAMMING_C_IT1_INCLUDE_MAIN_H_
