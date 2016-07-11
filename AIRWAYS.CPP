#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
std::fstream;

int a[50],b[50],cnt=0;
void pattern()
{
       clrscr();
       for(int i=0;i<80;i++)
       {

	     cout<<"#~";

       }
       for(i=0;i<22;i++)
       {

	     cout<<"#~";

	     cout<<endl;
       }
       for(i=0;i<80;i++)
       {

	     cout<<"#~";

       }
       for(i=1;i<24;i++)
       {
	     gotoxy(80,i);

	     cout<<"#~";

       }
}
void plane_details()
{
       pattern();
       gotoxy(29,3);
       cout<<"_____________";
       gotoxy(30,4);
       cout<<"PLANE DETAILS";
       gotoxy(29,5);
       cout<<"-------------";
       gotoxy(3,7);

       cout<<"Plane number     Plane  Name         Source      Destination\n";
       gotoxy(3,9);
       cout<<"1111             JET AIRWAYS	     NEW DELHI   MUMBAI\n";
       gotoxy(3,10);
       cout<<"1122             JET AIRWAYS         LUCKNOW     NEW DELHI\n";
       gotoxy(3,11);
       cout<<"1132             JET AIRWAYS         MUMBAI      KOLKATA\n";
       gotoxy(3,12);
       cout<<"1252             JET AIRWAYS	     NEW DELHI   GOA\n";
       gotoxy(3,13);
       cout<<"2112             JET AIRWAYS         KOLKATA     JAIPUR\n";
       gotoxy(3,14);
       cout<<"3125             JET AIRWAYS         KOLKATA     AHMEDABAD\n";
       gotoxy(3,15);
       cout<<"5058             JET AIRWAYS         KOLKATA     LONDON\n";
       gotoxy(3,16);
       cout<<"7034             JET AIRWAYS         NEW DELHI   NEW YORK\n";
       gotoxy(3,17);
       cout<<"8046             JET AIRWAYS         MUMBAI      MALAYSIA\n";
       gotoxy(3,18);
       cout<<"1123             JET AIRWAYS	     CHANDIGARH  NEW YORK\n";
       gotoxy(3,21);
       cout<<"* Press any key to continue *.............\n";
       getch();
}
void thanks()
{
       pattern();
       gotoxy(10,4);
       cout<<"#############################################";
       gotoxy(10,6);
       cout<<" Thanks for using this software . . . . . . .";
       gotoxy(10,8);
       cout<<"#############################################";
       gotoxy(40,12);
       cout<<"Developed by :-";
       gotoxy(40,14);
       cout<<"** Siffi Singh **";
       gotoxy(53,15);
       cout<<" Under the guidance of :";
       gotoxy(53,17);
       cout<<" Mr. Arvind Tiwary ";
       gotoxy(50,20);
       getch();
       exit(0);
}
struct dt
{
       int dd;
       int mm;
       int yy;
};

int checkdate(date);

class Passenger
{
       int pno;
       int seatno;
       int planeno;
       char Name[20];
       char Sex;
       int Age;
       char Source[25];
       char Destination[25];
       float Distance;
       float Fare;
       float Calcfare(float,int,int);
       int Class;
       int Checksex(char);
       dt d;
      public:
       void Getdata();
       void Savedata(Passenger);
       void Display();
       friend void cancellation();
       friend int chk_tkt(int,int);
       friend void save_array();
       friend int fetch_data();
};
 void save_array()
{
       Passenger t;
       ifstream fin;
       fin.open("air.dat",ios::in|ios::binary);
       fin.seekg(0);
       if(!fin.good())
	     cout<<"File doesn't exist";
       else
       {
	      while(!fin.eof())
	      {
		    fin.read((char*)&t,sizeof(Passenger));
		    a[cnt]=t.pno,b[cnt]=t.planeno;
		    cnt++;
	      }
	}
	fin.close();
}
int chk_tkt(int tno,int rno)
{
	 int flag=1;
	 for(int i=0;i<50;i++)
	 {
	      if(tno==a[i]&&rno==b[i])
	      {
		  cout<<"\n\n\t\t Invalid Entry!\n\t\tTicket number";
		  flag=0;
	      }
	 if(rno!=1111&&rno!=1122&&rno!=1132&&rno!=1252&&rno!=2112&&rno!=3125&&
	 rno!=5058&&rno!=7034&&rno!=8046&&rno!=1123)
	 {
		   cout<<"\t\t\n\n Invalid plane Number ! ! !\n";
		   flag=0;
	 }
	 }
	 return(flag);
}
void Savedata(Passenger p1)
{
	 ofstream fout;
	 fout.open("air.dat",ios::out|ios::binary|ios::app);
	 fout.write((char*)&p1,sizeof(Passenger));
	 cout<<"\n Record saved.....";
	 fout.close();
}



int fetch_data()
{
	 Passenger r;
	 int flag=0;
	 ifstream fin;
	 clrscr();
	 int tkt,rno;
	 cout<<"Enter ticket Number whose details u want to search:";
	 cin>>tkt;
	 fin.open("air.dat",ios::in|ios::binary);
	 fin.seekg(0);
	 fin.read((char*)&r,sizeof(Passenger));
	 do
	 {
		if(r.pno==tkt)
		{
			r.Display();
			flag=1;
			break;
		}
		fin.read((char*)&r,sizeof(Passenger));
	  }

	  while(fin);
	  fin.close();
	  return(flag);
}


int checkdate(dt d)
{
	  int tmp=0;
	  if(d.mm>12)
		 tmp=1;
	  if(d.mm==2)
	  {
		 if(d.dd>28)
		 tmp=1;
	  }
	  if(d.mm==1||d.mm==3||d.mm==5||d.mm==7||d.mm==8||d.mm==10||d.mm==12)
	  {
	       if(d.dd>31)
		  tmp=1;
	  }
	  if(d.mm==4||d.mm==6||d.mm==9||d.mm==11)
	  {
	       if(d.dd>30)
		  tmp=1;
	  }
	  return(tmp);
}
int Passenger::Checksex(char s)
{
	  int ret=0;
	  if(s=='m'||s=='f'||s=='F'||s=='M')
	  ret=1;
	  return(ret);
}
float Passenger::Calcfare(float Distance,int cl,int Age)
{
	  float t;
	  float f;
	  if(cl==1)
		  f=Distance*8;
	  else if(cl==2)
		  f=Distance*5;
	  else
		  f=Distance*3;
	  t=f;
	  if(Age<5)
	     t=0;
	  else if(Age>62)
	      t=(f-(f*0.2));
	  return t;
}
void Passenger::Getdata()
{
	  clrscr();
	  char ch;
	  fflush(stdin);
	  cout<<"Enter the details of the passenger"<<endl;
	  cout<<"\t--------------------------------"<<endl;
	  cout<<"\tEnter Name        :             ";
	  gets(Name);
	  cout<<"\tEnter age         :             ";
		  fflush(stdin);
	  cin>>Age;
	  char s;
	  int ss;
	  cout<<"\tEnter sex(M/F)    :             ";
	  s=getchar();
	  ss=Checksex(s);
	  while(ss==0)
	  {
	  cout<<"\t\t\n\nInvalid Entry ! ! ! !\n";
	  cout<<"\t Enter sex(M/F)   :             ";
	  s=getchar();
	  ss=Checksex(s);
}
Sex=s;
plane_details();
clrscr();
int n,m;
do
{
	  cout<<"\tEnter Ticket No          :  ";
	  cin>>pno;
	  cout<<"\t Enter plane No           :  ";
	  cin>>planeno;
	  n=chk_tkt(pno,planeno);
}while(n==0);
a[cnt]=pno;
b[cnt]=planeno;
	  cout<<"\t Enter date of entry     :  "<<endl;
do
{
	  cout<<"\tEnter date (dd)               :  ";
	  cin>>d.dd;
	  cout<<"\tEnter Month (mm)              :  ";
	  cin>>d.mm;
	  cout<<"\tEnter year (yy)               :  ";
	  cin>>d.yy;
	  m=checkdate(d);
	  if(m==1)
	  {
	  cout<<"\t\t\n Invalid date ! !\n";
	  }
}  while(m==1);

	  cout<<"\nEnter Seat No           :  ";
	  cin>>seatno;
	  cout<<"\nEnter Source             :  ";
	  cin>>Source;
	  cout<<"\nEnter Destination        :  ";
	  cin>>Destination;
	  cout<<"\nEnter Distance           :  ";
	  cin>>Distance;
	  cout<<"\nEnter class(1/2/3)       :  ";
	  cin>>Class;
	  float f=Calcfare(Distance,Class,Age);
	  cout<<"\nCalculated Fare          :  "<<f;
	  Fare=f;
	  cout<<"\n\n\n\tEnter any key for main menu....";
	  getch();
}

void Passenger::Display()
{
	  pattern();
	  gotoxy(25,4);
    //	  textcolor(10+BLINK);
	  cout<<"Passenger's Details";
	  gotoxy(25,5);
      //	  textcolor(10);
	  cout<<"-------------------";
	  gotoxy(15,7);
	 // textcolor(13);
	  cout<<"Name             :  ";
	  puts(Name);
	  gotoxy(15,8);
	  cout<<"Age              :  ";
	  cout<<Age<<endl;
	  gotoxy(15,9);
	  cout<<"Sex              :  ";
	  cout<<Sex<<endl;
	  gotoxy(15,10);
	  cout<<"Ticket No        :  ";
	  cout<<pno<<endl;
	  gotoxy(15,11);
	  cout<<"plane No         :  ";
	  cout<<planeno<<endl;
	  gotoxy(15,12);
	  cout<<"Date             :  ";
	  cout<<d.dd<<"-"<<d.mm<<"-"<<d.yy<<endl;
	  gotoxy(15,14);
	  cout<<"Berth No         :  ";
	  cout<<seatno<<endl;
	  gotoxy(15,15);
	  cout<<"Source           :  ";
	  cout<<Source<<endl;
	  gotoxy(15,16);
	  cout<<"Destination      :  ";
	  cout<<Destination<<endl;
	  gotoxy(15,17);
	  cout<<"Distance         :  ";
	  cout<<Distance<<endl;
	  gotoxy(15,18);
	  cout<<"Class            :  ";
	  cout<<Class<<endl;
	  gotoxy(15,19);
	  cout<<"Fare             :  ";
	  cout<<Fare<<endl;
       //	  textcolor(6);
	  gotoxy(15,21);
	  cout<<" Enter any key for main menu....." ;
	  getch();
}
void cancellation()
{
	  clrscr();
	  int tn;
	  Passenger s;
	  cout<<"\n\n Enter ticket no";
	  cin>>tn;
	  ifstream fi;
	  ofstream fo;
	  fi.open("air.dat",ios::binary|ios::in);
	  fi.open("tmp.dat",ios::binary|ios::out);
	  fi.seekg(0);
	  while(fi)
	  {
	       fi.read((char*)&s,sizeof(Passenger));
	       if(s.pno!=tn)
	       fo.write((char*)&s,sizeof(Passenger));
	  }
	  fi.close();
	  fo.close();
	  remove("air.dat");
	  rename("tmp.dat","air.dat");
	  gotoxy(28,13);
	  char st[]=" C a n c e l l i n g . . . . . . . . . . .";
	  for(int i=0;st[i]!=NULL;i++)
	  {
	       cout<<st[i];
	       cout<<'\a';
	      // delay(100);
	  }
	  clrscr();
	  gotoxy(28,13);
	//  textcolor(4+BLINK);
	  cout<<" RESERVATION  CANCELLED !\n";
	  gotoxy(15,22);
	  char a[]="************* Thanks for accepting service*************";
	  for(i=0;a[i]!=NULL;i++)
	  {
	       cout<<a[i];
	  //     delay(100);
	  }
	  getch();
	  int ptr=0;
	  for(i=0;i<50;i++)
	  {
	       if(a[i]==tn)
	       {
		  ptr=i;
		  break;
	       }
	  }
	  for(i=ptr;i<ptr;i++)
	  {
	       a[i]=a[i+1];
	  }
	  }
void main()
{
	 Passenger p1;

	 save_array();
	 int ch;
	 do
	 {
	     pattern();
	     gotoxy(12,3);
   //	     textcolor(13);
	     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	     gotoxy(12,5);
     //	     textcolor(11+BLINK);
	     cout<<"*~*~*~*~*~* WELCOME TO JET AIRWAYS *~*~*~*~*~*\n";
	     gotoxy(12,7);
       //	     textcolor(13);
	     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";	     gotoxy(30,9);
	     gotoxy(30,9);
	 //    textcolor(10);
	     cout<<"*****  MAIN  MENU  *****\n";
	     gotoxy(30,10);
	     cout<<"---------------------------";
	     gotoxy(25,12);
	 //    textcolor(12);
	     cout<<" 1. Enter Details\n";
	     gotoxy(25,14);
	     cout<<" 2. Show Details\n";
	     gotoxy(25,16);
	     cout<<" 3. Cancel Reservation\n";
	     gotoxy(25,18);
	     cout<<" 4. Exit\n";
	     gotoxy(25,21);
	 //    textcolor(15);
	     cout<<"* Enter your choice *";
	     cin>>ch;
	     switch(ch)
	     {
		   case 1:p1.Getdata();
			  Savedata(p1);
			  break;
		   case 2:int a=fetch_data();
			  if(a==0)

			  {   pattern();
			      gotoxy(27,12);
	 //		      textcolor(13+BLINK);
			      cout<<" Ticket number not found ! !";
			      getch();
			  }
			  break;
		   case 3:cancellation();
			  break;
		   case 4:thanks();
	 }      }
		  while(ch<4);
	}

