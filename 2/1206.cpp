#include<iostream>
using namespace std;
class stack
{
	char *elem;
	int Maxsize;
	int tail;
	void doubleSpace();
	public:
		stack(int size=50)
		{
			Maxsize=size;
			elem=new char[size];
			tail=-1;
		}
		~stack()
		{
			delete [] elem;
		}	
		void push(char val);
		char pop()
		{
			tail--;
			return elem[tail+1];
		}
		bool isEmpty()
		{
			return tail==-1;
		}
		char top()
		{
			return elem[tail];
		}
};
void stack::doubleSpace()
{
	char *temp=elem;
	Maxsize*=2;
	elem=new char[Maxsize];
	for(int i=0;i<Maxsize;i++)
		elem[i]=temp[i];
	delete[] temp;
}
void stack::push(char val)
{
	tail++;
	if(tail==Maxsize)
		doubleSpace();
	elem[tail]=val;
}

//b:begin e:end i:if t:then o:else #:none
char end[]="end", begin[]="begin", iF[]="if", then[]="then", elsE[]="else";
void nextSymbol(char str[], char* &symb)
{
	char prev=' ';
	int i=0,t,indx=0;
	while(true)
	{
		if(str[i]=='e'&&prev==' ')
		{
			t=1;
			while(true)
			{
				if(str[i+t]=='\0'||str[i+t]!=end[t])
				{
					break;
				}
				t++;
				if(end[t]=='\0')
				{
					if(str[i+t]==' '||str[i+t]=='\0')
					{
						symb[indx++]='e';
						i+=t; break;
					}
					else
					{
						i+=t;
						break;
					}
				}
			}
			t=1;
			while(true)
			{
				if(str[i+t]=='\0'||str[i+t]!=elsE[t])
				{
					break;
				}
				t++;
				if(elsE[t]=='\0')
				{
					if(str[i+t]==' '||str[i+t]=='\0')
					{
						symb[indx++]='o';
						i+=t; break;
					}
					else
					{
						i+=t;
						break;
					}
				}
			}
		}
		else if(str[i]=='b'&&prev==' ')
		{
			t=1;
			while(true)
			{
				if(str[i+t]=='\0'||(str[i+t]!=begin[t]))
				{
					i+=t;
					break;
				}
				t++;
				if(begin[t]=='\0')
				{
					if(str[i+t]==' '||str[i+t]=='\0')
					{
						symb[indx++]='b';
						i+=t;
						break;
					}
					else
					{
						i+=t;
						break;
					}
				}
			}
		}
		else if(str[i]=='i'&&prev==' ')
		{
			t=1;
			while(true)
			{
				if(str[i+t]=='\0'||str[i+t]!=iF[t])
				{
					i+=t;
					break;
				}
				t++;
				if(iF[t]=='\0')
				{
					if(str[i+t]==' '||str[i+t]=='\0')
					{
						symb[indx++]='i';
						i+=t;
						break;
					}
					else
					{
						i+=t;
						break;
					}
				}
			}
		}
		else if(str[i]=='t'&&prev==' ')
		{
			t=1;
			while(true)
			{
				if(str[i+t]=='\0'||str[i+t]!=then[t])
				{
					i+=t;
					break;
				}
				t++;
				if(then[t]=='\0')
				{
					if(str[i+t]==' '||str[i+t]=='\0')
					{
						symb[indx++]='t';
						i+=t;
						break;
					}
					else
					{
						i+=t;
						break;
					}
				}
			}
		}
		prev=str[i];
	//	cout<<i<<'#'<<prev<<'#'<<'\n';
		if(prev=='\0')
			break;
		i++;
	}
	symb[indx]='\0';
	return;
 } 
 int main()
 {
 	stack list;
 	char line[101];
 	char *symb=new char[50];
 	int i;
 	bool flag=true;
 	while(cin.getline(line,100))
 	{
 		//cout<<line<<endl;
 		if(flag)
 			nextSymbol(line,symb);
 		//cout<<symb<<endl;
 		i=0;
 		while(flag&&symb[i]!='\0')
 		{
 			switch(symb[i])
 			{
 				case'b': list.push('b');break;
 				case'e': while(list.top()=='t')
 						{ list.pop();}
				 		if(list.pop()=='b')
 							break;
 						else
						{
							flag=false;
						 }
				case'i':list.push('i');break;
				case't':if(list.pop()=='i')
				{
					list.push('t');
					break;
				}
				else
				{
					flag=false;
				}
				case'o':if(list.pop()!='t')
				{
					flag=false;
				}
				else break;
			 }
			 i++;
		 }
	}
	if(!flag)
	{
		cout<<"Error!";
		return 0;
	}
	if(list.isEmpty())
	{
		cout<<"Match!";
		return 0;
	}
	else
	{
		cout<<"Error!";
		return 0;
	 } 
 }
