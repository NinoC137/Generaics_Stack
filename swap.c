#include "stdio.h"
#include "string.h"

typedef struct Student_t
{
    int ID;
    int age;
} Student_t;

void swap(void* ptr1, void* ptr2, size_t nbytes){
    char temp[nbytes];
    memcpy(temp, ptr1, nbytes);
    memcpy(ptr1, ptr2, nbytes);
    memcpy(ptr2, temp, nbytes);
}

int main(void){
    int a = 3;
    int b = 4;
    printf("before: a = %d, b = %d\r\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("after: a = %d, b = %d\r\n", a, b);

    char* str1 = "hello";
    char* str2 = "world";
    printf("before: str1 : %s, str2 : %s\r\n", str1, str2);
    swap(&str1, &str2, sizeof(str1));   //思考: 为什么这里传入的参数是str1的地址? 以及为什么字节大小是1字节?
    printf("after: str1 : %s, str2 : %s\r\n", str1, str2);

    Student_t s1 = {1, 2};
    Student_t s2 = {3, 4};
    printf("before: s1.ID = %d, s1.age = %d\r\n", s1.ID, s1.age);
    swap(&s1, &s2, sizeof(Student_t));
    printf("after: s1.ID = %d, s1.age = %d\r\n", s1.ID, s1.age);

    return 0;
}
