#include<iostream>
#include<cstring>

using namespace std;


void bad_character_rule(char pat[],int bad_character[256],int size)
{
	int m = strlen(pat);
	int i=0;
	for(;i<size;i++)
		bad_character[i] = -1;
		
	i=0;
	for(;i<m;i++)
		bad_character[(int)pat[i]] = i;
	
}

void Boyer_Moore(char t[],char p[],int no_of_chars)
{
	int n = strlen(t);
	int m = strlen(p);
	
	int bad_character[no_of_chars];
	bad_character_rule(p,bad_character,no_of_chars);
	
	int i=0;
	while(i<(n-m+1))
	{
		int j = m-1;
		while(j>=0 && p[j] == t[i+j])
			j--;
		
		if(j < 0)
		{
			cout<<"Pattern is matched"<<endl;
		
		if(i+m < n)
			i = i+(m-bad_character[t[i+m]]);
		else
			i = i+1;
		}
		else
		{
			i = i+max(j - bad_character[t[i+j]],1);
		}
	}
	
}
int main()
{
	char text[] = "abcaabcccba";
	char pattern[] = "abc";
	Boyer_Moore(text,pattern,256);
	return 0;
}
