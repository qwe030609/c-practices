#include <stdio.h>
#define SIZE 6          /*�w�q�}�C�j�p*/
void inser (int *);     /*�ŧi���J�ƧǪk�Ƶ{��*/
void showdata (int *);  /*�ŧi�C�L�}�C�Ƶ{��*/
void inputarr (int *,int);  /*�ŧi��J�}�C�Ƶ{��*/

int main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);     /*��}�C�W�٤ΰ}�C�j�p�ǵ��Ƶ{��*/
	printf("�z��J����l�}�C�O�G");
	showdata (data);
	inser(data);
	system("pause");
	return 0;
}

void inputarr(int data[],int size)
{
	int i;
	for (i=0;i<size;i++)      /*�Q�ΰj���J�}�C���*/
	{ 
		printf("�п�J�� %d �Ӥ����G",i+1);
		scanf("%d",&data[i]);
	}
}
void showdata(int data[])
{  
	int i;
	for (i=0;i<SIZE;i++)
		printf("%3d",data[i]);   /*�C�L�}�C���*/
	printf("\n");
}
void inser(int data[])
{  
	int i;     /*i�����y����*/
	int j;     /*�Hj�өw����������*/
	int tmp;   /*tmp�ΨӼȦs���*/
	for (i=1;i<SIZE;i++)  /*���y�j�馸�Ƭ�SIZE-1*/
	{  
		tmp=data[i];
        j=i-1;
	    while (j>=0 && tmp<data[j])  /*�p�G�ĤG�����p��Ĥ@����*/
		{							 
			data[j+1]=data[j];		/*�N��Ҧ�����������@�Ӧ�m*/		
			j--;
		}
		data[j+1]=tmp;              /*�̤p���������Ĥ@�Ӥ���*/	
		printf("�� %d �����ˡG",i);
		showdata(data);
	}
}
