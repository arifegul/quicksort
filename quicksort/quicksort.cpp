#include<stdio.h>
#include<conio.h>


void swap(int &i, int &j) {
	
	int temp;
	
	temp = i;
	i = j;
	j= temp;
	
}


int partition(int a[], int low, int high) {
	
	int pivot;
	int up, down;
	
	pivot= a[low];
	up= low;
	down=high+1;
	
	do {
		do {
			
			up = up+1;
		}
		
		while (a[up] <= pivot);
		
		do {
			
			down = down-1;
		} 
		
		while (a[down] > pivot);
		swap(a[up], a[down]);
		
	}
	
	while (up < down);
	
	swap(a[up], a[down]);
	swap(a[low], a[down]);
	
	return down;
}

void quicksort(int a[], int low, int high) {
	
	int pivotpos;
	
	if(low<high) {
		
		pivotpos = partition(a,low,high);
		quicksort(a,low,pivotpos-1);
		quicksort(a,pivotpos+1,high);
	}
}



int main() {
	
	int a[20],number, i=0;
	printf("Enter the number of the elements: ");
	scanf("%d", &number);
	
	printf("\n Enter the elements: \n", number);
	
	for(i=0; i<number; i++)
		scanf("%d", &a[i]);
		
	quicksort(a,0,number-1);
		
	printf("\n The elements after sorting are:");
	
	for(i=0; i<number; i++)
		printf(" %d", a[i]);
	return 0;
}

