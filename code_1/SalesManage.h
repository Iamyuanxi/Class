#ifndef SALESMANAGE_H
#define SALESMANAGE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMSIZE 10
#define NAMESIZE 30
#define DATESIZE 12
#define PHONENUMSIZE 15
#define GENDERSIZE 8
#define FALSE 0
#define TRUE 1

typedef int BOOL;

typedef struct Salesman               //人员信息 
{
    char number[NUMSIZE];
	char name[NAMESIZE];
	char gender[GENDERSIZE];
	char birthDate[DATESIZE];
	char phone[PHONENUMSIZE];
	char address[80];
	char employedDate[DATESIZE];
	struct Salesman *next ;
}Salesman;

typedef struct ProductInformation               //产品信息  
{
    char code[NAMESIZE];
	char name[NAMESIZE];
	int totalNumber;
	float unitPrice;
	char producer[NAMESIZE];
	char stockDate[DATESIZE];
	struct ProductInformation *next;
}ProductInformation;

typedef struct MarketingInformation                  //销售信息 
{
	char salesman[NAMESIZE];
	char customer[NAMESIZE];
	char customerPhone[PHONENUMSIZE];
	char productName[NAMESIZE];
	char productCode[NAMESIZE];
	int amount;
	float unitPrice;
	char notes[30];
	char salesDate[DATESIZE];
	struct MarketingInformation *next;
}MarketingInformation;

typedef struct Producer               //进货商信息 
{
    char name[NAMESIZE];
	char phone[PHONENUMSIZE];
	char address[50];
	struct Producer *next;
}Producer;

typedef struct Customer               //顾客信息 
{
    char name[NAMESIZE];
	char phone[PHONENUMSIZE];
	char address[50];
	struct Customer *next;
}Customer;

//函数声明
//Salesman
BOOL AddSalesman(Salesman *head, const Salesman *salesman);
BOOL UpdateSalesman(Salesman *head, const Salesman *salesman);
BOOL DeleteSalesmanByName(Salesman *head, const char *name);
BOOL DeleteSalesmanByNumber(Salesman *head, const char *number);
Salesman **QuerySalesmanByName(const Salesman *head, const char *name);
Salesman *QuerySalesmanByNumber(const Salesman *head, const char *number);
BOOL SaveSalesmanDataToFile(Salesman *head, const char *fileName);
BOOL LoadSalesmanDataFromFile(Salesman *head, const char *fileName); 
//Product
BOOL AddProductInformation(ProductInformation* head, const ProductInformation* productInformation);
BOOL AddMarketingInformation(MarketingInformation* head, const MarketingInformation* marketingInformation);
BOOL UpdateProductInformation(ProductInformation* head, const ProductInformation* productInformation);
BOOL DeleteProductByName(ProductInformation* head, const char* name);
BOOL DeleteProductByNumber(ProductInformation* head, const char* number);
ProductInformation* QueryProductInformationByName(const ProductInformation* head, const char* name);
MarketingInformation** QueryMarketingInformationByName(const MarketingInformation* head, const char* name);
ProductInformation* QueryProductInformationByNumber(const ProductInformation* head, const char* code);
MarketingInformation** QueryMarketingInformationByNumber(const MarketingInformation* head, const char* code);
BOOL SaveProductInformationDataToFile(ProductInformation* head, const char* fileName);
BOOL SaveMarketingInformationDataToFile(MarketingInformation* head, const char* fileName);
BOOL LoadProductInformationDataFromFile(ProductInformation* head, const char* fileName);
BOOL LoadMarketingInformationDataFromFile(MarketingInformation* head, const char* fileName);
//Producer
BOOL AddProducer(Producer* head, const Producer* producer);
BOOL UpdateProducer(Producer* head, const Producer* producer);
BOOL DeleteProducerByName(Producer* head, const char* name);
Producer* QueryProducerByName(const Producer* head, const char* name);
BOOL SaveProducerDataToFile(Producer* head, const char* fileName);
BOOL LoadProducerDataFromFile(Producer* head, const char* fileName);
//Customer
BOOL AddCustomer(Customer *head, const Customer *customer);
BOOL UpdateCustomer(Customer *head, const Customer *customer);
BOOL DeleteCustomerByName(Customer *head, const char *name);
Customer *QueryCustomerByName(const Customer *head, const char *name);
BOOL SaveCustomerDataToFile(Customer *head, const char *fileName);
BOOL LoadCustomerDataFromFile(Customer *head, const char *fileName);
#endif
