#include <stdio.h>
#include <stdlib.h>
/*merge sort and count reverses in the orignal array*/
int res = 0;

int merge(int *a, int l, int m, int r) {
	int *b = (int*)malloc((r-l+1)*sizeof(int));
	int k = 0;
	int i, j;
	i = l;
	j = m+1;
	while(i<=m && j<=r) {
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			res += m-i+1;
		}
	}
	while(i <= m) 
		b[k++] = a[i++];
	while(j <= r) 
		b[k++] = a[j++];
	for(k=0; k<r-l+1; k++)
		a[l+k] = b[k];
	free(b);
}

void merge_sort(int *a, int l, int r) {
	if(l >= r) {
		return;	
	}	
	int m = (l+r)/2;
	merge_sort(a, l, m);
	merge_sort(a, m+1, r);
	merge(a, l, m, r);
}

int main(void) {
	int a[] = {10, 102, 9, 92};
	int n = sizeof(a)/sizeof(a[0]);
	merge_sort(a, 0, n-1);
	int i;
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("res = %d\n", res);
	return 0;
}
