#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

main(int argc,char** argv)				//argv[1]选手程序,argv[2]in,argv[3]out
{
	char stu[1000]={"./a.out  <  "},cmp[1000]={" ./compare "};
	int n;

	strcat(stu,argv[2]);
	strcat(stu,"  ");
	strcat(stu,">output.txt");

	//puts(stu);
	system(stu);

	strcat(cmp," output.txt ");
	strcat(cmp,argv[3]);

	//puts(cmp);
	n=system(cmp);

	system("rm ./output.txt");

	if(n==0)
	{
		printf("通过测试点");

		return 0;
	} 
	else printf("答案错误");
	return -1;

}