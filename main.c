#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <math.h>
#include <alloca.h>
#include<string.h>

int* resultic(int *a) {
    int *res;
    res = calloc(sizeof(int), 3);
    for (int i = 1; i <= 10; i++) {
        if ((i) % 3 == 0) {
            res[0] += a[i - 1];
        } else if ((i - 1) % 3 == 0 && (i - 1 != 0)) {
            res[1] += a[i - 1];
        } else if ((i - 2) % 3 == 0 && (i - 2 != 0)) {
            res[2] += a[i - 1];
        }
    }

    return res;
}

void practise_14() {
    int *a;
    a = malloc(sizeof(int) * 10);
    srand(time(NULL));
    printf("\n++++++++MAS++++++++\n");
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 20;
        printf("%3d", a[i]);
    }
    int *result;
    int* (*resultics)(int *a);
    resultics = resultic;
    result = malloc(sizeof(int) * 3);
    result = resultics(a);
    printf("\n+++++++RESULT+++++++\n");
    printf("Сумма элементов 3i: %d\nСумма элементов 3i+1: %d\nСумма элементов 3i+2: %d", result[0], result[1],
           result[2]);
}

int powi(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

void practise_11() {
    int **a = NULL;
    int m, n;
    srand(time(NULL));
    printf("Введите m: ");
    scanf("%d", &m);
    printf("Введите n: ");
    scanf("%d", &n);
    a = malloc(sizeof(int *) * m);
    printf("\n+++++++++++A+++++++++++\n");
    for (int i = 0; i < m; i++) {
        a[i] = malloc(sizeof(int) * n);
        for (int y = 0; y < n; y++) {
            a[i][y] = rand() % 20;
            printf("%4d", a[i][y]);
        }
        printf("\n");
    }
    int min = 21;
    int index_i = -1;
    int index_y = -1;
    int first = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int y = 0; y < n; y++) {
            if (a[i][y] < min) {
                min = a[i][y];
                index_i = i;
                index_y = y;
            }
        }
    }
    a[0][0] = a[index_i][index_y];
    a[index_i][index_y] = first;
    printf("\n+++++++++++A_END+++++++++++\n");
    for (int i = 0; i < m; i++) {
        for (int y = 0; y < n; y++) {
            printf("%4d", a[i][y]);
        }
        printf("\n");
    }
}

void practise_8_1() {
    int N = 100;
    int **ar;
    srand(time(NULL));
    int i, j, n, *mas;
    n = rand() % 10 + 2;
    ar = (int **) malloc(n * sizeof(int *));
    mas = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        mas[i] = rand() % 10 + 2;
        ar[i] = (int *) malloc(mas[i] * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < mas[i]; j++) {
            ar[i][j] = rand() % 201 - 100;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < mas[i]; j++) {
            printf("%5d ", ar[i][j]);
        }
        printf("\n");
        free(ar[i]);
    }
    free(ar);
}

void practise_8_2() {
    int N = 100;
    int *A, *B;
    srand(time(NULL));
    A = (int *) malloc(100 * sizeof(int));
    B = (int *) calloc(100, sizeof(int));
    printf("Указатель на А %d\nУказатель на B %d\n", A, B);
    printf("\nМассив A:\n");
    for (int i = 0; i < 100; i++) {
        *(A + i) = rand() % 201 - 100;
        printf("%d\t", A[i]);
    }
    printf("\nМассив В:\n");
    for (int i = 0; i < 100; i++) {
        *(B + i) = rand() % 201 - 100;
        printf("%d\t", B[i]);
    }
    A = (int *) realloc(A, 200 * sizeof(int));
    B = (int *) realloc(B, 50 * sizeof(int));
    printf("\n\nИзменённый указатель 1 на А %d\nИзменённый указатель 1 на B %d\n", A, B);
    A = (int *) realloc(A, 50 * sizeof(int));
    B = (int *) realloc(B, 200 * sizeof(int));
    printf("\nМассив A:\n");
    for (int i = 0; i < 200; i++) {
        *(A + i) = rand() % 201 - 100;
        printf("%d\t", A[i]);
    }
    printf("\nМассив B: \n");
    for (int i = 0; i < 200; i++) {
        *(B + i) = rand() % 201 - 100;
        printf("%d\t", B[i]);
    }
}

void practise_13() {
    FILE *f;
    srand(time(NULL));
    f = fopen("/Users/stanislavbratkov/CLionProjects/untitled/1.txt", "w");
    int l = rand() % 50;
    fprintf(f, "%d\n", l);
    for (int i = 0; i < l; i++) {
        int buf = rand() % 50;
        fprintf(f, "%d ", buf);
    }
    fclose(f);
    f = fopen("/Users/stanislavbratkov/CLionProjects/untitled/1.txt", "r");
    if (f != 0) {
        int *a;
        int len;
        fscanf(f, "%d", &len);
        printf("len: %d\n", len);
        a = malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
            fscanf(f, "%d", &a[i]);
//            printf("%d\n", a[i]);
        }
        fclose(f);
        int chose;
        printf("Shaker(1) or bitwise(2)");
        scanf("%d", &chose);
        if (chose == 1) {
            int left = 0, right = len - 1, flag = 1;
            while ((left < right) && flag > 0) {
                flag = 0;
                for (int i = left; i < right; i++) {
                    if (a[i] > a[i + 1]) {
                        int t = a[i];
                        a[i] = a[i + 1];
                        a[i + 1] = t;
                        flag = 1;
                    }
                }
                right--;
                for (int i = right; i > left; i--) {
                    if (a[i] < a[i - 1]) {
                        flag = 1;
                        int t = a[i];
                        a[i] = a[i - 1];
                        a[i - 1] = t;
                    }
                }
                left++;
            }
        } else if (chose == 2) {

            for (int c = 0; c < 2; c++) {
                int left = 0, right = len - 1, flag = 1;
                printf("%d", c);
                while ((left < right) && flag > 0) {
                    flag = 0;
                    for (int i = left; i < right; i++) {
                        if ((a[i] / powi(10, c)) % 10 > (a[i + 1] / powi(10, c)) % 10) {
                            flag = 1;
                            int t = a[i];
                            a[i] = a[i + 1];
                            a[i + 1] = t;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if ((a[i - 1] / powi(10, c)) % 10 > (a[i] / powi(10, c)) % 10) {
                            flag = 1;
                            int t = a[i];
                            a[i] = a[i - 1];
                            a[i - 1] = t;
                        }
                    }
                    left++;
                }
            }
        }

        f = fopen("/Users/stanislavbratkov/CLionProjects/untitled/result.txt", "w");
        for (int i = 0; i < len; i++) {
            fprintf(f, "%d\n", a[i]);
        }
    }
}

void twelve_practise() {
    char *str1 = NULL;
    char *str2 = NULL;
    char *str = NULL;
    str1 = malloc(sizeof(char) * 100);
    str2 = malloc(sizeof(char) * 100);
    printf("Введите 1 строку: ");
    scanf("%s", str1);
    printf("Введите 2 строку: ");
    scanf("%s", str2);
    unsigned int a = strlen(str1);
    unsigned int b = strlen(str2);
    str = malloc(sizeof(char) * (a + b));
    for (int i = 0; i < (a + b); i++) {
        if (i < b) {
            str[i] = str2[i];
        } else {
            str[i] = str1[i - b];
        }
    }
    printf("result: %s", str);
}

void mozzgi() {
    char *str;
    char *str1;
    char *constr;
    int buf = -1;
    str = malloc(sizeof(char) * 100);
    str1 = malloc(sizeof(char) * 100);
    scanf("%s", str);
    scanf("%s", str1);

    unsigned int a;
    a = strlen(str);
    unsigned int b;
    b = strlen(str1);
    constr = malloc(sizeof(char) * (a + b));
    for (int i = 0; i < a; i++) {
        if (str[i] == 'n') {
            buf = i;
        }
    }
    if (buf == -1) {
        printf("\nСимвола 'n' нет");
    } else {
        for (int i = 0; i <= buf; i++) {
            constr[i] = str[i];
        }
        for (int i = buf + 1; i < buf + 1 + b; i++) {
            constr[i] = str1[i - buf - 1];
        }
        for (int i = buf + 1 + b; i < a + b; i++) {
            constr[i] = str[i - b];
        }
    }
    printf("%s", constr);
    free(str);
    free(str1);
    free(constr);
///* выделить память под строку */
//    str = malloc(10);
///* скопировать в строку "Hello" */
//    strcpy(str, "Hello");
///* вывести строку */
//    printf("Строка: %s\n Адрес: %p\n", str, str);
//    str = realloc(str, 20);
//    printf("Строка: %s\n Новый адрес: %p\n", str, str);
///* освободить память */
//    free(str);
}

void ten_practise_4() {
    int **x = NULL;
    int **y = NULL;
    int **z = NULL;
    int xm, ym, n;
    srand(time(NULL));
    printf("Количество строк X: ");
    scanf("%d", &xm);
    printf("Количество строк Y: ");
    scanf("%d", &ym);
    printf("Количество столбцов: ");
    scanf("%d", &n);
    x = malloc(sizeof(int *) * xm);
    y = malloc(sizeof(int *) * ym);
    z = malloc(sizeof(int *) * (xm + 5 + ym));
    printf("\n==========X==========\n");
    for (int i = 0; i < xm; i++) {
        x[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            x[i][j] = rand() % 100 - 50;
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n==========Y==========\n");
    for (int i = 0; i < ym; i++) {
        y[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            y[i][j] = rand() % 100 - 50;
            printf("%d ", y[i][j]);
        }
        printf("\n");
    }
    printf("\n==========Z==========\n");
    for (int i = 0; i < (ym + xm + 5); i++) {
        z[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            if (i < xm) {
                z[i][j] = x[i][j];
            } else if ((i - xm) < 5) {
                z[i][j] = 1;
            } else if ((i - xm - 5) < ym) {
                z[i][j] = y[i - xm - 5][j];
            }
            printf("%4d", z[i][j]);
        }
        printf("\n");

    }
};

void ten_practise_3() {
    float **mas = NULL;
    float s = 1, k = 0;
    int n;
    srand(time(NULL));
    printf("Введите размерность: ");
    scanf("%d", &n);
    mas = malloc(sizeof(float *) * n);
    for (int i = 0; i < n; i++) {
        mas[i] = malloc(sizeof(float) * n);
        for (int y = 0; y < n; y++) {
            mas[i][y] = rand() % 100 - 50;
            printf("%.0f ", mas[i][y]);
            if (i >= y && mas[i][y] > 0) {
                s *= mas[i][y];
                k += 1;
            }
        }
        printf("\n");
    }
    float res = powf(s, 1 / k);
    printf("Результат = %f", res);

}

void ten_practise_2() {
    int **mas = NULL;
    int n;
    printf("Введите размерность: ");
    scanf("%d", &n);
    srand(time(NULL));
    mas = malloc(sizeof(int *) * n);
    int max = -51;
    int min = 51;
    for (int i = 0; i < n; i++) {
        mas[i] = malloc(sizeof(int) * n);
        for (int y = 0; y < n; y++) {
            mas[i][y] = rand() % 100 - 50;
            if (i == y && mas[i][y] > max) {
                max = mas[i][y];
            } else if (i == y && mas[i][y] < min) {
                min = mas[i][y];
            }
            printf("%d ", mas[i][y]);
        }
        printf("\n");
    }
    printf("\nПроизведения минимума и максимума = %d, Максимум = %d, Минимум = %d\n", max * min, max, min);
    printf("\n========Умноженная побочная========\n");
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            if (y == (n - i - 1)) {
                mas[i][y] = mas[i][y] * max;
            }
            printf("%d ", mas[i][y]);
        }
        printf("\n");
    }
}

void ten_practise_1() {
    int **mas = NULL;
    int *x = NULL;
    int n, m;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    printf("Введите количество столбцов: ");
    scanf("%d", &m);
    srand(time(NULL));
    mas = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        mas[i] = malloc(sizeof(int) * m);
        for (int y = 0; y < m; y++) {
            mas[i][y] = rand() % 100 - 50;
            printf("%d ", mas[i][y]);
        }
        printf("\n");
    }
    printf("\n================X================\n");
    x = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 100 - 50;
        printf("%d\n", x[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) {
            if (y < 3) {
                mas[i][y] = x[i];
            } else {
                mas[i][y] = mas[i][y];
            }
        }
    }
    printf("\n========================Результат========================\n");
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < m; y++) {
            printf("%d ", mas[i][y]);
        }
        printf("\n");
    }
}

void inf_mas(int *mas, int len) {
    int *res = NULL;
    int *res1 = NULL;
    int *result = NULL;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (mas[i] % 100 == mas[i] / 100) {
            k += 1;
            res1 = malloc(sizeof(int) * (k - 1));

            for (int y = 0; y < (k - 1); y++) {
                res1[y] = res[y];
            }
            res = malloc(sizeof(int) * k);
            for (int y = 0; y < (k - 1); y++) {
                res[y] = res1[y];
            }
            res[k - 1] = mas[i];
            free(res1);
        }
    }

    printf("\n==============Результат================\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", res[i]);
    }
}

void nine_practise() {
    int N = 20;
    int *mas = NULL;
    mas = malloc(sizeof(int) * N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        mas[i] = (rand() % 9 + 1) * 1000 + (rand() % 9 + 1) * 100 + (rand() % 9 + 1) * 10 + rand() % 9 + 1;
        printf("%d ", mas[i]);
    }
    inf_mas(mas, N);
}

int eight_practise() {
    int **mas = NULL;
    int *pm = NULL;
    int *A = NULL, *B = NULL;
    srand(time(NULL));
    int s = rand() % 10;
    mas = malloc(sizeof(int) * s);
    for (int i = 0; i < s; i++) {
        pm = malloc(sizeof(int) * s);;
        mas[i] = pm;
        for (int y = 0; y < s; y++) {
            mas[i][y] = rand() % 125;
            printf("%d ", mas[i][y]);
        }
        printf("\n");
    }

    return 0;
};

int check_mas(int *mas, int len) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            if ((mas[i] >= 0 && mas[i - 1] < 0) || (mas[i - 1] >= 0 && mas[i] < 0)) {
                k++;
            }
        }
    }
    return k;
};

int seven_practise() {
    int *mas = NULL;
    int s = 20;
    mas = malloc(sizeof(int) * s);
    srand(time(NULL));
    int i = 0;
    int k = 0;
    while (i < s) {
        mas[i] = rand() % 100 - 50;
        printf("%4d", mas[i]);
        if (i % 20 == 0) {
            printf("\n");
        }
        i++;
    }
    k = check_mas(mas, s);
    printf("\n================================================\n");
    printf("Количество пар = %d", k);
    return 0;
}

int q_mass() {
    int n, i, y, z, summn, summp, summm = 0;
    printf("Введите длину стороны матрицы: ");
    scanf("%d", &n);
    int m[n][n];
    i = 0;
    y = 0;
    while (i < n) {
        while (y < n) {
            srand(time(NULL) * (i + 1) * (y + 1));
            m[i][y] = rand() % 50;
            y++;
        }
        i++;
        y = 0;
    }
    i = 0;
    y = 0;
    //вывод начальной
    while (i < n) {
        printf("|");
        while (y < n) {
            printf("%d, ", m[i][y]);
            y++;
        }
        printf("\n");
        i++;
        y = 0;
    }
    i = 0;
    y = 0;
    z = 1;
    summn = 0;
    summp = 0;
    while (z < n) {
        while (i < n) {
            while (y < n) {
                if (y + z == i) {
                    summp += m[y][i];
                } else if (y == i + z) {
                    summn += m[i][y];
                }
                y++;
            }
            i++;
            y = 0;
        }
        if (summn > summm) {
            summm = summn;
        } else if (summp > summm) {
            summm = summp;
        }
        summn = 0;
        summp = 0;
        z++;
        y = 0;
        i = 0;
    }
    printf("Наибольшая сумма диагонали = %d", summm);
    return 0;
}

int code_block_schem() {
    float a, b, h, x;
    float Y;
    printf("Введите значение начала отрезка: ");
    scanf("%f", &a);
    printf("Введите значение шага цикла: ");
    scanf("%f", &h);
    printf("Введите значение конца отрезка: ");
    scanf("%f", &b);
    x = a;
    while (x <= b) {
        Y = powf(x, 3) + expf(-1 * x);
        printf("x = %f, Y = %f\n", x, Y);
        x += h;
    }
    return 0;
}

int pr5() {
    int mass[100];
    int nmass[100];
    int i, a;
    int in = 0;
    int ik = 0;
    a = 100;
    i = 0;
    srand(time(NULL));
    int ip = rand() % 99;
    int iv = rand() % 99;
    while (i < a) {
        srand(time(NULL) * i * 123);
        mass[i] = (rand() % 200) - 100;
        if (i == ip || i == iv) {
            mass[i] = 0;
        }
        if (mass[i] == 0) {
            nmass[i] = 1;
        } else {
            nmass[i] = 0;
        }
        printf("(%d: ", i);
        printf("%d;) ", mass[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
        i++;
    }
    int flag = 1;
    i = 0;
    while (i < a && flag == 1) {
        if (mass[i] == 0) {
            in = i;
            flag = 0;
        }
        i++;
    }
    i = 99;
    a = 0;
    int su;
    flag = 1;
    while (i > a && flag == 1) {
        if (mass[i] == 0) {
            ik = i;
            flag = 0;
        }
        i--;
    }
    if (in < ik) {
        i = in;
        a = ik;
        su = 0;
        while (i <= a) {
            su += mass[i];
            i++;
        }
    } else {
        su = -1;
    }
    printf("Сумма = %d", su);
    return 0;
}

int dop_mass() {
    int a = 10;
    int m[10];
    int zam[10];
    int i = 0;
    float s = 0;
    int z;
    int nz;
    int razd;
    printf("Номер элемента-разделителя([0;9]): ");
    scanf("%d", &razd);
    printf("Заменяемые элементы: ");
    scanf("%d", &z);
    printf("На что заменить: ");
    scanf("%d", &nz);
    printf("Исходный массив: ");
    int sumdo = 0;
    int sumposl = 0;
    while (i < a) {
        srand(time(NULL) * i);
        m[i] = (rand() % 20) - 10;
        s += m[i];
        printf("%d; ", m[i]);
        if (m[i] == z) {
            zam[i] = nz;
        } else {
            zam[i] = m[i];
        }
        if (i < razd) {
            sumdo += m[i];
        } else {
            sumposl += m[i];
        }
        i++;
    }
    printf("\n");
    sumdo += m[razd];
    if (sumdo > sumposl) {
        printf("Сумма до(%d) > суммы после(%d)", sumdo, sumposl);
    } else if (sumdo < sumposl) {
        printf("Сумма до(%d) < суммы после(%d)", sumdo, sumposl);
    } else {
        printf("Суммы равны(%d)", sumposl);
    }
    printf("\n");
    printf("Массив с заменами: ");
    i = 0;
    while (i < a) {
        printf("%d; ", zam[i]);
        i++;
    }
    s /= 10;
    printf("\n");
    printf("Среднее = %f;\n", s);
    int sp = 0;
    int so = 0;
    int kp = 0;
    int ko = 0;
    i = 0;
    int max = -11;
    int min = 11;
    printf("Элементы болше среднего: ");
    while (i < a) {
        if (m[i] > 0) {
            sp += m[i];
            kp++;
        } else if (m[i] < 0) {
            so += m[i];
            ko++;
        }
        if (m[i] > max) {
            max = m[i];
        } else if (m[i] < min) {
            min = m[i];
        }
        if (m[i] > s) {
            printf("%d; ", m[i]);
        }
        i++;
    }
    printf("\n");
    int raz = max - min;
    printf("Сумма положительных = %d;\nCумма отрицательных = %d;\nМаксимум = %d;\nМинимум = %d;\nРазность максимума и минимума = %d;\nКоличество положительных = %d;\nКоличество отрицательныз = %d;\n",
           sp, so, max, min, raz, kp, ko);
    printf("\n");

    for (i = 0; i < a - 1; i++) {
        // сравниваем два соседних элемента.
        for (int j = 0; j < a - i - 1; j++) {
            if (m[j] > m[j + 1]) {
                int tmp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = tmp;
            }
        }
    }
    i = 0;
    printf("Осортированный массив: ");
    while (i < a) {
        printf("%d; ", m[i]);
        i++;
    }
    return 0;
}

int calc() {
    float memory[10];
    int a = 1;
    float x;
    char o;
    float y;
    float z = 0;
    int m;
    printf("Введите первое значение: ");
    scanf("%f", &x);
    int i = 0;
    while (a == 1) {
        printf("Введите оператор(+,-,/,*): ");
        scanf(" %c", &o);
        printf("Введите число: ");
        scanf("%f", &y);
        if (o == '+') {
            z = x + y;
        } else if (o == '*') {
            z = x * y;
        } else if (o == '/') {
            z = x / y;
        } else if (o == '-') {
            z = x - y;
        }

        printf("Значение действия = %.2f\n", z);
        printf("Желаете продолжить или сделать операцию со старыми значениями?(1-да, 0-нет, 3-вспомнить): ");
        scanf("%d", &a);
        memory[i] = z;
        x = z;
        if (a == 3) {
            printf("Введите оператор(+,-,/,*): ");
            scanf(" %c", &o);
            printf("Какое действие хотите добавить? (Всего было: %d)", i);
            scanf("%d", &m);
            if (o == '+') {
                z = x + memory[m - 1];
            } else if (o == '*') {
                z = x * memory[m - 1];
            } else if (o == '/') {
                z = x / memory[m] - 1;
            } else if (o == '-') {
                z = x - memory[m - 1];
            }
        }
        if (a == 3) {
            printf("Значение действия = %.2f\n", z);
            printf("Желаете продолжить или сделать операцию со старыми значениями?(1-да, 0-нет): ");
            scanf("%d", &a);

        }

        i++;
    }
    return 0;
}

int mass() {
    int a = 50;
    int i = 0;
    int m[50];
    while (i < a) {
        srand(time(NULL) * i * 123);
        m[i] = (rand() % 20) - 10;
        printf("(%d: ", i);
        printf("%d;) ", m[i]);
        i++;
    }
    printf("\n");
    i = 0;
    int ma = -1;
    while (i < a) {
        if (m[i] < 0 && m[i] * (-1) > ma) {
            ma = m[i] * (-1);
        }
        i++;
    }
    printf("Максимально отрицательное число: %d\n", ma);
    i = 0;
    while (i < a) {
        if (m[i] > 0) {
            m[i] = ma;
        }
        i++;
    }
    i = 0;
    for (i; i < 50; i++) {
        printf("(%d: ", i);
        printf("%d;) ", m[i]);
    }
    return 0;
}

int game() {
    srand(time(NULL));
    int a = 1;
    int c;
    int l = rand() % 40;
    while (a == 1) {
        printf("Введите вашу догадку: ");
        scanf("%d", &c);
        if (c == l) {
            printf("YOU WIN!!!\n");
            a = 0;
        } else if (c > l) {
            printf("Меньше\n");
        } else if (c < l) {
            printf("Больше\n");
        }
    }
    return 0;
}

int feb() {
    int n;
    unsigned long int s;
    int i = 0;
    printf("Введите желаемое кол-во:");
    scanf("%d", &n);
    unsigned long int a_1 = 0;
    unsigned long int a = 1;
    printf("%lu, %lu, ", a_1, a);
    while (i < n - 2) {
        s = a_1 + a;
        printf("%lu, ", s);
        a_1 = a;
        a = s;
        i++;
    }
    printf("\n");
    return 0;
}

int hight() {
    float a, b, c;
    printf("Введите длинну стороны a: ");
    scanf("%f", &a);
    printf("Введите длинну стороны b: ");
    scanf("%f", &b);
    printf("Введите длинну стороны c: ");
    scanf("%f", &c);
    if (a + b > c && a + c > b && b + c > a) {
        float p2 = (a + b + c) / 2;

        float s = 2 * sqrtf(p2 * (p2 - a) * (p2 - b) * (p2 - c));

        float h = 0;
        char boo;
        int q = 1;
        while (q == 1) {
            printf("К какой стороне вы хотите узнать высоту: ");
            scanf(" %c", &boo);
            h = 0;
            if (boo == 'a') {
                h = s / a;

            } else if (boo == 'b') {
                h = s / b;

            } else if (boo == 'c') {
                h = s / c;

            }
            printf("Высота к запрошенной стороне равна: %f.\nЕсли вы видите 0, значит вы ввели несуществующую сторону! Хотите попробовать еще раз?(1-Да; 2-Нет): ",
                   h);
            scanf("%d", &q);

        }
        return 0;
    } else {
        printf("Введенный стороны не образуют треугольник(1-перезапустить; 2-выйти)");
        int f;
        scanf("%d", &f);
        if (f == 1) {
            hight();
            return 0;
        } else {
            return 0;
        }
    }
}

int main() {
    int s;
    printf("Выберите программу(1-Game; 2-Fibonacci series, 3-Triangle, 4-Array, 5-Calc, 6-Additional array, 7-Practical 5, 8-Block_Scheme, 9-Q_array, 10-7_Practise, 11-8_Practise, 12-9_Practise, 13-10_Practise, 14-Mozgii, 15-12_Practise, 16-13_practise, 17-8_practise, 18-11_practise, 19-14_practise): ");
    scanf("%d", &s);
    if (s == 1) {
        game();
    } else if (s == 2) {
        feb();
    } else if (s == 3) {
        hight();
    } else if (s == 4) {
        mass();
    } else if (s == 5) {
        calc();
    } else if (s == 6) {
        dop_mass();
    } else if (s == 7) {
        pr5();
    } else if (s == 8) {
        code_block_schem();
    } else if (s == 9) {
        q_mass();
    } else if (s == 10) {
        seven_practise();
    } else if (s == 11) {
        eight_practise();
    } else if (s == 12) {
        nine_practise();
    } else if (s == 13) {
        int n;
        printf("Введите номер задания: ");
        scanf("%d", &n);
        if (n == 1) {
            ten_practise_1();
        } else if (n == 2) {
            ten_practise_2();
        } else if (n == 3) {
            ten_practise_3();
        } else if (n == 4) {
            ten_practise_4();
        }
    } else if (s == 14) {
        mozzgi();
    } else if (s == 15) {
        twelve_practise();
    } else if (s == 16) {
        practise_13();
    } else if (s == 17) {
        int n;
        printf("Введите номер задания: ");
        scanf("%d", &n);
        if (n == 1) {
            practise_8_1();
        } else if (n == 2) {
            practise_8_2();
        }
    } else if (s == 18) {
        practise_11();
    } else if (s == 19) {
        practise_14();
    }
    return 0;
}
