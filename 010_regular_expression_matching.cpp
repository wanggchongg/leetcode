#include <iostream>
using namespace std;

typedef struct STACK
{
	int s_i;
	int p_i;
}STACK;

bool isMatch(char *s, char *p)
{
	if(s||p) return false;
	if('*' == p[0]) return false;
	int s_i = 0, p_i = 0;
	STACK *stack = (STACK *)malloc(sizeof(STACK)*100);
	int top = -1;

	while(s[s_i] && p[p_i])
	{
		if(p[p_i+1] != '*')
		{
			if(p[p_i] == '.' || p[p_i] == s[s_i])
			{
				p_i++;
				s_i++;
			}
			else
				return false;
		}
		else
		{
			top++;
			stack[top]->p_i = p_i;
			stack[top]->s_i = s_i;
			p_i += 2;
		}
	}
}

// bool isMatch(char *s, char *p)
// {
// 	int s_i = 0, p_i = 0;
// 	int star_i = 0;
// 	if(p[0] == '*')
// 		return false;
// 	while(s[s_i] && p[p_i])
// 	{
// 		if(p[p_i] == s[s_i])
// 		{
// 			s_i++;
// 			p_i++;
// 		}
// 		else if(p[p_i] == '.')
// 		{
// 			s_i++;
// 			p_i++;
// 		}
// 		else if(p[p_i] == '*')
// 		{
// 			if(p[p_i-1] == '.')
// 			{
// 				s_i++;
// 				star_i++;
// 			}
// 			else if(p[p_i-1] == s[s_i])
// 			{
// 				s_i++;
// 				star_i++;
// 			}
// 			else
// 			{
// 				p_i++;
// 				star_i = 0;
// 			}
// 		}
// 		else
// 		{
// 			if(p[p_i+1] == '*')
// 				p_i += 2;
// 			else
// 				return false;
// 		}
// 	}

// 	if(s[s_i])
// 		return false;

// 	while(p[p_i])
// 	{
// 		if(p[p_i] == '*')
// 		{
// 			p_i++;
// 		}
// 		else if(p[p_i] == '.')
// 		{
// 			if(star_i)
// 			{
// 				star_i--;
// 				p_i++;
// 			}
// 			else
// 				return false;
// 		}
// 		else if(p[p_i+1] == '*')
// 		{
// 			p_i += 2;
// 		}
// 		else if(p[p_i] == s[s_i-1])
// 		{
// 			if(star_i)
// 			{
// 				star_i--;
// 				p_i++;
// 			}
// 			else
// 				return false;
// 		}
// 		else
// 			return false;
// 	}

// 	return true;
// }

int main()
{
	char s[] = "abab";
	char p[] = ".*.*.*..";
	bool result;
	result = isMatch(s, p);

	cout<<"result="<<boolalpha<<result<<endl;
	return 0;
}
