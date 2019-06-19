int A;
int B = 2;
//float C;
float D = 2.0;
//string E;
//string F = "test";
//bool G;
bool H=true;
bool I=false;

int foo1()
{
    return 2;
}
float foo2()
{
    return 2.0;
}

void main() {
    print(A);
    print(B);
//    print(C);
    print(D);
    //print(E);
    //print(F);

    int a;
    int aa = 2;
    int aaa = 2.0;
    print(a);
    print(aa);
    print(aaa);
    float b;
    float bb = 2;
    float bbb = 2.0;
    print(b);
    print(bb);
    print(bbb);
    string c = "test";
    print(c);
    //bool d;
    bool dd = true;
    bool ddd = false;

    int e = 1 + a;
    int ee = 1 + b;
    int eee = aa + 2.0;
    int eeee = bb + 2.0;
    print(e);
    print(ee);
    print(eee);
    print(eeee);
    int f = foo1();
    int ff = 1 + foo1();
    int fff = foo1() - 1.0;
    print(f);
    print(ff);
    print(fff);

    float g = 1.0 + b;
    float gg = 1.0 + a;
    float ggg = bb + 1;
    float gggg = aa + 1;
    print(g);
    print(gg);
    print(ggg);
    print(gggg);

    float h = foo2();
    float hh = 1.0 + foo2();
    float hhh = foo2() - 1;
	h+=foo2();
    print(h);
    print(hh);
    print(hhh);
   
    return;
}
