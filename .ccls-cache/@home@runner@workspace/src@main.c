/* main.c */
#include <stdio.h>

/* Функция для вычисления суммы цифр числа */
int sumOfDigits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main (void)
{
	int test_number = 12345;
	printf("Сумма цифр числа %d: %d\n", test_number, sumOfDigits(test_number));
	return 0;
}
