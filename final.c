#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	int day;
	int month;
	int year;
}DATE;
typedef struct {
	char Name[20];
	float Price;
}PRODUCTO;


	


typedef struct {
	/* TODO (#1#): USE STRUCT */
	PRODUCTO Produto;
	char Nome[50];
	char ID_cliente[50];	
	char telephone[20];
	int Quantidade; //int is not too small?
	float Value;
//	int day; this also destroyed whole save
//	int month;
//	int year;
	DATE date;
}CUSTOMER;



char menu_main(void)
{
	system("cls");
	char option;
	printf("\tMAIN MENU\nSelect from menu below:\n");
	printf("A-Anonymize\tM-Marketing\nR-root menu\tS-Sair(Out)");
	printf("\n\tSelection:");
	option = getch();
}

void createFile(char *FileName)
{
	FILE *fp = NULL;
	
	fp = fopen (FileName, "rb");
	if (fp == NULL)
		fp = fopen(FileName, "wb");
	fclose(fp);
}

int menu_product(void)
{
	int option;
	printf("\nSelect product from menu below:\n");
	printf("1 - Premium\n2 - GoldFunds\n3-Premium funds\n4 - PremiumPlus");
	printf("\nSelection:");
	scanf("%d",&option);
	return option;
}

PRODUCTO newProduct(void)
{
	PRODUCTO product;
	
	
	system("cls");
	
	fflush(stdin);
	
	printf("Enter product name\n:");
	gets(product.Name);
	
	printf("Enter the price:");
	scanf("%f",&product.Price);
	fflush(stdin);
}

/* TODO (#1#): maybe create only function saveObject2File
 */
void saveProductToFile(char *filename)
{	

	FILE *fp = NULL;
	PRODUCTO product, productFromFile;
	int productExists = 0;
	
	
	
	fp = fopen(filename, "ab+");
	if (fp == NULL)
	{
		printf("File open ERROR\a");
		getch();
		exit(1);	
	}
	
	product = newProduct();
	while(fread(&productFromFile, sizeof(PRODUCTO),1 , fp) != 0 )
	{
		if (strcmp(productFromFile.Name,product.Name)==0 ) //why it is not working
		{
			printf("This product already exists. Press any key to continue.\a\n");
			getch();
			productExists = 1;
			break;
		}
	}
	
	
	
	if (productExists == 0)
	{
		fseek(fp, 0L, SEEK_END);
		fwrite(&product, sizeof(PRODUCTO), 1, fp);
		fclose(fp);
	}
	
}

int insertProduct(char* Name)
{
	CUSTOMER info;
	

	PRODUCTO Premium;
		strcpy(Premium.Name,"Premium");
		Premium.Price = 5;
	
	PRODUCTO Gold_funds;
		strcpy(Gold_funds.Name,"Gold funds");
		Gold_funds.Price = 10;

	PRODUCTO Premium_funds;
		strcpy(Premium_funds.Name,"Premium funds");
		Premium_funds.Price = 15;
	PRODUCTO Premium_Plus;
		strcpy(Premium_Plus.Name,"Premium Plus");
		Premium_Plus.Price = 20;
		
	if(strcmp(info.Produto.Name,Premium.Name))
		return Premium.Price;
	else if(strcmp(info.Produto.Name,Gold_funds.Name))
		return Gold_funds.Price;
	else if(strcmp(info.Produto.Name,Premium_funds.Name))
		return Premium_funds.Price;	
	else if(strcmp(info.Produto.Name,Premium_Plus.Name))
		return Premium_Plus.Price;		
}

PRODUCTO insertProducts(char *filename)
{
	FILE *fp = NULL;
	
	PRODUCTO Premium;
		strcpy(Premium.Name,"Premium");
		Premium.Price = 5;
	
	PRODUCTO Gold_funds;
		strcpy(Gold_funds.Name,"Gold funds");
		Gold_funds.Price = 10;

	PRODUCTO Premium_funds;
		strcpy(Premium_funds.Name,"Premium funds");
		Premium_funds.Price = 15;
	PRODUCTO Premium_Plus;
		strcpy(Premium_Plus.Name,"Premium Plus");
		Premium_Plus.Price = 20;
		
	fp = fopen(filename, "ab+");
	if (fp == NULL)
	{
		printf("File open ERROR\a");
		getch();
		exit(1);	
	}
	
	fseek(fp, 0L, SEEK_END);
	fwrite(&Premium, sizeof(PRODUCTO), 1, fp);
	fwrite(&Gold_funds, sizeof(PRODUCTO), 1, fp);
	fwrite(&Premium_funds, sizeof(PRODUCTO), 1, fp);
	fwrite(&Premium_Plus, sizeof(PRODUCTO), 1, fp);
	fclose(fp);
//	return Premium,Gold_funds,Premium_funds,Premium_Plus;
}

char* product_t(char *product_type)
{
	int op;
	do{
		op=menu_product();
	{
		switch(op)
	{
//		product_type
		case 1: strcpy(product_type,"Premium");
		break;
		case 2: strcpy(product_type,"Gold funds");
		break;
		case 3: strcpy(product_type,"Premium funds");
		break;
		case 4: strcpy(product_type,"Premium Plus");
		break;
		default: break;
	}
	}
	}while(op=! 'x');
	return product_type;
}

float total(char *product,char *filename)
{	
	FILE *fp;
	CUSTOMER total;
	float sum=0;
	fp = fopen(filename,"rb");
	
	while(fread(&total, sizeof(CUSTOMER),1 , fp) != 0)
	{
		
		/* DONE (#1#): There is a problem with CPU
 */
//		if(total.Produto==product)
//		{sum = sum+total.Value;}
	}
//	return sum;
}


CUSTOMER newCustomer(void)
{
//	char XD[50];
	
	CUSTOMER customer;
//	DATE date;
	char XD[20];
	
	system("cls");
	
	fflush(stdin);
	
	printf("Enter customer ID:");
	gets(customer.ID_cliente);
	
	printf("Enter the customer name:");
	gets(customer.Nome);
	
	printf("Choose ordered product:");
//	gets(customer.Produto);

	strcpy(customer.Produto.Name,product_t(customer.Produto.Name));

//	printf("%s\n",customer.Produto);
	fflush(stdin);
	printf("Enter the phone number:");
	gets(customer.telephone);
	
	printf("Enter the amount:");
	scanf("%d", &customer.Quantidade);
	
//	printf("Enter the ordered value:");
//	scanf("%f", &customer.Value);
	
	
	while(1)
	{
	printf("Enter the order date:\nFORMAT dd/mm/yyyy\n");
	scanf("%d/%d/%d",&customer.date.day,&customer.date.month,&customer.date.year);
	if(customer.date.day>31){
		printf("\aThere is no more than 31 days in a month!\n");
		continue;
	}
	else if(customer.date.month>12){
		printf("\aThere is no more than 12 month in a year!\n");
		continue;
	}
	else if(customer.date.year<1920){
		printf("\aYour date looks old-fashioned!\n");
		continue;
	}
	else if(customer.date.day==0||customer.date.month==0||customer.date.year==0){
		printf("Write date in one string with format dd/mm/yyyy!\n\a");
		continue;		
	}
	else
		break;
	}
	return customer;
}



CUSTOMER anonimizedCustomer(void)
{	
	CUSTOMER customer, anonCust;
	
//	anonCust.Nome==CUSTOMER.Produto.Name;
	strcpy(anonCust.Nome,customer.Produto.Name);
//	anonCust.telephone=="### ### ###";
	strcpy(anonCust.telephone,"### ### ###");
//	anonCust.ID_cliente==&customer.ID_cliente;
//	anonCust.Produto==&customer.Produto;
//	anonCust.Quantidade==&customer.Quantidade;
//	anonCust.Value==&customer.Value;


	return anonCust;

}

//char date(int day,int month,int year)
//{	
//	char date[10];
//	
////	char* chDay[2] = day+'0';
////	char* chMonth[2] = month+'0';
////	char* chYear[4] = year='0';
//////	char aux3[10];
//	
//	if(day>31)
//		return -1;
//	else if(month>12)
//		return -1;
//	else
//		return 0;
//	
//	date = strcat(chDay,chMonth);
//	date = strcat(date,chYear);
//}

void anonimize(char *file_to_be_opened,char *file_to_be_written)
{
	CUSTOMER CUSTOMER,anonCustomer;
	
	createFile(file_to_be_written);
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	
	
	fp1 = fopen(file_to_be_opened,"rb");
	fp2 = fopen(file_to_be_written,"wb");
	

	
	if (fp1 == NULL||fp2 == NULL)
	{
		printf("File open ERROR 404");
		getch();
		exit(1);	
	}

	while(fread(&anonCustomer, sizeof(CUSTOMER),1 , fp1) != 0 )
	{
		strcpy(anonCustomer.Nome,anonCustomer.Produto.Name);
		strcpy(anonCustomer.telephone,"### ### ###");
		fwrite(&anonCustomer, sizeof(CUSTOMER), 1, fp2);
		
	}
	fclose(fp1);
	fclose(fp2);
}


void saveCustomerToFile(char *filename)
{	
	FILE *fp = NULL;
	CUSTOMER customer, customerFromFile;
	int customerExists = 0;
	
	
	
	fp = fopen(filename, "ab+");
	if (fp == NULL)
	{
		printf("File open ERROR\a");
		getch();
		exit(1);	
	}
	
	customer = newCustomer();
	while(fread(&customerFromFile, sizeof(CUSTOMER),1 , fp) != 0 )
	{
		if (strcmp(customerFromFile.ID_cliente,customer.ID_cliente)==0 ) //why it is not working
		{
			printf("This customer already exists. Press any key to continue.\a\n");
			getch();
			customerExists = 1;
			break;
		}
	}
	
	
	if (customerExists == 0)
	{
		fseek(fp, 0L, SEEK_END);
		fwrite(&customer, sizeof(CUSTOMER), 1, fp);
		fclose(fp);
	}
	
}

int password(void)
{
	int flag=0;
	char pass[5];
	char rp[5]="x";
	char phrase[30]="BAD PASS!\nCALLING THE POLICE";
	system("cls");
	printf("TYPE PASSWORD:");
	gets(pass);
	while(strcmp(pass,rp)!=0)
	{
		printf("\n%s\a",phrase);
		printf(".",phrase);
		printf(".",phrase);
		printf(".",phrase);
		system("cls");
	}
}

int menu_root(void)
{	
	system("cls");
	int op;
	printf("\tRoot menu\nL-customer list\tA - Add customer\nP - products list\tQ - add product\n\tB - back\n");
	op=getch();
	return op;
	system("cls");
	
}

int menu_marketing(void)
{
	system("cls");
	int op;
	printf("Marketing menu\nL - Product list\nS - Subscribtions\nb - back\n");
	op=getch();
	return op;
	
}

void printCustomer(CUSTOMER oneCustomer)
{
	float value;
//	strcmp(one)
	printf("\nCustomer ID: %s\n", oneCustomer.ID_cliente);
	printf("Customer name: %s\n", oneCustomer.Nome);
	printf("Product chosen: %s\n", oneCustomer.Produto.Name);
	printf("Product amount: %d\n", oneCustomer.Quantidade);
	printf("Phone number: %s\n", oneCustomer.telephone);
	printf("Date: %d/%d/%d\n",oneCustomer.date.day,oneCustomer.date.month,oneCustomer.date.year);
	printf("Value: %.2f\n", value=oneCustomer.Quantidade*insertProduct(oneCustomer.Produto.Name));
//	printf("Date: %d/%d/%d",oneCustomer.date.day,oneCustomer.date.month,oneCustomer.date.year);
}


void listAllCustomers(char *filename, char *filename1)
{	
	system("cls");
	FILE *fp = NULL;
	CUSTOMER customerFromFile;
	insertProducts(filename1);
	
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("File open ERROR");
		getch();
		exit(1);	
	}
	
	while(fread(&customerFromFile, sizeof(CUSTOMER),1 , fp) != 0)
	{
		printCustomer(customerFromFile);
	}
	fclose(fp);
	getch();
	system("cls");
}


void printProduct(PRODUCTO oneProduct)
{
	
	printf("Product name: %s\n", oneProduct.Name);
	printf("Product price: %f\n", oneProduct.Price);
//	printf("Date: %d/%d/%d",oneCustomer.date.day,oneCustomer.date.month,oneCustomer.date.year);
}


void listAllProducts(char *filename)
{	
	system("cls");
	FILE *fp = NULL;
	PRODUCTO productFromFile;
	
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("File open ERROR");
		getch();
		exit(1);	
	}
	
	while(fread(&productFromFile, sizeof(PRODUCTO),1 , fp) != 0)
	{
		printProduct(productFromFile);
	}
	fclose(fp);
	getch();
	system("cls");
}



void marketing(char *filename, char *filename1){
		system("cls");
	float sumP,sumGF,sumPf,sumPP;
//	char* P[20],GF[20],Pf[20],PP[20];
	
	
	PRODUCTO Premium;
		strcpy(Premium.Name,"Premium");
		Premium.Price = 5;
	
	PRODUCTO Gold_funds;
		strcpy(Gold_funds.Name,"Gold funds");
		Gold_funds.Price = 10;

	PRODUCTO Premium_funds;
		strcpy(Premium_funds.Name,"Premium funds");
		Premium_funds.Price = 15;
	PRODUCTO Premium_Plus;
		strcpy(Premium_Plus.Name,"Premium Plus");
		Premium_Plus.Price = 20;

	
	CUSTOMER marketingInfo,randomhuj;
	PRODUCTO productInfo;
	
	FILE *fp=NULL;	
	fp = fopen(filename,"rb");
		if (fp == NULL)
	{
		printf("File open ERROR");
		getch();
		exit(1);	
	}
	FILE *fp1=NULL;
	fp1 = fopen(filename1,"rb");
		if (fp1 == NULL)
	{
		printf("File open ERROR");
		getch();
		exit(1);	
	}
	
	fread(&productInfo,sizeof(PRODUCTO),1,fp1);
//	fread(&randomhuj, sizeof(CUSTOMER),1, fp);
	//&& fread(&productInfo, sizeof(PRODUCTO),1 , fp) != 0 
	while(fread(&marketingInfo, sizeof(CUSTOMER),1 , fp) != 0)
	
	/* DONE (#1#): Problem with data comparison, same with 
	               password function? */
	{
		/* TODO (#1#): POPRAWIÆ TUTAJ */
//		&&strcmp(productInfo.Name,"Premium")
		if(strcmp(marketingInfo.Produto.Name,Premium.Name)==0)
		{
			sumP+=productInfo.Price*marketingInfo.Quantidade;	
//			P = &productInfo.Name;
//			strcpy(P,productInfo.Name);
		}
		else if(strcmp(marketingInfo.Produto.Name,Gold_funds.Name)==0)
		{
			sumGF+=productInfo.Price*marketingInfo.Quantidade;	
//			GF=productInfo.Name;
		}
		else if(strcmp(marketingInfo.Produto.Name,Premium_funds.Name)==0)
		{
			sumPf+=productInfo.Price*marketingInfo.Quantidade;	
//			Pf=productInfo.Name;
		}
		else if(strcmp(marketingInfo.Produto.Name,Premium_Plus.Name))
		{
			sumPP+=productInfo.Price*marketingInfo.Quantidade;	
//			PP=productInfo.Name;
		}
		
	}
	printf("%s | %.2f |%.2f\n",Premium.Name,Premium.Price,sumP);
	printf("%s | %.2f\n",Gold_funds.Name,sumGF);
	printf("%s |%.2f\n",Premium_funds.Name,sumPf);
	printf("%s | %.2f",Premium_Plus.Name,sumPP);
//	printf("%.2f",sumGF);
	fclose(fp);
	getch();
	system("cls");
}


int main(int argc, char *argv[]) 
{	


	char op;
	char customer_list[] = "customers.dat";
	char file_to_be_aonimizied[]="Marketing.dat";
	char product_list[] = "produtos.dat";
	insertProducts(product_list);
	/* TODO (#1#): ADD EXTENDED ASCII */
	printf("%c%c%c%c%c\n",201,205,205,205,187);
	printf("%c%c%c%c%c\n",186,' ',"JEEBAAAC",' ',186);
	printf("%c%c%c%c%c\n",200,205,205,205,188);
	createFile(customer_list);
	int number;
	do{
		op = menu_main();
		op = toupper(op);
		
		switch(op)
		{
			case 'A': printf("Anonimize\n");
				anonimize(customer_list,file_to_be_aonimizied);
				listAllCustomers(file_to_be_aonimizied,product_list);
				system("cls");
				break;
			case 'M': printf("Marketing\n");
				{
					do{
					op=(menu_marketing());
					switch(op){
						case 'l':printf("Product list");{
							marketing(customer_list,product_list);
							
//							date(8,8,1998);
							system("cls");
							break;
						}
						case 'S':printf("Subscriptions\a");{
//							saveCustomerToFile(customer_list);
//							total("Premium",customer_list);
							system("cls");
							break;
						}
						
						case 'b':printf("\nback\n");{
							system("cls");
							break;
						}
						default:system("cls");
					}
				}while(op!='b');
				}
				break;
			case 'R': {
				password();
				printf("ROOT MENU\n");
				{
					do{
					op=(menu_root());
					switch(op){
						case 'l':printf("Customer List");{
							listAllCustomers(customer_list,product_list);
							break;
						}
						case 'a':printf("Add customer");{
							saveCustomerToFile(customer_list);
							break;
						}
						case 'p':printf("Product list");{
							listAllProducts(product_list);
							break;
						}
						case 'q':printf("Add product");{
							saveProductToFile(product_list);
							break;
						}
						
						case 'b':printf("\nback\n");{
							break;
						}
					}
				}while(op!='b');
				
				break;
				}
			default: break;
		}
		
			}

			   
	}while (op != 'S');
	
	return 0;
}


