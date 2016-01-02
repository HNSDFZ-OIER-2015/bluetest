#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc,char** argv)			//argv[1]选手输出,argv[2]目标输出
{
	char shell[1000]={"diff -b -B  "};		//忽略空格、空行
	int n;

	strcat(shell,argv[1]);
	strcat(shell,"  ");
	strcat(shell,argv[2]);
	strcat(shell," >cmp.dia");

	n=system(shell);
	system("rm cmp.dia");
	//printf("%d\n",n);

	if(n==0) return 0;		//比对成功
	else return -1;			//比对失败

}