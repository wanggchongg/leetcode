int removeDuplicates(int A[], int n) {
	if(n<=1)
		return n;
	int count = 0;
	int i = 0;
    for(i=1; i<n; i++)
    {
    	if(A[i]!=A[i-1])
    	{
    		if(count)
	    		A[i-count] = A[i];
    	}
    	else
    		count++;
    }
    return n-count;
}