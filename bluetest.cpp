#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define ED printf("\n")
#define VER "1.0.0"
using namespace std;

main()
{
	int k,i;
	char ar[10][1000];
	puts("\n\n==============================================================\n\n");
	puts("#####   #       #    #  ######   #####  ######   ####    #####");
 	puts("#    #  #       #    #  #          #    #       #          #");
 	puts("#####   #       #    #  #####      #    #####    ####      #");
	puts("#    #  #       #    #  #          #    #            #     #");
 	puts("#    #  #       #    #  #          #    #       #    #     #");
	puts("#####   ######   ####   ######     #    ######   ####      #");
	puts("\n\n==============================================================");

	printf("欢迎来到Bluetest!\n\n1.新建试题\t2.导入试题\t3.阅读帮助\t4.参与bluetest开发\n\n请输入选择：");
	
	inp:		//错误输入书签
	
	scanf("%d",&k);

	if(k!=1 && k!=2 && k!=3 && k!=4)
	{
		printf("抱歉，请重新输入：");
		goto inp;
	}

	if(k==1)
	{
		printf("配置文件储存在：");
		scanf("%s",ar[0]);
		printf("请输入选手姓名：");
		scanf("%s",ar[1]);
		printf("请输入选手程序目录：");
		scanf("%s",ar[2]);
		printf("标准输入文件目录：");
		scanf("%s",ar[3]);
		printf("标准输出文件目录：");
		scanf("%s",ar[4]);

		freopen(ar[0],"w",stdout);			//写文件
		printf("选手姓名：%s\n",ar[1]);
		printf("程序目录：%s\n",ar[2]);
		printf("输入文件目录：%s\n",ar[3]);
		printf("输出文件目录：%s\n",ar[4]);

	}

	if(k==2)
	{
		printf("请输入要导入的配置文件地址：");
		scanf("%s",ar[0]);
		strcpy(ar[1],"./run  ");
		strcat(ar[1],ar[0]);
		system(ar[1]);
	}

	if(k==3)
	{
		printf("\n\n\t\t\t\t帮助文档-bluetest\n\n\n");

		printf("版本：%s\n",VER);
		printf("配置文件的说明：");
		puts("选手姓名：一个常规字符串，就是需要评测的选手的姓名。");
		puts("程序目录：一个.cpp文件地址，形如“~/桌面/test.cpp”，相对路径、绝对路径均可。");
		puts("输入文件目录：一个文件夹，形如“~/桌面/测试/input”，这里放置1.in、2.in、3.in……");
		puts("输出文件目录：一个文件夹，形如“~/桌面/测试/output”，这里放置1.out、2.out、3.out……");
		
		puts("\n\n\n评测程序的源码在compare.cpp、compile.cpp、judge.cpp、run.cpp、bluetest.cpp。");
		
		ED;ED;ED;ED;


	}

	if(k==4)
	{
		printf("由于作者水平有限、时间不够，bluetest需要你帮忙完善！如果你能实现以下任何功能，请联系我：\n\n\n");
		puts("*1.使bluetest支持Pascal");
		puts("*2.使bluetest支持限制程序运行的时间、内存");
		puts("*3.使bluetest支持多于10个测试点");
		puts("*4.使bluetest支持多位选手");
		puts("*5.使bluetest支持一次性导出成绩到HTML或CSV");
		puts("\n\n感谢！作者邮箱： iam.blue@foxmail.com\n\n\n");
		//或者blue@ourtrouble.com
	}

}