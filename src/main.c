/* main.c */
/*  
 * Автор: Xeiniya  
 * Описание: Программа сортирует массив натуральных чисел в порядке неубывания сумм цифр десятичной записи чисел.  
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Функция для вычисления суммы цифр числа */
int sumOfDigits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

/* Функция для сортировки массива */
int compare(const void *a, const void *b) {
	int sumA = sumOfDigits(*(int *)a);
	int sumB = sumOfDigits(*(int *)b);
	return sumA - sumB;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Использование: %s <размер массива>\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	if (n <= 0) return 1;

	int arr[n];
	srand(time(NULL));

	/* Заполнение массива случайными числами от 10 до 99 */
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 90 + 10; 
		printf("%d ", arr[i]);
	}
	printf("\n");

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}