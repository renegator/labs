//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
//sg1->Cells[0][0]="�������";
//sg1->Cells[1][0]="�����";
//sg1->Cells[2][0]="���";
sg2->Cells[0][0]="�������������";
sg2->Cells[1][0]="�����";
sg2->Cells[2][0]="��������";
}
//---------------------------------------------------------------------------
#define TT(X) case X:\
        l->Items->Add(AnsiString(r.value)+" - "#X+"["+AnsiString(X)+"]");\
        break;


void __fastcall TForm1::N3Click(TObject *Sender)
{

        l->Clear();
        //sg1->RowCount=2;
        sg2->RowCount=2;
        LexReader r(Memo1->Text.c_str());
        Token t;
        try {
        while(( t = r.nextToken()) != END)
        {
                switch(t)
                {
                TT(TYPE_ID)
                TT(TYPE_NUM)
                TT(PLUS)
                //TT(MINUS)
                TT(MUL)
                TT(MORE)
                TT(LESS)
                TT(EQUAL)
                TT(BRACKET_OPEN)
                TT(BRACKET_CLOSE)
                TT(SEMICOLON)
                TT(KEYWORD_IF)
                TT(KEYWORD_ELSE)
                TT(KEYWORD_ENDIF)
                TT(KEYWORD_WHILE)
                TT(KEYWORD_ENDLOOP)
                }
        }
        }
        catch(...)
        {
                MessageBoxA(0,"������", "������ ��� ����������",MB_OK);
        }
        for(ArrayMap::iterator i = r.identifiers.begin();i!=r.identifiers.end();++i)
        {
                char* t = *i;
                sg2->Cells[0][sg2->RowCount-1] = t;
                sg2->Cells[1][sg2->RowCount-1] = i.getval();
                sg2->RowCount = sg2->RowCount+1;
        }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
        try {
                Parser p(Memo1->Text.c_str());
                if(p.parse())MessageBoxA(0,"������� ���������","���������",MB_OK);
        }
        catch(LexReader::Error err)
        {
                MessageBoxA(0,
                (AnsiString("����������� ������\"")+AnsiString(err.message)+"\" � ������� "+AnsiString(err.position)).c_str(),
                "������",MB_OK);
        }
        catch(Parser::Error err)
        {
                MessageBoxA(0,"�������������� ������","������",MB_OK);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N5Click(TObject *Sender)
{
        Memo1->Enabled=true;
        l->Clear();
        sg2->RowCount=2;
        sg2->Cells[0][1]="";
        sg2->Cells[1][1]="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
        try {
                char* sss=Memo1->Text.c_str();
                AttributeParser p(sss);
                p.parse();// MessageBoxA(0,"������� ���������","���������",MB_OK);
                int k = 0;
                l->Items->Clear();
                delete exe.code;
                exe.code = new Translator::Code[p.coden+2];
                for(AttributeParser::TM* t=p.f ;t!=0;t=t->n)
                {
                        AnsiString s= AnsiString(k).sprintf("%04u: ",k);
                        switch(t->t)
                        {
                        case FADD:s=s+"�������("+IntToStr(t->p)+", "+IntToStr(t->q)+", "+IntToStr(t->s)+");";break;
                        case FMUL:s=s+"��������("+IntToStr(t->p)+", "+IntToStr(t->q)+", "+IntToStr(t->s)+");";break;
                        case FCMP:s=s+"��������("+IntToStr(t->p)+" "+(t->q==1?">":"<")+" "+IntToStr(t->s)+", "+IntToStr(*(t->r))+");";break;
                        case FMOV:s=s+"���������("+IntToStr(t->p)+", "+IntToStr(t->q)+");";break;
                        case FJZ:s=s+"������� �� 0("+IntToStr(t->p)+", "+IntToStr(t->q)+");";break;
                        case FJMP:s=s+"����������� �������("+IntToStr(t->p)+");";break;
                        case FLABEL:s=s+"�����("+IntToStr(*(t->r))+");";break;
                        }
                        l->Items->Add(s);
                        exe.code[k].t=t->t;
                        exe.code[k].q=t->q;
                        exe.code[k].p=t->p;
                        exe.code[k].s=t->s;
                        if((t->r)!=0)exe.code[k].r=(*(t->r));
                        k++;
                }
                exe.code[k].t=FSTOP;
                k=p.n;
                sg2->RowCount=k+1;
                for(int i = 1; i<sg2->RowCount+1;i++)
                {
                        sg2->Cells[0][i]="";
                        sg2->Cells[1][i]=i;
                        sg2->Cells[2][i]="0";
                }
                for(ArrayMap::iterator i = p.r.identifiers.begin();i!=p.r.identifiers.end();++i)
                {
                        char* t = *i;
                        int j = i.getval();
                        sg2->Cells[0][j] = t;
                        sg2->Cells[1][j] = j;
                        if(t[0]>='0'&&t[0]<='9')
                                {
                                        sg2->Cells[2][j]=sg2->Cells[0][j];
                                        exe.mem[j]=StrToInt(sg2->Cells[2][j]);
                                }
                }
                exe.n=k;
                exe.pos=0;
        }
        catch(...)
        {}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
        if(Memo1->Enabled) { N4Click(Sender); Memo1->Enabled=false; }
        int j;
        int v;
        int p=0;
        exe.step(j,v, p);
        if(j!=0)sg2->Cells[2][j]=v;
        l->ItemIndex=p;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
        N4Click(Sender);
        exe.run();
        for(int i=1;i<=exe.n;i++)
        sg2->Cells[2][i]=exe.mem[i];
}
//---------------------------------------------------------------------------

