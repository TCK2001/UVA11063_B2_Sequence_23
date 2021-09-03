/*
4
1 2 4 8
4
3 7 10 14
Sample Output
Case #1: It is a B2-Sequence.
Case #2: It is not a B2-Sequence.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm> 

using namespace std; 

int main()
{
	int n,t=0;
	while(cin>>n)
	{
		int size[n]={'\n'}; //입력하는 함수;
		int check[20001]={'\n'}; //중복 체크하는 함수 1;
		bool flag=true; //중복 체크하는 함수 2;
		for(int i=0;i<n;i++)
		{
			cin>>size[i];
			if(size[i]<1) //만약에 입력값이 0이거나 0보다 작으면 무조건false; 
			{
				flag=false;
			}
		}
		for(int j=0;j<n;j++) //0 ~ n-1
		{ 
			for(int k=j;k<n;k++) //0 ~ n-1  
			{
				if(check[size[j]+size[k]]!=0) //판단 함수 만약 전에 이 숫자가 있었을경우 false; 
				{			 		
					flag=false; //ex 1,2,3,4  i=0,j=0 -> 1+1=2 , i=0,j=1 -> 1+2=3 , i=0,j=2 -> 1+3=4 ,i=0,j=3 -> 1+4=5  
					break;      //			  i=1 j=1 -> 2+2=4(중복) , i=1 j=2 -> 2+3=5(중복) , i=1 j=3 -> 2+4=6 ..........
				}
				else
				{
					check[size[j]+size[k]]=1;
				}
			}
		}
		if(flag)
		{
			cout <<"Case #"<<++t<<": It is a B2-Sequence."<<endl;
		}
		else
		{	
			cout <<"Case #"<<++t<<": It is not a B2-Sequence."<<endl;
		}
	}
return 0;
}
