//---------------------------------------------------------------------------


#pragma hdrstop

#include <vcl.h>
#include "LogMsg.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

AnsiString strLogPath,strLogName;
cLogMsg::cLogMsg(void) {
	dwWriteLogCount = 0;
}

void cLogMsg::AddLineToLogQueue(AnsiString Line)
{
	queMsg.push(Line);
}
AnsiString cLogMsg::ReadQueMsg()
{
	if(queMsg.size())
	{
		AnsiString strTemp;
		strTemp = queMsg.front();
		queMsg.pop();
		return strTemp;
	}
	return "";
}
void cLogMsg::AddLocalFilePath(AnsiString ToolName)
{
	AnsiString Path = "C:\\ASMP\\log\\Shopfloor\\"+ToolName+"\\";
	if(!DirectoryExists(Path))
	{
		AnsiString SS,Temp = "";
		while(true)
		{
			SS = Path.SubString(1,Path.Pos("\\"));
			Path.Delete(1,Path.Pos("\\"));
			Temp+=SS;
			_mkdir( Temp.c_str());
			if(Path == "")
				break;
		}
	}
	strLogPath = Path;
}
void cLogMsg::WriteErrorMsg(AnsiString Line)
{
	LOG_DESC.errorcode = Line;
}
void cLogMsg::SetStartTimeMsg()
{
	dwStartTime = GetTickCount();
}
void cLogMsg::SetEndTimeMsg()
{
	float dwTimeTemp = (float)(GetTickCount()-dwStartTime)/1000;
	LOG_DESC.testtime.printf("%.2f",dwTimeTemp);
}

void cLogMsg::WriteLocalLOG(AnsiString Line,bool bPass)
{
	SetEndTimeMsg();
	//AddLineToLogQueue("Writing to the Log...");
	//dwWriteLogCount++;
	AnsiString Temp;
	Temp = "datetime,"+AnsiString(FormatDateTime("yyyy-mm-dd,hh-nn-ss", Now()))
		+",workorder,"+LOG_DESC.workorder
		+",userid,"+LOG_DESC.userid
		+",mac,,sn,"
		+",worksn,"+LOG_DESC.workordersn
		+",testtime,"+LOG_DESC.testtime
		+","+Line;
	Temp += bPass ? ",result,PASS" : ",Result,FAIL";
	if(!bPass)
		Temp += ",errorcode,"+LOG_DESC.errorcode;
	Temp += "\r\n";


	FILE * fp;
	strLogName = strLogPath+AnsiString(FormatDateTime("yyyy-mm-dd_hh-nn-ss", Now()))+".log";
	fp = fopen(strLogName.c_str(),"a+");
	fseek( fp, 0, SEEK_END);
	fwrite(Temp.c_str(),Temp.Length(),1,fp); //寫入一筆資料
	fclose(fp);
}
