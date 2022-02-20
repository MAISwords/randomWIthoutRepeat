//使用两个数组，一个是主数组，一个是辅助数组
//原理，利用辅助数组存储主数组的元素下标
//从而达到真正的不重复随机效果，本实例采用动画进行演示
//说明如果只是单纯使用rand()进行随机的话，那么实际上两次重复随机的次数也是一样的
// T.aoyan 2022.2.20 00:34
#include <iostream>
#include <cstdlib>  //取随机数要用到
#include <windows.h> //清屏功能的头文件
#include <time.h>    //让程序每次执行时的随机种子随着时间变动，增强随机性

//不重复随机函数
void randomWithoutRepeat()
{
	//记录算法消耗的时间
	DWORD time_start, time_end;
	time_start = GetTickCount();
	//让随机种子随系统时间变化
	srand((unsigned)time(0));
	//声明一个整数，用于证明我们总共随机了1600次
	int proof = 0;
	//声明一个整数，用于表示辅助数组的长度，这个值每次随机都会减少1
	int length = 1600;
	//声明两个数组，主数组和辅助数组，预计随机1600次
	int mainArray[1600];
	int supportArray[1600];
	//给主数组赋值，一开始全部都是0
	for (int i = 0; i < 1600; i++) { mainArray[i] = 0; }
	//给辅助数组赋值，储存的是主数组元素的下标，从0-1599
	for (int i = 0; i < 1600; i++) { supportArray[i] = i; }
	//算法开始
	while (true)
	{
		//进行动画打印
		for (int i = 0; i < 1600; i++)
		{
			if (mainArray[i] == 0) { std::cout << "□"; }//未被随机过的打印□
			else { std::cout << "■"; }//已经被随机过的打印■
									  //每输出40次，进行一次换行，人为构成一个正方形，便于观察
			if (i % 40 == 39) { std::cout << std::endl; }
		}
		//先进行判定，如果length的值小于1，那么算法流程结束
		if (length >= 1)
		{
			//每次打印完成之后,进行一次随机
			int random = rand() % length;
			//每随机一次，proof加1
			proof = proof + 1;
			//把随机到的值,所对应的下标在辅助数组对应的元素的那个值
			//与辅助数组最后的那个元素值进行交换
			int temp = supportArray[random];
			supportArray[random] = supportArray[length - 1];
			supportArray[length - 1] = temp;
			//之后把辅助数组末尾的那个数，当做主数组的下标进行操作即可
			mainArray[supportArray[length - 1]] = 1;
			//最后辅助数组的随机长度减1
			length = length - 1;
		}
		else { break; }//如果length长度为0，那么算法执行完毕，退出
					   //每次图像绘制完成后，休息50毫秒，并且清屏
		//Sleep(50);
		system("cls");
	}
	time_end = GetTickCount();
	std::cout << "该算法已经完成！一共随机了" << proof << "次！" << std::endl;
	std::cout << "该算法消耗的时间为:" << (time_end - time_start)<<"毫秒！" <<std::endl;
	system("pause");//程序执行完成之后，一个暂停，用于观察结论！

}
//重复随机函数
void randomRepeat()
{
	//记录算法消耗的时间
	DWORD time_start, time_end;
	time_start = GetTickCount();
	//让随机种子随系统时间变化
	srand((unsigned)time(0));
	//有效随机数一共是1600次,从0开始
	int length = 1600;
	//声明一个整数，用于记录我们总共随机了多少次
	int proof = 0;
	//声明一个数组，用于随机
	int mainArray[1600];
	//给数组赋值，一开始全部都是0
	for (int i = 0; i < 1600; i++) { mainArray[i] = 0; }
	
	//算法开始
	while (true)
	{
		//进行动画打印
		for (int i = 0; i < 1600; i++)
		{
			if (mainArray[i] == 0) { std::cout << "□"; }//未被随机过的打印□
			else { std::cout << "■"; }//已经被随机过的打印■
									  //每输出40次，进行一次换行，人为构成一个正方形，便于观察
			if (i % 40 == 39) { std::cout << std::endl; }
		}
		    //进行判断，如果有效随机数已经为0，那么算法结束
		if (length == 0 ) { break; }
			//每次打印完成之后,进行一次随机
			int random = rand() % 1600;
			//每随机一次，proof加1
			proof = proof + 1;
			//如果随机到的该下标元素是1，说明重复随机，如果是0，那么是有效随机
			if (mainArray[random] != 1) { mainArray[random] = 1;  length--; }
			//Sleep(50);
			system("cls");
	}
	time_end = GetTickCount();
	std::cout << "该算法已经完成！一共随机了" << proof << "次！" << std::endl;
	std::cout << "该算法消耗的时间为:" << (time_end - time_start) << "毫秒！" << std::endl;
	system("pause");//程序执行完成之后，一个暂停，用于观察结论！
		
}

int main()
{   
	randomWithoutRepeat();//不重复随机演示
	//randomRepeat();//重复随机演示

	return 0;
}
