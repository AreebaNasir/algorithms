#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void print(std::vector <int> const &a) {
   cout << "The vector elements are : ";
   
   for(int i=0; i < a.size(); i++)
      std::cout << a.at(i) << ' ';
}
//Prefix function

vector<int> Prefix_function(string P)
{
	vector<int> Pi(P.size());
	Pi[0]=0;
	int k=0;
	for(int q=1;q< P.size();q++)
	{
		while((k>0) && (P[k] != P[q]))
		{
			k=Pi[k-1];
		}
		if(P[k] == P[q])
			k=k+1;
		Pi[q]=k;
		
	}
	return Pi;
}

int main(){
	string st="aabaabcab";
	vector<int> Pii(st.size());
	Pii=Prefix_function(st);
	print(Pii);
	return 0;
	
}
