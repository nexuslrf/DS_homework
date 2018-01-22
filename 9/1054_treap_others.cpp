#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int delta, n, m, leave;
struct Treap{
    struct Node{
        int v, r, s;
        Node* ch[2];
        int cmp(int x) const{
            if(x == v) return -1;
            else return x < v ? 0 : 1;
        }
        void maintain(){
            s = ch[0]->s + ch[1]->s +1;
        }
    };
    Node *root, *null;
    Treap(){
        null = new Node();
        root = null;
    }
    void rotate(Node* &o, int d){
        Node* k = o->ch[d^1];
        o->ch[d^1] = k->ch[d];
        k->ch[d] = o;
        o->maintain();
        k->maintain();
        o = k;
    }
    void insert(Node* &o, int x){
        if(o == null){
            o = new Node();
            o->ch[0] = o->ch[1] = null;
            o->v = x;
            o->r = rand();
            o->s = 1;
        }
        else{
            int d = (x < o->v ? 0 : 1);
            insert(o->ch[d], x);
            if(o->ch[d]->r > o->r) rotate(o, d^1);
        }
        o->maintain();
    }
    int del(Node* &o, int x){
        if(o == null) return 0;
        if(o->v < x){
            int t = o->ch[0]->s + 1;
            o = o->ch[1];
            return t + del(o, x);
        }
        else{
            int t = del(o->ch[0], x);
            o->s -= t;
            return t;
        }
    }
    int find(Node* o, int k){
        if(o == null || k <= 0 || k > o->s) return 0;
        int s = (o->ch[1] == null ? 0 : o->ch[1]->s);
        if(s + 1 == k) return o->v;
        if(s >= k) return find(o->ch[1], k);
        return find(o->ch[0], k-s-1);
    }
} tp;

int main(){
    freopen("1054_treap_compare1.txt","w",stdout);
    scanf("%d %d", &n, &m);
    char p[10];
    int x;
    tp = Treap();
    while(n--){
        scanf("\n%s%d", p, &x);
        if(p[0] == 'I') if(x >= m) tp.insert(tp.root, x-delta);
        if(p[0] == 'A') delta += x;
        if(p[0] == 'S'){ delta -= x; leave += tp.del(tp.root, m-delta); }
        if(p[0] == 'F'){
            if(x > tp.root->s) printf("-1\n");
            else printf("%d\n", tp.find(tp.root, x)+delta);
        }
    }
    printf("%d\n", leave);
    return 0;
}