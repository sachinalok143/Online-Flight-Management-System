#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/* all functions */
void remove_acc(char Id[]);
void reserve(char s1[]);
void cancle(char s1[]);
void available_flight(char s1[]);
int match(char s1[],char s2[]);
void user_resister();
void admin_resister();
void update_pass(char s1[]);
void manage_pass(char s1[]);
void manage(char s1[]);
void admin_selector(char s1[],FILE *fp);
void edit_profile(char s1[]);
void concate(char s1[]);
void concate1(char s1[],char s2[]);
void admin_login();
void selecter();
void user_login();
void flight_detail();
/* GLOBAL variables */

int seat_no;
char Name[20],Email_id[50],Password[10],Passenger_ID[20],Mgs[50],Source[20],Destination[20],Flight_No[20],Passport_No[10],Date[10],Time[5],meal[20];
char type_of_Flight[20],Type_of_class[20],Meal[20];
int Eco,PriEco,Bus,F,M,E1,PE1,B1,F1,M1;

void print_file(char s[])
{
  FILE *fp= fopen(s,"r");
  char str;
	while (fscanf(fp, "%c",&str)!=EOF)
        printf("%c",str);
     fclose(fp);
  /*while(!feof(file))
	{
	fgets(c,999,file);
	puts(s);
	}
    fclose(file);*/
}

void manage_pass(char s1[])
{
  FILE *adm=fopen("admin_res.txt","r");
  char s[]="admin_res.txt";
  print_file(s);
  /*char str[999];
    while (fscanf(adm, "%s", str)!=EOF)
    printf("%s",str);*/
  manage(s1);
  fclose(adm);
}

void admin_login()
{
  char s1[20],s2[20];
  printf("Admin ID:\nPassword:\n");
  scanf("%s%s",s1,s2);
  char s3[]="adm";
  concate1(s1,s3);
  concate(s1);
  FILE *fp=fopen(s1,"r");
  char Admin_ID[20], Name[20], Email_id[50], Contact_no[20], Password[20];
  if(fp==NULL)
    {
      puts("you are not Registered yet. please Register first.");
      selecter();
    }
  else
    {
      fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",Admin_ID,Name,Email_id,Contact_no,Password);
      puts(Password);
      if(match(s2,Password)==0)
        {
          puts("you entered wrong Password");
          fclose(fp);
          selecter();
        }
      else
        {
          puts("login successfully ");
          admin_selector(s1,fp);
        }
    }
}
int main()
{
  selecter();
  return 0;
}


void selecter()
{

  printf("select desired option\n1.User Register\t2.Admin Register\n3.User Login\t4.Admin Login\n");
  int a;
  scanf("%d",&a);
  switch(a){
  case 1:
    user_resister();
    break;
  case 2:
    admin_resister();
    break;
  case 3:
    user_login();
    break;
  case 4:
    admin_login();
    break;
  default :
    printf("Select a right choice.\n");
    selecter();
  }
}	
void concate(char s1[])
{
  int i,j;
  char s2[]=".txt";
  for(i = 0; s1[i] != '\0'; ++i);

  for(j = 0; s2[j] != '\0'; ++j, ++i)
    {
      s1[i] = s2[j];
    }
  s1[i] = '\0';
}
void concate1(char s1[],char s2[])
{
  int i,j;
  for(i = 0; s1[i] != '\0'; ++i);

  for(j = 0; s2[j] != '\0'; ++j, ++i)
    {
      s1[i] = s2[j];
    }
  s1[i] = '\0';
}
void user_resister()
{
  char s1[20];
  printf("Enter your Passenger ID:\n");
  scanf("%s",s1);
  concate(s1);
  FILE *fp=fopen(s1,"r");
  if(fp!=NULL)
    {
      fclose(fp);
      printf("you are already Register.Enter 1 for user_login.\n");
      selecter();
    }
  else
    {
      fp=fopen(s1,"w+");
      printf("Name:\nEmail id:\nChoose a Password:\nPassport No.:\nPassenger ID:\n");
      scanf("%s%s%s%s%s",Name,Email_id,Password,Passport_No,Passenger_ID);
      strcpy(Flight_No,"");
      strcpy(Source," ");
      strcpy(Destination,"");
      strcpy(Date,"");
      strcpy(Time,"");
      seat_no=0;
      strcpy(Mgs,"no_massage");
      fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
      fclose(fp);
    }
  selecter();
}
void admin_resister()
{

  char s1[20];
  printf("Enter your Admin ID:\n");
  scanf("%s",s1);
  char s3[]="adm";
  concate1(s1,s3);
  concate(s1);
  FILE *fp=fopen(s1,"r");
  char Admin_ID[20],Name[20],Email_id[50],Password[10],Contact_no[10];
  if (fp==NULL)
    {
      fp=fopen(s1,"w");
      printf("Admin id:\nName:\nEmail id:\nContact no.\nChoose a Password:\n");
      scanf("%s%s%s%s%s",Admin_ID,Name,Email_id,Contact_no,Password);	
      fprintf(fp,"%s\t%s\t%s\t%s\t%s\n",Admin_ID,Name,Email_id,Contact_no,Password);
      fclose(fp);
      selecter();
    }
  else
    {
      puts("please login you already Registered\n");
      selecter();
    }
}
int match(char s1[],char s2[])
{
  int i,l;
  if(strlen(s1)>strlen(s2))l=strlen(s1);else l=strlen(s2);
  for (i = 0; i < l; i++)
    if(s1[i]!=s2[i]) return 0;
  return 1;
}
void reserve(char s1[])
{
  printf("Eneter the flight no.:\n");
  char Flight_No1[20];
  scanf("%s",Flight_No);
  char s3[]="flt";
  concate1(Flight_No,s3);
  concate(Flight_No);
  FILE *pf=fopen(Flight_No,"r");
  fscanf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)",type_of_Flight,Flight_No1,Source,Destination,Date,Time,&Eco,&E1,&PriEco,&PE1,&Bus,&B1,&F,&F1,&M,&M1);
  printf("Type:%s\nFlight no.:%s\nSource:%s\nDestination:%s\nDate:%s\nTime:%s\nseats available:\nEconomy class(%d):%d\nPremium Economic class(%d):%d\nBussiness class(%d):%d\nFirst class(%d):%d\nMixed class(%d):%d\n",type_of_Flight,Flight_No,Source,Destination,Date,Time,E1,Eco,PE1,PriEco,B1,Bus,F1,F,M1,M);
  printf("give the following details of flight to reserve:=\ntype_of_class:-\n1.Economic   2.Primium Economic  3.Bussiness 4.First 5.Mixed\n");
  fclose(pf);
  FILE *adm=fopen("admin_res.txt","a+");
  pf=fopen(Flight_No,"w");
  int l;
  scanf("%d",&l);
  FILE *res=fopen(s1,"r");
  char Flight_No2[20],Source1[20],Destination1[20],Date1[10],Time1[5];
  fscanf(res,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No2,Source1,Destination1,Date1,Time1,&seat_no,Mgs);
  fclose(res);
  res=fopen(s1,"w");
  switch(l){
  case 1:
    {
      if(Eco==0)
	{
	  printf("sorry! all seats are full in this class.\n");
	  available_flight(s1);
	}
      else
	{
	  fprintf(res,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID ,Flight_No1,Source,Destination,Date,Time,Eco,Mgs);
	  fprintf(adm,"%s\t%s\t%s\t%s\t%s\t%s\t%d\n",s1,Flight_No1,Source,Destination,Date,Time,Eco);
	  printf("your request for reservation of seat no %d in Economic class is Registered successfully.\n",Eco );
	  Eco--;
	  fclose(res);

	}
      break;
    }
  case 2:
    {
      if(PriEco==0)
	{
	  printf("sorry! all seats are full in this class.\n");
	  available_flight(s1);
	}
      else
	{
	  fprintf(res,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No1,Source,Destination,Date,Time,PriEco,Mgs);
	  fprintf(adm,"%s\t%s\t%s\t%s\t%s\t%s\t%d\n",s1,Flight_No1,Source,Destination,Date,Time,PriEco);
	  printf("your request for reservation of seat no %d in Economic class is Registered successfully.\n",PriEco );
	  PriEco--;
	  fclose(res);
	}
      break;
    }
  case 3:
    {
      if(Bus==0)
	{
	  printf("sorry! all seats are full in this class.\n");
	  available_flight(s1);
	}
      else
	{
       
	  fprintf(res,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No1,Source,Destination,Date,Time,Bus,Mgs);
	  fprintf(adm,"%s\t%s\t%s\t%s\t%s\t%s\t%d\n",s1,Flight_No1,Source,Destination,Date,Time,Bus);
	  printf("your request for reservation of seat no %d in Economic class is Registered successfully.\n",Bus);
	  Bus--;
	  fclose(res);
	}
      break;
    }
  case 4:
    {
      if(F==0)
	{
	  printf("sorry! all seats are full in this class.\n");
	  available_flight(s1);
	}
      else
	{
	  fprintf(res,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No1,Source,Destination,Date,Time,F,Mgs);
	  fprintf(adm,"%s\t%s\t%s\t%s\t%s\t%s\t%d\n",s1,Flight_No1,Source,Destination,Date,Time,F);
	  printf("your request for reservation of seat no %d in Economic class is Registered successfully.\n",F);
	  F--;
	  fclose(res);
	}
      break;
    }
  case 5:
    {
      if(M==0)
	{
	  printf("sorry! all seats are full in this class.\n");
	  available_flight(s1);
	}
      else
	{
	  fprintf(res,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No1,Source,Destination,Date,Time,M,Mgs);
	  fprintf(adm,"%s\t%s\t%s\t%s\t%s\t%s\t%d\n",s1,Flight_No1,Source,Destination,Date,Time,M);
	  printf("your request for reservation of seat no %d in Economic class is Registered successfully.\n",M);
	  M--;
	  fclose(res);
	}
      break;
    }
  default:
    {
      printf("chose a correct choice.\n");
      available_flight(s1);
    }
  }
  fclose(adm);
  fclose(pf);
  pf=fopen(Flight_No,"w");
  fprintf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\n",type_of_Flight,Flight_No1,Source,Destination,Date,Time,Eco,E1,PriEco,PE1,Bus,B1,F,F1,M,M1);
  fclose(pf);
  selecter();

}

void cancle(char s1[])
{
  FILE *pf=fopen(s1,"r");
  /*char str[999];*/
  int k,seat_no;
  print_file(s1);
  /*while (fscanf(pf, "%s", str)!=EOF)
    printf("%s",str);*/
  fscanf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,&seat_no,Mgs);
  fclose(pf);
  pf=fopen(s1,"w");
  printf("to confirm your cancellation of your ticket enter 1.\n");
  scanf("%d",&k);
  if(k==1)
    {
      strcpy(Flight_No," ");
      strcpy(Source," ");
      strcpy(Destination,"");
      strcpy(Date," ");
      strcpy(Time," ");
      seat_no=0;
      strcpy(Mgs,"your_ticket_is_cancled.");
    }
  fprintf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
  fclose(pf);
  selecter();

}

void available_flight(char s1[])
{
  printf("enter the flight details:--\nsource:\ndestination:\ndate(DD-MM-YYYY):\ntime(HOUR:MIN):\n");
  char source[20],destination[20],date[10],time[5];
  scanf("%s%s%s%s",source,destination,date,time);
  concate1(source,destination);
  concate1(source,date);
  concate1(source,time);
  concate(source);
  FILE *fp=fopen(source,"r");
  if(fp==NULL)
    {
      printf("No flight available for given details.\n");
      available_flight(s1);
    }
  else
    {
      //print_file(source);
      char str;
	while (fscanf(fp, "%c",&str)!=EOF)
        printf("%c",str);
     fclose(fp);
      printf("select a choice:-\n1.request to reserve.\t 2.cancle a ticket\n");
      int choice;
      scanf("%d",&choice);
      switch (choice)
        {
        case 1:{
          reserve(s1);
          break;
        }
        case 2:
          {
            cancle(s1);
            break;
          }
        default:{
          printf("select a right choice.\n");
          available_flight(s1);}
        }
      selecter();
    }
}

void edit_profile(char s1[])
{

  printf("Choose your option:\n1.Name\t2.Email_id\n3.Password\t4.Passport_No\t");
  int choice;
  scanf("%d",&choice);
  FILE *efp=fopen(s1,"r");
  fscanf(efp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,&seat_no,Mgs);
  fclose(efp);
  switch (choice)
    {
    case 1:{
      printf("Enter new name\n");
      scanf("%s",Name);
      efp=fopen(s1,"w");
      fprintf(efp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
      puts("your name is updated successfully.\n");
      fclose(efp);
      edit_profile(s1);
      break;}
    case 2:{
      printf("Enter new Email_id\n");
      scanf("%s",Email_id);
      efp=fopen(s1,"w");
      fprintf(efp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
      puts("your Email id is updated successfully.\n");
      fclose(efp);
      edit_profile(s1);
      break;}
    case 3:{
      printf("Enter new Password\n");
      scanf("%s",Password);
      efp=fopen(s1,"w");
      fprintf(efp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
      puts("your Password is updated successfully.\n");
      fclose(efp);
      edit_profile(s1);
      break;}
    case 4:{
      printf("Enter new Passport_No\n");
      scanf("%s",Passport_No);
      efp=fopen(s1,"w");
      fprintf(efp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
      puts("your Passport No is updated successfully.\n");
      fclose(efp);
      edit_profile(s1);
      break;}
    default :
      {
        puts("select a correct choice\n");
        edit_profile(s1);
      }
    }
  selecter();
}

void user_login()
{
  char s1[20],s2[20];
  printf("Passenger ID:\nPassword:\n");
  scanf("%s%s",s1,s2);
  concate(s1);
  FILE *fp=fopen(s1,"r");
  if(fp==NULL)
    {
      puts("you are not Registered yet. please Register first.");
      selecter();
    }
  else
    {
      fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,&seat_no,Mgs);
      if(match(s2,Password)==0)
        {
          puts("you entered wrong Password");
          fclose(fp);
          selecter();
        }
      else
        {
          puts("login successfully!\n");
          fp=fopen(s1,"r+");
          printf("Enter your choice.\n1.Edit Profile\t2.View available Flight\n3.cancle a tocket\t4.View profile\n5.Delet your account\t6.logout\n");
          int k;
          scanf("%d",&k);
          switch(k)
            {
            case 1:
              edit_profile(s1);
              break;
            case 2:
              available_flight(s1);
              break;
            case 3:
	      cancle(s1);
	      break;
	    case 4:
	      	printf("Name:%s\nEmail_id:%s\nPassword:%s\nPassport No.:%s\nPassenger Id:%s\n-----------------ticket details-----------\nFlight no.:%s\nSource:%s\nDestination:%s\nDate:%s\nTime:%s\nseat no:%d\nstatus:%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
		fclose(fp);
	      	selecter();
		break;
	    case 5:
	      remove_acc(s1);
	      fclose(fp);
	      selecter();
	      break;
	    case 6:
              fclose(fp);
              selecter();
              break;
            default:
              printf("chose a correct choice.\n");
              selecter();
            }
        }
      fclose(fp);
    }
}


void admin_selector(char s1[],FILE *fp)
{

  puts("select desired choice:\n1.Manage Passenger\t2.Update Passenger's status.\n3.upadte flight detail\t4.Delet your account\n5.logout\n");
  int k;
  scanf("%d",&k);
  switch(k)
    {
    case 1:
      manage_pass(s1);
      break;
    case 2:
      update_pass(s1);
      break;
    case 3:
      flight_detail();
      break;
    case 4:
      remove_acc(s1);
      fclose(fp);
      selecter();
      break;
    case 5:
      fclose(fp);
      selecter();
      break;
    default :
      puts("you entered wrong choice.\n");
      selecter();
    }
}

void update_pass(char s1[])
{
  puts("enter the Passenger_ID of the Passenger whose status you want to Update.\n");
  scanf("%s",Passenger_ID);
  concate(Passenger_ID);
  FILE *fp=fopen("admin_res.txt","r");
  char str;
	while (fscanf(fp, "%c",&str)!=EOF)
        printf("%c",str);
     fclose(fp);
  FILE *pf=fopen(Passenger_ID,"r"); 
  fscanf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,&seat_no,Mgs);
  fclose(pf);
  concate(Passenger_ID);
  pf=fopen(Passenger_ID,"w");
  puts("enter the massage that you want to put");
  scanf("%s",Mgs);
  fprintf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
  fclose(pf);
  pf=fopen(Passenger_ID,"r");
  admin_selector(s1,pf);
  fclose(pf);
}


void manage(char s1[])
{
  puts("Enter the Passenger Id of the Passenger whose profile you want to manage");
  scanf("%s",Passenger_ID);
  concate(Passenger_ID);
  char Passenger_ID1[20];
  FILE *pf=fopen(Passenger_ID,"r");
  if(pf==NULL)
    {
      puts("Enetered wrong Passenger_ID.");
      manage(s1);
    }
  else
    {
      fscanf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID1,Flight_No,Source,Destination,Date,Time,&seat_no,Mgs);
      /*char str[999];
	while (fscanf(pf, "%s", str)!=EOF)
	printf("%s",str);*/
      fclose(pf);
      pf=fopen(Passenger_ID,"w");
      printf("enter the corresponding choice that you want to manage in the Passengers profile.\n1.Flight and date and time \t2.seat no\t 3.to put a massage\n4.update Passenger's status\n");
      int k;
      scanf("%d",&k);
      switch (k)
	{
	case 1:
	  puts("Flight_No:\n date(DD-MM-YYYY):\nTime(HOUR:MIN):\n");
	  scanf("%s%s%s",Flight_No,Date,Time);
	  fprintf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID1,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
	  break;
	case 2:
	  puts("seat no.:\n");
	  scanf("%d",&seat_no);
	  fprintf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID1,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
	  break;
	case 3:
	  puts("enter the massage:\n");
	  scanf("%s",Mgs);
	  fprintf(pf,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",Name,Email_id,Password,Passport_No,Passenger_ID1,Flight_No,Source,Destination,Date,Time,seat_no,Mgs);
	  break;
	case 4:
	  update_pass(s1);
	  break;
	default:
	  puts("sorry!invalide entry\n");
	  fclose(pf);
	}
      fclose(pf);
    }
  pf=fopen(Passenger_ID,"r");
  admin_selector(s1,pf);
}

void flight_detail()
{
  char type_of_Flight[20];
  char source[20],flight_No[20];
  puts(":::::::::enter flight details:::::::::\ntype of Flight:\nflight no:\nSource:\ndestination:\ndate(DD-MM-YYYY):\ntime(HOUR:MIN):\n-----no.of seats in the defferent category(fair)----\nEconomy class(fair):\nPrimium Economic class(fair):\nBussiness class(fair):\nFirst class(fair):\nMixed class(fair):\nMeal:\n");
  scanf("%s%s%s%s%s%s%d%d%d%d%d%d%d%d%d%d%s",type_of_Flight,Flight_No,Source,Destination,Date,Time,&Eco,&E1,&PriEco,&PE1,&Bus,&B1,&F,&F1,&M,&M1,meal);
  strcpy(flight_No,Flight_No);
  concate1(Flight_No,"flt.txt");
  FILE *pf=fopen(Flight_No,"r");
  if(pf!=NULL)
    {
      puts("flight details already exist.Enter 1 if you want to over write.");
      int p;
      scanf("%d",&p);
      if(p==1){
	fclose(pf);
	pf=fopen(Flight_No,"w");
	fprintf(pf, "%s\t%s\t%s\t%s\t%s\t%s\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\t%s\n",type_of_Flight,flight_No,Source,Destination,Date,Time,Eco,E1,PriEco,PE1,Bus,B1,F,F1,M,M1,meal);
	fclose(pf);
      }
      else
	{	
	  fclose(pf);
	  selecter();
	}
    }
  else
    {
	
      pf=fopen(Flight_No,"w");
      fprintf(pf, "%s\t%s\t%s\t%s\t%s\t%s\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\t%d(%d)\t%s\n",type_of_Flight,flight_No,Source,Destination,Date,Time,Eco,E1,PriEco,PE1,Bus,B1,F,F1,M,M1,meal);
      fclose(pf);
    }

  strcpy(source,Source);
  concate1(Source,Destination);
  concate1(Source,Date);
  concate1(Source,Time);
  concate(Source);
  FILE *flt=fopen(Source,"a");
  if(flt==NULL)flt=fopen(Source,"w");
  fprintf(flt,"%s\t%s\t%s\t%s\t%s\t%s\n",type_of_Flight,flight_No,source,Destination,Date,Time);
  fclose(flt);
  selecter();
}
void remove_acc(char Id[])
{
  puts("\n enter 1 if you want to delete your acount.\n");
  int k;
  scanf("%d",&k);
  if(k==1)
    {
      int i=remove(Id);
      if(i==0)
	puts("your account deleted successfully.\n");
      else
	puts("enter wrong Id\n");
    }

}

