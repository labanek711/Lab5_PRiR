#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int random(int min, int max)
{
	srand(getpid());
   return min + rand() % (( max + 1 ) - min);
}

double calculate(int n)
 {
    double sum = 0;
    double temp;
    for(int i = 1; i <= n; i++)
    {
        temp = pow(-1, i - 1) / (2 * i - 1);
        sum += temp;
    }
    return 4 * sum;
}

int main()
{
    int proces;
    printf("Ilosc procesow: ");
    scanf("%d", &proces);
    for (int i = 0; i < proces; i++)
    {
        if (fork() == 0)
        {
            int n = random(100,5000);

            printf("N = %d, Pi= %f\n", n, calculate(n));
            exit(0);
        }
    }
    return 0;
}
