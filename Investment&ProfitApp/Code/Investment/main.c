#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define M 100

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int arr2[], int arr3[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for(j=0;j<n-i-1;j++)
			if (arr[j] < arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swap(&arr2[j], &arr2[j + 1]);
				swap(&arr3[j], &arr3[j + 1]);
			}
	}
}

int main() {
	
	int C,n,a[M], v[M], p[M];
	FILE* fp,*g;
	fp = fopen("investment_in3.txt", "r");
	g = fopen("investment_out.txt", "w");
	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d %d", &C, &n);
	fprintf(g, "\n   your Capital value:  %d", C);
	fprintf(g, "\n   the number of offers: %d ", n);

	
	for (int i = 0; i < n; i++) {
		fscanf(fp," %d", &a[i]);
		fprintf(g,"\n Enter the number available shares: %d", a[i]);
		fscanf(fp," %d", &v[i]);
		fprintf(g,"\n Each shares have the value : %d", v[i]);
		fscanf(fp," %d", &p[i]);
		fprintf(g,"\n Each shares have the profit :  %d", p[i]);
	}
	fclose(fp);
	clock_t t1,t2;
	t1 = 0;
	bubbleSort(p, a, v, n);
	t2 = clock();
	double time_taken =t2-t1 / CLOCKS_PER_SEC; // in seconds
	fprintf(g, "\n Bubble Sorting Time: %f ",time_taken);

	fprintf(g, "\n number available shares:  ");
	for (int i = 0; i < n; i++) {
		fprintf(g, " %d ", a[i]);
	}
	fprintf(g, "\nvalue of the shares:  ");
	for (int i = 0; i < n; i++) {
		fprintf(g, " %d ", v[i]);

	}
	fprintf(g, "\nprofit of the shares:  ");
	for (int i = 0; i < n; i++) {
		fprintf(g, " %d ", p[i]);

	}

	int sum = 0, money=C,profit=0,index=-1;
	for (int i = 0; i < n; i++) {
		if ((money > 0 )&& (money>=a[i]*v[i])) {//ne asiguram ca conditia este pusa pentru o suma de bani pe care ne permitem
			sum = sum + v[i] * a[i];//suma de bani cheltuita
			money= money - v[i] * a[i];//banii ramasi
			profit =profit+ p[i] * a[i];//profitul castigat
			index++;
		}
		else break;
	}
	fprintf(g, "\n We still have  %d  money ", money);
	fprintf(g, "\n First profit is  %d   ", profit);

	int sum2 = 0;
		for (int i = index + 1; i < n; i++) {//pornim de la indexul ramas in cumpararea actiunilor facuta anterior
			int j = a[i] ;
			while (j>=1) {
				if (money >= (a[i] - j) * v[i]) {
					sum2 = sum2 + (a[i] - j) * v[i];
					money = money - (a[i] - j) * v[i];
					profit = profit + p[i] * (a[i] - j);
					j--;
				}
				else j--;
			}
		}
	 fprintf(g, "\n We still have  %d  money ", money);
	 fprintf(g, "\n Final profit is  %d   ", profit);


	 fclose(g);

}