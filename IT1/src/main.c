// Copyright 2021 Nagdimaev Ilyagu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func/func.h"

void input_lanes(size_t * n) {
    printf("Введите число полос:\n");
    int res = scanf("%zu", n);
    while (!res || *n > 50) {
        // проверка на валидность
        if (!res) {
            printf("Введите корректно число полос!:\n");
            input_lanes(n);
            res = scanf("%zu", n);
        }
        if (*n > 50) {
            printf("Не существует такого количества полос!\n"
                   "Введите корректно число полос!:\n");
            res = scanf("%zu", n);
        }
    }
}

void input_type(char * test_type) {
    printf("%s\n", "Введите вид покрытия (Асфальт или Грунт):");
    while (1) {
        scanf("%49s", test_type);
        if (strcmp(test_type, ASPHALT) == 0)
            break;
        else if (strcmp(test_type, GROUND) == 0)
            break;
        else
            printf("%s", "Некорректный ввод, повторите еще раз:\n");
    }
}

int main() {
    Road *all_roads = calloc(50, sizeof(Road));
    size_t added_roads;
    // загружаем данные
    added_roads = load_data(all_roads);
    if (added_roads == LOAD_ERROR) {
        printf("%s\n", ERROR);
        return 0;
    }
    size_t n;
    // ввод числа полос
    input_lanes(&n);
    char test_type[50];
    // ввод типа покрытия
    input_type(test_type);
    const char* result = qual(all_roads, added_roads, test_type, n);
    if (strcmp(result, NOROADS) == 0 || strcmp(result, ERROR) == 0)
        printf("%s\n", result);
    else
        printf("\nСреднее качество дорог с покрытием %s  "
           "c количеством полос %zu: \n%s\n",
           test_type, n, result);
    free(all_roads);
    return 0;
}
