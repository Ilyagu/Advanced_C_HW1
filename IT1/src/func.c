// Copyright 2021 Nagdimaev Ilyagu

#include "func/func.h"

#include <stdio.h>
#include <string.h>

size_t push_back(Road *all_roads, size_t new_road, size_t length, const char type[],
                 const char quality[], size_t lanes) {
    // вспомогательная функция для load_data, пушит в конец массива объект
    all_roads[new_road].length = length;
    strncpy(all_roads[new_road].type, type, strlen(type));
    strncpy(all_roads[new_road].quality, quality, strlen(quality));
    all_roads[new_road].lanes = lanes;
    new_road++;
    return new_road;
}

int find_quality(char *quality) {
    // вычисление качества по атрибуту объекта
    if (quality == NULL) return QUAL_ERROR;
    else if (strcmp(quality, EXCELLENT) == 0)
        return 0;
    else if (strcmp(quality, GOOD) == 0)
        return 20;
    else if (strcmp(quality, BAD) == 0)
        return 35;
    else if (strcmp(quality, TERRIBLE) == 0)
        return 50;
    return QUAL_ERROR;
}

const char * decrypt(size_t n) {
    // вывод рейтинга в клиентском виде
    if (n == 0) {
        return NOROADS;
    } else if (n < 60) {
        return TERRIBLE;
    } else if (n < 71) {
        return BAD;
    } else if (n < 85) {
        return GOOD;
    } else if (n <= 100) {
        return EXCELLENT;
    } else {
        return ERROR;
    }
}

const char *qual(Road *all_roads, size_t added_roads, char *type, size_t lanes) {
    if (type == NULL) return ERROR;
    size_t sum = 0;
    size_t count = 0;
    for (size_t i = 0; i < added_roads; i++) {
        if ((all_roads[i].lanes == lanes) &&
            (strcmp(all_roads[i].type, type) == 0)) {
            // вычисление общего рейтинга
            sum = sum + MAX_RATING - find_quality(all_roads[i].quality);
            count++;
        }
    }
    if (count == 0) return decrypt(0);
    else
    return decrypt(sum / count);
}

int load_data(Road * all_roads) {
    if (all_roads == NULL) return LOAD_ERROR;
    // загрузка базы
    size_t added_roads = 0;
    added_roads = push_back(all_roads, added_roads,
                            300, ASPHALT, GOOD, 4);
    added_roads = push_back(all_roads, added_roads,
                            2000, GROUND, EXCELLENT, 1);
    added_roads = push_back(all_roads, added_roads,
                            400, ASPHALT, TERRIBLE, 5);
    added_roads = push_back(all_roads, added_roads,
                            50, GROUND, EXCELLENT, 1);
    added_roads = push_back(all_roads, added_roads,
                            500, ASPHALT, BAD, 3);
    added_roads = push_back(all_roads, added_roads,
                            50, GROUND, BAD, 2);
    added_roads = push_back(all_roads, added_roads,
                            200, ASPHALT, TERRIBLE, 5);
    added_roads = push_back(all_roads, added_roads,
                            600, GROUND, TERRIBLE, 1);
    added_roads = push_back(all_roads, added_roads,
                            100, ASPHALT, TERRIBLE, 5);
    added_roads = push_back(all_roads, added_roads,
                            30, GROUND, TERRIBLE, 1);
    return added_roads;
}
