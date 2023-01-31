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

struct node {
    bool endmark;
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
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
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
    // searching 
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        string str;
        cin>>str;
        if (search(str,str.size()))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }


    // if the string exist as a prefix
    int x;
    cin>>x;

    for(int i=1;i<=x;i++){
        string s;
        cin>>s;
        if(Pref_search(s,s.size())){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    //delete the trie
    del(root);
    return 0;
}

/**
17
abcdaabcdefa
ababcadacc
aaa
aa
aab
aabccc
aabc
aab
abcdaabcde
wow
this
that
those
this
is
absolutely
vogue
10
these
is
i
absolute
abcdaabcd
vog
abcdaabcdefa
aaaa
aabc
aabcc
*/

