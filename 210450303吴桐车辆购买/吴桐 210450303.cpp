//��ӭ��ʹ�ó������۹���ϵͳ  ����Ա��ʼ����password
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>


#define LEN 100
#define ArrLen 20

typedef struct VehicleInformatin
{
	//������ţ�Ʒ�ƣ��������ã��۸񣬿�������ۼ��ۿ�
	char id[ArrLen];
	char brand[ArrLen];
	char configuration[ArrLen];
	int amount;
	double price;
	double discount;
	
}Vehicle;

typedef struct VehicleLinkNodeList
{
	Vehicle data;
	struct VehicleLinkNodeList *next;
}VehicleList;



typedef struct UserInformation
{
	int id;//�û����
	//�û��������룬���գ�����
	char admin[ArrLen];
	char password[ArrLen];
	char birth[ArrLen];
	char mail[ArrLen];
}User;

typedef struct UserList
{
	User data[LEN];  
	int Length; 
}UserList;

typedef struct ShopRecord		//�����¼
{
	int id;
	char username[ArrLen];
	char goodsname[ArrLen];
	int amount;
	double price;
	clock_t recordtime;//��¼����ʱ��
}ShopRecord;

typedef struct ShopReList
{
	ShopRecord data;
	struct ShopReList *next;
}ShopReList;

struct admin 
{
	char password[ArrLen];
}admin={"password"};


void InitLink(VehicleList *&V);
void AddVehicle(VehicleList *&V);
void DispVehicle(VehicleList *V);
void InitUserNode(UserList *&U);
void Register(UserList *&U);
void DispUserList(UserList *U);
int Login(UserList *&U);
void UserSystem(UserList *&U,VehicleList *&V,ShopReList *&Sh,int i);
void InitShopReList(ShopReList *&Sh);
void Buy(VehicleList *&V,UserList *&U,ShopReList *&Sh,int i);
void Record(ShopReList *&Sh);
void UserRecord(ShopReList *&Sh,UserList *&U);
void PersonRecord(ShopReList *&Sh,int i);
void DispSelfInform(UserList *U,int i);
void ChangePassword(UserList *U,int &t,int i);
void ChangeInform(UserList *U,int i);
void ListDelete(UserList *&U);
void func();



int main()
{
	int cho;//ѡ��˵���
	int t1,t2;//����˳�

	VehicleList *V = NULL;
	InitLink(V);

	UserList *U = NULL;
	InitUserNode(U);

	ShopReList *Sh=NULL;
	InitShopReList(Sh);
	
	do
	{
		func();
		printf("------------------------------------\n");
		printf("--------��ӭʹ�ó�������ϵͳ--------\n");
		printf("----------- 1 �û����  ------------\n");
		printf("----------- 2 ����Ա���------------\n");
		printf("----------- 0 �˳�ϵͳ  ------------\n");
		printf("------------------------------------\n");

		printf("��ѡ��˵��");
		scanf("%d",&cho);
		system("cls");
		switch(cho)
		{
			system("cls");
			int k;
			case 1:
				t1 = 1;
				while(t1==1)
				{
					
					printf("----------------------------\n");
					printf("--------  �û���¼ ---------\n");
					printf("--------- 1 ��¼  ----------\n");
					printf("--------- 2 ע��  ----------\n");
					printf("--------- 0 ����  ----------\n");
					printf("----------------------------\n");

					int a;
					printf("������˵��");
					scanf("%d",&a);

					system("cls");
					switch(a)
					{
						
						case 1:	
							k = Login(U);
							Sleep(700);
							system("cls");

							if(k!=0)
							{
								UserSystem(U,V,Sh,k);
							}

							break;
						case 2:
							Register(U);
							Sleep(700);
							system("cls");
							break;	
						case 0:
							t1 = 0;
							break;
						default:printf("������������������\n");
					}	
				}
				break;
			case 2:
				t2 = 1;
				char b[20];
				system("cls");
				char pw[20];
				printf("���������Ա���룺");
				scanf("%s",pw);
				system("cls");
				if(strcmp(admin.password,pw)==0)
				{
					while(t2==1)
					{
					
						printf("-----------------------------------------\n");
						printf("------------  ����Աϵͳ   --------------\n");
						printf("------------1 ¼�복����Ϣ  -------------\n");
						printf("------------2 ��ʾ������Ϣ  -------------\n");
						printf("------------3 ��ʾ�û���Ϣ  -------------\n");
						printf("------------4 ��ѯ���й����¼  ---------\n");
						printf("------------5 �����û���Ų�ѯ�����¼ --\n");
						printf("------------6 �����û����ɾ���û�  -----\n");
						printf("------------7 �޸Ĺ���Ա����    ---------\n");
						printf("------------0 �˳�   --------------------\n");
						printf("-----------------------------------------\n");
										
						int a;
						printf("������˵���\n");
						scanf("%d",&a);
						system("cls");

						switch(a)
						{
							case 1:
								AddVehicle(V);
							
								system("cls");
								printf("��ӳɹ�\n");
								break;
							case 2:
								system("cls");
								DispVehicle(V);
								break;
							case 3:
								system("cls");
								DispUserList(U);
								break;
							case 4:
								system("cls");
								Record(Sh);
								break;
							case 5:
								UserRecord(Sh,U);
								break;
							case 6:
								ListDelete(U);
								break;
							case 7:
								printf("�޸Ĺ���Ա���룺");
								scanf("%s",b);
								strcpy(admin.password,b);
								t2 = 0;
								printf("�޸ĳɹ������µ�¼");
								break;
							case 0:
								t2 = 0;
								break;
							default:printf("������������������\n");
						}
	
					}
				}
				break;
			case 0:
				printf("ף��һ·˳�磡����\n");
				exit(0);
			default:
				printf("������������������\n");
		}
	}while(1);
	return 0;
}

void UserSystem(UserList *&U,VehicleList *&V,ShopReList *&Sh,int i)
{
	int t = 1;
	while(t==1)
	{		
		printf("----------------------------------\n");			
		printf("----------   �û�ϵͳ   ----------\n");
		printf("----------1 ��ʾ������Ϣ----------\n");
		printf("----------2 ����        ----------\n");
		printf("----------3 ��ѯ�����¼----------\n");
		printf("----------4 ��ѯ�û���Ϣ----------\n");
		printf("----------5 �޸�����    ----------\n");
		printf("----------6 �޸ĸ�����Ϣ----------\n");
		printf("----------0 ���ص�½����----------\n");
		printf("----------------------------------\n");	

		int a;
		printf("������˵���\n");
		scanf("%d",&a);

		system("cls");
		switch(a)
		{
			case 1:
				DispVehicle(V);
				break;
			case 2:
				Buy(V,U,Sh,i);
				break;
			case 3:
				PersonRecord(Sh,i);
				break;
			case 4:
				DispSelfInform(U,i);
				break;
			case 5:
				ChangePassword(U,t,i);
				system("cls");
				printf("�޸ĳɹ������µ�¼\n");
				break;
			case 6:
				ChangeInform(U,i);
				system("cls");
				printf("�޸ĳɹ�\n");
				break;	
			case 0:
				t = 0;
				break;
			default:printf("������������������\n");
		}
	}
}

void InitLink(VehicleList *&V)
{
	V = (VehicleList *)malloc(sizeof(VehicleList));
	V->next = NULL;
}

void InitShopReList(ShopReList *&Sh)
{
	Sh=(ShopReList *)malloc(sizeof(ShopReList));
	Sh->next=NULL;
}

void AddVehicle(VehicleList *&V)
{
	int x;
	int i;
	printf("������Ҫ��ӵĳ�������");
	scanf("%d",&x);

	for(i=1;i<=x;i++)
	{	
		Vehicle e;
		printf("�������%d��������Ϣ��\n",i);
		
		printf("�����복����ţ�");
		scanf("%s",e.id);

		
		VehicleList *p = V->next;

		while(p != NULL && strcmp(p->data.id,e.id)!= 0)
		{
			p = p->next;
		}
		if(p==NULL)
		{
			printf("�����복��Ʒ�ƣ�");
			scanf("%s",e.brand);
			printf("�����복�����ã�");
			scanf("%s",e.configuration);

			printf("�����복���۸�");
			scanf("%lf",&e.price);

			printf("�����복���������");
			scanf("%d",&e.amount);

			printf("�����복���ۿۣ�");
			scanf("%lf",&e.discount);

			VehicleList *s = (VehicleList *)malloc(sizeof(VehicleList));
			s->data = e;
			s->next = V->next;
			V->next = s;
		}
		else
		{
			printf("���иó���\n");
			printf("������Ҫ��ӵĿ������");
			scanf("%d",&e.amount);
			p->data.amount += e.amount;
		}		
	}	
}

void DispVehicle(VehicleList *V)
{
	if(V->next!=NULL)
	{
		VehicleList *p = V->next;
		printf("�������	����Ʒ��	��������	�����۸�	�������	�����ۿ�\n");
		printf("----------------------------------------------------------------------------------------\n");

		while(p!=NULL)
		{
			printf("%s		%s		%s		%lf	%d		%lf\n",p->data.id,p->data.brand,p->data.configuration,p->data.price,p->data.amount,p->data.discount);
			p = p->next;
		}
	}
	else
	{
		printf("û�г�����Ϣ\n");
	}

}

void InitUserNode(UserList *&U)
{
	U=(UserList *)malloc(sizeof(UserList));
	U->Length = 0;
}

void Register(UserList *&U)
{
	char name[20];
	printf("������ע���û�����");
	scanf("%s",name);
	int i = 0;

	while(i<U->Length && strcmp(U->data[i].admin,name)!=0)
	{
		i++;
	}
	
	if(i==U->Length)
	{
		U->Length++;
		strcpy(U->data[U->Length-1].admin,name);
		char pw[20];
		printf("���������룺");
		scanf("%s",pw);
		strcpy(U->data[U->Length-1].password,pw);
		printf("ע��ɹ�������\n");

		U->data[U->Length-1].id = i+1;//�Զ������û����

		printf("�����Ƹ�����Ϣ\n");
		printf("�������������գ�");
		scanf("%s",U->data[U->Length-1].birth);
		printf("�������������䣺");
		scanf("%s",U->data[U->Length-1].mail);
		printf("��ӭ���룡����\n");
	}
	else
	{
		printf("�û����Ѵ���\n");
	}
}

void DispUserList(UserList *U) 
{
	int i;
	if(U->Length!=0)
	{
		printf("�û����\t�û��˺�\t�û�����\t�û�����\t�û�����\n");
		printf("-------------------------------------------------------------------------------\n");
		for(i=0;i<U->Length;i++)
		{
			printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",U->data[i].id,U->data[i].admin,U->data[i].password,U->data[i].birth,U->data[i].mail);
		}
	}
	else
	{
		printf("û���û���Ϣ\n");
	}

}

int Login(UserList *&U)
{
	char name[20];
	printf("������ע���û�����");
	scanf("%s",name);
	int i=0;
	int key = 0;
	while(i<U->Length && strcmp(U->data[i].admin,name))
	{
		i++;
	}
	if(i==U->Length)
	{
		printf("�û���������\n");
	}
	else
	{
		char pw[20];
		printf("���������룺");
		scanf("%s",pw);
		if(strcmp(U->data[i].password,pw)==0)
		{
			printf("��½�ɹ�\n");
			return i+1;
		}
		else
		{
			printf("�������\n");
			return 0;
		}
	}
	return 0;
}


void Buy(VehicleList *&V,UserList *&U,ShopReList *&Sh,int i)
{
	int n;
	char id[20];
	printf("������Ҫ����ĳ�����ţ�");
	scanf("%s",id);

	VehicleList *p=V->next;
	while(p != NULL && strcmp(p->data.id,id)!=0)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("û�иó���\n");
	}
	else
	{
		printf("������Ҫ�����������");
		scanf("%d",&n);

		if(p->data.amount < n)
		{
			printf("��治�������¹��򣬸���Ʒһ����%d����\n",p->data.amount);
		}
		else
		{
			p->data.amount -= n;
			
			printf("�������\n");

			ShopRecord e;			
			
			e.id = i;
			strcpy(e.goodsname,p->data.brand);
			e.amount = n;
			e.price = p->data.price * p->data.discount * n;
			strcpy(e.username,U->data[i-1].admin);
			e.recordtime = time(NULL);

			
			ShopReList *s=(ShopReList *)malloc(sizeof(ShopReList));
			s->data = e;
			s->next = Sh->next;
			Sh->next = s;

		}
	}
}

void Record(ShopReList *&Sh)//��ѯ�����û����й����¼
{
	if(Sh->next!=NULL)
	{
		ShopReList *p=Sh->next;
		printf("\n");		
		printf("-------------------------------------------------------------\n");
		printf("�û�����\t��Ʒ����\t��������\t���ѽ��\n");

		while(p!=NULL)
		{
			printf("%s%s\t\t%s\t\t%d\t\t%lf\n",ctime(&p->data.recordtime),p->data.username,p->data.goodsname,p->data.amount,p->data.price);
			p=p->next;
		}	
	}
	else
	{
		printf("û�����Ѽ�¼\n");
	}

}

void UserRecord(ShopReList *&Sh,UserList *&U)
{
	int i;
	int cnt=0;
	printf("������Ҫ��ѯ�Ŀͻ���ţ�");
	scanf("%d",&i);
	if(i <= U->Length)
	{
		ShopReList *p=Sh->next;	
		while(p!=NULL)
		{
			if(p->data.id==i)
			{
				if(cnt==0)
				{
					printf("-------------------------------------------------------------\n");
					printf("�û�����\t��Ʒ����\t��������\t���ѽ��\n");
				}
				printf("%s%s\t\t%s\t\t%d\t\t%lf\n",ctime(&p->data.recordtime),p->data.username,p->data.goodsname,p->data.amount,p->data.price);
				cnt++;
			}
			p=p->next;
		}
		if(p==NULL && cnt==0)
		{
			printf("�ÿͻ�δ�ڱ������ѹ�\n");
		}
	}
	else
	{
		printf("û�иÿͻ�\n");
	}
}

void PersonRecord(ShopReList *&Sh,int i)
{
	
	ShopReList *p=Sh->next;

	printf("\n");		
	printf("-------------------------------------------------------------\n");
	printf("�û�����\t��Ʒ����\t��������\t���ѽ��\n");
	while(p!=NULL)
	{
		if(p->data.id==i)
		{
			printf("%s%s\t\t%s\t\t%d\t\t%lf\n",ctime(&p->data.recordtime),p->data.username,p->data.goodsname,p->data.amount,p->data.price);
		}
		p=p->next;
	}
}

void DispSelfInform(UserList *U,int i)
{
	printf("�û��˺�\t�û�����\t�û�����\t�û�����\n");
	printf("-------------------------------------------------------------------------------\n");

	printf("%s\t\t%s\t\t%s\t\t%s\n",U->data[i-1].admin,U->data[i-1].password,U->data[i-1].birth,U->data[i-1].mail);
}

void ChangeInform(UserList *U,int i)
{
	printf("�޸ĸ�����Ϣ\n");
	printf("�������޸ĺ�����գ�");
	scanf("%s",U->data[i-1].birth);
	printf("�������޸ĺ�����䣺");
	scanf("%s",U->data[i-1].mail);
}

void ChangePassword(UserList *U,int &t,int i)
{
	char pw[20];
	char npw[20];
	printf("������ԭ���룺");
	scanf("%s",pw);
	if(strcmp(U->data[i-1].password,pw)==0)
	{
		printf("�����������룺");
		scanf("%s",npw);
		strcpy(U->data[i-1].password,npw);
		t = 0;
	}
	else
	{
		printf("�������\n");
	}
}

void ListDelete(UserList *&U)
{
	int j;
	int i;
	printf("������Ҫɾ�����û���ţ�");
	scanf("%d",&i);

	if(i<1||i>U->Length)
	{
		printf("�������\n");
	}

	for(j=i-1;j<U->Length-1;j++)
	{
		U->data[j] = U->data[j+1];
		U->data[j].id--;
	}

	U->Length--;
}
 
void func()
{
	system("title ��������ϵͳ");
	system("mode con cols=100 lines=30");//linesΪ����colsΪ��
	system("date/T ");
	system("time/T");
	system("color f0");
}

