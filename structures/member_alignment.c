#include <stdio.h>

typedef struct structa_tag
{
    char c;   
    short int s;
} structa_t;

typedef struct structb_tag
{
    short int s;
    char c;
    int i;
} structb_t;

typedef struct structc_tag
{
    char c;
    double d;
    int i;
} structc_t;

typedef struct structd_tag
{
    double d;
    int i;
    char s;
} structd_t;


int main()
{
    printf("size of structa is %zu.\n", sizeof(structa_t));
    printf("size of structb is %zu.\n", sizeof(structb_t));
    printf("size of structc is %zu.\n", sizeof(structc_t));
    printf("size of structd is %zu.\n", sizeof(structd_t));

}
