#include<iostream>
#include<cstring>
using namespace std;
struct digtal
{
	int val;
	digtal *next;
};
struct bignum
{
	digtal *head;
	int len;
	bignum()
	{
		head = new digtal;
		head->next = NULL;
		len = 0;
	}
	bignum(char str[])
	{
		head = new digtal;
		head->next = NULL;
		len = strlen(str);
		digtal* temp;
		for (int i = 0; i < len; i++)
		{
			temp = new digtal;
			temp->val = str[i] - '0';
			temp->next = head->next;
			head->next = temp;
		}
	}
	bignum(int x)
	{
		head = new digtal;
		head->next = NULL;
		len=0;
		digtal* temp,*p=head;
		while(x)
		{
			temp = new digtal;
			temp->val = x%10;
			len++;
			temp->next = p->next;
			p->next = temp;
			p=temp;
			x/=10;
		}
	}
	bignum(const bignum &a)
	{
		head = new digtal;
		head->next = NULL;
		len = a.len;
		digtal *p = head,*q=a.head,*temp;
		while (q->next)
		{
			q = q->next;
			temp = new digtal;
			temp->val = q->val;
			temp->next = p->next;
			p->next = temp;
			p=temp;
		}
	}
	bignum& operator=(const bignum&a)
	{
		if (this == &a)
			return *this;
		digtal*p, *q;
		p = head;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}
		head = new digtal;
		head->next = NULL;
		len = a.len;
		digtal *temp;
		p = head; q = a.head;
		while (q->next)
		{
			q = q->next;
			temp = new digtal;
			temp->val = q->val;
			temp->next = p->next;
			p->next = temp;
			p=temp;
		}
		return *this;
	}
	~bignum()
	{
		digtal*p, *q;
		p = head;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}
	}
	friend ostream& operator<<(ostream&out, bignum&a)
	{
		bignum c;
		digtal *p=c.head,*q=a.head,*temp;
		while(q->next) 
		{
			q=q->next;
			temp=new digtal;
			temp->val=q->val;
			temp->next=p->next;
			p->next=temp;
		}
		while(p->next)
		{
			p=p->next;
			out<<p->val;
		}
		return out;
	}
	friend istream& operator>>(istream&in, bignum&a)
	{

		digtal*p, *q;
		p = a.head;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}
		char str[1000001];
		in >> str;
		a.head = new digtal;
		a.head->next = NULL;
		a.len = strlen(str);
		digtal* temp;
		for (int i = 0; i < a.len; i++)
		{
			temp = new digtal;
			temp->val = str[i] - '0';
			temp->next = a.head->next;
			a.head->next = temp;
		}
		return in;
	}
	friend bignum operator+(bignum &a, bignum &b)
	{
		int n = a.len < b.len ? a.len : b.len;
		digtal *p, *q,*r,*temp;
		bignum c;
		p = a.head;
		q = b.head;
		r = c.head;
		int up = 0;
		for (int i = 0; i < n; i++)
		{
			p = p->next;
			q = q->next;
			temp = new digtal;
			c.len++;
			temp->val = p->val + q->val + up;
			if (temp->val > 9)
			{
				temp->val = temp->val % 10;
				up = 1;
			}
			else
				up = 0;
			temp->next = r->next;
			r->next = temp;
			r = temp;
		}
		while (p->next)
		{
			p = p->next;
			temp = new digtal;
			c.len++;
			temp->val = p->val  + up;
			if (temp->val > 9)
			{
				temp->val = temp->val % 10;
				up = 1;
			}
			else
				up = 0;
			temp->next = r->next;
			r->next = temp;
			r = temp;
		}
		while (q->next)
		{
			q = q->next;
			temp = new digtal;
			c.len++;
			temp->val = q->val + up;
			if (temp->val > 9)
			{
				temp->val = temp->val % 10;
				up = 1;
			}
			else
				up = 0;
			temp->next = r->next;
			r->next = temp;
			r = temp;
		}
		if (up)
		{
			temp = new digtal;
			c.len++;
			temp->val = 1;
			temp->next = r->next;
			r->next = temp;
		}
		return c;
	}
};
int main()
{
	bignum a;
	bignum b;
	bignum c;
	cin >> a >> b;
	c = a + b;
	cout<<c;
	return 0;
}
