#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define ED printf("\n")
using namespace std;

char fun[10];

void ITOA(int xxx)			//Linux下没有itoa()
{
	memset(fun,0,sizeof(char));	//清空方便动手

	char a[10]={0},o[10]={0};
	int i=0,l;

	while (xxx>0)
	{
		a[i]=xxx%10+48;
		xxx=xxx/10;
		i++;
	}

	l=i-1;

	for(i=0;i<=l;i++) o[i]=a[l-i];

	//printf("\t%s\n\n",o);

	strcpy(fun,o);
	//printf("\t%s\n\n",fun);
	//return o;

}

//ar[1]选手姓名，ar[2]程序目录，ar[3]输入文件目录，ar[4]输出文件目录
int main(int argc,char** argv)		//argv[1]评测设置文件
{
	//ITOA(50);
	//freopen()
	char ar[10][1000];

	freopen(argv[1],"r",stdin);

	//puts(argv[1]);

	scanf("选手姓名：%s\n",ar[1]);
	scanf("程序目录：%s\n",ar[2]);
	scanf("输入文件目录：%s\n",ar[3]);
	scanf("输出文件目录：%s\n",ar[4]);
	//scanf("卡时（秒）：%s\n",ar[5]);
	//scanf("卡内存（KB）：%s\n",ar[6]);

	queue <char> q;			//储存选手程序过点情况

	char ci[1000]={"./compile "},ju[1000]={"./judge ./a.out  "},ti[100]={"ulimit -t "},cp[100]={"ulimit -m "};
	
	//strcat(ti,ar[5]);
	//system(ti);
	//strcat(cp,ar[6]);
	//system(cp);

	int n,i,s=0;
	printf("开始评测选手 %s ：\n",ar[1]);
	strcat(ci,ar[1]);
	strcat(ci," ");
	strcat(ci,ar[2]);

	//puts(ci);

	n=system(ci);

	if(n!=0)
	{
		printf("%s编译错误！\n",ar[2]);
		return -1;
	}
	for(i=1;i<=10;i++)
	{
		
		strcat(ju,ar[3]);
		strcat(ju,"/");
		ITOA(i);
		strcat(ju,fun);
		strcat(ju,".in ");				//标准输入.in
		strcat(ju,ar[4]);			//标准输出.out
		strcat(ju,"/");
		strcat(ju,fun);
		strcat(ju,".out ");	
		//puts(ju);

		n=system(ju);
		printf("--------测试点#%d",i);
		strcpy(ju,"./judge ./a.out  ");
		if(n==0) s+=10,q.push('T');
		else q.push('F');
		ED;
	}

	printf("\n\n\n\t选手 %s 拿到的分数为：%d。\t",ar[1],s);
	while(q.size()!=0) printf("%c",q.front()),q.pop();
	ED;ED;

	return s;


}