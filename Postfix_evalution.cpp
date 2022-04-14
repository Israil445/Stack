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

stack<int>st;
string infix;
string postfix;


int post_eval(){
    for(int i=0;i<postfix.size();i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            st.push(postfix[i]-'0');

        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();

            switch(postfix[i]){
                case '+':
                    st.push(b+a);
                    break;
                case '-':
                   st.push(b-a);
                    break;
                case '*':
                    st.push(b*a);
                    break;

                case '/':
                    st.push(b/a);
                    break;
                case '^':
                    st.push(pow(b,a));
                    break;


            }

        }
    }
    return st.top();
}



int main()
{

    cout<<"Enter The Postfix Expression : ";
    cin>>postfix;

    int ans=post_eval();

    cout<<ans<<nl;


    return 0;
}
