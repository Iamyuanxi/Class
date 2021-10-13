#include"SalesManage.h"

/*输入函数*/ 
char *Sgets(char *st , int n)
{
	char *retVal;
	char *find;
	char number[NUMSIZE];
	
	retVal = fgets(st, n, stdin);
	
	if (retVal != NULL)
	{
		find = strchr(st, '\n');		// 查找换行符
	
		if (find != NULL)
		{				   
			*find = '\0';	// 在此处放置一个空字符
		}			   		
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}		   			// 处理剩余输入行
		}
	}

	return retVal;
}

/*界面*/ 
BOOL Form(void)
{
	printf("\t\t    _____________________________\n");
	printf("\t\t   │ 1. 添加信息    2. 信息查询 │\n");
	printf("\t\t   │                            │\n");
	printf("\t\t   │ 3. 修改信息    4. 删除信息 │\n");
	printf("\t\t   │                            │\n");
	printf("\t\t   │ 0. 返回上级                │\n");
	printf("\t\t   │____________________________│\n");
	printf("\t\t请您选择(0-4):"); 

	return TRUE;
}  

BOOL MainSelect()
{
	system("cls"); /*清屏*/
	
	printf("\t\t ====================================\n");
	printf("\t\t│         销售信息管理系统         │\n");
	printf("\t\t ====================================\n");
	printf("\t\t   _______________________________\n");
	printf("\t\t  │ 1. 人员管理     2. 产品管理  │\n");
	printf("\t\t  │                              │\n");
	printf("\t\t  │ 3. 进货商管理   4. 顾客管理  │\n");
	printf("\t\t  │                              │\n");
	printf("\t\t  │ 0. 退出系统                  │\n");
	printf("\t\t  │______________________________│\n");
	printf("\t\t请您选择(0-4):"); 
	
	return TRUE;
} 

int Manage(const char *type)
{
	int n;
	
	system("cls"); /*清屏*/
	
	printf("\t\t ====================================\n");
	printf("\t\t│             %s             │\n", type);
	printf("\t\t ====================================\n");
	
	Form();
	
	scanf("%d",&n);
	getchar();
	
	return n;
}

BOOL AddSalesman(Salesman *head)
{
	bool flag = 1;
	
	while (flag)
	{
		Salesman *pNew = (Salesman *) malloc (sizeof(Salesman));
		system("cls");
		
		puts("请输入代号：");
		Sgets(pNew->number , NUMSIZE);
		
		if (QuerySalesmanByNumber(head, pNew->number) != NULL)		//需要添加的记录已经存在 
		{
			printf("代号为 %s 的销售员信息已添加！\n请重新输入" , pNew->number);
			
			free(pNew);
			
			getchar(); 
			continue;
		}
		
		puts("请输入姓名：");
		Sgets(pNew->name , NAMESIZE);
		
		puts("请输入性别：");
		Sgets(pNew->gender , GENDERSIZE);
		
		puts("请输入联系电话：");
		Sgets(pNew->phone , PHONENUMSIZE); 
		
		puts("请输入联系地址：");
		Sgets(pNew->address , 80); 
		
		puts("请输入出生年月（日期输入格式xxxx-xx-xx）：");
		Sgets(pNew->birthDate , DATESIZE); 
		
		puts("请输入入职时间（日期输入格式xxxx-xx-xx）：");
		Sgets(pNew->employedDate , DATESIZE);
		
		pNew->next=NULL; 
		
		AddSalesman(head, pNew);
													 
		printf("\n是否继续添加（是1，否0）？\n");
		scanf("%d",&flag);
							
		while (getchar() != '\n')
		{
			continue;
		}
	}
	
	return TRUE;
}

BOOL QuerySalesman(Salesman *head)
{
	Salesman **p1;
	Salesman *p2;
	char number[NUMSIZE];
	char name[NAMESIZE];
	int flag = 1;
		
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关销售员的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		printf("查询方式：1.姓名查询	2.代号查询\n请选择查询方式：");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
		
		switch (flag)
		{
			case 1:
				puts("请输入需要查询的销售员的姓名：");
				Sgets(name , NAMESIZE);
				p1 = QuerySalesmanByName(head, name);
				
				printf("\n");
				
				if (p1 == NULL)
				{
					puts("没有该销售员");
				}
				else
				{
					printf("代号\t姓名\t性别\t联系电话\t联系地址\t出生年月日\t入职时间\n");
					
					while (*p1 != NULL)
					{
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", (*p1)->number, (*p1)->name, (*p1)->gender, (*p1)->phone, (*p1)->address,
							(*p1)->birthDate, (*p1)->employedDate);
							
						++p1;
					}
				}
				
				break;
				
			case 2:
				puts("请输入需要查询的销售员的代号：");
				Sgets(number , NUMSIZE);
				p2 = QuerySalesmanByNumber(head, number);
										
				printf("\n");
										
				if (p2 == NULL)
				{
					puts("没有该销售员");
				}
				else
				{
					printf("代号\t姓名\t性别\t联系电话\t联系地址\t出生年月日\t入职时间\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p2->number, p2->name, p2->gender, p2->phone, p2->address,
							p2->birthDate, p2->employedDate);
				}
				
				break;	
				
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
		}						
								
		printf("\n是否继续查询（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;	
		}
								
	}
	
	return TRUE;
}

BOOL AlterSalesman(Salesman *head)
{
	Salesman *p;
	Salesman *pnew;
	char number[NUMSIZE];
	int flag = 1;
	int type = 1; 
	
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关销售员的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要修改信息的销售员的代号：");
		Sgets(number , NUMSIZE);
		p = QuerySalesmanByNumber(head, number);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("没有该销售员");
		}
		else
		{
			printf("代号\t姓名\t性别\t联系电话\t联系地址\t出生年月日\t入职时间\n");
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p->number, p->name, p->gender, p->phone, p->address,
			p->birthDate, p->employedDate);
			
			pnew = (Salesman *) malloc (sizeof(Salesman));	//记录存在创建一个记录的副本
			*pnew = *p; 
			
			while (type)
			{
				printf("请选择需要修改信息的类别:\n");
				printf("(1.姓名\t2.性别\t3.联系电话\t4.联系地址\t5.出生年月日\t6.入职时间\t0.结束修改本条记录信息)\n");
				scanf("%d", &type);	
				
				while (getchar() != '\n')
				{
					continue;
				}
				
				if (type == 0)
				{
					type = 1;
					break;
				}
				
				puts("请输入新的内容:");
				
				switch (type)
				{
					case 1:
						Sgets(pnew->name , NAMESIZE);
						break;
						
					case 2:
						Sgets(pnew->gender , GENDERSIZE);
						break;
						
					case 3:
						Sgets(pnew->phone , PHONENUMSIZE);
						break;
						
					case 4:
						Sgets(pnew->address , 80);
						break;
						
					case 5:
						Sgets(pnew->birthDate , DATESIZE); 
						break;
						
					case 6:
						Sgets(pnew->employedDate , DATESIZE);
						break;
				}	
			}
			
			UpdateSalesman(head, pnew);
		}
		
		printf("\n是否继续修改（是1，否0）？\n");
		scanf("%d", &flag);

		while (getchar() != '\n')
		{
			continue;
		}
	}
} 

BOOL DeleteSalesman(Salesman *head)
{
	char number[NUMSIZE];
	char name[NAMESIZE];
	int flag = 1;
	
	while (flag)
	{	
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关销售员的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		printf("删除方式：1.姓名删除	2.代号删除\n请选择删除方式：");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
				
		switch (flag)
		{
			case 1:
				puts("请输入需要删除信息的销售员姓名：");
				Sgets(name , NAMESIZE);
										
				if (DeleteSalesmanByName(head, name) != 1)
				{
					printf("没有姓名为 %s 的销售员\n",name);
				}
				else
				{
					printf("成功删除姓名为 %s 的销售员\n",name);
				}
				
				break;
				
			case 2:
				puts("请输入需要删除信息的销售员代号：");
				Sgets(number , NUMSIZE);
										
				if (DeleteSalesmanByNumber(head, number) != 1)
				{
					printf("没有代号为 %s 的销售员\n",number);
				}
				else
				{
					printf("成功删除代号为 %s 的销售员\n",number);
				}
					
				break;
				
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
		}				
		
		printf("\n是否继续删除（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;
		}
						
	}
	
	return TRUE;
}

BOOL AddProduct(ProductInformation *Phead, MarketingInformation *Mhead)
{
	int type = 1;
	int flag = 1;
	
	while (type)
	{
		system("cls");
		
		puts("请选择需要添加的类型——1.产品自身信息，2.产品销售信息， 0.结束添加产品信息");
		scanf("%d",&type);
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		switch (type)
		{
			case 1:
				while (flag) 
				{
					system("cls");
					
					ProductInformation *pnew1 = (ProductInformation *) malloc (sizeof(ProductInformation));
		
					if (pnew1 == NULL)
					{
						printf("申请内存空间失败！\n");
						exit(EXIT_FAILURE);	
					} 
					
					puts("请输入产品名称：");
					Sgets(pnew1->name , NAMESIZE);
					
					if (QueryProductInformationByName(Phead , pnew1->name) != NULL)
					{
						printf("名称为 %s 的产品已添加！\n" , pnew1->name);
						free(pnew1);
						printf("\n是否继续添加产品自身信息（是1，否0）？\n");
						scanf("%d",&flag);
						
						while (getchar() != '\n')
						{
							continue;	
						}
					
						continue;
					}
					
					puts("请输入产品编码：");
					Sgets(pnew1->code , NAMESIZE);
					
					puts("请输入产品总数：");
					scanf("%d",&pnew1->totalNumber);
					
					while (getchar() != '\n')
					{
							continue;	
					}
					
					puts("请输入产品进价：");
					scanf("%f",&pnew1->unitPrice);
					
					while (getchar() != '\n')
					{
							continue;	
					}
							
					puts("请输入产品产商：");
					Sgets(pnew1->producer , NAMESIZE);
					
					puts("请输入产品入库时间(如：xxxx-xx-xx)：");
					Sgets(pnew1->stockDate , DATESIZE);
					
					pnew1->next = NULL; 
					
					AddProductInformation(Phead, pnew1);
					
					printf("\n是否继续添加产品自身信息（是1，否0）？\n");
					scanf("%d",&flag);
				
					while (getchar() != '\n')
					{
						continue;	
					}
				}
				
				flag = 1;
				break;
				
			case 2:
				while (flag) 
				{
					system("cls");
					
					MarketingInformation *pnew2 = (MarketingInformation *) malloc (sizeof(MarketingInformation));
		
					if (pnew2 == NULL)
					{
						printf("申请内存空间失败！\n");
						exit(EXIT_FAILURE);	
					} 
					
					puts("请输入销售员姓名：");
					Sgets(pnew2->salesman , NAMESIZE);
					
					puts("请输入顾客姓名：");
					Sgets(pnew2->customer , NAMESIZE);
					
					puts("请输入顾客联系方式：");
					Sgets(pnew2->customerPhone , PHONENUMSIZE);
					
					puts("请输入产品名称：");
					Sgets(pnew2->productName , NAMESIZE);
					
					puts("请输入产品编码：");
					Sgets(pnew2->productCode , NAMESIZE);
					
					puts("请输入产品销售数量：");
					scanf("%d",&pnew2->amount);
					
					while (getchar() != '\n')
					{
							continue;
					}
								
					puts("请输入产品售价：");
					scanf("%f",&pnew2->unitPrice);
					
					while (getchar() != '\n')
					{
							continue;	
					}
							
					puts("请输入产品说明：");
					Sgets(pnew2->notes , 30);
					
					puts("请输入产品销售时间：");
					Sgets(pnew2->salesDate , DATESIZE);
					
					pnew2->next = NULL; 
					
					AddMarketingInformation(Mhead, pnew2);
					
					printf("\n是否继续添加产品销售信息（是1，否0）？\n");
					scanf("%d",&flag);
	
					while (getchar() != '\n')
					{
						continue;
					}
				}
				
				break; 
			
			case 0:
				break;
		}	
	}
	
	return TRUE;
}

BOOL QueryProduct(ProductInformation *Phead, MarketingInformation *Mhead)
{
	ProductInformation *p1;
	MarketingInformation **p2;
	char code[NUMSIZE];
	char name[NAMESIZE];
	int flag = 1;
	int count = 0;
		
	while (flag)
	{
		system("cls");
		
		if (Phead->next == NULL)
		{
			puts("当前尚无有关产品的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		printf("查询方式：1.名称查询	2.编码查询\n请选择查询方式：");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
		
		switch (flag)
		{
			case 1:
				puts("请输入需要查询的产品名称：");
				Sgets(name , NAMESIZE);
				p1 = QueryProductInformationByName(Phead, name);
				
				printf("\n");
				
				if (p1 == NULL)
				{
					puts("没有该产品");
				}
				else
				{
					printf("编码\t\t名称\t\t总数\t进价\t产商\t\t入库时间\n");
					printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", p1->code, p1->name, 
					p1->totalNumber, p1->unitPrice, p1->producer, p1->stockDate);
				}
				
				if ((p2 = QueryMarketingInformationByName(Mhead, name)) == NULL)
				{
					printf("暂无该产品的销售记录！");
				}
				else
				{
					printf("\n销售时间\t销售数量\t售价\t销售员\t顾客\t顾客联系方式\t\t说明\n");
					
					while (p2[count] != NULL)
					{
						printf("%s\t%d\t%13.2f\t%s\t%s\t%s\t\t%s\n", p2[count]->salesDate, p2[count]->amount, p2[count]->unitPrice,
							p2[count]->salesman, p2[count]->customer, p2[count]->customerPhone, p2[count]->notes);
							
						++count;
					}
					
					count = 0;
					
					free(p2);
				}

				break;
				
			case 2:
				puts("请输入需要查询的产品编码：");
				Sgets(code , NUMSIZE);
				p1 = QueryProductInformationByNumber(Phead, code);
										
				printf("\n");
										
				if (p2 == NULL)
				{
					puts("没有该产品");
				}
				else
				{
					printf("编码\t\t名称\t\t总数\t进价\t产商\t\t入库时间\n");
					printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", p1->code, p1->name, 
					p1->totalNumber, p1->unitPrice, p1->producer, p1->stockDate);
				}
				
				if ((p2 = QueryMarketingInformationByNumber(Mhead, code)) == NULL)
				{
					printf("暂无该产品的销售记录！");
				}
				else
				{
					printf("\n销售时间\t销售数量\t售价\t销售员\t顾客\t顾客联系方式\t\t说明\n");
					
					while (p2[count] != NULL)
					{
						printf("%s\t%d\t%13.2f\t%s\t%s\t%s\t\t%s\n", p2[count]->salesDate, p2[count]->amount, p2[count]->unitPrice,
							p2[count]->salesman, p2[count]->customer, p2[count]->customerPhone, p2[count]->notes);
							
						++count;
					}
					
					count = 0;
					
					free(p2);
				}
						
				break;	
				
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
		}						
								
		printf("\n是否继续查询（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;	
		}
								
	}
	
	return TRUE;
}

BOOL AlterProduct(ProductInformation *head)
{
	ProductInformation *p;
	ProductInformation *pnew;
	char name[NUMSIZE];
	int flag = 1;
	int type = 1; 
	
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关销售员的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要修改的产品名称：");
		Sgets(name , NAMESIZE);
		p = QueryProductInformationByName(head, name);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("没有该产品");
		}
		else
		{
			printf("编码\t\t名称\t\t总数\t进价\t产商\t\t入库时间\n");
			printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", p->code, p->name, 
			p->totalNumber, p->unitPrice, p->producer, p->stockDate);
			
			pnew = (ProductInformation *) malloc (sizeof(ProductInformation));	//记录存在创建一个记录的副本
			*pnew = *p; 
			
			while (type)
			{
				printf("请选择需要修改信息的类别:\n");
				printf("(1.编码\t2.总数\t3.进价\t4.产商\t5.入库时间\t0.结束修改本条记录信息)\n");
				scanf("%d", &type);	
				
				while (getchar() != '\n')
				{
					continue;
				}
				
				if (type == 0)
				{
					type = 1;
					break;
				}
				
				puts("请输入新的内容:");
				
				switch (type)
				{
					case 1:
						Sgets(pnew->code , NUMSIZE);
						break;
						
					case 2:
						scanf("%d",&pnew->totalNumber);
						
						while (getchar() != '\n')
						{
							continue;
						}
							
						break;
						
					case 3:
						scanf("%f",&pnew->unitPrice);
						
						while (getchar() != '\n')
						{
							continue;
						}
							
						break;
						
					case 4:
						Sgets(pnew->producer , NAMESIZE); 
						break;
						
					case 5:
						Sgets(pnew->stockDate , DATESIZE);
						break;
				}	
			}
			
			UpdateProductInformation(head, pnew);
		}
		
		printf("\n是否继续修改（是1，否0）？\n");
		scanf("%d", &flag);

		while (getchar() != '\n')
		{
			continue;
		}
	}
} 

BOOL DeleteProduct(ProductInformation *head)
{
	char code[NAMESIZE];
	char name[NAMESIZE];
	int flag = 1;
	
	while (flag)
	{	
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关销售员的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		printf("删除方式：1.名称删除	2.编码删除\n请选择删除方式：");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
				
		switch (flag)
		{
			case 1:
				puts("请输入需要删除信息的产品名称：");
				Sgets(name , NAMESIZE);
										
				if (DeleteProductByName(head, name) != 1)
				{
					printf("没有名称为 %s 的产品\n",name);
				}
				else
				{
					printf("成功删除名称为 %s 的产品\n",name);
				}
				
				break;
				
			case 2:
				puts("请输入需要删除信息的产品编码：");
				Sgets(code , NAMESIZE);
										
				if (DeleteProductByNumber(head, code) != 1)
				{
					printf("没有编码为 %s 的产品\n",code);
				}
				else
				{
					printf("成功删除编码为 %s 的产品\n",code);
				}
					
				break;
				
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
		}				
		
		printf("\n是否继续删除（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;
		}
						
	}
	
	return TRUE;
}

BOOL AddProducer(Producer *head)
{
	int flag = 1;
	
	while (flag)
	{
		Producer *pnew = (Producer *) malloc (sizeof(Producer));
		system("cls");
		
		puts("请输入姓名：");
		Sgets(pnew->name , NAMESIZE);
		
		if (QueryProducerByName(head, pnew->name) != NULL)		//需要添加的记录已经存在 
		{
			printf("姓名为 %s 的进货商信息已添加！\n" , pnew->name);
			free(pnew);
			getchar(); 
			continue;
		}
		
		puts("请输入联系电话：");
		Sgets(pnew->phone , PHONENUMSIZE); 
		puts("请输入联系地址：");
		Sgets(pnew->address , 80); 
		
		pnew->next=NULL; 
		
		AddProducer(head, pnew);
													 
		printf("\n是否继续添加（是1，否0）？\n");
		scanf("%d",&flag);
							
		while(getchar() != '\n')
		{
			continue;	
		}
	}
	
	return TRUE;
}

BOOL QueryProducer(Producer *head)
{
	Producer *p;
	char name[NAMESIZE];
	int flag = 1;
		
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关进货商的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要查询的进货商的姓名：");
		Sgets(name , NAMESIZE);
		p = QueryProducerByName(head, name);
				
		printf("\n");
				
		if (p == NULL)
		{
			puts("没有该进货商");
		}
		else
		{
			printf("姓名\t联系电话\t联系地址\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
		}	
								
		printf("\n是否继续查询（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;	
		}
								
	}
	
	return TRUE;
}

BOOL AlterProducer(Producer *head)
{
	Producer *p;
	Producer *pnew;
	char name[NAMESIZE];
	int flag = 1;
	int type = 1; 
	
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关进货商的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要修改信息的进货商的姓名：");
		Sgets(name , NAMESIZE);
		p = QueryProducerByName(head, name);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("没有该进货商");
		}
		else
		{
			printf("姓名\t联系电话\t联系地址\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
			
			pnew = (Producer *) malloc (sizeof(Producer));	//记录存在创建一个记录的副本
			*pnew = *p; 
			
			printf("\n1.联系电话\t2.联系地址\t0.结束修改本条记录信息");
			
			while (type)
			{
				printf("\n请选择需要修改信息的类别:\n");
				scanf("%d", &type);	
				
				while (getchar() != '\n')
				{
					continue;
				}
					
				if (type == 0)
				{
					type = 1;
					break;
				}
					
				puts("请输入新的内容:");
				
				switch (type)
				{
					case 1:
						Sgets(pnew->phone , PHONENUMSIZE); 
						break;
				
					case 2:
						Sgets(pnew->address , 50); 
						break;
				}	
			} 
			
			UpdateProducer(head, pnew);
		}
		
		printf("\n是否继续修改（是1，否0）？\n");
		scanf("%d", &flag);

		while (getchar() != '\n')
			continue;
	}
} 

BOOL DeleteProducer(Producer *head)
{
	char name[NAMESIZE];
	int flag = 1;
	
	while (flag)
	{	
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关进货商的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要删除信息的进货商姓名：");
		Sgets(name , NAMESIZE);
										
		if (DeleteProducerByName(head, name) != 1)
		{
			printf("没有姓名为 %s 的进货商\n",name);
		}
		else
		{
			printf("成功删除姓名为 %s 的进货商\n",name);
		}
		
		printf("\n是否继续删除（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;
		}
						
	}
	
	return TRUE;
}

BOOL AddCustomer(Customer *head)
{
	int flag = 1;
	
	while (flag)
	{
		Customer *pnew = (Customer *) malloc (sizeof(Customer));
		system("cls");
		
		puts("请输入姓名：");
		Sgets(pnew->name , NAMESIZE);
		
		if (QueryCustomerByName(head, pnew->name) != NULL)		//需要添加的记录已经存在 
		{
			printf("姓名为 %s 的顾客信息已添加！\n" , pnew->name);
			free(pnew);
			getchar(); 
			continue;
		}
		
		puts("请输入联系电话：");
		Sgets(pnew->phone , PHONENUMSIZE); 
		puts("请输入联系地址：");
		Sgets(pnew->address , 80); 
		
		pnew->next=NULL; 
		
		AddCustomer(head, pnew);
													 
		printf("\n是否继续添加（是1，否0）？\n");
		scanf("%d",&flag);
							
		while (getchar() != '\n')
		{
			continue;	
		}
	}
	
	return TRUE;
}

BOOL QueryCustomer(Customer *head)
{
	Customer *p;
	char name[NAMESIZE];
	int flag = 1;
		
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关顾客的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要查询的顾客的姓名：");
		Sgets(name , NAMESIZE);
		p = QueryCustomerByName(head, name);
				
		printf("\n");
				
		if (p == NULL)
		{
			puts("没有该顾客");
		}
		else
		{
			printf("姓名\t联系电话\t联系地址\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
		}	
								
		printf("\n是否继续查询（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;	
		}
								
	}
	
	return TRUE;
}

BOOL AlterCustomer(Customer *head)
{
	Customer *p;
	Customer *pnew;
	char name[NAMESIZE];
	int flag = 1;
	int type = 1; 
	
	while (flag)
	{
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关顾客的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要修改信息的顾客的姓名：");
		Sgets(name , NAMESIZE);
		p = QueryCustomerByName(head, name);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("没有该顾客");
		}
		else
		{
			printf("姓名\t联系电话\t联系地址\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
			
			pnew = (Customer *) malloc (sizeof(Customer));	//记录存在创建一个记录的副本
			*pnew = *p; 
			
			printf("\n1.联系电话\t2.联系地址\t0.结束修改本条记录信息");
			
			while (type)
			{
				printf("\n请选择需要修改信息的类别:\n");
				scanf("%d", &type);	
				
				while (getchar() != '\n')
				{
					continue;
				}
					
				if (type == 0)
				{
					type = 1;
					break;
				}
					
				puts("请输入新的内容:");
				
				switch (type)
				{
					case 1:
						Sgets(pnew->phone , PHONENUMSIZE); 
						break;
				
					case 2:
						Sgets(pnew->address , 50); 
						break;
				}	
			} 
			
			UpdateCustomer(head, pnew);
		}
		
		printf("\n是否继续修改（是1，否0）？\n");
		scanf("%d", &flag);

		while (getchar() != '\n')
		{
			continue;
		}
	}
} 

BOOL DeleteCustomer(Customer *head)
{
	char name[NAMESIZE];
	int flag = 1;
	
	while (flag)
	{	
		system("cls");
		
		if (head->next == NULL)
		{
			puts("当前尚无有关顾客的记录！");
			puts("请按[Enter]键继续...");
			getchar();
			break;
		}
		
		puts("请输入需要删除信息的顾客姓名：");
		Sgets(name , NAMESIZE);
										
		if (DeleteCustomerByName(head, name) != 1)
		{
			printf("没有姓名为 %s 的顾客\n",name);
		}
		else
		{ 
			printf("成功删除姓名为 %s 的顾客\n",name);	
		}
		
		printf("\n是否继续删除（是1，否0）？\n");
		scanf("%d", &flag);
								
		while (getchar() != '\n')
		{
			continue;
		}
						
	}
	
	return TRUE;
}

Salesman *InitializeSalesman(void)
{
	Salesman *head = (Salesman *) malloc (sizeof(Salesman));
	
	head->next = NULL;
	
	return head; 
} 

ProductInformation *InitializeProductInformation(void)
{
	ProductInformation *head = (ProductInformation *) malloc (sizeof(ProductInformation));
	
	head->next = NULL;
	
	return head; 
} 

MarketingInformation *InitializeMarketingInformation(void)
{
	MarketingInformation *head = (MarketingInformation *) malloc (sizeof(MarketingInformation));
	
	head->next = NULL;
	
	return head; 
} 

Producer *InitializeProducer(void)
{
	Producer *head = (Producer *) malloc (sizeof(Producer));
	
	head->next = NULL;
	
	return head; 
} 

Customer *InitializeCustomer(void)
{
	Customer *head = (Customer *) malloc (sizeof(Customer));
	
	head->next = NULL;
	
	return head; 
} 

void SalesmanManage(Salesman *head)
{
	int n;
	
	while (n = Manage("人员管理"))
	{
		switch (n)
		{  
			case 1:
				AddSalesman(head);
				break; 
							
			case 2:
				QuerySalesman(head);
				break; 
							
			case 3: 
				AlterSalesman(head);
				break; 
							
			case 4:  
				DeleteSalesman(head);
				break; 
							
			case 0:
				break;
							
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
							
		}
	} 
} 

void ProductManage(ProductInformation *productInformationHead, MarketingInformation *marketingInformationHead)
{
	int n;
	
	while (n = Manage("产品管理"))
	{
		switch (n)
		{  
			case 1:
				AddProduct(productInformationHead, marketingInformationHead);
				break; 
							
			case 2:
				QueryProduct(productInformationHead, marketingInformationHead);
				break; 
							
			case 3: 
				AlterProduct(productInformationHead);
				break; 
							
			case 4:  
				DeleteProduct(productInformationHead);
				break; 
							
			case 0:
				break;
							
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
							
		}
	} 
}

void ProducerManage(Producer *head)
{
	int n;
	
	while (n = Manage("进货商管理"))
	{
		switch (n)
		{  
			case 1:
				AddProducer(head);
				break; 
							
			case 2:
				QueryProducer(head);
				break; 
				
			case 3: 
				AlterProducer(head);
				break; 
							
			case 4:  
				DeleteProducer(head);
				break; 
							
			case 0:
				break;
							
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
							
		}
	} 
}

void CustomerManage(Customer *head)
{
	int n;
	
	while (n = Manage("顾客管理"))
	{
		switch (n)
		{  
			case 1:
				AddCustomer(head);
				break; 
							
			case 2:
				QueryCustomer(head);
				break; 
							
			case 3: 
				AlterCustomer(head);
				break; 
							
			case 4:  
				DeleteCustomer(head);
				break; 
				
			case 0:
				break;
							
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
							
		}
	} 
}

int main(void)
{
	int flag = 1;
	int n;
	
	//初始化头结点 
	Salesman *salesmanHead = InitializeSalesman();
	ProductInformation *productInformationHead = InitializeProductInformation();
	MarketingInformation *marketingInformationHead = InitializeMarketingInformation();
	Producer *producerHead = InitializeProducer();
	Customer *customerHead = InitializeCustomer();
	
	while (flag)
	{
		MainSelect();
		
		scanf("%d",&flag);
		getchar();
		
		switch (flag)
		{
			case 1:
				LoadSalesmanDataFromFile(salesmanHead, "Salesman.txt");
				SalesmanManage(salesmanHead);
				SaveSalesmanDataToFile(salesmanHead, "Salesman.txt");
				break;
				
			case 2:
				LoadProductInformationDataFromFile(productInformationHead, "ProductInformation.txt");
				LoadMarketingInformationDataFromFile(marketingInformationHead, "MarketingInformation.txt");
				ProductManage(productInformationHead, marketingInformationHead);
				SaveProductInformationDataToFile(productInformationHead, "ProductInformation.txt");
				SaveMarketingInformationDataToFile(marketingInformationHead, "MarketingInformation.txt");
				break;
				
			case 3:
				LoadProducerDataFromFile(producerHead, "Producer.txt");
				ProducerManage(producerHead);
				SaveProducerDataToFile(producerHead, "Producer.txt");
				break;
				
			case 4:
				LoadCustomerDataFromFile(customerHead, "Customer.txt");
				CustomerManage(customerHead);
				SaveCustomerDataToFile(customerHead, "Customer.txt");
				break;
				
			case 0:
				break;
				
			default:
				printf("\t\t无效的功能，请重新选择！\n\t\t请按任意键继续...");
				getchar();
		}
	}
}
