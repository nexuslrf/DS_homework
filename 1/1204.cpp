#include<iostream>
#include<cstring>
using namespace std;
struct Line
{
	Line* next;
	char ln[2001];
	int len;
	Line(char str[]="")
	{
		next=NULL;
		len=strlen(str);
		strcpy(ln,str);
	}
};
class txt
{
	private:
		Line* head,*last;
		int lines;
	public:
		txt()
		{
			head=new Line;
			head->next=NULL;
			lines=0;
			last=head;
		}
		~txt()
		{
			Line* p=head,*q;
			while(p)
			{
				q=p;
				p=p->next;
				delete q;
			}
		}
		void pushline(char str[]="")
		{
			Line* temp=new Line(str);
			temp->next=last->next;
			last->next=temp;
			last=temp;
			lines++;
		}
		Line* move(int k)
		{
			Line* p=head;
			for(int i=0;i<k;i++)
				p=p->next;
			return p;
		}
		void list(int i,int j)
		{
			if(i<1||i>j||j>lines)
			{
				cout<<"Error!"<<endl;
				return;
			}
			Line* p=move(i);
			for(int m=i;m<=j;m++)
			{
				cout<<p->ln<<endl;
				p=p->next;
			}
		}
		void ins(int i,int j,char str[])
		{
			if(i<1||i>lines)
			{
				cout<<"Error!"<<endl;
				return;
			}
			Line* p=move(i);
			if(j>p->len+1)
			{
				cout<<"Error!"<<endl;
				return;
			}
			int n=strlen(str);
			if(n+p->len>2000)
			{
				cout<<"Error!"<<endl;
				return;
			}
			for(int k=p->len;k>=j-1;k--)
			{
				p->ln[k+n]=p->ln[k];
			}
			for(int k=j-1;k<n+j-1;k++)
			{
				p->ln[k]=str[k-j+1];
			}
			p->len+=n;
		}	
		void del(int i,int j,int num)
		{
			if(i<1||i>lines)
			{
				cout<<"Error!"<<endl;
				return;
			}
			Line* p=move(i);
			if(j>p->len+1)
			{
				cout<<"Error!"<<endl;
				return;
			}
			if(j+num>p->len+1)
			{
				cout<<"Error!"<<endl;
				return;
			}
			for(int k=j-1+num;k<=p->len+1;k++)
			{
				p->ln[k-num]=p->ln[k];
			}
			p->len-=num;
		}
		void quit()
		{
			Line* p=head->next;
			while(p)
			{
				cout<<p->ln<<endl;
				p=p->next;
			}
		}	
 };
 struct command
 {
 	char t;
 	int p[3];
 	char str[2001];
 };
 int main()
 {
 	char str[2001];
 	txt Txt;
 	while(true)
 	{
 		cin.getline(str,2001);
 		if(strcmp(str,"******")==0)
 			break;
 		Txt.pushline(str);
 	}
 	command lst[100];
 	int n=0;
 	char type[5];
 	while(true)
 	{
 		cin>>type;
 		if(type[0]=='l')
 		{
 			lst[n].t='l';
 			cin>>lst[n].p[0]>>lst[n].p[1];
 		}
 		if(type[0]=='i')
 		{
 			lst[n].t='i';
 			cin>>lst[n].p[0]>>lst[n].p[1];
 			cin.get();
 			cin.getline(lst[n].str,2000);
		 }
		if(type[0]=='d')
		{
			lst[n].t='d';
			cin>>lst[n].p[0]>>lst[n].p[1]>>lst[n].p[2];
		}
		n++;
		if(type[0]=='q')
		{
			lst[n-1].t='q';
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(lst[i].t=='l')
 		{
 			Txt.list(lst[i].p[0],lst[i].p[1]);
 		}
 		if(lst[i].t=='i')
 		{
 			Txt.ins(lst[i].p[0],lst[i].p[1],lst[i].str);
		 }
		if(lst[i].t=='d')
		{
			Txt.del(lst[i].p[0],lst[i].p[1],lst[i].p[2]);
		}
		if(lst[i].t=='q')
		{
			Txt.quit();
		}
	}
	return 0;
 }
