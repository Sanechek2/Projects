#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void selection_sort(int array[], int len);

int main() {
    int spisok[10001];
    int length;

    printf("Wright the length of the spisok: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        scanf("%d", &spisok[i]);
    }
    selection_sort(spisok, length);
    printf("The spisok array is: ");
    for (int i = 0; i < length; i++) {
        printf("%d, ", spisok[i]);
    }
    printf("\n");


}
// 45 34 432 1 2
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



/// ----- Insert_Sort -----
// void insert_sort(int sort[], int lenght);
//
// int main() {
//     int spisok[10001];
//     int len;
//     printf("Insert the length of the spisok: ");
//     scanf("%d", &len);
//     for (int i= 0; i < len; i++) {
//           scanf("%d", &spisok[i]);
//     }
//     insert_sort(spisok, len);
//     printf("The sorted array is: \n");
//     for (int i= 0; i < len; i++) {
//         printf("%d, ", spisok[i]);
//     }
//
// }
// // 45 4 44 3
// void insert_sort(int sort[], int length) {
//     for (int i = 1; i < length; i++) {
//         int key = sort[i];
//         int j = i -1;
//         while (j>=0 && sort[j] > key) {
//             sort[j+1] = sort[j];
//             j = j -1 ;
//         }
//         sort[j + 1] = key;
//     }
// }


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


