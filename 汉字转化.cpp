#include<stdio.h>
#include<string.h>

int hz(char a[]){//���к���->����ת��
	if (strcmp(a,"��") == 0) return 0;
	if (strcmp(a,"һ") == 0) return 1;
	if (strcmp(a,"��") == 0) return 2;
	if (strcmp(a,"��") == 0) return 3;
	if (strcmp(a,"��") == 0) return 4;
	if (strcmp(a,"��") == 0) return 5;
	if (strcmp(a,"��") == 0) return 6;
	if (strcmp(a,"��") == 0) return 7;
	if (strcmp(a,"��") == 0) return 8;
	if (strcmp(a,"��") == 0) return 9;
	if (strcmp(a,"ʮ") == 0) return 10;
}
void sz(int sum){//��������->����ת��
	if(sum<=10){	
		if(sum==0) printf("��");
		else if(sum==1) printf("һ");
		else if(sum==2) printf("��");
		else if(sum==3) printf("��");
		else if(sum==4) printf("��");
		else if(sum==5) printf("��");
		else if(sum==6) printf("��");
		else if(sum==7) printf("��");
		else if(sum==8) printf("��");
		else if(sum==9) printf("��");
		else if(sum==10) printf("ʮ");
	}
	if(sum>10 && sum <20){
		if(sum==11) printf("ʮһ");
		else if(sum==12) printf("ʮ��");
		else if(sum==13) printf("ʮ��");
		else if(sum==14) printf("ʮ��");
		else if(sum==15) printf("ʮ��");
		else if(sum==16) printf("ʮ��");
		else if(sum==17) printf("ʮ��");
		else if(sum==18) printf("ʮ��");
		else if(sum==19) printf("ʮ��");
	}
}

int hanzi(char sum[])//�����ֱ������
{	
	char a[10],b[10];
	if(strlen(sum)==2){
		return	hz(sum);//�㵽ʮ������		 
    }
    else if(strlen(sum)==4){
        a[0]=sum[0];//��ʮλ���������a��
        a[1]=sum[1];
        a[2]='\0'; 
		b[0]=sum[2];//����λ���������b��
		b[1]=sum[3];
		b[2]='\0';
        if(hanzi(a)==10) 
			return hz(b)+10;//ʮ����ʮ֮�������,ʮһ��ʮ��
        else
            return 10*hz(a);//��λ�������磺20,30��
    }
    else if(strlen(sum)==6){
        a[0]=sum[4];//����λ���������a��
        a[1]=sum[5];
        a[2]='\0';
        b[0]=sum[0];//��ʮλλ���������b��
        b[1]=sum[1];
        b[2]='\0';
        return hz(a)+hz(b)*10;//��ʮ���ϣ���ʮ�����µ�����,������ʮ��
    }
}
void shuzi(int sum)//�����ֱ�ɺ���
{
	int a,b;
	if(sum<20)
		sz(sum);			
	else{
		a=sum/10;//����ʮλ��
		sz(a);
		printf("ʮ");
		if(sum%10!=0){//�ж��ǲ�������
			b=sum%10;//���ڸ�λ��
			sz(b);
		}		
	}
}
int main()
{
    int sum, temp,i;
    char a[100], b[10],c[10],d[10],e[100]; //a[10]�����ݴ溺��,b[10]�洢����
    scanf("%s",a);
    scanf("%s",b);//���ڴ����������ĺ��֣���Ǯ�������п�֮��� 
	//printf("%s",b);
	if (strcmp(a,"����") != 0){
		scanf("%s",a);//�ж��Ƿ��ǡ����ڡ�,���˳��жϣ����Ǽ���
	}
    scanf("%s",a);//����ֵ	
    sum = hanzi(a);//������ֵ��hanzi�������ں���תΪ���� 
    scanf("%s",a); 
	while(strcmp(a,"����")!= 0){//�ж��Ƿ����������� 
		if(strcmp(a, "����") == 0){
			scanf("%s",a);
			temp = hanzi(a);
			sum = sum + temp;
		}
		else if(strcmp(a, "����") == 0){
			scanf("%s",a);
			temp = hanzi(a);
			sum = sum - temp;
		}
		scanf("%s",a);//�ж��Ƿ����ѭ��
	}	
	scanf("%s",a);//�������
	if(strcmp(a,b)== 0){
		printf("�Ƿ������һ���������룺������������룺f\n");//�����ж�
		scanf("%s",a);
		if(strcmp(a,"f")== 0)			
			shuzi(sum);
		if(strcmp(a,"���")== 0){//����һ��������ǲ������
			scanf("%s",a);
			if(strcmp(a,b)== 0){//ƥ������Ƿ����
				scanf("%s",a);
				if(strcmp(a,"����")== 0){	
					scanf("%s",a);
					temp=hanzi(a);
					scanf("%s %s %s",c,d,e);
					if(sum>temp){
						shuzi(sum);	
						printf("\n");
						for(i=1;i<strlen(e)-2;i=i+2)//ȥ������
							printf("%c%c",e[i],e[i+1]);
						printf("\n");
					}
					else{
						scanf("%s %s %s",c,d,e);
						shuzi(sum);
						printf("\n");
						for(i=1;i<strlen(e)-2;i=i+2)//ȥ������
							printf("%c%c",e[i],e[i+1]);
						printf("\n");
					}
				}
			}
			else
				printf("�˱���������");
		}
	}
	else
		printf("û�д˱���");	
	return 0;
}