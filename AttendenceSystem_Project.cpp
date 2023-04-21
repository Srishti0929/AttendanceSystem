//Program to take attendence of a class.
#include<iostream> // ifstream(Read->cout) + ofstream(Write->cin)
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
//#include"check2.h"
using namespace std;
 
static int i=0;
char ch,CH;

	void read()
	{
		ifstream infile("attendence1.txt",ios::in); //1. in -> read mode
		int j=1;
		int rol; 
		string name,attn;
							
		if ( infile.is_open() )   
		{	
	    	while( infile>>rol>>name>>attn ) //2.
			{	
			cout<<"  \t\t*  "<<j++<<".";
			cout<<"\t     "<<rol<<"\t     "<<name<<"\t     "<<attn<<"\t  *"<<endl;	
			}
		cout<<"\t\t"<<"* * * * * * * * * * * * * * * * * * * * * * * * * *\n";
		infile.close();	
		}
		else{
			cout<< "Error: Not able to open the file.\n\n";
		}
		
	}
	

	class attendence
{
		int roll; char name[20]; char atten[8];
	public:
	void setdata( )
	{	ofstream outobj("attendence1.txt",ios::app); //app->append	//1.
		cout<< "\t\t"<<"For Student "<<i+1<<" :-"<<endl;
		cout<< "\t" <<"I/P roll no.   :";  cin>>roll;		getchar();
		cout<< "\t" <<"I/P name       :";  gets(name); //getchar();
		cout<< "\t" <<"I/P attendence :";  cin>>CH;
		if(CH=='p')
				strcpy(atten,"present");
		else if(CH=='a')		
				strcpy(atten,"absent");
		outobj<<roll<<"\t"<<name<<"\t"<<atten<<"\n";  //2.
		outobj.close();
	}	
	
	void display( )
	{					
		read();	
	}
			
	int modify(int rollno)
	{
		int count,opt;  char ch;
		
		int c=0;
	string read1,read2,read3;
	cout<<"I/P A String To Search In A File= ";
	cin>>read2;
	fstream infile("attendence1.xlsx",ios::in);					
	//ofstream outfile("attendence1.xlsx",);	
		if ( infile.is_open() )   
		{	
	    	while( infile>>read1 )
			{	
				if(read1==read2)
				{ cout<<"\t"<<"* * * * Record Has Been Matched. * * * *\n";
				  cout<<"I/P New String To Repace= "; 
				  cin>>read3;
				  //outfile<<read3;
				  infile<<read3;
				  //read1=read3;
					c++;
				}	
				
			}
			infile.close();
		}
		
		 if(c==0)
		{ cout<<"\t"<<"* * * * Record Has Not Been Matched. * * * *\n";
		}
		
		if(count==1)
		{	cout<<"\n";
			cout<<"\t"<<"Choose Options To Update :-\n";
			{
			cout<<"\t"<<"1.Rollno.\n";
			cout<<"\t"<<"2.Name\n";
			cout<<"\t"<<"3.Attendence\n";
			cout<<"\t"<<"4.All the details\n";	
			cout<<"\n\t"<<"Enter the option :";
			cin>>opt;
			 
			 	if(opt==1)
				{ 	cout<<"\t"<<"I/P roll no. :";
				  	cin>>roll;	 					
				}	 
			 	else if(opt==2)
			 	{ 	cout<<"\t"<<"I/P name :";	
				  	cin>>name;						
				}	
			 	
				 else if(opt==3)
			 	{   cout<<"\t"<<"I/P attendence :";
					cin>>ch;						
							if(ch=='p')
						strcpy(atten,"present");
							else if(ch=='a')		
						strcpy(atten,"absent");	
				}	
							
				else if(opt==4)
				{
					cout<<"\tI/P roll no.   :";
					cin>>roll;
					cout<<"\tI/P name       :";
					cin>>name;
					cout<<"\tI/P attendence :";
					cin>>ch;
							if(ch=='p')
						strcpy(atten,"present");
							else if(ch=='a')		
						strcpy(atten,"absent");			 
				}	
			cout<<"\t\t* * Data has been Updated. * *\n";				 	
			}
			
		}	
			else
		{	cout<<"\t"<<"* * * * Record has not been matched. * * * *\n";
			
		}		
	}
};
main()
{	char ch,ch1;
	int m,n,k=1,j,op,rol;
	attendence *p;
	
	do
	{
	system("cls");	
	cout<<setw(40) <<"  * * * * * * * * * * "<<endl;
	cout<<setw(41) <<" * ATTENDENCE  SHEET *\n";
	cout<<setw(40) <<"  * * * * * * * * * * "<<endl;	
	cout<<"\t"<<"MENU:\n";
	cout<<"\t"<<"1. Input   The Attendence.\n";
	cout<<"\t"<<"2. Modify  The Attendence.\n";
	cout<<"\t"<<"3. Display The Attendence.\n";
	cout<<"\t"<<"4. Exit.\n";
	cout<<"\t"<<"Enter option :";  		  cin>>op;
	cout<<"\n\n";
		if(op==1)
	{	system("cls");
		cout<<setw(59)<<"* * * * * * * * INPUT DATA * * * * * * * *\n";
	    cout<<setw(60)<<"* Input 'p' for present and 'a' for absent *\n";
	    cout<<setw(60)<<"* * * * * * * * * *  * * * * * * * * * * *\n\n";
	    cout<<"\t"<<"Input total no. of the students :";
		cin>>n;
		p=new attendence[n];  //int *p=new int[n];
			for(i=0 ; i<n ;i++)
			{
				p[i].setdata();
			}
	}
		else if(op==2)
	{	system("cls");
		cout<<"\t\t\t"<<" * * * * * * *  \n";
		cout<<"\t\t\t"<<"* MODIFY DATA *\n";
		cout<<"\t\t\t"<<" * * * * * * * \n\n";
		cout<<"\t"<<"* Input 'Rollno.' to Modify :";
		cin>>rol;
				p->modify(rol);
	/*	for(j=i-1;j>=0;j--)
			{
				m=p[j].modify(rol);
				
			}			
			if(m==0)
				{	cout<<"\t* * * * Record has not been found. * * * *\n";
				}
	*/
	}
		else if(op==3)
	{	system("cls");
		cout<<"\t\t\t"<<" * * * * * * * * \n";
		cout<<"\t\t\t"<<"* DISPLAY  DATA *\n";
		cout<<"\t\t\t"<<" * * * * * * * *\n\n";
		cout<<"\t\t"<<"* * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	    cout<<"\t\t"<<"* Sr.no. "<<"  Rollno. "<<"  Name "<<"\t     Attendence   *"<<endl;
	    cout<<"\t\t"<<"* * * * * * * * * * * * * * * * * * * * * * * * * *\n";
				 p->display( );			
			
	}
	
	else if(op==4)
	{	exit;
	}
		else
		{	cout<<"Entered Wrong Choice.\n";
		}
		cout<<"\n"<<"\t"<<"Do you want to continue choose y(yes)/n(no) :";	
		cin>>ch1;	
		cout<<"\n\n";
	
	}while(ch1=='y');
	
}
