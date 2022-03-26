#include<stdio.h>
#include<string.h>
#include<stdlib.h>


double price[7] = {55.80 , 30.50 , 50.00 , 35.00 , 59.00 , 99.00 , 150.00 };
double mealTaxPrices[7];
int adultNumber,childNumber;


void printMeals();
void orderMeals();
double orderForAdult();
double orderForChildren();
int main()
{
    char response = 'y';
    
     
     printMeals();
     while(response == 'y'|| response == 'Y')
    {
            printf("please enter number of adults  :");
            scanf("%d",&adultNumber);
            
            printf("please enter number of children:");
            scanf("%d",&childNumber);
            
                       
            orderMeals();
            
            printf("\nwould you like to continue(y/n):");
            scanf("\n%c",&response);
    }
  
 printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
   system("pause");
   return 0;
}

void printMeals()
{
     
      printf("\20*******************  WELCOME TO CAFETERIA **************************\20\n");
      printf(" \t\t\t Below is the menue:\20\n");
      printf(" \t\t\t MEALS\t\t\tPRICE:\n");
      printf(" \t\t\t \22*******************************\22\n");
      printf(" \t\t\t 1- OREO MILK SHAKE\t\tRS55.80\n");
      printf(" \t\t\t 2- LEMON ICE TEA\t\tRS30.50\n");
      printf(" \t\t\t 3- COLD COFFEE\t\t\tRS50.00\n");
      printf(" \t\t\t 4- GARLIC BREAD\t\tRS35.00\n");
      printf(" \t\t\t 5- CHEESY VEGGIE BURGER\t\tRS59.00\n");
      printf(" \t\t\t 6- EXOTIC VEGGIE PIZZA\t\t\tRS99.00\n");
      printf(" \t\t\t 7- SAUCY VEG NOODLES\t\t\tRS150.00\n");
      
      
      
      printf("\n");
}
void orderMeals()
{
	double totalPriceForAdult, totalPriceForChildren;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");  
         
         
        totalPriceForAdult =  orderForAdult();
        totalPriceForChildren = orderForChildren();
		allPayment = totalPriceForAdult + totalPriceForChildren ;
        
     printf("\n \t\t     \22**************************************\22    \n");
     printf(" \t\t   ******************  final BILL   ************      \n");
     printf(" \t\t\tadult/child\tcount\t\ttotal price\n");
     printf(" \t\t\tadults\t\t%d\t\t%5.2f\n",adultNumber,totalPriceForAdult);
     printf(" \t\t\tchildren\t%d\t\t%5.2f\n",childNumber,totalPriceForChildren);
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );
      
	 
     
     if(allPayment < 10)
		 discount=((allPayment * 0.5)/100);
     else if(allPayment>= 10 && allPayment<20)
          discount=((allPayment * 1)/100);
     else if(allPayment>= 20 && allPayment<30)
          discount=((allPayment * 1.5)/100);
     else if(allPayment>= 30 && allPayment<40)
          discount=((allPayment * 2.0)/100);
	 else 
		  discount= ((allPayment * 5.0)/100);

          printf(" \t\t\tTotal bill after discount\t%5.2f\n",allPayment-discount);

}
double orderForAdult()
{
     int menuOption,i,amount;
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0;
      if(adultNumber <=0)
		   printf("\n ");
	  else 
      printf("*\tadults:\n");
      for(i=0;i<adultNumber;i++)
     {
               printf("adult %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \n try again! ");
								  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);
                              
                              
                           totalPerPerson = totalPerPerson + (amount * price[menuOption - 1] );
                              
                              printf("\nWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);
               
                              
                           
               }
               printf("\n");
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }
     
     return totalAllPerson + ((totalAllPerson * tax) / 100);
}
double orderForChildren()
{
       int menuOption,i,amount;
      char response = 'y';
      double totalPerChild = 0.0,totalAllChildren = 0.0;
      double tax = 5.0,oneOrder;
       if(childNumber <=0)
		   printf("\n");
	   else
       printf("*\tChildren:\n");
       for(i=0;i<childNumber;i++)
     {
               printf("child %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \n try again! ");
                                  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);
                              
                              oneOrder = (price[menuOption - 1] * 60)/100 ;//this one order for a child with discount %60 of one order of adult
                              totalPerChild = totalPerChild + (amount * oneOrder)  ;
                              
							  printf("Would you like to enter more orders(y/n):");
                              scanf("\n%c",&response);
                              
                           
               }
               totalAllChildren += totalAllChildren +  totalPerChild;
               response = 'y';
               totalPerChild = 0.0;
               
               printf("\n");
               
     }
     
     return totalAllChildren + ((totalAllChildren * tax) / 100);
}

