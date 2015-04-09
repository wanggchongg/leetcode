int removeElement(int A[], int n, int elem) {
	if(!A||n<=0)
		return 0;
	int count = 0, i;
	for(i=0; i<n; i++)
	{
		if(A[i]!=elem)
		{
			if(count)
				A[i-count] = A[i];
		}
		else
			count++;
	}
	return n-count;
}