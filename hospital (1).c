#include<stdio.h>
#include<stdlib.h>
#include<windows.h>//gotoxy()
#include<conio.h>//delay(),getch()
#include<ctype.h>//toupper(),tolower()
#include<string.h>
char ans=0;
int ok=0;
int b, valid=0;
  //FUNCTION DECLERATION 
 void welcome_screen(void);
 void title(void);
 void mainmenu(void);
 void login_screen(void);
 void Add_rec(void);
 void func_list(void);
 void search_rec(void); 
 void edit_rec(void);
 void dlt_rec(void);
 void ex_it(void);
 void gotoxy(short x,short y)
{
 	COORD pos ={x,y}; // sets co-ordinates in (x,y)
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
 // list of global variable 
struct patient 
{
  	int age ;
  	char gender;
  	char first_name[20];
  	char last_name[20];
    char contact_no[15];
 	char address [30];
  	char Email[30];
  	char doctor[20];
  	char problem[20];
};
struct patient p,temp_c;
int main()
{
	
  	welcome_screen();
  	title();
  	login_screen();
	return 0;
 }
 /***************************************************************welcome screem******************************************************************************************************/
void welcome_screen(void)//function for welcome screen 	
{
  	printf("\n\n\n\n\n\n\n\t\t\t\t******************************************");
  	printf("\n\t\t\t\t**\t\t WELCOME TO \t\t**");
  	printf("\n\t\t\t\t**    CITY HOSPITAL MANAGEMENT SYSTEM   **");
  	printf("\n\t\t\t\t******************************************");
  	printf("\n\n\n\n\n press any key to continue..........\n");
  	getch();
  	system("cls");//use to clear screen
} 
 /************************************************************title screen*********************************************************************************************************/
void title(void)//function for title screen
{
  	printf("\n\n\t\t--------------------------------------------------------------------------------------------------------------------");
  	printf("\n\t\t\t\t\t\t     CITY HOSPITAL     ");
  	printf("\n\n\t\t--------------------------------------------------------------------------------------------------------------------");
} 
   /************************************************************* main menu*******************************************************************************************************/
void mainmenu(void)
{
	system("cls");
  	int choose;
  	title();
  	printf("\n\n\n\t\t\t\t 1. Add Patients Record\n");
  	printf("\n\n\n\t\t\t\t 2. Lists Patients Record\n");
  	printf("\n\n\n\t\t\t\t 3. Search Patients Record\n");
  	printf("\n\n\n\t\t\t\t 4. Edit Patients Record\n");
  	printf("\n\n\n\t\t\t\t 5. Delete Patients Record\n");
  	printf("\n\n\n\t\t\t\t 6. Exit\n");
  	printf("\n\n\n\n\t\t\t\t choose from 1 to 6:");
	fflush(stdin);
  	scanf("%i",&choose);
  	switch(choose)
  	{
  	 	case 1:
  	 		Add_rec();
  	 		break;
  	 	case 2:
		    func_list();
		    break;
		case 3:
		    search_rec();
		    break;
		case 4:
			edit_rec();
			break;
		case 5:
		    dlt_rec();
		    break;
		case 6:
		    ex_it();
			break;
		default:
		    printf("\t\t\t\t Invalid entry! please enter right option : ");
		    getch();
	    }
    }
    /********************************************************************* exit screen*************************************************************************/
void ex_it(void)
{
	system("cls");
	title();
	printf("\n\n\n\n\n\t\t\t THANK YOU FOR VISITING \n");
	getch();
}
/********************************************************************** login screen******************************************************************************************/
void login_screen(void)
{
   // list of variables 
	int e =0;
	char username[15];
	char password[15];
	char original_username[25]="ABES";
	char original_password[25]="1011";
	do
	{
	 	printf("\n\n\n\n\t\t\t\t enter username and password : ");
	 	printf("\n\n\n\t\t\t\t\t USERNAME : ");
	 	scanf("%s",&username);
	 	printf("\n\n\n\t\t\t\t\t PASSWORD : ");
	 	scanf("%s",&password);
	 	if(strcmp(username,original_username)== 0 && strcmp(password,original_password)== 0)
	 	{
	 	    printf("\n\n\n\t\t\t\t\t......Login Successful.......");
		    getch();
			mainmenu();
			break;
		}
		else
		{
			printf("\n\t\t\t\t\t password is incorrect! try again :  ");
			e++;
			getch();
		}
	}while(e<=2);
	if(e>2)
	{
		printf(" you have cross the limit you cannot login: ");
		getch();
		ex_it();
	}
	system("cls");
}
	/************************************************************** add record*****************************************************************************/			 
void Add_rec (void)
{
    system("cls");
	title();
	// list of variables 
	char ans;
	FILE*ek;
	ek=fopen("record2.dat","a");// open file in write mode
	printf("\n\t\t\t\t\t\t************************** Add Patients Record ***************************\n");
	/************************************************* first name ******************************************************/
	A:
	printf("\n\t\t\t first name:");
	scanf ("%s",p.first_name);
	p.first_name[0]=toupper(p.first_name[0]);
	if(strlen(p.first_name)>20||strlen(p.first_name)<2)
	{
		printf("\n\t Invalid:\t the max range for firstname is 20 and min range is 2 ");
		goto A ;
	}
	else 
	{
		for(b=0;b<strlen(p.first_name);b++)
		{
			if(isalpha(p.first_name[b]))
			{
				valid=1;
			}
		else

		{

			valid=0;
			break;
		} 
	}
	if(!valid)
	{
		printf("\n\t\t\t first name contain invalid character!\n enter again : ");
		goto A;
	}
}
/************************************************ last name ***************************************************************/
    B:
 	printf("\n\t\t\t last name :");
	scanf ("%s",p.last_name);
	p.last_name[0]=toupper(p.last_name[0]);
	if(strlen(p.last_name)>20||strlen(p.last_name)<2)
	{
		printf("\n\t Invalid:\t the max range for last name is 20 and min range is 2 ");
		 goto  B;
	}
	else 
	{
		for(b=0;b<strlen(p.last_name);b++)
		{
			if(isalpha(p.last_name[b]))
			{
				valid=1;
			}
		    else
		    {
			    valid=0;
			    break;
		    } 
	    }
	    if(!valid)
	    {
		    printf("\n\t\t\t first name contain invalid character!\n enter again : ");
		    goto B;
	    }
    } 
	/****************************************************gender***************************************************************************/ 
    G:
      	printf("\n\t\t\t gender[F/M] : ");
      	fflush(stdin);
   	    scanf("%c",&p.gender);
   	    if(toupper(p.gender)== 'M'||toupper(p.gender)== 'F')
     	{
   		    ok=1;
   		}
	   else
	    {
	   	    ok=0;
	   	    printf("\n\t\t gender contain invalid character! (enter either M or F)");
		    goto G;
	    }
/********************************************************* age **************************************************************/
    printf("\n\t\t\t Age:");
    scanf("%i",&p.age);
/********************************************************** Address ********************************************************/
    do
    {
	    C:
        printf("\n\t\t\t address : ");
        scanf ("%s",p.address);
	    p.address[0]=toupper(p.address[0]);
	    if(strlen(p.address)>20||strlen(p.address)<4)
	    {
		    printf("\n\t Invalid:\t the max range for last name is 20 and min range is 4");
		    goto C;    
        }
    }while(!valid);
		
/****************************************************************** contact no.***************************************************************/
    do
    {
	    D:
	    printf("\n\t\t\t contact no :");
	    fflush(stdin);
	    scanf ("%s",p.contact_no);
	    if(strlen(p.contact_no)>10||strlen(p.contact_no)!=10)
	    {
		    printf("\n\t  sorry! Invalid contact number :\t  contact number must contain 10 digits enter again:");
		    goto D;
	    }
	    else 
	    {
		    for(b=0;b<strlen(p.contact_no);b++)
		    {
			    if(!isalpha(p.contact_no[b]))
			    {
				    valid=1;
			    }
		        else
		        {
			        valid=0;
			        break;
		        } 
	        }
	        if(!valid)
	        {
		        printf("\n\t\t\t contact number  contain invalid character!\n enter again : ");
		        goto D;
            }
        }
    }while(!valid);

/*************************************************************** E-mail*******************************************************************************************/
    do
    {
	    printf("\n\t\t\t E-mail :");
	    scanf ("%s",p.Email);
	    if(strlen(p.Email)>30||strlen(p.Email)<8)
	    {
		    printf("\n\t Invalid:\t the max range for last name is 30 and min range is 8 ");
	    }
    }while(strlen(p.Email)>30||strlen(p.Email)<8);
/***********************************************************************problem***********************************************************************************/
    E:
	printf("\n\t\t\t problem :");
	scanf ("%s",p.problem);
	p.problem[0]=toupper(p.problem[0]);
	if(strlen(p.problem)>15||strlen(p.problem)<3)
	{
		printf("\n\t Invalid:\t the max range for last name is 15 and min range is 3 ");
		goto E;
	}
	else 
	{
		for(b=0;b<strlen(p.problem);b++)
		{
			if(isalpha(p.problem[b]))
			{
				valid=1;
			}
	        else
		    {
			    valid=0;
			    break;
		    } 
	    }
	    if(!valid)
	    {
		    printf("\n\t\t\t problem contain invalid character!\n enter again : ");
		    goto E;
	    }
    }

/******************************************************************************prescribed doctor *************************************************************************/
    F:
    printf("\n\t\t\t prescribed doctor :");
	scanf ("%s",p.doctor);
	p.doctor[0]=toupper(p.doctor[0]);
	if(strlen(p.doctor)>30||strlen(p.doctor)<3)
	{
		printf("\n\t Invalid:\t the max range for doctor name  is 30 and  min range is 3 ");
		goto  F;
	}
	else 
	{
		for(b=0;b<strlen(p.doctor);b++)
		{
			if(isalpha(p.doctor[b]))
			{
				valid=1;
			}
		    else
		    {
			    valid=0;
			    break;
		    } 
	    }
	    if(!valid)
	    {
		    printf("\n\t\t\t doctor name  contain invalid character!\n enter again : ");
		    goto F;
	    }
    }
    fprintf(ek," %s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor);
    printf("\n\n\n\t\t\t\t.............INFORMATION RECORD SUCCESSFUL...........");
    fclose(ek);   // file closed 
    sd:
	getch();
	printf("\n\n\t\t Do you  want to add more record [Y/N]? ");
	fflush(stdin);
	scanf("%c",&ans);
	if(toupper(ans)=='Y')
	{
	    Add_rec();
	}
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t\t Thank You :");
		getch();
		mainmenu();
	}
	else
	{
		printf("\n\t\t\t Invalid Input \n");
		goto sd;
    }
}
			
    /******************************************************* view record **********************************************************/
	void func_list()
	{
		int row;
		system("cls");
		title();
		FILE *ek;
		ek=fopen("record2.dat","r");
		printf("\n\n\t\t\t\t ************************ List of Patients Record **************************\n");
		gotoxy(1,15);
		printf("full name");
	 	gotoxy(20,15);
		printf("gender");
	 	gotoxy(32,15);
		printf("age");
	 	gotoxy(37,15);
		printf("address");
	 	gotoxy(49,15);
		printf("contact no");
	 	gotoxy(64,15);
		printf("Email");
	 	gotoxy(88,15);
		printf("problem");
	 	gotoxy(98,15);
		printf("prescribed doctor \n");
		printf("==============================================================================================================================================================");
		
		
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor)!=EOF)
        {
       	gotoxy(1,row);
        printf("%s %s",p.first_name,p.last_name);
		gotoxy(20,row);
		printf("%c",p.gender);
		gotoxy(32,row);
		printf("%i",p.age);
		gotoxy(37,row);
		printf("%i",p.address);
		gotoxy(49,row);
		printf("%s",p.contact_no);
		gotoxy(64,row);
		printf("%s",p.Email);
		gotoxy(88,row);
		printf("%s",p.problem);
		gotoxy(98,row);
		printf("%s",p.doctor);
		row++;
	}
	fclose(ek);
	getch();
	mainmenu();
}

void search_rec()
{
	char name[20];
	system("cls");
	title();
	FILE *ek;
	ek=fopen("record2.dat","r");
	printf("\n\n\t\t\t*************** search patient record******************\n");
	gotoxy(12,8);
	printf("\n Enter Patient name to be viewed : ");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor)!=EOF)
       {
       	    if(strcmp(p.first_name,name)==0)
       	    {
       		    gotoxy(1,15);
       		    printf("fullname");
       			gotoxy(25,15);
		        printf("gender");
	 	        gotoxy(32,15);
		        printf("age");
	 	        gotoxy(37,15);
		        printf("address");
	 	        gotoxy(52,15);
		        printf("contact no");
	 	        gotoxy(64,15);
		        printf("Email");
	 	        gotoxy(80,15);
		        printf("problem");
	 	        gotoxy(95,15);
		        printf("prescribed doctor \n");
		        printf("========================================================================================================================================================");
       		    gotoxy(1,18);
                printf("%s %s",p.first_name,p.last_name);
	            gotoxy(25,18);
		        printf("%c",p.gender);
		        gotoxy(32,18);
		        printf("%i",p.age);
		        gotoxy(52,18);
		        printf("%s",p.contact_no);
		        gotoxy(64,18);
		        printf("%s",p.Email);
		        gotoxy(80,18);
		        printf("%s",p.problem);
		        gotoxy(95,18);
		        printf("%s",p.doctor);	
		        printf("\n");
				break;
            }
		}
	    if(strcmp(p.first_name,name)!=0)
	    {
		    gotoxy(5,10);
		    printf("record not found ! ");
		    getch();
	    }
	    fclose(ek);
	    L:
		getch();
		printf("\n\t\t\t do you want to view more[Y/N] ? ");
		scanf("%c",&ans);
		if(toupper(ans)=='Y')
		{
			search_rec();
		}
		else if(toupper(ans)=='N')
		{
			printf("\n\t\t Thank You ");
			getch();
			mainmenu();
		}
		else 
		{
			printf("\n\t Invalid Input : \n");
			goto L;
		}
	}
	/**********************************************************edit record ******************************************************************/
void edit_rec(void)
{
    FILE *ek,*ft;
	int i,b,valid=0;
	char ch;
	char name[20];
	system("cls");
	title();
	ft=fopen("temp2.dat","w+");
	ek=fopen("record2.dat","r");
	if(ek==NULL)
	{
		printf("\n\t\t cannot open file!");
		getch();
		mainmenu();
	}
	printf("\n\t\t\t************************ Edit Patient Record****************************\n");
	gotoxy(12,13);
	printf("enter the first name of the patient:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL)
	{
		printf("cannot open file!");
		getch();
		mainmenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor)!=EOF)
       {
       	if(strcmp(p.first_name,name)==0)
       	{
       		valid=1;
       		gotoxy(25,17);
       		printf("********************* Existing record **********************");
       		gotoxy(10,19);
       		printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s \n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor);
       		gotoxy(12,22);
       		printf("Enter new first name :");
       		scanf("%s",p.first_name);
       		gotoxy(12,24);
       		printf("Enter last name:");
       		scanf("%s",p.last_name);
       		gotoxy(12,26);
		    printf(" Enter gender:");
		    scanf("%c",p.gender);
		    p.gender=toupper(p.gender);
	 	    gotoxy(12,28);
		    printf(" Enter age:");
		    scanf("%i",&p.age);
	 	    gotoxy(12,30);
		    printf(" Enter address:");
		    scanf("%s",p.address);
			p.address[0]=toupper(p.address[0]);
	 	    gotoxy(12,32);
		    printf(" Enter contact no");
			scanf("%s",p.contact_no);
	 	    gotoxy(12,34);
		    printf("Enter E-mail");
		    scanf("%s",p.Email);
	 	    gotoxy(12,36);
            printf(" Enter problem");
			scanf("%s",p.problem);
	 	    p.problem[0]=toupper(p.problem[0]);
		    gotoxy(12,38);
		    printf(" Enter prescribed doctor");
		    scanf("%s",p.doctor);
			p.doctor[0]=toupper(p.doctor[0]);
			printf("\n Press U for updating operation : ");
            ch=getche();
		    if(ch=='u'||'U');
		    {
			    fprintf(ft,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor);
			    printf("\n\n\t\t\t Patient record Updated Successfully........");
		    }			
	    }
	    else 
	    {
		    fprintf(ft,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor);
		}
    }
    if(!valid)
    {
	    printf("\n\t\t No record Found ....");
    }
    fclose(ft);
    fclose(ek);
    remove("record2.dat");
    rename("temp2.dat","record2.dat");
    getch();
    mainmenu();
}
void dlt_rec()
{
	char name[20];
	int found =0;
	system("cls");
	title();
	FILE *ek,*ft;
	ft=fopen("temp_file2.dat","w+");
    ek=fopen("record2.dat","r");
	printf("\n\n\t\t\t*************** delete patient record******************\n");
	gotoxy(12,8);
	printf("\n Enter Patient name to be delete : ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor)!=EOF);
       {
       	    if(strcmp(p.first_name,name)!=0)
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor);
       		else
			{
       			printf("%s %s %c %i %s %s %s %s %s\n ",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.Email,p.problem,p.doctor);
       			found=1;
       		}
       	}
       	if(found==0)
		   {
		   	printf("\n\n\n\t\t\t Record not found.........");
		   	getch();
		   	mainmenu();
		   }
		   else
		   {
		   	fclose(ek);
		   	fclose(ft);
		   	remove("record2.dat");
			rename("temp_file2.dat","record2.dat");
			printf("\n\n\t\t\t Record Deleted successfully......");
			getch();
			mainmenu();
		}
    }			   		
       	
			
	   
	 	
				    
  
    
