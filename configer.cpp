#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define ED printf("\n")
using namespace std;

int main(int argc,char** argv)
{

	freopen(argv[1],"r",stdin);

	int n,i=0,k;

	char p[100][1000],s[1000],a[1000],te[1000]={"ls  "},inp[1000],out[1000],pro[100];

	scanf("%s%s%s",pro,inp,out);
	scanf("%s",s);
	
	strcat(te,s);
	//puts(te);
	strcat(te,"  > list");
	system(te);

	freopen("list","r",stdin);

	freopen(argv[1],"w",stdout);

	while(scanf("%s",p[i])!=EOF)
	{
		printf("选手姓名：%s\n",p[i]);
		printf("程序目录：%s/%s/%s.cpp\n",s,p[i],pro);
		printf("输入文件目录：%s\n",inp);
		printf("输出文件目录：%s\n",out);
		ED;ED;ED;

	}

}