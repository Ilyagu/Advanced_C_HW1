// Copyright 2021 Nagdimaev Ilyagu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func/func.h"

int main() {
    Road *all_roads = calloc(50, sizeof(Road));
    if (all_roads == NULL) {
        printf("%s\n", ERROR);
        return 0;
    }
    size_t added_roads;
    // загружаем данные
    added_roads = load_data(all_roads);
    if (added_roads == LOAD_ERROR) {
        printf("%s\n", ERROR);
        return 0;
    }
    size_t lanes;
    // ввод числа полос
    if (input_lanes(&lanes) == 1) {
        printf("%s\n", ERROR);
        return 0;
    }
    char test_type[50];
    // ввод типа покрытия
    if (input_type(test_type) == 1) {
        printf("%s\n", ERROR);
        return 0;
    }
    const char* result = qual(all_roads, added_roads, test_type, lanes);
    if (strcmp(result, NOROADS) == 0 || strcmp(result, ERROR) == 0)
        printf("%s\n", result);
    else
        printf("\nСреднее качество дорог с покрытием %s  "
           "c количеством полос %zu: \n%s\n",
           test_type, lanes, result);
    free(all_roads);
    return 0;
}
