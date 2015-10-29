#include <stdio.h>
#include <stdlib.h>

char smallest_character(char str[], char c);

int main()
{
    printf("pid: %d\n", getpid());
    sleep(10);

    char list1[] = {'c','f','j','p','v','\0'};
    char list2[] = {'c','c','k','\0'};
    printf("\n\n\nInput : [%s] \n",list1);
    printf("Output : %c \n", smallest_character( list1, 'a' ));
    printf("Output : %c \n", smallest_character( list1, 'c' ));
    printf("Output : %c \n", smallest_character( list1, 'z' ));
    printf("\nInput : [%s] \n",list2);
    printf("Output : %c \n\n\n", smallest_character( list2, 'f' ));

    return 0;
}

char smallest_character(char str[], char c)
{
    int l = 0;
    int r = 0;
    char ret = str[0];
    while(str[r++] != '\0');
    r-=2;
    while(l <= r) {
        int m = l + (r-l) / 2;
        if(str[m] > c) {
            ret = str[m];
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ret;
}


