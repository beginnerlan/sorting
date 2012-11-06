int find_idx(int *a, int n , int key) {
	int low, high, mid; 
	low = 0;
	high = n-1;
	while(low <= high) {
		mid = low+(high-low)/2;
		if(a[mid] >= key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(low == 0)
		return -1;
	else
		return low-1;
}