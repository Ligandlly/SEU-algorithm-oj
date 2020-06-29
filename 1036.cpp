#include <bits/stdc++.h>
using namespace std;
char *a;
char *b;
int *c;
void save(int n){
	c[0] = -1;
	int i=0,j=-1;
	while(i<n){
		if(j==-1||b[i]==b[j]){
			++i;++j;
			c[i] = j;
//			cout<<"i "<<i<<" c[i] "<<c[i]<<endl;
		}else{
			j = c[j];
		}
	}
	
/*	for(int i=0;i<=n;i++)
	cout<<c[i]<<" ";
	cout<<endl;*/
}
int kmp(int l1,int l2){
	int i = 0;int j=0;int num = 0;
	while(j<l1)
	{
		if(i==-1||a[j] == b[i])
		{i++;j++;}
		else i = c[i];
		if(i==l2){
			num++;i = c[i];
		}
	}
	return num;
}
int main(){
	int M,l1,l2;
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>l1>>l2;
		a = new char[l1+1];
		b = new char[l2+1];
		c = new int[l2+1];
		cin>>a>>b;
		save(l2);
		cout<<kmp(l1,l2)<<endl;
delete []a; delete []b; delete []c;
	}
	return 0;
} 
