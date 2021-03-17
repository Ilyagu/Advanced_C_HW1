// Copyright 2021 Nagdimaev Ilyagu

#include "func/func.h"

#include <stdio.h>
#include <string.h>

#define MAX_QULITY_SIZE 50
#define MAX_EXCELLENT_RATING 100
#define MAX_GOOD_RATING 85
#define MAX_BAD_RATING 71
#define MAX_TERRIBLE_RATING 60

int push_back(Road *all_roads, size_t new_road, size_t length, const char type[],
                 const char quality[], size_t lanes) {
    // обработка нуля в указателе
    if (all_roads == NULL) return PUSH_ERROR;
    if (new_road >= MAX_ROADS) return new_road;
    // вспомогательная функция для load_data, пушит в конец массива объект
    all_roads[new_road].length = length;
    strncpy(all_roads[new_road].type, type, 50);
    strncpy(all_roads[new_road].quality, quality, 50);
    all_roads[new_road].lanes = lanes;
    new_road++;
    return new_road;
}

// вычисление качества по атрибуту объекта
int find_quality(char *quality) {
    // обработка нуля в указателе
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

// вывод рейтинга в клиентском виде
const char * decrypt(size_t n) {
    if (n == 0) {
        return NOROADS;
    } else if (n < MAX_TERRIBLE_RATING) {
        return TERRIBLE;
    } else if (n < MAX_BAD_RATING) {
        return BAD;
    } else if (n < MAX_GOOD_RATING) {
        return GOOD;
    } else if (n <= MAX_EXCELLENT_RATING) {
        return EXCELLENT;
    } else {
        return ERROR;
    }
}

// главная функция выдающая результат: среднее качество дорог с покрытием и числом полос
const char *qual(Road *all_roads, size_t added_roads, char *type, size_t lanes) {
    // обработка нуля в указателе
    if (type == NULL || all_roads == NULL) return ERROR;
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
    // если нет таких дорог
    if (count == 0) return decrypt(0);
    else
    return decrypt(sum / count);
}

size_t input_lanes(size_t * lanes) {
    if (lanes == NULL) return 1;
    printf("Введите число полос:\n");
    int res = scanf("%zu", lanes);
    while (!res || *lanes > MAX_QULITY_SIZE) {
        // проверка на валидность
        if (!res) {
            printf("Введите корректно число полос!:\n");
            res = scanf("%zu", lanes);
        }
        if (*lanes > 50) {
            printf("Не существует такого количества полос!\n"
                   "Введите корректно число полос!:\n");
            res = scanf("%zu", lanes);
        }
    }
    return 0;
}

size_t input_type(char * test_type) {
    if (test_type == NULL) return 1;
    printf("%s\n", "Введите вид покрытия (Асфальт или Грунт):");
    while (1) {
        scanf("%49s", test_type);
        if (strcmp(test_type, ASPHALT) == 0)
            return 0;
        else if (strcmp(test_type, GROUND) == 0)
            return 0;
        else
            printf("%s", "Некорректный ввод, повторите еще раз:\n");
    }
    return 0;
}

int load_data(Road * all_roads) {
    // обработка нуля в указателе
    if (all_roads == NULL) return LOAD_ERROR;
    // загрузка базы
    int added_roads = 0;
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
                            100, ASPHALT, BAD, 5);
    added_roads = push_back(all_roads, added_roads,
                            30, GROUND, TERRIBLE, 1);
    return added_roads;
}
