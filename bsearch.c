#include <stdio.h>

int bsearch1(int *a, int low, int high, int key) {
	while(low <= high) {
		int mid = low+(high-low)/2;
		if(a[mid] == key)
			return mid;
		else if(a[mid < key])
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -(low+1);
}

int bsearch2(int *a, int low, int high, int key) {
	while(low < high) {
		//low < high, so mid < high
		int mid = low + (high-low)/2;
		if(a[mid] <  key)
			low = mid + 1;
		else 
			high = mid;
	}
	if(low == high && a[low] == key)
		return low;
	return -(low+1);
}

int main(void) {
	int a[] = {1, 1, 1, 1, 1, 1, 1};
	int n = sizeof(a)/sizeof(a[0]);
	int key = 1;
	printf("search1: %d\n", bsearch1(a, 0, n-1, key));
	printf("search2: %d\n", bsearch2(a, 0, n-1, key));
	return 0;
}
