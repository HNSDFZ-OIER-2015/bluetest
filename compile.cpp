#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc,char** argv)				//argc参数数量，argv[1]选手，argv[2]文件地址
{
	char path[1000],name[1000],shell[1000]={"g++  "},err[1000],cpy[1000]={"mv error.dia "};
	int n,i,p;

	if(fopen(argv[2],"r")==NULL) 
	{
		printf("%s选手的%s源码都找不到！\n",argv[1],argv[2]);		//找不到文件
		return -2;
	}

	else
	{
		//Go-----------------------------------------------------

		printf("开始编译选手\"%s\"的题目：%s------",argv[1],argv[2]);

		strcat(shell,argv[2]);			//g++ example.cpp
		strcat(shell," 2>error.dia");		//g++ example.cpp 2>error.dia

		p=system(shell);			//执行，信息保存到p中

		if(p==0) 
		{
			printf("编译成功！\n");
			system("rm error.dia");
			return 0;
		}
		else
		{
			strcpy(err,"Error");			//Error
			strcat(err,"-");				//Error-
			strcat(err,argv[1]);			//Error-Blue
			strcat(err,"-");				//Error-Blue-
			strcat(err,argv[2]);			//Error-Blue-Example.cpp

			strcat(cpy,err);
			//printf("%s",cpy);
			printf("编译失败！错误信息保存在./%s.\n",err);
			system(cpy);

			return -1; 
		}
		//Ed-----------------------------------------------------
	}

}
