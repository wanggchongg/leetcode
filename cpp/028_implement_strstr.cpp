int strStr(char *haystack, char *needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if(len1 < len2)
    	return -1;
    int i;
    for(i=0; i<len1-len2; i++)
    {
    	if(!memcmp(haystack+i, needle, len2))
    	{
    		return i;
    	}
    }
    return -1;
}