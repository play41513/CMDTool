#ifndef ConstantStringH
#define ConstantStringH
//---------------------------------------------------------------------------
//標題
#define APP_TITLE "PD Voltage Test Tool  ver 3.0 ( ActionStar.)";

#define STEP_GET_USB_DEVICE				1
#define STEP_CMD						2
#define STEP_CMD_CHECK_REPORT_METHOD	3
#define STEP_CHECK_REPORT_FILE			4
#define STEP_CHECK_REPORT_LINE			5
#define STEP_PASS						6
#define STEP_FAIL						7
#define STEP_WAIT_DEV_OUTPUT			8
#define STEP_START_DELAY 				9
#define STEP_REMOVE_ASIX				10
#define STEP_CHECK_SYS_FILE				11

#define WM_UI 				 WM_USER+100
#define WP_UI_RESULT_WAIT	 WM_UI+1
#define WP_UI_RESULT_TEST	 WM_UI+2
#define WP_UI_RESULT_PASS	 WM_UI+3
#define WP_UI_RESULT_FAIL	 WM_UI+4

#define WM_REPOET 			 WM_USER+200
#define WP_REPOET_LINE		 WM_REPOET+1
#define WP_REPOET_CLEAR		 WM_REPOET+2
#define WP_REPOET_SYS_FILE   WM_REPOET+3

typedef struct _INI_DESCRIPOR
{
	AnsiString ININame;


	AnsiString ToolName;
	AnsiString Cmdline;
	AnsiString AutoVPIDContent;
	AnsiString FileName;
	AnsiString Content[10];

	bool bAutoScreen;
	bool bAutoVPID;
	bool bAutoStart;
	bool bReportingMethodIsFile;

	DWORD dwAutoScreenCount;
	DWORD dwDelayTimeStart;
	DWORD dwFailRepeatCount;
	DWORD dwContentLineCount;

	AnsiString ErrorMsg;
	AnsiString ReportMsg;
}INI_DESCRIPOR;

typedef struct _LOG_DESCRIPOR
{
  AnsiString datetime;
  AnsiString workorder;
  AnsiString userid;
  AnsiString mac;
  AnsiString sn;
  AnsiString workordersn;
  AnsiString result;
  AnsiString testtime;
  AnsiString errorcode;

}LOG_DESCRIPOR;


#define MB_WARNING(handle, msg) MessageBox(handle, msg, MB_CAPTIONWARNING, MB_ICONWARNING)
//---------------------------------------------------------------------------
#endif
