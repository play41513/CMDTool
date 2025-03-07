//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>

#include "MainThread.h"
#include <ExtCtrls.hpp>
#include "FileControl.h"
#include "ConstantString.h"
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *plMassProduction;
	TPanel *Panel6;
	TPanel *Panel7;
	TPanel *plName;
	TPanel *plCMDLine;
	TPanel *Panel3;
	TPanel *plResult;
	TPanel *Panel8;
	TMemo *moReport;
	TPanel *Panel9;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *plLoginTitle;
	TImage *ImageLogo;
	TPanel *plCloseLoginWindows;
	TImage *ImgCloseLoginWindows;
	TPanel *plCloseWindows;
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
	cFileControl * mFileControl;
	TMainThread *mainThread;

	INI_DESCRIPOR INI_Desc;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);

	TWndMethod OldFormWndProc;
	void __fastcall FormWndProc(TMessage& Message);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
