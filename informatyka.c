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
void quick_sort(int array[], int left, int right);
void quick_sort_random(int array[], int left, int right);
void heapfi(int arr[], int n, int i);
void heap_sort(int array[], int len);
void sadgewick_shell_sort(int array[], int len);
void print_array(int arr[], int length);
void generateData(int arr[], int n, int type);



int main(int argc, char *argv[]) {
//to było dla sobie zrobione
    srand(time(NULL));
    int algorithm_type = 0;
    int type;
    int length = 0;
    int interactive_mode = 1;
    int *spisok = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--algorithm") == 0 && i + 1 < argc) {
             algorithm_type = atoi(argv[i + 1]);
             interactive_mode = 0;
        }
    }

    if (interactive_mode) {

        printf("Input algorithm type (1-Insert, 2-Shell, 3-Select, 4-Heap,\n5-Quick, 6-QuickRand, 7-Sadgewick–ShellSort): \n");
        if (scanf("%d", &algorithm_type) != 1) return 1;

        printf("Input length: ");
        if (scanf("%d", &length) != 1) return 1;

        spisok = malloc(length * sizeof(int));
        if (spisok == NULL) return 1;

        printf("Wybierz rodzaj danych:\n");
        printf("0 - Losowe\n1 - Rosnace\n2 - Malejace\n3 - Stale\n4 - A-ksztaltne\nWybor: ");
        scanf("%d", &type);
        generateData(spisok, length, type);

        // for (int i = 0; i < length; i++) {
        //     spisok[i] = rand() % 100001;
        // } 0.000013  0.000018
    }
    else {
        if (scanf("%d", &length) != 1) return 1;

        spisok = malloc(length * sizeof(int));
        if (spisok == NULL) return 1;

        for (int i = 0; i < length; i++) {
            if (scanf("%d", &spisok[i]) != 1) break;
        }
    }

    clock_t start = clock();
    switch (algorithm_type) {
        case 1: insert_sort(spisok, length); break;
        case 2: sadgewick_shell_sort(spisok, length); break;
        case 3: selection_sort(spisok, length); break;
        case 4: heap_sort(spisok, length); break;
        case 5: quick_sort(spisok, 0, length - 1); break;
        case 6: quick_sort_random(spisok, 0, length - 1); break;
        default: heap_sort(spisok, length); break;
    }

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    if (interactive_mode) {
        printf("The spisok array is: \n");
        print_array(spisok, length);
        printf("Time spent: %f\n", time_spent);
    }
    else {printf("Time spent: %f\n", time_spent);}
    free(spisok);
    return 0;
}

void generateData(int arr[], int n, int type){
    switch(type){
        case 0:
            for(int i = 0; i < n; i++) arr[i] = rand()% 1000;
            break;
        case 1:
            for(int i = 0; i < n; i++) arr[i] = i;
            break;
        case 2:
            for(int i = 0; i < n; i++) arr[i] =  n -i;
            break;
        case 3:
            for(int i = 0; i < n; i++) arr[i] = 7;
            break;
        case 4:
            for(int i = 0; i < n; i++) arr[i] = i * 2;
            for(int i = n / 2 + 1; i< n; i++) arr[i] = arr[n - i - 1];
            break;
    }
}

void print_array(int arr[], int n) {
    if (n <= 20) {
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    } else {
        for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
        printf("... ");
        for (int i = n - 10; i < n; i++) printf("%d ", arr[i]);
    }
    printf("\n");
}

void heap_sort(int array[], int len) {
    for (int i = len/2 - 1; i >= 0; i--) {
        heapfi(array, len, i);

    }
    for (int i = len-1; i >= 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapfi(array, i, 0);
    }

}

void heapfi(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapfi(arr, n, largest);
    }
}

void quick_sort_random(int array[], int left, int right) {

    int random = rand() % (right - left + 1) + left;

    if (left < right) {

        int temp = array[left];
        array[left] = array[random];
        array[random] = temp;

        int pivot = array[left];
        int i = left;

        for (int j = left+1; j <= right; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp_last = array[left];
        array[left] = array[i];
        array[i] = temp_last;

        quick_sort(array, left, i-1);
        quick_sort(array, i+1, right);
    }
}

void quick_sort(int array[], int left, int right) {

    if (left < right) {
        int pivot = array[left];
        int i = left;

        for (int j = left+1; j <= right; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[left];
        array[left] = array[i];
        array[i] = temp;

        quick_sort(array, left, i-1);
        quick_sort(array, i+1, right);
    }
}

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

void sadgewick_shell_sort(int array[], int len) {
    int v, h, j;
    int incs[16] = {1391376, 463792, 198768, 86961, 33936,
        13776, 4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1};
    for (int k=0; k<16; k++) {
        h = incs[k];
        if (h>=len) continue;
        for (int i = h; i < len; i++) {
            v = array[i];
            j = i;
            while (j > h && array[j-h] > v) {
                array[j]= array[j-h];
                j -= h;
            }
            array[j] = v;
        }
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

