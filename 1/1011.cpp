#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
private:
  double x,y;
public:
  friend istream& operator>>(istream&is, MyComplex& a)
  {
  	is>>a.x>>a.y;
  	return is;
  }
  friend ostream& operator<<(ostream&os, const MyComplex& a)
  {
  	os<<setprecision(2)<<fixed<<a.x<<" "<<a.y;
  	return os;
  }
  friend MyComplex operator+(const MyComplex& a,const MyComplex& b)
  {
  	MyComplex c;
  	c.x=a.x+b.x;
  	c.y=a.y+b.y;
  	return c;
  }
  friend MyComplex operator-(const MyComplex& a,const MyComplex& b)
  {
  	MyComplex c;
  	c.x=a.x-b.x;
  	c.y=a.y-b.y;
  	return c;
  }
  friend MyComplex operator*(const MyComplex& a,const MyComplex& b)
  {
  	MyComplex c;
  	c.x=a.x*b.x-a.y*b.y;
  	c.y=a.x*b.y+a.y*b.x;
  	return c;
  }
  friend MyComplex operator/(const MyComplex& a,const MyComplex& b)
  {
  	MyComplex c;
  	double n=b.x*b.x+b.y*b.y;
  	c.x=(a.x*b.x+a.y*b.y)/n;
  	c.y=(b.x*a.y-a.x*b.y)/n;
  	return c;
  }
  MyComplex& operator+=(const MyComplex& a)
  {
  	x+=a.x;
  	y+=a.y;
  	return *this;
  }
  MyComplex& operator-=(const MyComplex& a)
  {
  	x-=a.x;
  	y-=a.y;
  	return *this;
  }
  MyComplex& operator*=(const MyComplex& a)
  {
  	double xt=x*a.x-y*a.y;
  	double yt=x*a.y+a.x*y;
  	x=xt; y=yt;
  	return *this;
  }
  MyComplex& operator/=(const MyComplex& a)
  {
  	double n=a.x*a.x+a.y*a.y;
  	double xt=(x*a.x+y*a.y)/n;
  	double yt=(a.x*y-x*a.y)/n;
  	x=xt; y=yt;
  	return *this;
  }
};

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;

  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}
