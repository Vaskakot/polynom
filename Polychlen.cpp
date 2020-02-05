#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
class Polychlen{
    struct Monochlen{
        int a;
        int n;
        Monochlen* next=NULL;
    };
    typedef Monochlen* refer;
    void Del (refer &H, refer x)//удаляет элемент х из списка
{
    refer q = H;
    if(H==x)H=x->next;
    else
    {
        while (q&&q->next!=x)q=q->next;
        if(q==NULL)return;
        q->next=x->next;
    }
    delete x;
}
     refer Create( int A,int N)
    {
        refer P = new Monochlen;
        P->a = A;
        P->n = N;
        P->next = NULL;
        return P;
    }
public:
    refer s;
    ~Polychlen()
    {
        refer k;
        while(k)
        {
            Del(s,k);
            k=k->next;
        }
    }
    Polychlen()
    {
        s=NULL;
    }
    Polychlen(string P)
    {
            s=NULL;
            int z;
            long long m=0;
            string v;
            s=new Monochlen;
            refer c=s;
            while(P.size())
            {
                m=P.find('x');
                if(m==string::npos)
                {
                    c->a = atoi(P.c_str());
                    c->n = 0;
                    c->next=NULL;
                    P="";
                }
                else
                {
                    v=P.substr(0, m);
                    c->a=atoi(v.c_str());
                    P.erase(0, m+2);
                    if(P.find('+')<P.find('-'))z=P.find('+');
                    else z=P.find('-');
                    if(z==string::npos)v=P.substr(0, P.size());
                    else v=P.substr(0, z);
                    c->n=atoi(v.c_str());
                    P.erase(0, z);
                    if(P.size()){c->next=new Monochlen;
                    c=c->next;}
                }
            }
    }
    void PrintPLC(char c)
    {
        refer r=s;
        while(r)
        {
            if(r->a>0)cout<<"+";
            cout<<r->a<<c<<"^"<<r->n;
            r=r->next;
        }
        cout << endl;
    }
    bool Equaliser(Polychlen T)
    {
        refer q=s, r=T.s;
        while(q&&r && q->a==r->a &&q->n==r->n)
        {
            q=q->next;
            r=r->next;
        }

        return (q == NULL && r == NULL);
    }
    int Soulver(int x)
    {
        refer q=s;
        int Sum=0;
        while(q)
        {
            Sum+=(q->a)*pow(x, q->n);
            q=q->next;
        }
        return Sum;
    }
    Polychlen Derivative()
    {
           cout<<"here"<<endl;
        Polychlen T;
        refer q=s, r;
        while (q)
        {
            refer P=Create((q->a)*(q->n),(q->n) - 1);
            if(T.s == NULL)
            {
                T.s=P;
                r=P;
            }
            else
            {
                r->next = P;
                r=r->next;
            }
            q=q->next;
        }
        return T;
    }
    Polychlen operator+(refer A)
    {
        refer q=s, p=A;
        Polychlen T;
        refer D, w=D;
        while (q&&p)
        {
            if(q->n==p->n)D=Create(q->a+p->a, q->n);
            else if(q->n>p->n)D=Create(q->a,q->n);
            else D=Create(p->a,p->n);
            D=D->next;
            q=q->next;
            p=p->next;
        }
        while(q)
        {
            D=Create(q->a, q->n);
            D=D->next;
            q=q->next;
        }
        while(p)
        {
            D=Create(p->a, p->n);
            D=D->next;
            p=p->next;
        }
        T.s=w;
        return T;
    }
    void operator*(int K)
    {
        refer q=s;
        while (q)
        {
            q->a = q->a*K;
            q=q->next;
        }
    }
};
int main()
{
    string P;
    //getline(cin, P);
    P = "5x^5-4x^4+3x^3+2";
    Polychlen PLC(P), A;
    PLC.PrintPLC('x');
    cout << "OK" << endl;
    cout<<"res = " << PLC.Soulver(1)<<endl;
    Polychlen plc(P);
    plc.PrintPLC('y');
    cout << PLC.Equaliser(PLC) << " " << PLC.Equaliser(A)<< " ??????? " << endl<< endl ; cout << "here ";

    plc = PLC.Derivative();
    cout<<"here"<<endl;
    plc.PrintPLC('x');
    bool b = PLC.Equaliser(plc);
    cout<<"here"<<endl;
    //cout<<a<<" "<<b<<endl;
    return 0;

}
