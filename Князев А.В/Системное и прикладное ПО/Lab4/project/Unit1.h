//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>

#include "Unit3.h"
#include "Unit4.h"
#include "Unit2.h"
#include "Unit5.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TImageList *ImageList1;
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TQuery *Query1;
        TToolButton *ToolButton8;
        TDataSource *DataSource2;
        TDBGrid *DBGrid2;
        TDBNavigator *DBNavigator1;
        TLabel *Label1;
        TLabel *Label2;
        TDBNavigator *DBNavigator2;
        TQuery *Query2;
        TSplitter *Splitter1;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton3;
        TQuery *Query3;
        TMenuItem *N13;
        TMenuItem *N14;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TMenuItem *N15;
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall ToolButton12Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
