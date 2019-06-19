float bbb(int a);
int foo(int a) {
   a += 6;
   return a;
}
void lol(int a) {
    print(a);
	return;
}

void main(){
   int a;
   int c=100;
   int d=6;
   float dd;
   int b;
   b = c>d;

   print(b);
   a = foo(4)+5;
   lol(a);
   return;
}

