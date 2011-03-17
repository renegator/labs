//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
sg->Cells[0][0]="1";
sg->Cells[1][0]="1";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        sg->ColCount= 1<<Edit1->Text.ToInt();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int nn = Edit1->Text.ToInt();
        int n = 1<<nn;
        double* a = new double[n];
        for(int i=0;i<n;i++)
        {
                a[i] = sg->Cells[i][0].ToDouble();
        }
        double* aa = new double[n];
        int i=0;
        //-----------------------
        for (int lvl=1; lvl<=nn; lvl++)
        {
             int d = 1<<(lvl-1); // V_lvl
             for(int base=1; base+d<=n; base+=d+d)
             {
                for(int b=base; b<d+base; b++)
                {
                        aa[i]=a[b-1]+a[b+d-1];
                        i++;
                }
                for(int b=base; b<d+base; b++)
                {
                        aa[i]=a[b-1]-a[b+d-1];
                        i++;
                }
             }
             double* c = a;
             a = aa;
             aa = c;
             i = 0;
        }
        //----------------
        for(int i=0;i<n;i++)
        {
                sg->Cells[i][0] = FloatToStr(a[i]);
        }
        delete aa;
        delete a;
}
//---------------------------------------------------------------------------
