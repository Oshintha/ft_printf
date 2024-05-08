#include <stdio.h>
#include <stdarg.h>
# include <string.h>

void print(char *placeholders, ...)
{
	int num_args = strlen(placeholders);

	va_list args;
	va_start (args, placeholders);

	for (int i = 0; i < num_args; i++)
	{
		if (placeholders[i] == 'd')
		{
			int x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}

	}
	va_end(args);
}
int main()
{
	print("fddfd", 1, 4, 5, 6.5, 5.8);
	return (0);
}
