#include<iostream>
using namespace std;
template<class T>
class List
{
	private:
		T* data;
		int length;
		int maxsize;
	public:
		List(int iniSize=10)
		{
			data=new T[iniSize];
			maxsize=iniSize;
			length=0;
		}
		List(const List<T>& a)
		{
			maxsize=a.maxsize;
			data=new T[maxsize];
			length=a.length;
			for(int i=0;i<a.length;i++)
			{
				data[i]=a.data[i];
			}
		}
		int len()
		{
			return length;
		}
		~List(){delete[] data;}
		void push(T x)
		{
			data[length]=x;
			length++; 
		}
		
		T& operator[](int idx)
		{
			return data[idx];
		}
		friend List<T> operator+(List<T> a,List<T> b)
		{
			int n=a.len()+b.len()+10;
			List<T> c(n);
			for(int i=0;i<a.len();i++)
				c.push(a[i]);
			for(int i=0;i<b.len();i++)
				c.push(b[i]);
			return c;
		}
		friend ostream& operator<<(ostream&os,List<T> a)
		{
			for(int i=0;i<a.len();i++)
			{
				os<<a[i]<<" ";
			}
			return os;
		}
 };
 int main()
 {
 	char str[10];
 	cin>>str;
 	int m,n;
 	cin>>m>>n;
 	if(str[0]=='i')
 	{
 			List<int> a(m);
 			List<int> b(n);
 			int temp;
 			for(int i=0;i<m;i++)
 			{
 				cin>>temp;
 				a.push(temp);
			 }
			 for(int i=0;i<n;i++)
 			{
 				cin>>temp;
 				b.push(temp);
			 }
			 cout<<a+b;
	}
	if(str[0]=='d')
	{
			List<double> a(m);
 			List<double> b(n);
 			double temp;
 			for(int i=0;i<m;i++)
 			{
 				cin>>temp;
 				a.push(temp);
			 }
			 for(int i=0;i<n;i++)
 			{
 				cin>>temp;
 				b.push(temp);
			 }
			 cout<<a+b;
	}
	if(str[0]=='c')
	{
	
			List<char> a(m);
 			List<char> b(n);
 			char temp;
 			for(int i=0;i<m;i++)
 			{
 				cin>>temp;
 				a.push(temp);
			 }
			 for(int i=0;i<n;i++)
 			{
 				cin>>temp;
 				b.push(temp);
			 }
			 cout<<a+b;
	 }
	 return 0;
 	
 }
