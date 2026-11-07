
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
     int num1 = atoi(argv[1]);
     int num2 = atoi(argv[2]);
     int div = atoi(argv[3]);
     if (num1 > num2) {
         while (num1 >= num2) {
             if (num1 % div == 0) {
                 cout<<num1<<endl;
                 }
                num1 --;
             }
         } else {
         while (num1 <= num2) {
             if (num1 % div == 0) {
                 cout<<num1<<endl;
                 }
                 num1 ++;
             }
         }
     }