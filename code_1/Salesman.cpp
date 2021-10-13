#include"SalesManage.h"

BOOL AddSalesman(Salesman *head, const Salesman *salesman)	//����1��ʾ��ӳɹ���0��ʾ��¼�Ѵ��ڡ� 
{	
	Salesman *curr = head;
	 
	while (curr->next != NULL)	//��λ�������β 
	{
		curr = curr->next;
	}
	
	curr->next = (Salesman *) salesman; 
	
	return TRUE; 
}

BOOL UpdateSalesman(Salesman *head, const Salesman *salesman)	//����1��ʾ�޸ĳɹ�
{
	Salesman *prev = head;
	Salesman *curr = head->next; 
	
	while (curr != NULL)
	{
		if (strcmp(curr->number, salesman->number) == 0)
		{
			prev->next = (Salesman *) salesman;
			prev->next->next = curr->next;
			
			free(curr);
			
			break;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	return TRUE; 
}

BOOL DeleteSalesmanByName(Salesman *head, const char *name)		//����1��ʾɾ���ɹ���0��ʾû�иü�¼ 
{
	Salesman *prev = head;
	Salesman *curr = head->next;
	int isExist = 0; 
	
	while (curr != NULL)
	{
		if (strcmp(curr->name, name) == 0)		//������Ϊname�ļ�¼ȫ��ɾ�������ǵ�ͬ��ͬ�գ� 
		{
			prev->next = curr->next;
			free(curr);
			isExist = 1;
			break;				
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	
	return isExist == 1 ? TRUE : FALSE;
}

BOOL DeleteSalesmanByNumber(Salesman *head, const char *number)		//����1��ʾɾ���ɹ���0��ʾû�иü�¼ 
{
	Salesman *prev = head;
	Salesman *curr = head->next;
	int isExist = 0; 
	
	while (curr != NULL)
	{
		if (strcmp(curr->number, number) == 0)
		{
			prev->next = curr->next;
			free(curr);
			isExist = 1;
			break;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	
	return isExist == 1 ? TRUE : FALSE;
}

Salesman **QuerySalesmanByName(const Salesman *head, const char *name)
{
	Salesman *curr = head->next;
	Salesman **array = (Salesman **) malloc (sizeof(Salesman*) * 10);
	int count = 0;
	
	while (curr != NULL)
	{
		if (strcmp(curr->name,name) == 0)
		{
			array[count++] = curr;
		}
		
		curr = curr->next;	
	}
	
	array[count] = NULL;	
	
	return count == 0 ? NULL : array;
}

Salesman *QuerySalesmanByNumber(const Salesman *head, const char *number)
{
	Salesman *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(curr->number, number) == 0)
		{
			break;
		}
		
		curr = curr->next;	
	}	
	
	return curr;
}

BOOL SaveSalesmanDataToFile(Salesman *head, const char *fileName)
{
	Salesman *curr = head->next;
	Salesman *prev = head;
	FILE *fp;
	
	if ((fp = fopen(fileName,"w")) == NULL)
   	{
   		perror(fileName);
		return FALSE;					
	}
	
	while (curr != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", curr->number, curr->name,
			curr->gender,curr->phone, curr->address,
			curr->birthDate, curr->employedDate);
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	
	free(prev);
	fclose(fp);
	
	return TRUE;
}

BOOL LoadSalesmanDataFromFile(Salesman *head, const char *fileName)
{
	Salesman *pNew;
	Salesman *pTail = head;
	FILE *fp;
	
   	if ((fp = fopen(fileName,"a+")) == NULL)
   	{
   		perror(fileName);
		return FALSE;								//exit(EXIT_FAILURE);	
	}
		
	while (!feof(fp))
	{
		pNew = (Salesman*) malloc (sizeof(Salesman));
		
		if (pNew == NULL)
		{
			return FALSE;
		} 
		
		if ((fscanf(fp, "%s%s%s%s%s%s%s", pNew->number, pNew->name, pNew->gender,
			pNew->phone, pNew->address, pNew->birthDate, pNew->employedDate)) != 7)
		{
			free(pNew);
			break;
		}
		
		pNew->next = NULL;
		pTail->next = pNew;
		pTail = pNew;
	}
	
	fclose(fp);
	
	return TRUE;
}
