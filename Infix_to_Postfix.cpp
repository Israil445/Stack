//Bismillah Hir Rehmanir Rahim
//Allah knows best
#pragma GCC optimize("Ofast")
#pragma  GCC optimize ("O3")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define   ll        long long
#define   lli       long long int
#define   ld        long double
#define   PI        2*acos(0.0)
#define   pb        push_back
#define   ppb       pop_back
#define   pf        push_front
#define   ppf       pop_front
#define   inf       1e18
#define   ff        first
#define   ss        second
#define   mp        make_pair
#define   vi        vector<int>
#define   si        set<int>
#define   ii        pair<int,int>
#define   all(v)    (v).begin(),(v).end()
#define   rall(v)   (v).begin(),(v).end(),greater<ll>()
#define   rall1(v)  (v).rbegin(),(v).rend()
#define   uniq(v)   (v).erase(unique(all(v)),(v).end())
#define   read(v)   for(auto &it:v) cin>>it
#define   write(v)  for(auto &it:v) cout<<it<<" "
#define   GCD(a,b)   __gcd(a,b)
#define   nl         "\n"
#define   lb         lower_bound
#define   up         upper_bound
#define   ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace __gnu_pbds;
using namespace std;


stack<char>st;
string infix;
vector<char>postfix;

int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
        case '/':
            return 2;
        case '*':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }
}

void inToPost(){
    char symbol,next;
    bool ok=false;
    for(int i=0;i<infix.length();i++){
        symbol=infix[i];
        switch(symbol){
            case '(':
                st.push(symbol);
                break;
            case ')':

                while((next=st.top())!='('){
                    postfix.push_back(next);
                    st.pop();
                    ok=true;
                }
                if(ok){
                    st.pop();
                    ok= false;
                }


                break;

            case '+':
                while(!st.empty() && precedence(st.top()) >= precedence(symbol)){
                    postfix.push_back(st.top());
                    st.pop();

                }
                st.push(symbol);
                break;

            case '-':
                while(!st.empty() && precedence(st.top()) >= precedence(symbol)){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(symbol);
                break;

            case '*':
                while(!st.empty() && precedence(st.top()) >= precedence(symbol)){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(symbol);
                break;

            case '/':
                while(!st.empty() && precedence(st.top()) >= precedence(symbol)){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(symbol);
                break;

            case '^':
                while(!st.empty() && precedence(st.top()) >= precedence(symbol)){
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(symbol);
                break;

            default:
                postfix.push_back(symbol);


        }
    }

    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }



}
void print(){

    for(char c:postfix){
        cout<<c;
    }
    cout<<nl;


}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cout<<"Enter The Infix Expression : ";
    cin>>infix;
    inToPost();
    print();

    return 0;
}
