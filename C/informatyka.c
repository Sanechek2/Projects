#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insert_sort(int sort[], int lenght);
void selection_sort(int array[], int len);
void bubble_sort(int array[], int len);
void shell_sort(int array[], int len);

int main() {
    srand(time(NULL));
    int spisok[10001];
    int length;
    printf("Enter the length of the spisok: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        spisok[i] = rand() % 1001;
    }
    // insert_sort(spisok, length);
    //selection_sort(spisok, length);
    // bubble_sort(spisok, length);
    shell_sort(spisok, length);
    printf("The spisok array is: ");
    for (int i = 0; i < length; i++) {
        printf("%d", spisok[i]);
        if (i < length-1) {
            printf(", ");
        }
    }
    printf("\n");


}
// 45 34 432 1 2

void shell_sort(int array[], int len) {
    int key = len / 2;
    while (key > 0) {
        for (int j = key; j < len; j++) {
            int k = j;
            int temp = array[j];
            while (k >= key && array[k-key] > temp) {
                array[k] = array[k-key];
                k -= key;
            }
            array[k] = temp;
        }
        key /= 2;
    }
}

void bubble_sort(int array[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selection_sort(int array[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i; // 1
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[min]) {
                min = j; // 3
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void insert_sort(int sort[], int length) {
    for (int i = 1; i < length; i++) {
        int key = sort[i];
        int j = i -1;
        while (j>=0 && sort[j] > key) {
            sort[j+1] = sort[j];
            j = j -1 ;
        }
        sort[j + 1] = key;
    }
}

/// Caesar
// char message[100];
// scanf("%s", message);
// char output[100] = {0};
// int key;
// printf("Input key: ");
// scanf("%d", &key);
//
// for (int i = 0; i < strlen(message); i++) {
//     if (message[i] >= 'a' && message[i] <= 'z') {
//         output[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
//     }
//     else if (message[i] >= 'A' && message[i] <= 'Z') {
//         output[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
//     }
// }
//
// printf("%s\n", output);


/// praca z srand i losowymi dannymi
// double b1, a2, b2;
// int n;
// scanf("%d", &n);
// int list[n];
//
// srand(time(NULL));
//
// for (int i = 0; i < n; i++) {
//     list[i] = rand() % (n+1);
//     printf("%d\n", list[i]);
// }

// double a, b, c;
// scanf("%lf %lf", &a, &b);
//
// c = a*(a+b) / ((a+b)*(a+b));
//
// printf("%.4lf\n", c);


