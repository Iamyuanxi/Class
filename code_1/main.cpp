#include"SalesManage.h"

/*���뺯��*/ 
char *Sgets(char *st , int n)
{
	char *retVal;
	char *find;
	char number[NUMSIZE];
	
	retVal = fgets(st, n, stdin);
	
	if (retVal != NULL)
	{
		find = strchr(st, '\n');		// ���һ��з�
	
		if (find != NULL)
		{				   
			*find = '\0';	// �ڴ˴�����һ�����ַ�
		}			   		
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}		   			// ����ʣ��������
		}
	}

	return retVal;
}

/*����*/ 
BOOL Form(void)
{
	printf("\t\t    _____________________________\n");
	printf("\t\t   �� 1. �����Ϣ    2. ��Ϣ��ѯ ��\n");
	printf("\t\t   ��                            ��\n");
	printf("\t\t   �� 3. �޸���Ϣ    4. ɾ����Ϣ ��\n");
	printf("\t\t   ��                            ��\n");
	printf("\t\t   �� 0. �����ϼ�                ��\n");
	printf("\t\t   ��____________________________��\n");
	printf("\t\t����ѡ��(0-4):"); 

	return TRUE;
}  

BOOL MainSelect()
{
	system("cls"); /*����*/
	
	printf("\t\t ====================================\n");
	printf("\t\t��         ������Ϣ����ϵͳ         ��\n");
	printf("\t\t ====================================\n");
	printf("\t\t   _______________________________\n");
	printf("\t\t  �� 1. ��Ա����     2. ��Ʒ����  ��\n");
	printf("\t\t  ��                              ��\n");
	printf("\t\t  �� 3. �����̹���   4. �˿͹���  ��\n");
	printf("\t\t  ��                              ��\n");
	printf("\t\t  �� 0. �˳�ϵͳ                  ��\n");
	printf("\t\t  ��______________________________��\n");
	printf("\t\t����ѡ��(0-4):"); 
	
	return TRUE;
} 

int Manage(const char *type)
{
	int n;
	
	system("cls"); /*����*/
	
	printf("\t\t ====================================\n");
	printf("\t\t��             %s             ��\n", type);
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
		
		puts("��������ţ�");
		Sgets(pNew->number , NUMSIZE);
		
		if (QuerySalesmanByNumber(head, pNew->number) != NULL)		//��Ҫ��ӵļ�¼�Ѿ����� 
		{
			printf("����Ϊ %s ������Ա��Ϣ����ӣ�\n����������" , pNew->number);
			
			free(pNew);
			
			getchar(); 
			continue;
		}
		
		puts("������������");
		Sgets(pNew->name , NAMESIZE);
		
		puts("�������Ա�");
		Sgets(pNew->gender , GENDERSIZE);
		
		puts("��������ϵ�绰��");
		Sgets(pNew->phone , PHONENUMSIZE); 
		
		puts("��������ϵ��ַ��");
		Sgets(pNew->address , 80); 
		
		puts("������������£����������ʽxxxx-xx-xx����");
		Sgets(pNew->birthDate , DATESIZE); 
		
		puts("��������ְʱ�䣨���������ʽxxxx-xx-xx����");
		Sgets(pNew->employedDate , DATESIZE);
		
		pNew->next=NULL; 
		
		AddSalesman(head, pNew);
													 
		printf("\n�Ƿ������ӣ���1����0����\n");
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
			puts("��ǰ�����й�����Ա�ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		printf("��ѯ��ʽ��1.������ѯ	2.���Ų�ѯ\n��ѡ���ѯ��ʽ��");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
		
		switch (flag)
		{
			case 1:
				puts("��������Ҫ��ѯ������Ա��������");
				Sgets(name , NAMESIZE);
				p1 = QuerySalesmanByName(head, name);
				
				printf("\n");
				
				if (p1 == NULL)
				{
					puts("û�и�����Ա");
				}
				else
				{
					printf("����\t����\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t����������\t��ְʱ��\n");
					
					while (*p1 != NULL)
					{
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", (*p1)->number, (*p1)->name, (*p1)->gender, (*p1)->phone, (*p1)->address,
							(*p1)->birthDate, (*p1)->employedDate);
							
						++p1;
					}
				}
				
				break;
				
			case 2:
				puts("��������Ҫ��ѯ������Ա�Ĵ��ţ�");
				Sgets(number , NUMSIZE);
				p2 = QuerySalesmanByNumber(head, number);
										
				printf("\n");
										
				if (p2 == NULL)
				{
					puts("û�и�����Ա");
				}
				else
				{
					printf("����\t����\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t����������\t��ְʱ��\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p2->number, p2->name, p2->gender, p2->phone, p2->address,
							p2->birthDate, p2->employedDate);
				}
				
				break;	
				
			default:
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
		}						
								
		printf("\n�Ƿ������ѯ����1����0����\n");
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
			puts("��ǰ�����й�����Ա�ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫ�޸���Ϣ������Ա�Ĵ��ţ�");
		Sgets(number , NUMSIZE);
		p = QuerySalesmanByNumber(head, number);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("û�и�����Ա");
		}
		else
		{
			printf("����\t����\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t����������\t��ְʱ��\n");
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p->number, p->name, p->gender, p->phone, p->address,
			p->birthDate, p->employedDate);
			
			pnew = (Salesman *) malloc (sizeof(Salesman));	//��¼���ڴ���һ����¼�ĸ���
			*pnew = *p; 
			
			while (type)
			{
				printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
				printf("(1.����\t2.�Ա�\t3.��ϵ�绰\t4.��ϵ��ַ\t5.����������\t6.��ְʱ��\t0.�����޸ı�����¼��Ϣ)\n");
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
				
				puts("�������µ�����:");
				
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
		
		printf("\n�Ƿ�����޸ģ���1����0����\n");
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
			puts("��ǰ�����й�����Ա�ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		printf("ɾ����ʽ��1.����ɾ��	2.����ɾ��\n��ѡ��ɾ����ʽ��");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
				
		switch (flag)
		{
			case 1:
				puts("��������Ҫɾ����Ϣ������Ա������");
				Sgets(name , NAMESIZE);
										
				if (DeleteSalesmanByName(head, name) != 1)
				{
					printf("û������Ϊ %s ������Ա\n",name);
				}
				else
				{
					printf("�ɹ�ɾ������Ϊ %s ������Ա\n",name);
				}
				
				break;
				
			case 2:
				puts("��������Ҫɾ����Ϣ������Ա���ţ�");
				Sgets(number , NUMSIZE);
										
				if (DeleteSalesmanByNumber(head, number) != 1)
				{
					printf("û�д���Ϊ %s ������Ա\n",number);
				}
				else
				{
					printf("�ɹ�ɾ������Ϊ %s ������Ա\n",number);
				}
					
				break;
				
			default:
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
		}				
		
		printf("\n�Ƿ����ɾ������1����0����\n");
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
		
		puts("��ѡ����Ҫ��ӵ����͡���1.��Ʒ������Ϣ��2.��Ʒ������Ϣ�� 0.������Ӳ�Ʒ��Ϣ");
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
						printf("�����ڴ�ռ�ʧ�ܣ�\n");
						exit(EXIT_FAILURE);	
					} 
					
					puts("�������Ʒ���ƣ�");
					Sgets(pnew1->name , NAMESIZE);
					
					if (QueryProductInformationByName(Phead , pnew1->name) != NULL)
					{
						printf("����Ϊ %s �Ĳ�Ʒ����ӣ�\n" , pnew1->name);
						free(pnew1);
						printf("\n�Ƿ������Ӳ�Ʒ������Ϣ����1����0����\n");
						scanf("%d",&flag);
						
						while (getchar() != '\n')
						{
							continue;	
						}
					
						continue;
					}
					
					puts("�������Ʒ���룺");
					Sgets(pnew1->code , NAMESIZE);
					
					puts("�������Ʒ������");
					scanf("%d",&pnew1->totalNumber);
					
					while (getchar() != '\n')
					{
							continue;	
					}
					
					puts("�������Ʒ���ۣ�");
					scanf("%f",&pnew1->unitPrice);
					
					while (getchar() != '\n')
					{
							continue;	
					}
							
					puts("�������Ʒ���̣�");
					Sgets(pnew1->producer , NAMESIZE);
					
					puts("�������Ʒ���ʱ��(�磺xxxx-xx-xx)��");
					Sgets(pnew1->stockDate , DATESIZE);
					
					pnew1->next = NULL; 
					
					AddProductInformation(Phead, pnew1);
					
					printf("\n�Ƿ������Ӳ�Ʒ������Ϣ����1����0����\n");
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
						printf("�����ڴ�ռ�ʧ�ܣ�\n");
						exit(EXIT_FAILURE);	
					} 
					
					puts("����������Ա������");
					Sgets(pnew2->salesman , NAMESIZE);
					
					puts("������˿�������");
					Sgets(pnew2->customer , NAMESIZE);
					
					puts("������˿���ϵ��ʽ��");
					Sgets(pnew2->customerPhone , PHONENUMSIZE);
					
					puts("�������Ʒ���ƣ�");
					Sgets(pnew2->productName , NAMESIZE);
					
					puts("�������Ʒ���룺");
					Sgets(pnew2->productCode , NAMESIZE);
					
					puts("�������Ʒ����������");
					scanf("%d",&pnew2->amount);
					
					while (getchar() != '\n')
					{
							continue;
					}
								
					puts("�������Ʒ�ۼۣ�");
					scanf("%f",&pnew2->unitPrice);
					
					while (getchar() != '\n')
					{
							continue;	
					}
							
					puts("�������Ʒ˵����");
					Sgets(pnew2->notes , 30);
					
					puts("�������Ʒ����ʱ�䣺");
					Sgets(pnew2->salesDate , DATESIZE);
					
					pnew2->next = NULL; 
					
					AddMarketingInformation(Mhead, pnew2);
					
					printf("\n�Ƿ������Ӳ�Ʒ������Ϣ����1����0����\n");
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
			puts("��ǰ�����йز�Ʒ�ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		printf("��ѯ��ʽ��1.���Ʋ�ѯ	2.�����ѯ\n��ѡ���ѯ��ʽ��");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
		
		switch (flag)
		{
			case 1:
				puts("��������Ҫ��ѯ�Ĳ�Ʒ���ƣ�");
				Sgets(name , NAMESIZE);
				p1 = QueryProductInformationByName(Phead, name);
				
				printf("\n");
				
				if (p1 == NULL)
				{
					puts("û�иò�Ʒ");
				}
				else
				{
					printf("����\t\t����\t\t����\t����\t����\t\t���ʱ��\n");
					printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", p1->code, p1->name, 
					p1->totalNumber, p1->unitPrice, p1->producer, p1->stockDate);
				}
				
				if ((p2 = QueryMarketingInformationByName(Mhead, name)) == NULL)
				{
					printf("���޸ò�Ʒ�����ۼ�¼��");
				}
				else
				{
					printf("\n����ʱ��\t��������\t�ۼ�\t����Ա\t�˿�\t�˿���ϵ��ʽ\t\t˵��\n");
					
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
				puts("��������Ҫ��ѯ�Ĳ�Ʒ���룺");
				Sgets(code , NUMSIZE);
				p1 = QueryProductInformationByNumber(Phead, code);
										
				printf("\n");
										
				if (p2 == NULL)
				{
					puts("û�иò�Ʒ");
				}
				else
				{
					printf("����\t\t����\t\t����\t����\t����\t\t���ʱ��\n");
					printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", p1->code, p1->name, 
					p1->totalNumber, p1->unitPrice, p1->producer, p1->stockDate);
				}
				
				if ((p2 = QueryMarketingInformationByNumber(Mhead, code)) == NULL)
				{
					printf("���޸ò�Ʒ�����ۼ�¼��");
				}
				else
				{
					printf("\n����ʱ��\t��������\t�ۼ�\t����Ա\t�˿�\t�˿���ϵ��ʽ\t\t˵��\n");
					
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
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
		}						
								
		printf("\n�Ƿ������ѯ����1����0����\n");
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
			puts("��ǰ�����й�����Ա�ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫ�޸ĵĲ�Ʒ���ƣ�");
		Sgets(name , NAMESIZE);
		p = QueryProductInformationByName(head, name);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("û�иò�Ʒ");
		}
		else
		{
			printf("����\t\t����\t\t����\t����\t����\t\t���ʱ��\n");
			printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", p->code, p->name, 
			p->totalNumber, p->unitPrice, p->producer, p->stockDate);
			
			pnew = (ProductInformation *) malloc (sizeof(ProductInformation));	//��¼���ڴ���һ����¼�ĸ���
			*pnew = *p; 
			
			while (type)
			{
				printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
				printf("(1.����\t2.����\t3.����\t4.����\t5.���ʱ��\t0.�����޸ı�����¼��Ϣ)\n");
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
				
				puts("�������µ�����:");
				
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
		
		printf("\n�Ƿ�����޸ģ���1����0����\n");
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
			puts("��ǰ�����й�����Ա�ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		printf("ɾ����ʽ��1.����ɾ��	2.����ɾ��\n��ѡ��ɾ����ʽ��");
		scanf("%d", &flag); 
		
		while (getchar() != '\n')
		{
			continue;
		}
			
		system("cls");
				
		switch (flag)
		{
			case 1:
				puts("��������Ҫɾ����Ϣ�Ĳ�Ʒ���ƣ�");
				Sgets(name , NAMESIZE);
										
				if (DeleteProductByName(head, name) != 1)
				{
					printf("û������Ϊ %s �Ĳ�Ʒ\n",name);
				}
				else
				{
					printf("�ɹ�ɾ������Ϊ %s �Ĳ�Ʒ\n",name);
				}
				
				break;
				
			case 2:
				puts("��������Ҫɾ����Ϣ�Ĳ�Ʒ���룺");
				Sgets(code , NAMESIZE);
										
				if (DeleteProductByNumber(head, code) != 1)
				{
					printf("û�б���Ϊ %s �Ĳ�Ʒ\n",code);
				}
				else
				{
					printf("�ɹ�ɾ������Ϊ %s �Ĳ�Ʒ\n",code);
				}
					
				break;
				
			default:
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
		}				
		
		printf("\n�Ƿ����ɾ������1����0����\n");
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
		
		puts("������������");
		Sgets(pnew->name , NAMESIZE);
		
		if (QueryProducerByName(head, pnew->name) != NULL)		//��Ҫ��ӵļ�¼�Ѿ����� 
		{
			printf("����Ϊ %s �Ľ�������Ϣ����ӣ�\n" , pnew->name);
			free(pnew);
			getchar(); 
			continue;
		}
		
		puts("��������ϵ�绰��");
		Sgets(pnew->phone , PHONENUMSIZE); 
		puts("��������ϵ��ַ��");
		Sgets(pnew->address , 80); 
		
		pnew->next=NULL; 
		
		AddProducer(head, pnew);
													 
		printf("\n�Ƿ������ӣ���1����0����\n");
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
			puts("��ǰ�����йؽ����̵ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫ��ѯ�Ľ����̵�������");
		Sgets(name , NAMESIZE);
		p = QueryProducerByName(head, name);
				
		printf("\n");
				
		if (p == NULL)
		{
			puts("û�иý�����");
		}
		else
		{
			printf("����\t��ϵ�绰\t��ϵ��ַ\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
		}	
								
		printf("\n�Ƿ������ѯ����1����0����\n");
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
			puts("��ǰ�����йؽ����̵ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫ�޸���Ϣ�Ľ����̵�������");
		Sgets(name , NAMESIZE);
		p = QueryProducerByName(head, name);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("û�иý�����");
		}
		else
		{
			printf("����\t��ϵ�绰\t��ϵ��ַ\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
			
			pnew = (Producer *) malloc (sizeof(Producer));	//��¼���ڴ���һ����¼�ĸ���
			*pnew = *p; 
			
			printf("\n1.��ϵ�绰\t2.��ϵ��ַ\t0.�����޸ı�����¼��Ϣ");
			
			while (type)
			{
				printf("\n��ѡ����Ҫ�޸���Ϣ�����:\n");
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
					
				puts("�������µ�����:");
				
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
		
		printf("\n�Ƿ�����޸ģ���1����0����\n");
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
			puts("��ǰ�����йؽ����̵ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫɾ����Ϣ�Ľ�����������");
		Sgets(name , NAMESIZE);
										
		if (DeleteProducerByName(head, name) != 1)
		{
			printf("û������Ϊ %s �Ľ�����\n",name);
		}
		else
		{
			printf("�ɹ�ɾ������Ϊ %s �Ľ�����\n",name);
		}
		
		printf("\n�Ƿ����ɾ������1����0����\n");
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
		
		puts("������������");
		Sgets(pnew->name , NAMESIZE);
		
		if (QueryCustomerByName(head, pnew->name) != NULL)		//��Ҫ��ӵļ�¼�Ѿ����� 
		{
			printf("����Ϊ %s �Ĺ˿���Ϣ����ӣ�\n" , pnew->name);
			free(pnew);
			getchar(); 
			continue;
		}
		
		puts("��������ϵ�绰��");
		Sgets(pnew->phone , PHONENUMSIZE); 
		puts("��������ϵ��ַ��");
		Sgets(pnew->address , 80); 
		
		pnew->next=NULL; 
		
		AddCustomer(head, pnew);
													 
		printf("\n�Ƿ������ӣ���1����0����\n");
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
			puts("��ǰ�����йع˿͵ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫ��ѯ�Ĺ˿͵�������");
		Sgets(name , NAMESIZE);
		p = QueryCustomerByName(head, name);
				
		printf("\n");
				
		if (p == NULL)
		{
			puts("û�иù˿�");
		}
		else
		{
			printf("����\t��ϵ�绰\t��ϵ��ַ\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
		}	
								
		printf("\n�Ƿ������ѯ����1����0����\n");
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
			puts("��ǰ�����йع˿͵ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫ�޸���Ϣ�Ĺ˿͵�������");
		Sgets(name , NAMESIZE);
		p = QueryCustomerByName(head, name);
		
		printf("\n");
		
		if (p == NULL)
		{
			puts("û�иù˿�");
		}
		else
		{
			printf("����\t��ϵ�绰\t��ϵ��ַ\n");
			printf("%s\t%s\t%s\n", p->name, p->phone, p->address);
			
			pnew = (Customer *) malloc (sizeof(Customer));	//��¼���ڴ���һ����¼�ĸ���
			*pnew = *p; 
			
			printf("\n1.��ϵ�绰\t2.��ϵ��ַ\t0.�����޸ı�����¼��Ϣ");
			
			while (type)
			{
				printf("\n��ѡ����Ҫ�޸���Ϣ�����:\n");
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
					
				puts("�������µ�����:");
				
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
		
		printf("\n�Ƿ�����޸ģ���1����0����\n");
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
			puts("��ǰ�����йع˿͵ļ�¼��");
			puts("�밴[Enter]������...");
			getchar();
			break;
		}
		
		puts("��������Ҫɾ����Ϣ�Ĺ˿�������");
		Sgets(name , NAMESIZE);
										
		if (DeleteCustomerByName(head, name) != 1)
		{
			printf("û������Ϊ %s �Ĺ˿�\n",name);
		}
		else
		{ 
			printf("�ɹ�ɾ������Ϊ %s �Ĺ˿�\n",name);	
		}
		
		printf("\n�Ƿ����ɾ������1����0����\n");
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
	
	while (n = Manage("��Ա����"))
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
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
							
		}
	} 
} 

void ProductManage(ProductInformation *productInformationHead, MarketingInformation *marketingInformationHead)
{
	int n;
	
	while (n = Manage("��Ʒ����"))
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
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
							
		}
	} 
}

void ProducerManage(Producer *head)
{
	int n;
	
	while (n = Manage("�����̹���"))
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
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
							
		}
	} 
}

void CustomerManage(Customer *head)
{
	int n;
	
	while (n = Manage("�˿͹���"))
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
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
							
		}
	} 
}

int main(void)
{
	int flag = 1;
	int n;
	
	//��ʼ��ͷ��� 
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
				printf("\t\t��Ч�Ĺ��ܣ�������ѡ��\n\t\t�밴���������...");
				getchar();
		}
	}
}
