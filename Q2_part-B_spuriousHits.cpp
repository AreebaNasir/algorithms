#include<iostream>
#include<cstring>

using namespace std;

void Rabin_Karb(char T[] ,char P[] ,int d,int q)
{
	int n= strlen(T);
	int m=strlen(P);
	int p=0;
	int t=0;
	int h=1;
	int k=0;
	//To find the value of h
	for(k=0;k<m-1;k++)
	{
		h = (h*d)%q;
	}
	//To find hash value for pattern as well as first Text part
	k=0;
	while(k<m)
	{
		p = (d*p+P[k])%q;
		t = (d*t+T[k])%q;
		k++;
	}
	//To compare the hash values
	k=0;
	int count=0;
	for(;k<n-m;k++)
	{
		if(p==t)
		{
			int j;
			for(j=0;j<m;j++)
			{
				if(P[j] != T[k+j])
					break;					
			}
			if(j == m)
				cout<<"Pattern matched within text"<<endl;
			else
				{
					cout<<"Spurious hit is encountered"<<endl;
					count++;
				}				
		}
		if(k<n-m)
		{
			t = (d*(t-T[k]*h)+T[k+m]) % q;
			
		}
		if(t<0)
			t = (t+q);
	}
	cout<<"\nNumber of Spurious hits are "<<count;	
}

int main()
{
	char pattern[]  = "26";
	char text[]  = "3141592653589793";
	int q=11;
	Rabin_Karb(text,pattern,10,q);
	return 0;
}
