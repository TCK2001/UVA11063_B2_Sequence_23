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
		int size[n]={'\n'}; //�Է��ϴ� �Լ�;
		int check[20001]={'\n'}; //�ߺ� üũ�ϴ� �Լ� 1;
		bool flag=true; //�ߺ� üũ�ϴ� �Լ� 2;
		for(int i=0;i<n;i++)
		{
			cin>>size[i];
			if(size[i]<1) //���࿡ �Է°��� 0�̰ų� 0���� ������ ������false; 
			{
				flag=false;
			}
		}
		for(int j=0;j<n;j++) //0 ~ n-1
		{ 
			for(int k=j;k<n;k++) //0 ~ n-1  
			{
				if(check[size[j]+size[k]]!=0) //�Ǵ� �Լ� ���� ���� �� ���ڰ� �־������ false; 
				{			 		
					flag=false; //ex 1,2,3,4  i=0,j=0 -> 1+1=2 , i=0,j=1 -> 1+2=3 , i=0,j=2 -> 1+3=4 ,i=0,j=3 -> 1+4=5  
					break;      //			  i=1 j=1 -> 2+2=4(�ߺ�) , i=1 j=2 -> 2+3=5(�ߺ�) , i=1 j=3 -> 2+4=6 ..........
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
