#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int dpaoe[100001];
int dpsingle[100001];
int monster[1001];
struct skill {
    int damage;
    int blue;
    skill(int d=0, int b=0) {
        damage = d;
        blue = d;
    }
};
skill aoe[1001];
skill single[1001];
int naoe=0;
int nsingle=0;
int Max=0;
int min(int a, int b) {
    if (a <= b) { return a; }
    else return b;
}
void aoeinit() {
    for (int i = 1; i <= Max; i++) { dpaoe[i] = 10000000; }
    dpaoe[0] = 0;
    for (int i = 1; i <= Max; i++) {
        for (int j = 1; j <= naoe; j++) {
            if (aoe[j].damage >= i) { 
                dpaoe[i] = min(dpaoe[i], aoe[j].blue);
            }
            else {
                dpaoe[i] = min(dpaoe[i], dpaoe[i - aoe[j].damage] + aoe[j].blue);
            }
        }
    }
    //cout << dpaoe[0] << dpaoe[6000] << dpaoe[9999];
}
void singleinit() {
    //memset(dpsingle, 10000000, sizeof(dpsingle[0]));
    for (int i = 1; i <= Max; i++) { dpsingle[i] = 10000000; }
    dpsingle[0] = 0;
    for (int i = 1; i <= Max; i++) {
        for (int j = 1; j <= nsingle; j++) {
            if (single[j].damage >= i) {
                dpsingle[i] = min(dpsingle[i], single[j].blue);
            }
            else {
                dpsingle[i] = min(dpsingle[i], dpsingle[i - single[j].damage] + single[j].blue);
            }
        }
    }
}
int main() {
    int num;
    cin >> num;
    int tmp;
    for (int i = 1; i <= num; i++) {
        cin >> tmp;
        monster[i] = tmp;
        if (tmp > Max) { Max = tmp; }
        
    }
    int num2;
    cin >> num2;
    int blue;
    int damage;
    string name;
    string type;
    for (int i = 1; i <= num2; i++) {
        cin >> name >> blue >> type >> damage;
        if (type == "All") { naoe++; aoe[naoe].blue = blue; aoe[naoe].damage = damage; }
        else if (type == "Single") { nsingle++; single[nsingle].blue = blue; single[nsingle].damage = damage; }
    }
    
    aoeinit();
    singleinit();
    int ans;
    int tmp2;
    int Min = 10000000;
    for (int i = 0; i <= Max; i++) {
        //if (dpaoe[i] == 10000000) { continue; }
        ans = dpaoe[i];
        for (int j = 1; j <= num; j++) {
            tmp2 = monster[j] - i;
            if (tmp2 <= 0) { continue; }
            else {
                ans = ans + dpsingle[tmp2];
            }
        }
        if (ans < Min) {  Min = ans; }
    }
    
    cout << Min;
    int x;
    cin >> x;
}