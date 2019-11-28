#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<climits>
#define vertex 7
using namespace std;
struct user
{
    char username[20];
    char password[20];
    char name[20];
    char phno[20];
    struct user *next;

};
typedef struct user* U;
U start=NULL;
time_t t = time(0);
tm* now = localtime(&t);
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void starting();
void signup();
void signin();
void zoom();
void ola();
void choice();
U create();
void printing();
void choiceforchart();
int minimumDist(int dist[], bool Dset[]);
void dijkstra(int graph[vertex][vertex],int src);
char ch8,ch11;
int ch9,renttotalcost,rentdistance;
int main()
{
   starting();
   return 0;
}
void starting()
{
    int ch1;
    system("cls");
    cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
    cout<<"\t\t\t\tEnter 1 to Sign in\n\n";
    cout<<"\t\t\t\tEnter 2 to Sign up\n\n";
    cout<<"\t\t\t\tEnter your choice (999 to exit): ";
    cin>>ch1;
    if(ch1==1)
       signin();
    else if(ch1==2)
       signup();
    else
    {
        system("cls");
        starting();
    }
}
U temp;
void signin()
{
    char us[20],pa[20];
    system("cls");
    cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tSIGN IN ";
    cout<<"\n\t\t\t\tEnter your userid:\n\t\t\t\t";
    getchar();
    gets(us);
    temp=start;
    if(temp==NULL)
    {
        cout<<"\n\t\t\t\tUser not found";
        cout<<"\n\t\t\t\tPlease Wait";
        for(int z=0;z<4;z++)
        {
            cout<<".";
            delay(500);
        }
        signup();
    }
    if(temp->next==NULL)
    {
      if(strcmp(temp->username,us)==0)
        {
            cout<<"\n\t\t\t\tEnter your password:\n\t\t\t\t";
            gets(pa);
            if(strcmp(temp->password,pa)==0)
            {
               // cout<<"\n\t\t\t\tWelcome "<<temp->username;
                choice();
               // break;
            }
            else
            {
                cout<<"\n\t\t\t\tWrong password";
                delay(1000);
                signin();
            }
        }
        else
        {
            cout<<"\n\t\t\t\tWrong username"; delay(1000); signin();
        }
    }
    else
    {
    while(temp->next!=NULL)
    {
        if(strcmp(temp->username,us)==0)
        {
            cout<<"\n\t\t\t\tEnter your password:\n\t\t\t\t";
            gets(pa);
            if(strcmp(temp->password,pa)==0)
            {
                //cout<<"\n\t\t\t\tWelcome "<<temp->username;
                choice();
                break;
            }
            else
            {
                cout<<"\n\t\t\t\tWrong password";
                delay(1000);
                temp=temp->next;
                //signin();
                continue;
            }
        }
        else
        {
           /* cout<<"\n\t\t\t\tWrong username";
            delay(1000);
            signin();*/
            temp=temp->next;
            continue;
        }
    } }
}
void choice()
{
    int ch5;
    system("cls");
    cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t Welcome "<<temp->name;
    cout<<"\n\t\t\t Enter 1 for Book a Car";
    cout<<"\n\t\t\t Enter 2 for Rent a Car";
    cout<<"\n\t\t\t Enter your choice (999 to exit): ";
    cin>>ch5;
    if(ch5==1) zoom();
    else if(ch5==2) ola();
    else if(ch5==999) starting();
    else choice();
}
void zoom()
{
    system("cls");
    cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
    string car[]={"Alto K10","Swift Dezire","Hyundai i10","Tata Hexa","Scorpio"};
    int seats[]={5,5,5,7,7};
    int costwp[]={12,15,13,20,18};
    int costwop[]={16,19,17,24,22};
    int hrs,ch2,ch3,ch7,cost;
    char ch4;

    cout<<"\n\n\t\t\t\t\t Menu\n";
    for(int i=0;i<5;i++)
    {
      cout<<"\n\t\t\t\t\t "<<i+1<<"."<<car[i];
    }
    cout<<"\n\t\t\t\t\tEnter your choice (999 to exit):";
    cin>>ch2;
    if(ch2<=0||ch2>=6&&ch2!=999)  {zoom();}
    else if(ch2==999) {choice();}
    system("cls");
        cout<<"\n\t\t\t Car :"<<car[ch2-1];
        cout<<"\n\t\t\t No. of seats :"<<seats[ch2-1];
        cout<<"\n\t\t\t Car cost per km(including petrol) :"<<costwp[ch2-1];
        cout<<"\n\t\t\t Car cost per km(excluding petrol) :"<<costwop[ch2-1];
        cout<<"\n\t\t\t Enter 1 for including petrol \n\t\t\t Enter 2 for excluding petrol \n\t\t\t Enter your choice :\n\t\t\t";
        cin>>ch3;
        if(ch3==1)
        {
            cout<<"\n\t\t\tEnter the no. of km :";
            cin>>hrs;
            if(hrs<=0)
            {
                cout<<"\n\t\t\t Wrong input";
                cout<<"\n\t\t\t\tPlease Wait";
                for(int z=0;z<4;z++)
                {
                    cout<<".";
                    delay(500);
                }
                zoom();
            }
            else if(hrs<=80)
            {
                cout<<"\n\t\t\tCar cannot be booked for less than 80km";
                cout<<"\n\t\t\t\tPlease Wait";
                for(int z=0;z<4;z++)
                {
                    cout<<".";
                    delay(500);
                }
                zoom();
            }
            cost=hrs*costwp[ch2-1];
            cout<<"\n\t\t\t Total Cost : "<<cost;
        }
        else if(ch3==2)
        {
            cout<<"\n\t\t\tEnter the no. of km :";
            cin>>hrs;
             if(hrs<=0)
            {
                cout<<"\n\t\t\t Wrong input";
                cout<<"\n\t\t\t\tPlease Wait";
                for(int z=0;z<4;z++)
                {
                    cout<<".";
                    delay(500);
                }
                zoom();
            }
            else if(hrs<=80)
            {
                cout<<"\n\t\t\tCar cannot be booked for less than 80km";
                cout<<"\n\t\t\t\tPlease Wait";
                for(int z=0;z<4;z++)
                {
                    cout<<".";
                    delay(500);
                }
                zoom();
            }
            cost=hrs*costwop[ch2-1];
            cout<<"\n\t\t\t Total Cost (in rupees): "<<cost;
        }
        else
        {
            cout<<"\n\t\t\tWrong input";
            cout<<"\n\t\t\t\tPlease Wait";
            for(int z=0;z<4;z++)
            {
                cout<<".";
                delay(500);
            }
            zoom();
        }

       cout<<"\n\t\t\t Confirm booking (y/n) :";
       cin>>ch4;
       if(ch4=='y')
       {
           system("cls");
           cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
           cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
           cout<<"\t\t--------------------------------------------------------------\n";
           cout<<"\n\t\t\t BOOKING CONFIRMED !!!!";
           cout<<"\n\t\t\t Car type :"<<car[ch2-1];
           cout<<"\n\t\t\t No. of seats :"<<seats[ch2-1];
           if(ch3==1)
            cout<<"\n\t\t\t Car cost per km(including petrol) :"<<costwp[ch2-1];
           if(ch3==2)
            cout<<"\n\t\t\t Car cost per km(excluding petrol) :"<<costwop[ch2-1];
           cout<<"\n\t\t\t No. of Kms :"<<hrs;
           cout<<"\n\t\t\t Total cost :"<<cost;
           cout <<"\n\t\t\t Date of booking :"<< (now->tm_year +1900) << '/'<< (now->tm_mon +1) << '/'<<  (now->tm_mday)<< "\n";
            cout<<"\n\t\t\t 1 to continue \n\t\t\t 999 to exit: ";
            cin>>ch7;
            if(ch7==1)
                choice();
            else if(ch7==999)
            {
                system("cls"); starting();
            }
            else
            {
                cout<<"\n\t\t\t\t Wrong input";
                cout<<"\n\t\t\t\tPlease Wait";
                for(int z=0;z<4;z++)
                {
                    cout<<".";
                    delay(500);
                }
                starting();
            }
       }
       if(ch4=='n')
       {
           system("cls");
           cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
           cout<<"\n\t\t\t BOOKING FAILED !!!!";
          /* int ch7;
           cout<<"\n\t\t\t Want to continue Press 0\n\t\t\t";
           cin>>ch7;
           if(ch7==0)
            {

                system("cls"); starting();
            }*/
       }
       int ch12;
	cout<<"\n\t\t\t\t----------------------\n\t\t\t\t 1 to continue \n\t\t\t\t 999 to exit: ";
            cin>>ch12;
            if(ch12==1)
                choice();
            else if(ch12==999)
            {
                system("cls"); starting();
            }

}
void signup()
{
    system("cls");
    cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tSIGN UP ";
    U node;
    node = create();
    if (start==NULL)
    {
        start = node;
    }
    else
    {
        node->next = start;
        start = node;
    }
    temp=start;
    choice();
}
U create()
{
    U getnode;
    getnode=(U)malloc(sizeof(struct user));
    cout<<"\n\t\t\t\tEnter username :";
    getchar();
    //gets(getnode->username);
    cin>>getnode->username;
    cout<<"\n\t\t\t\tEnter password :";
    getchar();
    //gets(getnode->password);
    cin>>getnode->password;
    cout<<"\n\t\t\t\tEnter Name : ";
    getchar();
    gets(getnode->name);
    //cin>>getnode->name;
    cout<<"\n\t\t\t\tEnter Phone no. :";
    getchar();
    //gets(getnode->phno);
    cin>>getnode->phno;
    getnode->next = NULL;
    return ( getnode );

}
void ola()
{
    int graph[vertex][vertex]={{0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
		                        {0,0,0,0,1,0,0}};

	//delay(1000);
	system("cls");
	cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
	cout<<"\n\t\t\t\t Current location :CMRIT ";
	int ch14;
    cout<<"\n\t\t\t\t Enter 1 to see Distance chart (or any other key to continue):";
	cin>>ch14;
	if(ch14==1)
    {
        printing();
    }
    cout<<"\n\t\t\t\t Where to:";
	cout<<"\n\t\t\t\t A->CMRIT ";
	cout<<"\n\t\t\t\t B->Kundanhalli ";
	cout<<"\n\t\t\t\t C->Aecs Layout ";
	cout<<"\n\t\t\t\t D->Marathalli ";
	cout<<"\n\t\t\t\t E->Whitefield ";
	cout<<"\n\t\t\t\t F->Mahadevpura ";
	cout<<"\n\t\t\t\t G->Big Bazaar ";
	cout<<"\n\t\t\t\tEnter your destination (X to exit): ";
	cin>>ch8;
	if(ch8!='A'&&ch8!='B'&&ch8!='C'&&ch8!='D'&&ch8!='E'&&ch8!='F'&&ch8!='G'&&ch8!='X')
    //if(ch8>=65&&ch8<71)
        {
            cout<<"8\n\t\t\t\t Wrong input";
            cout<<"\n\t\t\t\tPlease Wait";
            for(int z=0;z<4;z++)
            {
                cout<<".";
                delay(500);
            }
            ola();
        }
    else if(ch8=='X')
        choice();
    string rentcar[]={"Micro (Rs 6/km)","Mini  (Rs 9/km)"};
    cout<<"\n\n\t\t\t\tModes :\n";
    for(int i=0;i<2;i++)
    {
      cout<<"\n\t\t\t\t"<<i+1<<"."<<rentcar[i]<<"\n";
    }
    cout<<"\n\t\t\t\tEnter the mode (999 to exit): ";
    cin>>ch9;
    if(ch9!=1&&ch9!=2&&ch9!=999)
    {
        cout<<"\n\t\t\t\t Wrong input";
        cout<<"\n\t\t\t\tPlease Wait";
        for(int z=0;z<4;z++)
        {
            cout<<".";
            delay(500);
        }
            ola();
    }
    else if(ch9==999)
        choice();

    dijkstra(graph,0);

}
int rentcost[]={6,9};
int minimumDist(int dist[], bool Dset[])
{
	int min=INT_MAX,index;
	for(int v=0;v<vertex;v++)
	{
		if(Dset[v]==false && dist[v]<=min)
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
//randomize();
void dijkstra(int graph[vertex][vertex],int src)
{

	int dist[vertex];
	bool Dset[vertex];
	for(int i=0;i<vertex;i++)
	{
		dist[i]=INT_MAX;
		Dset[i]=false;
	}
	dist[src]=0;
	for(int c=0;c<vertex;c++)
	{
		int u=minimumDist(dist,Dset);
		Dset[u]=true;
		for(int v=0;v<vertex;v++)

		{
			if(!Dset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
		}
	}
	//cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i=0;i<vertex;i++)
	{
		char c=65+i;
		if(ch8=='A')
        {
            cout<<"\n\t\t\t\t This is your current location";
            cout<<"\n\t\t\t\tPlease Wait";
            for(int z=0;z<4;z++)
            {
                cout<<".";
                delay(500);
            }
            ola();
        }
        else if(c==ch8)
        {
            rentdistance=dist[i];
            renttotalcost=rentcost[ch9-1]*rentdistance;
            cout<<"\n\t\t\t---------------------------------------";
            cout<<"\n\t\t\t\t Shortest Distance : "<<dist[i];
            cout<<"\n\t\t\t\t Minimum Fare : "<<renttotalcost;
            cout<<"\n\t\t\t\t Confirm (y/n) :";
            cin>>ch11;
            break;
        }

	}
	if(ch11=='y')
    {
        system("cls");
        cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
        cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
        cout<<"\t\t--------------------------------------------------------------\n";
        cout<<"\n\t\t\t Booking confirmed ";
        cout<<"\n\t\t\t Fare : "<<renttotalcost;
        cout<<"\n\t\t\t OTP : "<<rand()*91;
        cout <<"\n\t\t\t Date of booking :"<< (now->tm_year +1900) << '/'<< (now->tm_mon +1) << '/'<<  (now->tm_mday)<< "\n";
    }
    else if(ch11=='n')
    {
        system("cls");
        cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
        cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
        cout<<"\t\t--------------------------------------------------------------\n";
        cout<<"\n\t\t\t Booking Failed ";
    }
    else
    {
        ola();
    }
	int ch10;
	cout<<"\n\t\t\t----------------------\n\t\t\t\t 1 to continue \n\t\t\t\t 999 to exit: ";
            cin>>ch10;
            if(ch10==1)
                choice();
            else if(ch10==999)
            {
                system("cls"); starting();
            }

}
void printing()
{
    int ch15;
    system("cls");
    cout<<"\n\n\n\n\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\t\tWelcome to CAR RENTAL SYSTEM\n\n";
    cout<<"\t\t--------------------------------------------------------------\n";
    cout<<"\n\t\t\tDistance from location to location(in km)";
    cout<<"\n\t\t\t         5               ";
    cout<<"\n\t\t\tCmrit---------Kundanhalli";
    cout<<"\n\t\t\t         3               ";
    cout<<"\n\t\t\tCmrit---------AECS Layout";
    cout<<"\n\t\t\t         2               ";
    cout<<"\n\t\t\tCmrit---------Marathalli";
    cout<<"\n\t\t\t                7               ";
    cout<<"\n\t\t\tAecs Layout---------WhiteField";
    cout<<"\n\t\t\t              2               ";
    cout<<"\n\t\t\tMarathalli---------Whitefield";
    cout<<"\n\t\t\t              1               ";
    cout<<"\n\t\t\tWhiteField---------Mahadevpura";
    cout<<"\n\t\t\t               6               ";
    cout<<"\n\t\t\tMahadevpura---------Marathalli";
    cout<<"\n\t\t\t              3               ";
    cout<<"\n\t\t\tWhiteField---------Kundanhalli";
    cout<<"\n\t\t\t            1               ";
    cout<<"\n\t\t\tBigBazar---------Kundanhalli";
    cout<<"\n\n\t\t\tEnter 1 for Cab booking :";
    cin>>ch15;
    if(ch15==1)
    {
        system("cls");
    }
    else
    {
        printing();
    }

}

