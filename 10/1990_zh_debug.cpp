#include<cstdio>
#include<iostream>
using namespace std;

int systime = 0, sysid = 0;

struct pulu {
	int id;      //编号
	int like;    //喜好度
	int time;    //达到这一状态的时间
	pulu() :like(-1), id(sysid++), time(systime++) {}
	bool operator<(const pulu &p) const { return (like < p.like || (like == p.like && time > p.time)); }
	bool operator>(const pulu &p) const { return (like > p.like || (like == p.like && time < p.time)); }
};

class priorityQueue
{
private:
	int currentLength;
	int *pos;     //记录编号为i的cd在堆数组中的位置
	pulu *array;
	void buildHeap();
	void percolateDown(int hole);
public:
	priorityQueue(const int &size);
	~priorityQueue() { delete[]array; }
	void enQueue(const pulu &x);
	pulu deQueue(const int &x);
	int getHead()const { return array[1].id; }
	void printTable() {
		for (int i = 1; i <= currentLength; ++i)
			cout << '*' << array[i].id << ends << array[i].like << ends << array[i].time << '*' << endl;
	}
};

priorityQueue::priorityQueue(const int &n)
{
	currentLength = n;
	array = new pulu[n + 1];
	pulu zz=array[1];
	cout<<systime;
	pos = new int[n + 1];
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &array[i].like);
		pos[i] = i;
	}
	buildHeap();
}

void priorityQueue::buildHeap()
{
	for (int i = currentLength / 2; i>0; --i)
		percolateDown(i);
}

void priorityQueue::enQueue(const pulu &x)
{
	int hole = ++currentLength;
	for (; hole > 1 && x < array[hole / 2]; hole /= 2)
	{
		array[hole] = array[hole / 2];
		pos[array[hole / 2].id] = hole;
	}
	array[hole] = x;
	pos[x.id] = hole;
}

pulu priorityQueue::deQueue(const int &idx)
{
	int px = pos[idx];
	pulu y = array[px];
	array[px] = array[currentLength];
	pos[array[currentLength].id] = px;
	currentLength--;
	percolateDown(px);
	return y;
}

void priorityQueue::percolateDown(int hole)
{
	pulu x = array[hole];
	int child;
	for (; hole * 2 <= currentLength; hole = child)
	{
		child = hole * 2;
		if (child != currentLength && array[child + 1]<array[child])child++;
		if (array[child]>x)break;
		else { 
			array[hole] = array[child]; 
			pos[array[child].id] = hole; 
		}
	}
	array[hole] = x;
	pos[x.id] = hole;
}

int main() {
	// freopen("1990.in","r",stdin);
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	priorityQueue que(n);
	//que.printTable();
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		pulu u = que.deQueue(x);
		u.time = systime++;
		u.like += y;
		que.enQueue(u);
		//que.printTable();
		printf("%d\n", que.getHead());
	}
	return 0;
}

