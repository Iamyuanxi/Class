#include"SalesManage.h"

BOOL AddCustomer(Customer *head, const Customer *customer) 				//添加 
{	
	Customer *curr = head;
	 
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr->next = (Customer *) customer;
	
	return TRUE;
}

BOOL UpdateCustomer(Customer *head, const Customer *customer)			//修改 
{
	Customer *prev = head;
	Customer *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(customer->name, curr->name) == 0)
		{
			prev->next = (Customer *) customer;
			prev->next->next = curr->next;
			
			free(curr);
			
			break;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	return TRUE;
}

BOOL DeleteCustomerByName(Customer *head, const char *name)				//删除 
{
	Customer *prev = head;
	Customer *curr = head->next;
	int isExist = 0; 
	
	while (curr != NULL)
	{
		if (strcmp(name, curr->name) == 0)		
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

Customer *QueryCustomerByName(const Customer *head, const char *name)			//查找 
{
	Customer *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(name,curr->name) == 0)
		{
			break;
		}
		
		curr = curr->next;	
	}	
	
	return curr;
}

BOOL SaveCustomerDataToFile(Customer *head, const char *fileName)				//保存 
{
	Customer *curr = head->next;
	Customer *prev = head;
	FILE *fp;
	
	if ((fp = fopen(fileName,"w")) == NULL)
   	{
   		perror(fileName);
		return FALSE;
	}
	
	while (curr != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\n", curr->name, curr->phone, curr->address);
		free(prev);
		prev = curr;
		curr = prev->next;
	}
	
	free(prev);
	fclose(fp);
	
	return TRUE;
}

BOOL LoadCustomerDataFromFile(Customer *head, const char *fileName)				//打开 
{
	Customer *pNew;
	Customer *pTail = head;
	FILE *fp;
	
   	if ((fp=fopen(fileName,"a+")) == NULL)
   	{
   		perror(fileName);
		return FALSE;								//exit(EXIT_FAILURE);	
	}
		
	while (!feof(fp))
	{
		pNew = (Customer *) malloc (sizeof(Customer));
		
		if (pNew == NULL)
		{
			return FALSE;
		}
		
		if ((fscanf(fp, "%s%s%s", pNew->name, pNew->phone, pNew->address)) != 3)
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
