//---------------------------------------------------------------------------

#ifndef LogMsgH
#define LogMsgH
#include <queue>
#include <direct.h>
#include <fstream.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "ConstantString.h"
//---------------------------------------------------------------------------
class cLogMsg
{
	private:
		std::queue<AnsiString> queMsg;
		AnsiString strLogName;
		AnsiString strLocalLog;
		AnsiString strErrorMsg;
		AnsiString strStartTime;
		AnsiString WNetERROR_MSG;
		DWORD dwWriteLogCount;

		LOG_DESCRIPOR LOG_DESC;
		DWORD dwStartTime;
		void SetEndTimeMsg();
	public:
		cLogMsg::cLogMsg(void);
		void AddLineToLogQueue(AnsiString Line);
		void AddLocalFilePath(AnsiString ToolName);
		void WriteLocalLOG(AnsiString Line,bool bPass);
		void WriteErrorMsg(AnsiString Line);
		void SetStartTimeMsg();
        AnsiString ReadQueMsg();
};
#endif
