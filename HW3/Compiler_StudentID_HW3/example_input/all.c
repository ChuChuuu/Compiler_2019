int a;
int b=10;
float c = 5.3;
int intfun(float a,int c){
	print("cast float-int");
	int b = a;//test casting
	print(b);
	print("test argument");
	print(c);
	return b;
}
float floatfun(float a,int c){
	print("cast int-float");
	float b = c;
	print(b);
	print("test argument");
	print(a);
	return b;
}
void main(){
	//test global
	print("1.will a = 0");
	print(a);//global->no initial
	print("2.will b = 10");
	print(b);//global->int with value
	print("3.will c = 5.3");
	print(c);//global->float with value
	//different scope with same name
	int a = 1;
	print("4.will a = 1");
	print(a);//global-scope1
	int d = 2;
	{
		int d = 3;//scope1-scope2
		print("5.will d = 3");
		print(d);
	}
	print("6.will d = 2");
	print(d);//scope1
	float e = 3.2;
	//test print
	print("test string,1,2.2,gb=10,gc=5.3,e=3.2");
	print(1);
	print(2.2);
	print(b);
	print(c);
	print(e);
	//test arthmetic;
	int f = 0;
	float g = 0.0;
	f++;
	print("7.++ f = 1");
	print(f);
	f--;
	print("8.-- f = 0");
	print(f);

	//function cast
	print("do function float");
	f = floatfun(5.2,3);
	print("do function int");
	g = intfun(1.2,3);
	print(f);
	print(g);
	f = intfun(1.2,3);
	g = floatfun(5.2,3);
	print("-------");
	print(f);
	print(g);
	float i = floatfun(5.3,3);
	print("-------");
	print(i);
	print("------");
	//divide by zero
	int j = 48;
	j /= 50/g;
	print(j);
	
return;
}
