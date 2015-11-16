/*************************************************************************
    > File Name: random.cpp
    > Author: zhangke
    > Mail: ch.zhangke@gmail.com 
    > Created Time: 2015年11月15日 星期日 22时13分55秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
int *Random(int size,int downLimit,int upLimit,int *result)
{
	srand(time(NULL));
	result = new int [size];
	for(int i=0;i<size;)
	{
		int a=downLimit+rand()%(upLimit-downLimit);
		int judge=1;
		int j=0;
		for(;j<i;++j)
		{
			if(a==result[j])
			{
				judge=0;
				break;
			}
		}
		if(judge)
		{
			result[i]=a;
			++i;
		}
		
	}
	return result;
}
int char_to_int(char *a)
{
	int length=strlen(a);
//	cout<<length<<endl;
	int judge=0;
	int result=0;
	if(a[0]=='-')
	{
		for(int i=1;i<length;++i)
		{
			result+=(a[i]-'0')*pow(10,(length-1-i));
		}
	}
	else
	{
		judge=1;
		for(int i=0;i<length;++i)
		{
			result+=(a[i]-'0')*pow(10,(length-i-1));
		}
	}
	if(judge){
//		cout<<"result="<<result<<endl;
		return result;
	}
	else
		return (-1)*result;

}
int main(int argc,char *argv[])
{
	int *result;
	if(argc==1)
	{
		result=Random(1,0,100,result);
		cout<<"随机数为: ";
		cout<<*result<<endl;
	}
	else
	{
		int size=char_to_int(argv[1]);
	//	cout<<"size="<<size<<endl;
		int downLimit=char_to_int(argv[2]);
		int upLimit=char_to_int(argv[3]);
		result=Random(size,downLimit,upLimit,result);
		cout<<"随机数为： ";
		for(int i=0;i<size;++i)
			cout<<result[i]<<" ";
		cout<<endl;
	}
	return 0;

}
