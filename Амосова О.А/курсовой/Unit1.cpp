//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop
#define YY0 -10
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
double F(double x, double y)
{
        return x*x-log(4-y+exp(y))+4;
}
double df(double x,double y)
{
        return (2*x)                 //dx
        /      ((exp(y)-1)/(exp(y)-y+4));              //dy
}
double fn(double x, double y)
{
        double z;
        z = y+1;
        //double y0=y;
        // ���� � ����� � : F(x,y)=0
        //for(int i=0;i<50;i++)
        //while(fabs(F(x,y))>0.01)
        while((fabs(y-z)>0.01))
        {
                z=y;
                y=y-F(x,y)/df(x,y);
        }
        return y;
}
double f(double x)
{
        return fn(x,YY0);
}
//-------------------Fibonacci---------------------------------------
double Fi(double);
double fibmin()
{
        int d,k=-1,p=0;
        double L0,l,a=-3.0,b=0.0,eps,x,y,N=-1,kk=1.0;
        eps=0.001;
        L0=b-a;
        l=L0/eps;
        do {N++;}
        while (Fi(N)<(fabs(L0)/l));
        x=a+(Fi(N-2)/Fi(N))*(b-a);
        y=a+(Fi(N-1)/Fi(N))*(b-a);
        do{
                k++;
                if (f(x)<=f(y))
                {
                        b=y;
                        y=x;
                        x=a+(Fi(N-k-3)/Fi(N-k-1))*(b-a);
                };

                if (f(x)>f(y))
                {
                        a=x;
                        x=y;
                        y=a+(Fi(N-k-2)/Fi(N-k-1))*(b-a);
                };
        }while(k!=N-3);
        y=x+eps;
        if (f(x)<=f(y))
        {
                b=y;
        };

        if (f(x)>f(y))
        {
                a=x;
        };
        return (b+a)/2;
};
double fibmax()
{
        int d,k=-1,p=0;
        double L0,l,a=-3.0,b=0.0,eps,x,y,N=-1,kk=1.0;
        eps=0.001;
        L0=b-a;
        l=eps;
        do {N++;}
        while (Fi(N)<(fabs(L0)/l));
        x=a+(Fi(N-2)/Fi(N))*(b-a);
        y=a+(Fi(N-1)/Fi(N))*(b-a);
        do{
                k++;
                if (f(x)>=f(y))
                {
                        b=y;
                        y=x;
                        x=a+(Fi(N-k-3)/Fi(N-k-1))*(b-a);
                };

                if (f(x)<f(y))
                {
                        a=x;
                        x=y;
                        y=a+(Fi(N-k-2)/Fi(N-k-1))*(b-a);
                };
        }while(k!=N-3);
        y=x+eps;
        if (f(x)>=f(y))
        {
                b=y;
        };

        if (f(x)<f(y))
        {
                a=x;
        };
        return (b+a)/2;
};

double Fi(double n)
{
        double f0,fk,p;
        f0=1;
        fk=1;
        for(int i=2;i<=n;i++)
        {
                p=fk;
                fk=fk+f0;
                f0=p;
        };
        if (n<2){fk=1;};
        return fk;
};
//-------------------/Fibonacci--------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        double y = YY0;
        for(double x=-3;x<-0.1;x+=0.01)
        {
                y=YY0;
                y=fn(x,y);
                Chart1->Series[0]->AddXY(x,y,"",RGB(0,0,0));
                //Chart1->Series[1]->AddXY(x,(7-x*x)/(x+4),"",RGB(0,0,0));
        }
        double max = fibmax();
        double fmax = f(max);
        Chart1->Series[1]->AddXY(max, fmax,"",RGB(0,0,0));
        MessageBoxA(0,AnsiString("������������� �������� "+AnsiString(fmax)+" � ����� "+AnsiString(max)).c_str(),"�������",MB_OK);
        //double min = fibmin();
        //Chart1->Series[1]->AddXY(min, f(min),"",RGB(0,0,0));

}
//---------------------------------------------------------------------------
