#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    n = 0;

    puts("Masukkan banyak baris: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k < (2*i-1); k++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (int k = n; k >= (2*i - 5); k--)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
