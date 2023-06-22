//欢迎您使用车辆销售管理系统  管理员初始密码password
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>


#define LEN 100
#define ArrLen 20

typedef struct VehicleInformatin
{
	//车辆编号，品牌，车辆配置，价格，库存量，售价折扣
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
	int id;//用户编号
	//用户名，密码，生日，邮箱
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

typedef struct ShopRecord		//购买记录
{
	int id;
	char username[ArrLen];
	char goodsname[ArrLen];
	int amount;
	double price;
	clock_t recordtime;//记录购买时间
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
	int cho;//选择菜单项
	int t1,t2;//入口退出

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
		printf("--------欢迎使用车辆购买系统--------\n");
		printf("----------- 1 用户入口  ------------\n");
		printf("----------- 2 管理员入口------------\n");
		printf("----------- 0 退出系统  ------------\n");
		printf("------------------------------------\n");

		printf("请选择菜单项：");
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
					printf("--------  用户登录 ---------\n");
					printf("--------- 1 登录  ----------\n");
					printf("--------- 2 注册  ----------\n");
					printf("--------- 0 返回  ----------\n");
					printf("----------------------------\n");

					int a;
					printf("请输入菜单项：");
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
						default:printf("输入有误，请重新输入\n");
					}	
				}
				break;
			case 2:
				t2 = 1;
				char b[20];
				system("cls");
				char pw[20];
				printf("请输入管理员密码：");
				scanf("%s",pw);
				system("cls");
				if(strcmp(admin.password,pw)==0)
				{
					while(t2==1)
					{
					
						printf("-----------------------------------------\n");
						printf("------------  管理员系统   --------------\n");
						printf("------------1 录入车辆信息  -------------\n");
						printf("------------2 显示车辆信息  -------------\n");
						printf("------------3 显示用户信息  -------------\n");
						printf("------------4 查询所有购买记录  ---------\n");
						printf("------------5 根据用户编号查询购买记录 --\n");
						printf("------------6 根据用户编号删除用户  -----\n");
						printf("------------7 修改管理员密码    ---------\n");
						printf("------------0 退出   --------------------\n");
						printf("-----------------------------------------\n");
										
						int a;
						printf("请输入菜单项\n");
						scanf("%d",&a);
						system("cls");

						switch(a)
						{
							case 1:
								AddVehicle(V);
							
								system("cls");
								printf("添加成功\n");
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
								printf("修改管理员密码：");
								scanf("%s",b);
								strcpy(admin.password,b);
								t2 = 0;
								printf("修改成功请重新登录");
								break;
							case 0:
								t2 = 0;
								break;
							default:printf("输入有误，请重新输入\n");
						}
	
					}
				}
				break;
			case 0:
				printf("祝您一路顺风！！！\n");
				exit(0);
			default:
				printf("输入有误，请重新输入\n");
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
		printf("----------   用户系统   ----------\n");
		printf("----------1 显示车辆信息----------\n");
		printf("----------2 购买        ----------\n");
		printf("----------3 查询购买记录----------\n");
		printf("----------4 查询用户信息----------\n");
		printf("----------5 修改密码    ----------\n");
		printf("----------6 修改个人信息----------\n");
		printf("----------0 返回登陆界面----------\n");
		printf("----------------------------------\n");	

		int a;
		printf("请输入菜单项\n");
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
				printf("修改成功请重新登录\n");
				break;
			case 6:
				ChangeInform(U,i);
				system("cls");
				printf("修改成功\n");
				break;	
			case 0:
				t = 0;
				break;
			default:printf("输入有误，请重新输入\n");
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
	printf("请输入要添加的车辆数：");
	scanf("%d",&x);

	for(i=1;i<=x;i++)
	{	
		Vehicle e;
		printf("请输入第%d辆车的信息：\n",i);
		
		printf("请输入车辆编号：");
		scanf("%s",e.id);

		
		VehicleList *p = V->next;

		while(p != NULL && strcmp(p->data.id,e.id)!= 0)
		{
			p = p->next;
		}
		if(p==NULL)
		{
			printf("请输入车辆品牌：");
			scanf("%s",e.brand);
			printf("请输入车辆配置：");
			scanf("%s",e.configuration);

			printf("请输入车辆价格：");
			scanf("%lf",&e.price);

			printf("请输入车辆库存量：");
			scanf("%d",&e.amount);

			printf("请输入车辆折扣：");
			scanf("%lf",&e.discount);

			VehicleList *s = (VehicleList *)malloc(sizeof(VehicleList));
			s->data = e;
			s->next = V->next;
			V->next = s;
		}
		else
		{
			printf("已有该车辆\n");
			printf("请输入要添加的库存量：");
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
		printf("车辆编号	车辆品牌	车辆配置	车辆价格	车辆库存	车辆折扣\n");
		printf("----------------------------------------------------------------------------------------\n");

		while(p!=NULL)
		{
			printf("%s		%s		%s		%lf	%d		%lf\n",p->data.id,p->data.brand,p->data.configuration,p->data.price,p->data.amount,p->data.discount);
			p = p->next;
		}
	}
	else
	{
		printf("没有车辆信息\n");
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
	printf("请输入注册用户名：");
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
		printf("请输入密码：");
		scanf("%s",pw);
		strcpy(U->data[U->Length-1].password,pw);
		printf("注册成功！！！\n");

		U->data[U->Length-1].id = i+1;//自动设置用户编号

		printf("请完善个人信息\n");
		printf("请输入您的生日：");
		scanf("%s",U->data[U->Length-1].birth);
		printf("请输入您的邮箱：");
		scanf("%s",U->data[U->Length-1].mail);
		printf("欢迎加入！！！\n");
	}
	else
	{
		printf("用户名已存在\n");
	}
}

void DispUserList(UserList *U) 
{
	int i;
	if(U->Length!=0)
	{
		printf("用户编号\t用户账号\t用户密码\t用户生日\t用户邮箱\n");
		printf("-------------------------------------------------------------------------------\n");
		for(i=0;i<U->Length;i++)
		{
			printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",U->data[i].id,U->data[i].admin,U->data[i].password,U->data[i].birth,U->data[i].mail);
		}
	}
	else
	{
		printf("没有用户信息\n");
	}

}

int Login(UserList *&U)
{
	char name[20];
	printf("请输入注册用户名：");
	scanf("%s",name);
	int i=0;
	int key = 0;
	while(i<U->Length && strcmp(U->data[i].admin,name))
	{
		i++;
	}
	if(i==U->Length)
	{
		printf("用户名不存在\n");
	}
	else
	{
		char pw[20];
		printf("请输入密码：");
		scanf("%s",pw);
		if(strcmp(U->data[i].password,pw)==0)
		{
			printf("登陆成功\n");
			return i+1;
		}
		else
		{
			printf("密码错误\n");
			return 0;
		}
	}
	return 0;
}


void Buy(VehicleList *&V,UserList *&U,ShopReList *&Sh,int i)
{
	int n;
	char id[20];
	printf("请输入要购买的车辆编号：");
	scanf("%s",id);

	VehicleList *p=V->next;
	while(p != NULL && strcmp(p->data.id,id)!=0)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("没有该车辆\n");
	}
	else
	{
		printf("请输入要购买的数量：");
		scanf("%d",&n);

		if(p->data.amount < n)
		{
			printf("库存不足请重新购买，该商品一共有%d件。\n",p->data.amount);
		}
		else
		{
			p->data.amount -= n;
			
			printf("购买完成\n");

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

void Record(ShopReList *&Sh)//查询所有用户所有购买记录
{
	if(Sh->next!=NULL)
	{
		ShopReList *p=Sh->next;
		printf("\n");		
		printf("-------------------------------------------------------------\n");
		printf("用户姓名\t商品名称\t购买数量\t消费金额\n");

		while(p!=NULL)
		{
			printf("%s%s\t\t%s\t\t%d\t\t%lf\n",ctime(&p->data.recordtime),p->data.username,p->data.goodsname,p->data.amount,p->data.price);
			p=p->next;
		}	
	}
	else
	{
		printf("没有消费记录\n");
	}

}

void UserRecord(ShopReList *&Sh,UserList *&U)
{
	int i;
	int cnt=0;
	printf("请输入要查询的客户编号：");
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
					printf("用户姓名\t商品名称\t购买数量\t消费金额\n");
				}
				printf("%s%s\t\t%s\t\t%d\t\t%lf\n",ctime(&p->data.recordtime),p->data.username,p->data.goodsname,p->data.amount,p->data.price);
				cnt++;
			}
			p=p->next;
		}
		if(p==NULL && cnt==0)
		{
			printf("该客户未在本店消费过\n");
		}
	}
	else
	{
		printf("没有该客户\n");
	}
}

void PersonRecord(ShopReList *&Sh,int i)
{
	
	ShopReList *p=Sh->next;

	printf("\n");		
	printf("-------------------------------------------------------------\n");
	printf("用户姓名\t商品名称\t购买数量\t消费金额\n");
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
	printf("用户账号\t用户密码\t用户生日\t用户邮箱\n");
	printf("-------------------------------------------------------------------------------\n");

	printf("%s\t\t%s\t\t%s\t\t%s\n",U->data[i-1].admin,U->data[i-1].password,U->data[i-1].birth,U->data[i-1].mail);
}

void ChangeInform(UserList *U,int i)
{
	printf("修改个人信息\n");
	printf("请输入修改后的生日：");
	scanf("%s",U->data[i-1].birth);
	printf("请输入修改后的邮箱：");
	scanf("%s",U->data[i-1].mail);
}

void ChangePassword(UserList *U,int &t,int i)
{
	char pw[20];
	char npw[20];
	printf("请输入原密码：");
	scanf("%s",pw);
	if(strcmp(U->data[i-1].password,pw)==0)
	{
		printf("请输入新密码：");
		scanf("%s",npw);
		strcpy(U->data[i-1].password,npw);
		t = 0;
	}
	else
	{
		printf("密码错误\n");
	}
}

void ListDelete(UserList *&U)
{
	int j;
	int i;
	printf("请输入要删除的用户编号：");
	scanf("%d",&i);

	if(i<1||i>U->Length)
	{
		printf("输入错误\n");
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
	system("title 车辆销售系统");
	system("mode con cols=100 lines=30");//lines为长，cols为宽
	system("date/T ");
	system("time/T");
	system("color f0");
}

