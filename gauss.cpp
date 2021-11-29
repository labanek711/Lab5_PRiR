#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctime>

int random(int min, int max)
{
	srand(getpid());
   return min + rand() % (( max + 1 ) - min);
}

double funkcja(double x)
 {
	 
    return 4 * x - 6 * x + 5;
}

double kwadraturyGaussa(int a, int b, double wagi1[], double wagi2[]){
	int n = sizeof(wagi1);
	double temp = 0;
	for(int i=0; i<n; i++){
		temp += wagi1[i] * funkcja(((b-a)/2)*wagi2[i] + ((b+a)/2));
	}
	return ((b-a)/2)*temp;
}

int main(){
	
	
	double wagi1[] = 
				{0.3626837833783620,
				0.3626837833783620,
				0.3137066458778873,
				0.3137066458778873,
				0.2223810344533745,
				0.2223810344533745,
				0.1012285362903763,
				0.1012285362903763};
	double wagi2[] = 
				{-0.1834346424956498,
				0.1834346424956498,
				-0.5255324099163290,
				0.5255324099163290,
				-0.7966664774136267,
				0.7966664774136267,
				-0.9602898564975363,
				0.9602898564975363};
	int p;
    printf("Ilosc procesow: ");
    scanf("%d", &p);
    for(int i=0; i<p; i++){
		if(fork() == 0){
			int a = random(-20,0);
			int b = random(0,20);
			printf("\nCalka w przedziale (%d - %d) wynosi %f",a,b,kwadraturyGaussa(a,b,wagi1,wagi2));
			exit(0);
		}
	}
return 0;
}
