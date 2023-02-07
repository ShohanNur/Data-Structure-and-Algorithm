#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MIN
#define MXN      100001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;

map<ll,ll>mp;

struct node {
    bool endmark;
    ll cnt=0;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;


void insert(string str, int len)
{
    node* curr = root;

  //  curr->cnt++;

    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL){
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;

}
ll search(string str, int len)
{
    node* curr = root;
    ll res=0;

    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';

        if (curr->next[id] != NULL){
            //return false;
            res = curr->next[id]->cnt;
        }
        else{
            break;
        }
        curr = curr->next[id];
    }
    return res;
}

bool Pref_search(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return true;
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
int main()
{

    root = new node();

    // inserting 
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        string str;
        cin>>str;
        insert(str, str.size());
    }
    // prefix counting : 
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        string str;
        cin>>str;
        cout<<search(str,str.size())<<endl;
    }
    del(root);
    return 0;
}

/**
3
abc
abx
abx
2
ab
k
*/

