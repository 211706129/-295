#include<stdio.h>
#include<string.h>

int hz(char a[]){//进行汉字->数字转变
	if (strcmp(a,"零") == 0) return 0;
	if (strcmp(a,"一") == 0) return 1;
	if (strcmp(a,"二") == 0) return 2;
	if (strcmp(a,"三") == 0) return 3;
	if (strcmp(a,"四") == 0) return 4;
	if (strcmp(a,"五") == 0) return 5;
	if (strcmp(a,"六") == 0) return 6;
	if (strcmp(a,"七") == 0) return 7;
	if (strcmp(a,"八") == 0) return 8;
	if (strcmp(a,"九") == 0) return 9;
	if (strcmp(a,"十") == 0) return 10;
}
void sz(int sum){//进行数字->汉字转变
	if(sum<=10){	
		if(sum==0) printf("零");
		else if(sum==1) printf("一");
		else if(sum==2) printf("二");
		else if(sum==3) printf("三");
		else if(sum==4) printf("四");
		else if(sum==5) printf("五");
		else if(sum==6) printf("六");
		else if(sum==7) printf("七");
		else if(sum==8) printf("八");
		else if(sum==9) printf("九");
		else if(sum==10) printf("十");
	}
	if(sum>10 && sum <20){
		if(sum==11) printf("十一");
		else if(sum==12) printf("十二");
		else if(sum==13) printf("十三");
		else if(sum==14) printf("十四");
		else if(sum==15) printf("十五");
		else if(sum==16) printf("十六");
		else if(sum==17) printf("十七");
		else if(sum==18) printf("十八");
		else if(sum==19) printf("十九");
	}
}

int hanzi(char sum[])//将汉字变成数字
{	
	char a[10],b[10];
	if(strlen(sum)==2){
		return	hz(sum);//零到十的数字		 
    }
    else if(strlen(sum)==4){
        a[0]=sum[0];//将十位存放在数组a中
        a[1]=sum[1];
        a[2]='\0'; 
		b[0]=sum[2];//将个位存放在数组b中
		b[1]=sum[3];
		b[2]='\0';
        if(hanzi(a)==10) 
			return hz(b)+10;//十到二十之间的数字,十一，十二
        else
            return 10*hz(a);//二位整数（如：20,30）
    }
    else if(strlen(sum)==6){
        a[0]=sum[4];//将个位存放在数组a中
        a[1]=sum[5];
        a[2]='\0';
        b[0]=sum[0];//将十位位存放在数组b中
        b[1]=sum[1];
        b[2]='\0';
        return hz(a)+hz(b)*10;//二十以上，九十九以下的数字,例如三十二
    }
}
void shuzi(int sum)//将数字变成汉字
{
	int a,b;
	if(sum<20)
		sz(sum);			
	else{
		a=sum/10;//等于十位数
		sz(a);
		printf("十");
		if(sum%10!=0){//判断是不是整数
			b=sum%10;//等于个位数
			sz(b);
		}		
	}
}
int main()
{
    int sum, temp,i;
    char a[100], b[10],c[10],d[10],e[100]; //a[10]用来暂存汉字,b[10]存储变量
    scanf("%s",a);
    scanf("%s",b);//用于储存代表变量的汉字，如钱包，银行卡之类的 
	//printf("%s",b);
	if (strcmp(a,"等于") != 0){
		scanf("%s",a);//判断是否是“等于”,是退出判断，不是继续
	}
    scanf("%s",a);//赋初值	
    sum = hanzi(a);//将赋初值用hanzi函数用于汉字转为数字 
    scanf("%s",a); 
	while(strcmp(a,"看看")!= 0){//判断是否进入运算操作 
		if(strcmp(a, "增加") == 0){
			scanf("%s",a);
			temp = hanzi(a);
			sum = sum + temp;
		}
		else if(strcmp(a, "减少") == 0){
			scanf("%s",a);
			temp = hanzi(a);
			sum = sum - temp;
		}
		scanf("%s",a);//判断是否进行循环
	}	
	scanf("%s",a);//输入变量
	if(strcmp(a,b)== 0){
		printf("是否进入下一步，进输入：如果，否则输入：f\n");//进行判断
		scanf("%s",a);
		if(strcmp(a,"f")== 0)			
			shuzi(sum);
		if(strcmp(a,"如果")== 0){//看下一个输入的是不是如果
			scanf("%s",a);
			if(strcmp(a,b)== 0){//匹配变量是否相等
				scanf("%s",a);
				if(strcmp(a,"大于")== 0){	
					scanf("%s",a);
					temp=hanzi(a);
					scanf("%s %s %s",c,d,e);
					if(sum>temp){
						shuzi(sum);	
						printf("\n");
						for(i=1;i<strlen(e)-2;i=i+2)//去除引号
							printf("%c%c",e[i],e[i+1]);
						printf("\n");
					}
					else{
						scanf("%s %s %s",c,d,e);
						shuzi(sum);
						printf("\n");
						for(i=1;i<strlen(e)-2;i=i+2)//去除引号
							printf("%c%c",e[i],e[i+1]);
						printf("\n");
					}
				}
			}
			else
				printf("此变量不存在");
		}
	}
	else
		printf("没有此变量");	
	return 0;
}