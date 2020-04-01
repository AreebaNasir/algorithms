#include<iostream>
#include<cstring>

using namespace std;

void Naive_Algorithm(char t[],char p[])
{
	int n=strlen(t);
	int m=strlen(p);
	for(int i=0;i<n-m+1;)
	{
		int j=0;
		for(;j<m;j++)
		{
			if(t[i+j] != p[j])
				break;
		}
		if(j==m)
		{
			cout<<"\nPattern matched"<<endl;
			i+=m;
		}
			
		else if(j==0)
			i++;
		else
			i+=j;
	}
}

int main()
{
	char Pattern[]="aab";
	char text[]="aacaabbaadaab";
	Naive_Algorithm(text,Pattern);
	return 0;
}
