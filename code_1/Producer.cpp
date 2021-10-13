#include"SalesManage.h"

BOOL AddProducer(Producer *head, const Producer *producer) 
{	
	Producer *curr = head;
	
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr->next = (Producer *) producer;
	
	return TRUE; 
}

BOOL UpdateProducer(Producer *head, const Producer *producer)	
{
	Producer *prev = head;
	Producer *curr = head->next;
	
	while (curr != NULL)
	{
		if (strcmp(curr->name, producer->name) == 0)
		{
			prev->next = (Producer *) producer;
			prev->next->next = curr->next;
			
			free(curr);
			
			break;
		}
		
		prev = curr;
		curr = curr->next;
	}
	
	return TRUE; 
}

BOOL DeleteProducerByName(Producer *head, const char *name)		
{
	Producer *prev = head;
	Producer *curr = head->next;
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

Producer *QueryProducerByName(const Producer *head, const char *name)
{
	Producer *curr = head->next;
	
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

BOOL SaveProducerDataToFile(Producer *head, const char *fileName)
{
	Producer* curr = head->next;
	Producer* prev = head;
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
		curr = curr->next;
	}
	
	free(prev);
	fclose(fp);
	
	return TRUE;
}

BOOL LoadProducerDataFromFile(Producer* head, const char* fileName)
{
	Producer* pNew;
	Producer* pTail = head;
	FILE *fp;
	
   	if ((fp = fopen(fileName,"a+")) == NULL)
   	{
   		perror(fileName);
		return FALSE;									
	}
		
	while (!feof(fp))
	{
		pNew = (Producer *) malloc (sizeof(Producer));
		
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
