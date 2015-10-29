#include <stdio.h>
#include <stdlib.h>

char smallest_character( char str[], char c );
char do_recursive( char str[], char c, int l, int r, char ret );

int main()
{
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

char smallest_character( char str[], char c )
{

    int l = 0;
    int r = 0;
    while(str[r++] != '\0');
    r-=2;
    return do_recursive( str, c, l, r , str[0]);
}

char do_recursive(char str[], char c, int l, int r, char ret)
{

    int m = l + (r-1) / 2;
    if(l > r) return ret;
    if( str[m] > c ) {
        return do_recursive(str, c, l, m-1, str[m]);
    } else {
        return do_recursive(str, c, m+1, r, ret);
    }
}

