#include <stdio.h>
#include <stdlib.h>

int findRevFac(int userNum, int divisor)
{
	if (userNum%divisor != 0)
	{
		return -1;
	}
	else if (userNum / divisor == 1)
	{
		return divisor;
	}
	else
	{
		divisor++;
		return findRevFac(userNum / (divisor - 1), divisor);
	}
}


int main(int argc, char *argv[])
{
	FILE *inputFile = fopen(argv[1], "r");
	FILE *outputFile = fopen(argv[2], "w");
	int userNum;

	while ((fscanf(inputFile, "%d", &userNum) == 1))
	{
		int revFactorial = findRevFac(userNum, 2);

		(revFactorial != -1) ? fprintf(outputFile, "%d = %d!\n", userNum, revFactorial) : fprintf(outputFile, "%d NONE\n", userNum);

	}

	fclose(outputFile);
	fclose(inputFile);
	return 0;
}