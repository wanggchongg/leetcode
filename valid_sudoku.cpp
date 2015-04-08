bool isValidSudoku(char board[9][9]) {
	char compare[10] = {0};
	int i, j, k, l;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(board[i][j]>='1'&&board[i][j]<='9')
			{
				compare[board[i][j]-'0']++;
			}
			if(compare[board[i][j]-'0']>1)
				return false;
		}
		memset(compare, 0, 10);
	}

	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(board[j][i]>='1'&&board[j][i]<='9')
			{
				compare[board[j][i]-'0']++;
			}
			if(compare[board[j][i]-'0']>1)
				return false;
		}
		memset(compare, 0, 10);
	}

	for(i=0; i<9; i+=3)
	{
		for(j=0; j<9; j+=3)
		{
			for(k=0; k<3; k++)
			{
				for(l=0; l<3; l++)
				{
					if(board[i+k][j+l]>='1'&&board[i+k][j+l]<='9')
					{
						compare[board[i+k][j+l]-'0']++;
					}
					if(compare[board[i+k][j+l]-'0']>1)
						return false;
				}
			}
			memset(compare, 0, 10);
		}
	}
	return true;
}