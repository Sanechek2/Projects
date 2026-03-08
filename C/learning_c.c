#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



int main() {
    
}

//    ------------- 


//    ------------- Fibinacci ------------
// int fib() {
//     int k, n, F[100];
//     scanf("%d"
//     , &k);
//     F[0]= 1;
//     F[1]= 1;
//     n= 2;
//     while ( k >= n ){
//         F[n]= F[n-1] + F[n-2];
//         n+= 1; 
//     }
//     printf("%d\n", F[k]);
//     return 0; }
// -------------------------------------


//    ------------ adding files -----------
// fib();
    // char line[255];
    // FILE * fpointer = fopen("employees.txt", "r");

    // // fprintf(fpointer, "Cockroach, dishwasher\nBunny, manager\nCat, CEO");
    // // fprintf(fpointer, "\nMouse, intern\n");
    // fgets(line, 255, fpointer);
    // fgets(line, 255, fpointer);
    // printf("first line: %s", line);
    // fclose(fpointer);
    // return 0;
//    -------------------------------------

//    -------------- pointers --------------
// int age = 55555;
    // int *pAge = &age;
    // double gpa = 3.4;
    // double * pGpa = &gpa;
    // char grade = 'F';
    // char * pGrade = &grade;

    // printf("age's memory adress: %d \ngpa %p \n", &*&age, &gpa);
//.     ----------------------------------

//      -----------   memory   ----------
// int age = 30;
    // double gpa = 3.4;
    // char grade = 'F';

    // printf("age: %p \ngpa: %p\ngrade: %p", &age, &gpa, &grade);
    // printf("%p \n", &gpa);
    // printf("%p \n", &grade);
//       ---------------------------------
 
//        ---------- spiski ----------
// int nums[3][2] = {
    // {1,2}, 
    // {3,4},
    // {5,6}
    // }; 

    // //printf("%d \n", nums[1][1]);

    // int i, j;
    // for (i=0; i < 3; i++){
    //     for(j=0; j < 2; j++){
    //         printf("%d, ", nums[i][j]);
    //     }
    //     printf("\n");
    // }
//    ----------------------------------


//        ----------- for -------------
// int luckyNumbers[]= {4, 6, 77, 997, 43};
    // int i;
    // // while (i >= 1){
    // //     printf("%d\n", i);
    // //     i--;
    // // }
    // for(i = 0; i <5; i++){
    //     printf("%d \n", luckyNumbers[i]);
    // }
//        -----------------------------


//        ---------- while -------------
// int index = 6;
    // do {
    //     printf("%d \n", index);
    //     index ++;
    // }while(index <=5 );

    //++++++++++++++++++++++++++++++++++
    // int secretNumber = 5;
    // int guess;
    // int guessCount = 0;
    // int guessLimit = 3;
    // int outOfGuesses = 0;

    // while ( guess != secretNumber  && outOfGuesses == 0){
    //     if (guessCount < guessLimit){
    //         printf("enter number: ");
    //         scanf("%d", &guess);
    //         guessCount ++;
    //     } else {
    //         outOfGuesses = 1;
    //     }
    // }
    // if (outOfGuesses == 1){
    //     printf("You are loser \n");
    // } else {
    //     printf("You Win! \n");
    // }
// -------------------------------------

//         -------- structer ----------

// struct Student {
//     char name[50];
//     char major[50];
//     int age;
//     double gpa;
// };

// struct Student student1;
    // student1.age = 22;
    // student1.gpa = 4.3;
    // strcpy(student1.name, "Mother_fucker");
    // strcpy(student1.major, "Lox");
    // printf("%s \n", student1.name);

    // struct Student student2;
    // student2.age = 20;
    // student2.gpa = 0.6;
    // strcpy(student2.name, "Dumb_fucker");
    // strcpy(student2.major, "Lox");

    // printf("%s \n", student2.name);
// ------------------------------------------------
// int max(int num1, int num2, int num3){
//     int result;
//     if (num1 >= num2 && num1 >=num3){
//         result=num1;
//     } else if (num2 >= num1 && num2 >= num3){
//         result = num2;
//     } else {
//         result = num3;
//     }
//     return result;
// } if (!(3>23)){
        //printf("true \n");
    //}

// double cube(double num){
//     return num * num * num; // printf("answear: %f \n", cube(5.46)); // double cube(double num);
// }

// void sayHi (char name[], int age){
//     printf("hi %s you have drunk %d liters of vodka \n", name, age);
// } 
// sayHi("simpson", 34);
// sayHi("bugaga", 77);

// int wtf(){
//.      ------switch -----
    // char grade = 'F';
    // switch (grade){
    //     case 'A':
    //     printf("you are awesome \n");
    //     break;
    //     case 'B':
    //     printf("you are good \n");
    //     break;
    //     case 'C':
    //     printf("you are me \n");
    //     break;
    //     case 'D':
    //     printf("you are lazy \n");
    //     break;
    //     case 'F':
    //     printf("you are dumb \n");
    //     break;
    //     default :
    //     printf("wtf \n");
    //     break;
    // }

//     // int luckyNumbers[10];
//     // luckyNumbers[2] = 43;
//     // luckyNumbers[1] = 7;

//     // char prhrase[32] = "abc def ghi jkl";
//     // printf("%d \n", luckyNumbers[2]);
//     // printf("%s \n", prhrase);
//     // return 0;

//     // char color[20];
//     // char pluralNoun[30];
//     // char something[30];
//     // char somethingL[30];

//     // printf("enter a color: ");
//     // scanf("%s", color);
//     // printf("enter a plural noun: ");
//     // scanf("%s", pluralNoun);
//     // printf("enter something: ");
//     // scanf("%s%s", something, somethingL);

//     // printf("roses are %s \n", color);
//     // printf("%s are blue \n", pluralNoun);
//     // printf("i love  %s %s \n", something, somethingL);
//     // return 0;
// }

// int calculator(){
//     double num1;
//     double num2;
//     printf("enter first number ");
//     scanf("%lf", &num1);
//     printf("enter second number ");
//     scanf("%lf", &num2);
//     printf("answear: %f \n", num1 + num2);
//     return 0;

//     // double num1;
//     // double num2;
//     // char op;
//     // printf("enter first number \n");
//     // scanf("%lf", &num1);
//     // printf("enter operator \n");
//     // scanf(" %c", &op);
//     // printf("enter second number \n");
//     // scanf("%lf", &num2);

//     // if (op == '+'){
//     //     printf("%f \n", num1 + num2);
//     // } else if (op == '-'){
//     //     printf("%f \n", num1 - num2);
//     // } else if (op == '*'){
//     //     printf("%f \n", num1 * num2);
//     // } else if (op == '/'){
//     //     printf("%f \n", num1 / num2);
//     // } else {
//     //     printf("invalid operator \n");
//     // }

// }

// int past_main(){
    // char name[20];
    // printf("Enter your name ");
    // fgets(name, 20, stdin); //only for str and problem with space
    // printf(" your suck %s's dick \n", name);

    // return 0;
//     // const int NAM = 5;
//     // printf("%d\n", NAM);
//     // // num = 77;
//     // printf("%d \n", NAM);
//     // const char = 'bugaga';
// }

// int som() {
//     // int age = 40;
//     // double gpa = 66.7;
//     // char grade = 'F';
//     // char fuck[] = "fuck?";
//     // return 0;
// }

// int printing() {
//     /*
//     printf("Hi, C!\n");
//     printf("    /| \n");
//     printf("   / | \n");
//     printf("  /  | \n");
//     printf(" /___| \n");
//     */

//     // float n = 5 / 4.4;
//     // printf("%f \n", ceil(44.2));
//     // printf("%f \n", floor(54.2));

//     // char chatactter_name[] = "bob, the builder";
//     // int character_age = 997;
//     // // printf(" there once was a man named %s\n" , chatactter_name);
//     // // printf(" something bob %d\n", character_age);
//     // // character_age = 66;
//     // // printf(" he really liked  %d\n", character_age);
//     // int favNumber = 6667;
//     // printf(" my %s is %d", "dick",  favNumber);
//     // return 0;

    
// }
