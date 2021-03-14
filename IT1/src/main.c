// Copyright 2021 Nagdimaev Ilyagu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func/func.h"

int main() {
    Road *all_roads = calloc(50, sizeof(Road));
    // print(all_roads, added_roads);
    size_t added_roads;
    added_roads = load_data(all_roads);
    size_t n;
    printf("Введите число дорог:\n");
    input_lanes(&n);
    char test_type[50];
    input_type(test_type);
    char* result = qual(all_roads, added_roads, test_type, n);
    if (strcmp(result, "Таких дорог нет!") == 0 || strcmp(result, "ERROR") == 0)
        printf("%s\n", result);
    else
        printf("\nСреднее качество дорог с покрытием %s  "
           "c количеством полос %zu: \n%s\n",
           test_type, n, result);
    free(all_roads);
    return 0;
}

void input_lanes(size_t * n) {
    int res = scanf("%zu", n);
    if (!res) {
        printf("Введите корректно число дорог!:\n");
        input_lanes(n);
    }
    if (*n > 50) {
        printf("Нет существует количества полос!\n"
               "Введите корректно число дорог!:\n");
        input_lanes(n);
    }
}

void input_type(char * test_type) {
    printf("%s\n", "Введите вид покрытия (Асфальт или Грунт):");
    while (1) {
        scanf("%49s", test_type);
        if (strcmp(test_type, "Асфальт") == 0)
            break;
        else if (strcmp(test_type, "Грунт") == 0)
            break;
        else
            printf("%s", "Некорректный ввод, повторите еще раз:");
    }
}
