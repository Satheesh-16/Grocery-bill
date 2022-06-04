#include<stdio.h>
#include<string.h>
struct Customer_details
{
	char name[20];
	int cus_id,no_of_bills;
	float Cus_Total_Amount;
}customer[40];


struct Item_details
{
	char it_name[40],date[40];
	int count_of_items;
	float price,weight;
}ItemLi[40];

struct Bill_item{
	char item_name[20];
	int quantity;
	float price,Ind_amount;
};
struct Billing_func
{
	char B_date[40],B_name[20];
	int B_cus_id;
	int list_items,*bill_no;
	float B_Total_Amount;
	struct Bill_item Bill_it[40];
}Billing[40];

int check_item(char *s,int l){
	int i;
	for(i=0;i<=l;i++){
		if(ItemLi[i].it_name == s){
			return 1;
		}
	}
}


//int check_quantity(char s[],int l){
//	int i=0;
//	for(i=0;i<l;i++){
//		if()
//	}
//}


int main()
{
	int i=0,j=0,cus=-1,item=-1,bill=-1,choi,cus_check=0;
	long long int b_no;
	int exit=1;
	while(exit){
		int ch;
		printf("\n----------------------------------Welcome to the Store--------------------------------------------\n");
		printf("1. Create Customer\n2. Create Item\n3. Create Bill\n4. Display Overall Bill list\n5. Show bill by bill number\n6. Bills for a customer\n");
		printf("7. Total sales to a customer\n8. Display Total customer Details\n9. Display Total Item in Store\n10. Exit");
		printf("\n\nEnter Your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				cus++;
				printf("Enter Customer Name : ");
				scanf("%s",customer[cus].name);
				printf("Enter Customer id : ");
				scanf("%d",&customer[cus].cus_id);
				customer[cus].no_of_bills = 0;
				customer[cus].Cus_Total_Amount = 0.0;
				break;
			case 2:
				item++;
				printf("\nEnter Item Name : ");
				scanf("%s",ItemLi[item].it_name);
				printf("Enter Number of items : ");
				scanf("%d",&ItemLi[item].count_of_items);
				printf("Enter price : ");
				scanf("%f",&ItemLi[item].price);
				printf("Enter Date : ");
				scanf("%s",ItemLi[item].date);
				printf("Enter weight : ");
				scanf("%f",&ItemLi[item].weight);
				break;
			case 3:
				if(item==-1){
					printf("Sorry!!! No Items Available in the Store");
				}
				else{
					bill++;
					int ch2,it_ch=-1;
					printf("\nEnter Customer Name : ");
					scanf("%s",Billing[bill].B_name);
					printf("Enter Customer Id : ");
					scanf("%d",&Billing[bill].B_cus_id);
					printf("Enter Date : ");
					for(i=0;i<=cus;i++){
						if(Billing[bill].B_cus_id == customer[i].cus_id){
							cus_check=1;
						}
					}
					if(cus_check){
					}
					else{
						cus++;
						strcpy(customer[cus].name,Billing[bill].B_name);
						customer[cus].cus_id = Billing[bill].B_cus_id;
						customer[cus].no_of_bills = 0;
						customer[cus].Cus_Total_Amount = 0.0;
					}
					scanf("%s",Billing[bill].B_date);
					Billing[bill].bill_no = &Billing[bill].B_cus_id;
					printf("Your Bill Number : %d",Billing[bill].bill_no);
					
					printf("\n==========================================================================================================================\n");
					printf("Item_name\t\t\tNumber of items\t\t\tPrice\t\t\tDate\t\t\tWeight\n");
					printf("==========================================================================================================================\n");
					for(i=0;i<=item;i++){
						printf("\n%s\t\t\t\t%d\t\t\t\t%.2f\t\t\t%s\t\t%.3f",ItemLi[i].it_name,ItemLi[i].count_of_items,ItemLi[i].price,ItemLi[i].date,ItemLi[i].weight);
					}
					
					
					do{
						it_ch++;               //for adding items in the list
						printf("\nEnter Item Name : ");
						scanf("%s",Billing[bill].Bill_it[it_ch].item_name);
						if(check_item(Billing[bill].Bill_it[it_ch].item_name,item)){
								printf("Enter Price of the Item : ");
								scanf("%f",&Billing[bill].Bill_it[it_ch].price);
								printf("Enter Quantity of the item : ");
								scanf("%d",&Billing[bill].Bill_it[it_ch].quantity);
								Billing[bill].Bill_it[it_ch].Ind_amount=((Billing[bill].Bill_it[it_ch].quantity)*(Billing[bill].Bill_it[it_ch].price));
								Billing[bill].B_Total_Amount+=Billing[bill].Bill_it[it_ch].Ind_amount;
						}
						else {
							printf("Required Product is Not available\n");
						}
						printf("Enter 1 for add item and 0 for no item addition : ");
						scanf("%d",&ch2);
					}while(ch2);
					Billing[bill].list_items = it_ch;
					for(i=0;i<=cus;i++){
						if(Billing[bill].B_cus_id == customer[i].cus_id){
							customer[i].Cus_Total_Amount += Billing[bill].B_Total_Amount;
							customer[i].no_of_bills++;
						}
					}
					}
				
				break;
			case 4:
				for(i=0;i<=bill;i++){
					printf("\n\t\tZoho Company\t\t\n");
					printf("%s\t\t%s\n",Billing[i].B_name,Billing[i].B_date);
					printf("%d\n",Billing[i].B_cus_id);
					printf("=====================================================================================\n");
					printf("Item_name\t\tQuantity\t\tPrice\t\t\tAmount\n");
					printf("=====================================================================================\n");
					for(j=0;j<=Billing[i].list_items;j++){
						printf("\n%s\t\t\t%d\t\t\t%f\t\t\t%f",Billing[i].Bill_it[j].item_name,Billing[i].Bill_it[j].quantity,Billing[i].Bill_it[j].price,Billing[i].Bill_it[j].Ind_amount);
					}
					printf("\n\nTotal Amount\t\t\t\t\t%f",Billing[i].B_Total_Amount);
				}
				break;
			case 5:
				printf("Enter Bill no : ");
				scanf("%lld",&b_no);
				for(i=0;i<=bill;i++){
					int *x;
					x = (int*) b_no;
					if(x == (Billing[i].bill_no)){
					printf("\n\t\t------------------------Zoho Company------------------------\t\t\n\n");
					printf("%s\t\t%s\\t%p\n",Billing[i].B_name,Billing[i].B_date,Billing[i].bill_no);
					printf("%d\n",Billing[i].B_cus_id);
					printf("=====================================================================================\n");
					printf("Item_name\t\tQuantity\t\tPrice\t\t\tAmount\n");
					printf("=====================================================================================\n");
					for(j=0;j<=Billing[i].list_items;j++){
						printf("\n%s\t\t\t%d\t\t\t%f\t\t\t%f",Billing[i].Bill_it[j].item_name,Billing[i].Bill_it[j].quantity,Billing[i].Bill_it[j].price,Billing[i].Bill_it[j].Ind_amount);
					}
					printf("\nTotal Amount\t\t\t\t\t\t%f",Billing[i].B_Total_Amount);
					}
				}
				break;
			case 6:
				printf("Enter Customer Id : ");
				scanf("%d",&choi);
				if(cus==-1){
					printf("No customer id is created");
				}
				else{
					for(i=0;i<=cus;i++){
					if(customer[i].cus_id == choi){
						printf("Number of Bills : ");
						printf("%d ",customer[i].no_of_bills);
					}
				}
				}
				
				break;
			case 7:
				printf(" Enter Customer id : ");
				int cd;
				scanf("%d",&cd);
				printf("Customer\t\tCustomer id\t\tTotal Sales Amount\n");
				for(i=0;i<=cus;i++){
					if(cd == customer[i].cus_id){
						printf("  %s\t\t\t%d\t\t\t%.2f",customer[i].name,customer[i].cus_id,customer[i].Cus_Total_Amount);
					}
				}
				break;
			case 8:
				printf("\n==========================================================================================================================\n");
				printf("Customer Name\t\t\tCustomer id\t\tNo Of Bills\t\tTotal Amount\n");
				printf("============================================================================================================================\n");
				for(i=0;i<=cus;i++){
					printf("\n%s\t\t\t%d\t\t\t%d\t\t\t%.2f",customer[i].name,customer[i].cus_id,customer[i].no_of_bills,customer[i].Cus_Total_Amount);
				}
				printf("\n \n");
				break;
			case 9:
				printf("\n==========================================================================================================================\n");
				printf("Item_name\t\t\tNumber of items\t\t\tPrice\t\t\tDate\t\t\tWeight\n");
				printf("==========================================================================================================================\n");
				for(i=0;i<=item;i++){
					printf("\n%s\t\t\t\t%d\t\t\t\t%.2f\t\t\t%s\t\t%.3f",ItemLi[i].it_name,ItemLi[i].count_of_items,ItemLi[i].price,ItemLi[i].date,ItemLi[i].weight);
				}
				printf("\n \n");
				break;
			case 10:
				exit = 0;
				break;
			default:
				printf("Enter Correct Choice!!!\n");
				break;
		}
	}
	return 0;
}
