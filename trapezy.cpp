#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double funkcja(double x)
 {
    return 4 * x - 6 * x + 5;
}

int random(int min, int max)
{
	srand(getpid());
   return min + rand() % (( max + 1 ) - min);
}

double oblicz(double a, double b, int trapezy)
 {
    double sum = 0;
    double h = (b - a) / trapezy;
    sum += (funkcja(a) + funkcja(b)) / 2;
    for(int i = 1; i < trapezy; i++)
    {
        sum += funkcja(a + i * h);
    }

    return sum * h;
}

int main()
 {
    int p;
    printf("Liczba potomnych procesow: ");
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
        {
        if (fork() == 0) {
			
            int a = random(-40,0);
			int b = random(0,40);

            int trapezy = (rand() % (20 - 1 + 1)) + 1;

            printf("\nCalka w przedziale (%d - %d) wynosi %f",a,b, oblicz(a, b, trapezy));

            exit(0);
        }
    }

    return 0;
}
