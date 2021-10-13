#include"SalesManage.h"

BOOL AddProductInformation(ProductInformation *head, const ProductInformation *productInformation) 
{	
	ProductInformation *curr = head;
	 
	while (curr->next != NULL)
	{
		curr = curr->next;		//遍历至链表表尾 
	}
	
	curr->next = (ProductInformation *) productInformation;	//productInformation变量类型是const ProductInformation*，不能直接赋值给普通指针，需要用强制类型转换。 
	
	return TRUE; 
}

BOOL AddMarketingInformation(MarketingInformation *head, const MarketingInformation *marketingInformation) 
{	
	MarketingInformation *curr = head;
	 
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr->next = (MarketingInformation *) marketingInformation;
	
	return TRUE; 
}

BOOL UpdateProductInformation(ProductInformation *head, const ProductInformation *productInformation)
{
	ProductInformation *prev = head;
	ProductInformation *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(curr->name, productInformation->name) == 0)
		{
			prev->next = (ProductInformation *) productInformation;
			prev->next->next = curr->next;		//productInformation->next = curr->next;	由于const修饰只能读不能写所以用 prev->next替换 
			
			free(curr);
			
			break;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	return TRUE; 
}

BOOL DeleteProductByName(ProductInformation *head, const char *name)	
{
	ProductInformation *prev = head;
	ProductInformation *curr = head->next;
	int isExist = 0; 
	
	while (curr != NULL)
	{
		if (strcmp(curr->name, name) == 0)		
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

BOOL DeleteProductByNumber(ProductInformation *head, const char *code)		
{
	ProductInformation *prev = head;
	ProductInformation *curr = head->next;
	int isExist = 0; 
	
	while (curr != NULL)
	{
		if (strcmp(curr->code, code) == 0)
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

ProductInformation *QueryProductInformationByName(const ProductInformation *head, const char *name)
{
	ProductInformation *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(curr->name, name) == 0)
		{
			break;
		}
		
		curr = curr->next;	
	}	
	
	return curr;
}

MarketingInformation **QueryMarketingInformationByName(const MarketingInformation *head, const char *name)
{
	MarketingInformation *curr = head->next;
	MarketingInformation **array = (MarketingInformation**) malloc (sizeof(MarketingInformation*) * 10);
	int count = 0;
	
	while (curr != NULL)
	{
		if (strcmp(curr->productName, name) == 0)
		{
			array[count++] = curr;
		}
		
		curr = curr->next;	
	}	
	
	array[count] = NULL;
	
	return count == 0 ? NULL : array;
}

ProductInformation *QueryProductInformationByNumber(const ProductInformation *head, const char *code)
{
	ProductInformation *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(curr->code, code) == 0)
		{
			break;
		}
		
		curr = curr->next;	
	}	
	
	return curr;
}

MarketingInformation **QueryMarketingInformationByNumber(const MarketingInformation *head, const char *code)
{
	MarketingInformation *curr = head->next;
	MarketingInformation **array = (MarketingInformation**) malloc (sizeof(MarketingInformation*)*10);
	int count = 0;
	
	while (curr != NULL)
	{
		if (strcmp(curr->productCode, code) == 0)
		{
			array[count++] = curr;
		}
		
		curr = curr->next;	
	}	
	
	array[count] = NULL;
	
	return count == 0 ? NULL : array;
}

BOOL SaveProductInformationDataToFile(ProductInformation *head, const char *fileName)
{
	ProductInformation *curr = head->next;
	ProductInformation *prev = head;
	FILE *fp;
	
	if ((fp = fopen(fileName,"w")) == NULL)
   	{
   		perror(fileName);
		return FALSE;							
	}
	
	while (curr != NULL)
	{
		fprintf(fp, "%s\t%s\t%d\t%f\t%s\t%s\n", curr->code, curr->name, 
			curr->totalNumber, curr->unitPrice, curr->producer, curr->stockDate);
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	
	free(prev);
	fclose(fp);
	
	return TRUE;
}

BOOL SaveMarketingInformationDataToFile(MarketingInformation *head, const char *fileName)
{
	MarketingInformation *curr = head->next;
	MarketingInformation *prev = head;
	FILE *fp;
	
	if ((fp = fopen(fileName,"w")) == NULL)
   	{
   		perror(fileName);
		return FALSE;						
	}
	
	while (curr != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%f\t%s\t%s\n", curr->salesman, curr->customer,
		curr->customerPhone, curr->productName, curr->productCode, curr->amount,
		curr->unitPrice, curr->notes, curr->salesDate);
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	
	free(prev);
	fclose(fp);
	
	return TRUE;
}

BOOL LoadProductInformationDataFromFile(ProductInformation *head, const char *fileName)
{
	ProductInformation *pNew;
	ProductInformation *pTail = head;
	FILE *fp;
	
   	if ((fp=fopen(fileName,"a+")) == NULL)
   	{
   		perror(fileName);
		return FALSE;								
	}
		
	while (!feof(fp))
	{
		pNew = (ProductInformation *) malloc (sizeof(ProductInformation));
		
		if (pNew == NULL)
		{
			return FALSE;
		} 
		
		if ((fscanf(fp, "%s%s%d%f%s%s", pNew->code, pNew->name, &pNew->totalNumber, &pNew->unitPrice, 
			pNew->producer, pNew->stockDate)) != 6)
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

BOOL LoadMarketingInformationDataFromFile(MarketingInformation *head, const char *fileName)
{
	MarketingInformation *pNew;
	MarketingInformation *pTail = head;
	FILE *fp;
	
   	if ((fp=fopen(fileName,"a+")) == NULL)
   	{
   		perror(fileName);
		return FALSE;							
	}
		
	while (!feof(fp))
	{
		pNew = (MarketingInformation *) malloc (sizeof(MarketingInformation));
		
		if (pNew == NULL)
		{
			return FALSE;	
		} 
		
		if ((fscanf(fp, "%s%s%s%s%s%d%f%s%s", pNew->salesman, pNew->customer,
			pNew->customerPhone, pNew->productName, pNew->productCode, &pNew->amount,
			&pNew->unitPrice, pNew->notes ,pNew->salesDate)) != 9)
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
