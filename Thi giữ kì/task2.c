/*
Lê Thế Anh
MSSV: 20200018
*/
#include <stdio.h>
#define maxSize 30

// Stack dung de luu phep toan
char stack[maxSize];
int size = 0;
void push(char operator) {
   if (size == maxSize - 1) {
      printf("Stack overflow");
      return;
   }
   stack[size] = operator;
   size++;
}
char pop() {
   if (size == 0) {
      printf("Stack empty");
      return '\n';
   }
   return stack[--size];
}
char getTop() { return stack[size - 1]; }

// Ham lay thu tu thuc hien phep tinh
int getOrder(char c) {
   if (c == '+' || c == '-')
      return 0;
   else
      return 1;
}

// Stack dung de tinh toan ket qua
int numberStack[maxSize];
int numSize = 0;
void pushNum(int x) {
   if (numSize == maxSize - 1) {
      printf("Stack overflow");
      return;
   }
   numberStack[numSize] = x;
   numSize++;
}
int popNum() {
   if (numSize == 0) {
      printf("Stack empty");
      return '\n';
   }
   return numberStack[--numSize];
}
int main() {
   char c = getchar();
   int x;
   int result = 0;
   do {
      if ('0' <= c && c <= '9') {
         pushNum((int)c - '0');
         putchar(c);
         putchar(' ');
      } else {
         int order = getOrder(c);
         while (size > 0 && getOrder(getTop()) >= order) {
            char operator= pop();
            int tmp = popNum();
            if (operator== '+')
               tmp += popNum();
            if (operator== '-')
               tmp = popNum() - tmp;
            if (operator== '*')
               tmp *= popNum();
            if (operator== '/')
               tmp = popNum() / tmp;
            pushNum(tmp);
            putchar(operator);
            putchar(' ');
         }
         push(c);
      }
      c = getchar();
   } while (c != '\n');
   while (size > 0) {
      char operator= pop();
      int tmp = popNum();
      if (operator== '+')
         tmp += popNum();
      if (operator== '-')
         tmp = popNum() - tmp;
      if (operator== '*')
         tmp *= popNum();
      if (operator== '/')
         tmp = popNum() / tmp;
      pushNum(tmp);
      putchar(operator);
      putchar(' ');
   }
   result = popNum();
   printf("\nResult = %d", result);
}