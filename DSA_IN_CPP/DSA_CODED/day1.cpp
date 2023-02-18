#include<iostream>
#include<math.h>
//there are different-different namespaces in which cout or identifiers has different-different scopes so need to specify
using namespace std;
/*multi
line 
comment */
int main(){
int n;
cin>>n;
long j;
unsigned int i=1;// max->0 to 2^32-1
signed int l=-1;//max->-2^31 to 2^31-1
cout<<"namaste Bharat"<<endl;
cout<<"you entered the number "<<n<<endl;
//  cout<<"namaste Bharat \n";
cout<<sizeof(n)<<endl;//32-bit compiler acc.
cout<<sizeof(j)<<endl;//32-bit compiler acc.
char ch= 97;// implicit typecasting
int x='a';// implicit typecasting
double d=2.901;
int k= int(d)+2;// explicit typecasting
cout<<k<<endl;
cout<<ch<<endl;
cout<<x<<endl;
char x1=1023;//overflow but last 8 bits(as 2 byte) are copied and rest is not taken into consideration
cout<<x1+1<<endl;
cout<<ceil(double(20)/3)<<endl; // ans of int/int will always be int so implicitly typecasted so need to use this method
return 0;
}