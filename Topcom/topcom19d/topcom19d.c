#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int fatorial(long int n)
{
    if (n > 0)
        return n * fatorial(n - 1);
    else
        return 1;
}

long int arranjo(long int n,long int p)
{
    if (p > 1)
        return n * arranjo(n - 1, p - 1);
    else
        return n;
}

long int combinacao(long int n,long int p)
{
    return arranjo(n, p) / fatorial(p);
}

int main(int argc, char const *argv[])
{
    char a[1000000], b[1000000];
    long int aux = 0, seq = 0, count = 0, ans = 0, i;
    scanf("%s\n%s", a, b);
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] != b[i])
        {
            seq = 1;
            if (seq = 1)
            {
                count++;
            }
        }
        else if (a[i] == b[i])
        {
            if (seq == 1)
            {
                long int inter = combinacao(count, 1);
                if (inter > 1)
                    inter -= 1;
                ans += inter;
                count = 0;
            }
            seq = 0;
        }
        //printf("%c///%c///ans: %ld///count: %ld\n", a[i], b[i], ans, count);
    }
    if (a[i-1] != b[i-1])
    {
       
        long inter = combinacao(count, 1);
        if (inter > 1)
            inter -= 1;
        ans += inter;
    }
    printf("%ld\n", ans);
    return 0;
}
