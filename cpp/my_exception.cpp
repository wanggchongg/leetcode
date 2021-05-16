#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	int a, b;
	while(cin>>a>>b)
	{
		try{ //执行交互代码块
			if(a==b)
				throw runtime_error("Data must not equal"); //抛出异常
			cout<<a+b<<endl;
		}catch(runtime_error err){ //捕获异常
			cout<<err.what()
				<<"\nTry Again? Enter y or n"<<endl;
			char c;
			cin>>c;
			if(!cin || c=='n')
				break;
		}
	}
	return 0;
}