#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
string in;
void solve(){
	getline(cin,in);
	in+="+";
	char a;
	string sa="";
	string pre="";   //前一个+-号
	cout<<"f'(x)=";
	LL len=in.length();
	LL i=5;
	if(in[i]=='-') 
	{
		i=6; pre="-";
	}
	for(;i<len;i++)
	{
	    a=in[i];
	    if(a=='+'||a=='-')   //对前面一项求导
        {
            if(sa.length()==1&&sa=="x")  //只有一个x
            {
                cout<<pre<<1;
            }
            else if(sa.find('x')==-1)    //只有一个A
            {
            	if(sa.length()+6+pre.length()==len)  cout<<0;  //只有一项 
            }
            else if(sa[sa.length()-1]=='x')  //Ax的情况
            {
            	string num=sa.substr(0,sa.length()-1);
            	LL t=atoi(num.c_str());
                cout<<pre<<t;
            }
            else if(sa[0]=='x')  //x^i的情况
            {
            	string num=sa.substr(2,sa.length()-2);
            	LL mi=atoi(num.c_str());
                if(mi==2) cout<<pre<<"2x";
                else cout<<pre<<mi<<"x^"<<mi-1;
            }
            else      //Ax^i的情况
            {
            	LL index=sa.find('x');
            	string Ai=sa.substr(0,index);
            	LL A=atoi(Ai.c_str());
            	string ii=sa.substr(index+2,sa.length()-index-2);
                LL mi=atoi(ii.c_str());
                if(mi==2) cout<<pre<<A*mi<<'x';
                else cout<<pre<<A*mi<<"x^"<<mi-1;
            } 
            sa="";
            pre=a;
        }
        else sa+=a;
	}

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}