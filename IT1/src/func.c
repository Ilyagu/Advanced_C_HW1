// Copyright 2021 Nagdimaev Ilyagu

#include "func/func.h"

#include <stdio.h>
#include <string.h>

size_t push_back(Road *all_roads, size_t new_road, size_t length, char type[100],
                 char quality[100], size_t lanes) {
    all_roads[new_road].length = length;
    strncpy(all_roads[new_road].type, type, strlen(type));
    strncpy(all_roads[new_road].quality, quality, strlen(quality));
    all_roads[new_road].lanes = lanes;
    new_road++;
    return new_road;
}

size_t find_quality(char *quality) {
    if (strcmp(quality, "Отличное") == 0)
        return 0;
    if (strcmp(quality, "Хорошее") == 0)
        return 20;
    if (strcmp(quality, "Плохое") == 0)
        return 35;
    if (strcmp(quality, "Ужасное") == 0)
        return 50;
    return 200;
}

char * decrypt(size_t n) {
    if (n == 0) {
        return "Таких дорог нет!";
    } else if (n < 60) {
        return "Ужасное";
    } else if (n < 71) {
        return "Плохое";
    } else if (n < 85) {
        return "Хорошее";
    } else if (n <= 100) {
        return "Отличное";
    } else {
        printf("%zu", n);
        return "ERROR";
    }
}

char *qual(Road *all_roads, size_t added_roads, char *type, size_t lanes) {
    size_t sum = 0;
    size_t count = 0;
    for (size_t i = 0; i < added_roads; i++) {
        if ((all_roads[i].lanes == lanes) &&
            (strcmp(all_roads[i].type, type) == 0)) {
            sum = sum + 100 - find_quality(all_roads[i].quality);
            count++;
        }
    }
    if (count == 0) return decrypt(0);
    else
    return decrypt(sum / count);
}

size_t load_data(Road * all_roads) {
    size_t added_roads = 0;
    added_roads = push_back(all_roads, added_roads,
                            300, "Асфальт\0", "Хороше\0", 4);
    added_roads = push_back(all_roads, added_roads,
                            2000, "Грунт\0", "Отличное\0", 1);
    added_roads = push_back(all_roads, added_roads,
                            400, "Асфальт\0", "Ужасное\0", 5);
    added_roads = push_back(all_roads, added_roads,
                            50, "Грунт\0", "Отличное\0", 1);
    added_roads = push_back(all_roads, added_roads,
                            500, "Асфальт\0", "Плохое\0", 3);
    added_roads = push_back(all_roads, added_roads,
                            50, "Грунт\0", "Плохое\0", 2);
    added_roads = push_back(all_roads, added_roads,
                            200, "Асфальт\0", "Ужасное\0", 5);
    added_roads = push_back(all_roads, added_roads,
                            600, "Грунт\0", "Ужасное\0", 1);
    added_roads = push_back(all_roads, added_roads,
                            100, "Асфальт\0", "Ужасное\0", 5);
    added_roads = push_back(all_roads, added_roads,
                            30, "Грунт\0", "Ужасное\0", 1);
    return added_roads;
}
