#include <iostream>
using namespace std;

int needweek (int ny,int y,int w);
int num(int m,int n);
void print (int y,int w) ;

int main ()
{
	int year=2025,week=3,ny=0,nd=0,nw=0;//n是need 
	cout<<"输入你所需的日历的年份。"<<endl;
	cin>>ny;
	
	nw=needweek(ny,year,week);//计算星期 
	print(ny,nw);//准备打印 
	
	system("pause");
	return 0;
} 
 



int needweek (int ny,int y,int w)
{
	if (ny<y)//比参考数据 2025年 小的情况
	{
		while(ny<y)
		{
			if((ny%4==0&&ny%100!=0) || (ny%400==0))
			{
				ny++;
				w+=5;//366%7=2    7-2=5
			}
			else
			{
				ny++;
				w+=6;//365%7=1    7-1=6
			}
		} 
	}
	else //比参考数据 2025年 小和相同的情况
	{
		while(ny>y)
		{
				if((y%4==0&&y%100!=0) || (y%400==0))
				{
					y++;
					w+=2;//366%7=2
				}
				else
				{
					y++;
					w++;//365%7=1
				}
		 } 
	}
	w%=7;
	return w;
} 


int num(int m,int n,int y)
{
	if (m==4||m==6||m==9||m==11) 
	{
		n=30;
	}
	else if(m==2)
	{
		if((y%4==0&&y%100!=0) || (y%400==0))
		{
			n=29;
		}
		else
		{
			n=28;
		}
	}
	else
	{
		n=31;
	}
	
	
	return n;
}


void print (int y,int week) 
{
	int n=0,i=0;
	for (int m=1;m<=12;m++)
	{
		i=0;
		cout<<"\n==================== "<<y<<"年"<<m<<"月 ===================="<<endl;
		cout<<"周一\t周二\t周三\t周四\t周五\t周六\t周日"<<endl;
		
		n=num(m,n,y);
		
		
		for(int w=week;w>1;w--)//打印空格 
		{
			cout<<"\t";
			i++;
		}
		week+=n;//算出下一月的第一天对应星期
		week%=7;
		
		for (int d=1;d<=n;d++)//打印日期 
		{
			if(i==0)
			{
				cout<<endl;
			}
			cout<<d<<"\t";
			i++;
			i%=7;
		} 
	}
}














