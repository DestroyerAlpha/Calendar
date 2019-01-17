#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

int day(int, int);
int leap(int);

int main()
{
	int year,month,date;
	scanf("%d %d %d",&year,&month,&date);
	int count = day(month,date);
	for(int i = min(year,2019);i<max(year,2019);i++)
	{
		if(2019<year)
		{
			if(leap(i)==1)
				count +=2;
			else
				count +=1;
		}
		else
		{
			if(leap(i)==1)
				count +=5;
			else
				count +=6;
		}
	}
	if(leap(year)==1&&month>2)
		count++;
	count = count%7;
	switch(count)
	{
		case 0:
			printf("SUNDAY\n");
			break;
		case 1:
			printf("MONDAY\n");
			break;
		case 2:
			printf("TUESDAY\n");
			break;
		case 3:
			printf("WEDNESDAY\n");
			break;
		case 4:
			printf("THURSDAY\n");
			break;
		case 5:
			printf("FRIDAY\n");
			break;
		case 6:
			printf("SATURDAY\n");
			break;	
	}
	return 0;
}

int day(int a,int b)
{
	int count = 2;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(a==1)
		count += (b-1);
	else
	{
		count = count + 30 + b; 
		for(int i=1;i<a-1;i++)
		{
			count+=	days[i];	
		}
	}
	return count%7;
}

int leap(int a)
{
	int leapy = 0;
	if(a%4==0)
	{
		leapy = 1;		
		if(a%100==0)
		{
			leapy = 0;
			if(a%400==0)
				leapy = 1;		
		}	
	}
	return leapy;
}
