#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double _atoi(char *s);

int main(int argc, char *argv[])
{
    char number[50];
    FILE *file;
    double i = 2, n;

    if (argc != 2)
    {
        printf("Usage: factors <file>\n");
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("can't open file\n");
        exit(1);
    }

    while (fgets(number, 50 * sizeof(char), file) != NULL)
    {
	    while (fmod(n, i) != 0)
	    	i++;
	    printf("%f=%f*%f",n , n / 2, i);	
        printf("%f\n", _atoi(number));
    }
}

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: 0 if there are no numbers in the string
 */
double _atoi(char *s)
{
	double sign = 1;
	double result = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign = -1;

		else if (*s >= '0' && *s <= '9')
			result = result * 10 + (*s - '0');

		else if (result > 0)
			break;

		s++;
	}

	return (sign * result);
}
