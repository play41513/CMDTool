// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
AnsiString Temp;
bool MouseIsDown = false;
TPoint PanelMouseDownPos;
// ---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner) : TForm(Owner) {
	mFileControl = new cFileControl(&INI_Desc);
	if(!mFileControl->FindINIFile())
	{
		MessageBox(frmMain->Handle, "(!)設定檔讀取錯誤", NULL, MB_ICONWARNING);
		PostMessage(Handle,WM_QUIT,0,0);
	}
	//消息
	OldFormWndProc = this->WindowProc;
	this->WindowProc = FormWndProc;

	plName->Caption = INI_Desc.ToolName;
	plCMDLine->Caption = INI_Desc.Cmdline;
	if(!INI_Desc.bAutoScreen && !INI_Desc.bAutoVPID)
	{
		plResult->Caption = "Start";
		plResult->BevelOuter = bvLowered;
		plResult->BevelInner = bvSpace;
    }
	mainThread = new TMainThread(false,frmMain->Handle,&INI_Desc);
	if(INI_Desc.bAutoStart)
		mainThread->SetThreadStepStart();
}
void __fastcall TfrmMain::FormWndProc(TMessage& Message)
{
	switch(Message.Msg)
	{
		case WM_UI:
			switch(Message.WParam)
			{
				case WP_UI_RESULT_WAIT:
					plResult->Caption = "Wait...";
					plResult->Color = clCream;
					break;
				case WP_UI_RESULT_PASS:
					plResult->Caption = "PASS";
					plResult->Color = clGreen;
					break;
				case WP_UI_RESULT_FAIL:
					plResult->Caption = "FAIL";
					plResult->Color = clRed;
					break;
				case WP_UI_RESULT_TEST:
					plResult->Caption = "Testing...";
					plResult->Color = clCream;
					break;
			}
			break;
		case WM_REPOET:
			switch(Message.WParam)
			{
				case WP_REPOET_LINE:
					moReport->Text = INI_Desc.ReportMsg;
					break;
				case WP_REPOET_CLEAR:
					moReport->Clear();
					break;
				case WP_REPOET_SYS_FILE:
					lbxEnum->Items->Text = mainThread->mFileList->Text;
					break;
            }

	}
	TForm :: WndProc(Message);
}
// ---------------------------------------------------------------------------
void __fastcall TfrmMain::FormResize(TObject *Sender)
{
	//Width = 352;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::plResultClick(TObject *Sender)
{
	if(!INI_Desc.bAutoScreen && !INI_Desc.bAutoVPID)
	{
		mainThread->SetThreadStepStart();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::lbxEnumDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State)
{
	TListBox *lbx = (TListBox *)Control;
	if(lbx == NULL) return;
	bool bPass =  lbx->Items->Strings[Index].Pos("[O]") ? true:false;
	if(bPass)
		lbx-> Canvas-> Font-> Color = clGreen;
	else
		lbx-> Canvas-> Font-> Color = clHotLight;
	lbx-> Canvas-> TextRect(Rect, 1, Rect.Top + 1, lbx-> Items-> Strings[Index]);
	frmMain->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::lbxEnumDblClick(TObject *Sender)
{
    int index = lbxEnum->ItemIndex;
    if (index >= 0 && index < lbxEnum->Items->Count)
    {
		AnsiString path = lbxEnum->Items->Strings[index];
		AnsiString folder = ExtractFilePath(path);
        ShellExecute(0, "open", folder.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::plLoginTitleMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if (Button == mbLeft) // 確認是左鍵按下
    {
		MouseIsDown = true;
		PanelMouseDownPos = Point(X, Y);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::plLoginTitleMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
    if (MouseIsDown)
    {
		TPoint NewPos = ClientToScreen(Point(X, Y));
		NewPos.x -= PanelMouseDownPos.x;
		NewPos.y -= PanelMouseDownPos.y;
		Left = NewPos.x;
		Top = NewPos.y;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::plLoginTitleMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (Button == mbLeft) // 確認是左鍵放開
    {
        MouseIsDown = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ImgCloseLoginWindowsClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ImgCloseLoginWindowsMouseEnter(TObject *Sender)
{
	plCloseLoginWindows->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ImgCloseLoginWindowsMouseLeave(TObject *Sender)
{
	plCloseLoginWindows->BevelOuter = bvNone;
}
//---------------------------------------------------------------------------


