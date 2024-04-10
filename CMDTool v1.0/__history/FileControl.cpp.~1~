//---------------------------------------------------------------------------


#pragma hdrstop

#include <vcl.h>
#include "FileControl.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

bool cFileControl::FindINIFile()
{
	TSearchRec Sr;
	TStringList*FileList=new TStringList();
	if(FindFirst("*.ini",faAnyFile,Sr)==0)
	{
		do
		{
			FileList->Add(Sr.Name);
		}
		while(FindNext(Sr)==0);
		FindClose(Sr);
	}
	if(FileList->Count>1||FileList->Count==0)
	{
		delete FileList;
		return false;
	}
	else
	{
		strSettingINI = ExtractFilePath(Application->ExeName)+FileList->Strings[0];
		INI_Desc.ININame = FileList->Strings[0].SubString(1,FileList->Strings[0].Pos(".")-1);
		delete FileList;
		return true;
	}
}
INI_DESCRIPOR cFileControl::ReadINIFile()
{
	AnsiString value;
	TIniFile *ini;
	String fn = ChangeFileExt(strSettingINI, ".ini");
	ini = new TIniFile(fn);
	INI_Desc.VPID_AutoTest = ini->ReadBool("DUT_VPID_AUTO_TEST","AUTO",false);
	value	   			   = ini->ReadString("DUT_VPID_AUTO_TEST","PIDVID","vid_0000&pid_0000");
	INI_Desc.Auto_VID = value.SubString(5,4);
	INI_Desc.Auto_PID = value.SubString(14,4);
	//
	INI_Desc.Voltage_AutoTest = ini->ReadBool("DUT_VOLTAGE_AUTO_TEST","AUTO",false);
	INI_Desc.Auto_VoltageValue = ini->ReadString("DUT_VOLTAGE_AUTO_TEST","Voltage_Value","5.00");
	INI_Desc.dwDelayTime_Auto_Voltage = ini->ReadInteger("DUT_VOLTAGE_AUTO_TEST","DelayTime",0);

	INI_Desc.bSwitchBack5V = false;
	INI_Desc.bExitWhenPASS = ini->ReadBool("Parameter","ExitWhenPASS",false);
	INI_Desc.dwExitWhenPASSCount = ini->ReadInteger("Parameter","ExitWhenPASSCount",1);
	INI_Desc.strLoaderName = ini->ReadString("Parameter","LoaderName","3311F");
	//
	INI_Desc.WNetLOG.bWNetLog = ini->ReadBool("WNetLog","WriteLog",false);
	INI_Desc.WNetLOG.IP		  = ini->ReadString("WNetLog","IP","");
	INI_Desc.WNetLOG.Password = ini->ReadString("WNetLog","Password","");
	INI_Desc.WNetLOG.User	  = ini->ReadString("WNetLog","User","");
	INI_Desc.WNetLOG.ufolder  = ini->ReadString("WNetLog","ufolder","");

	INI_Desc.WNetLOG.bRecordMAC = ini->ReadBool("RecordMAC","RecordMAC",false);
	INI_Desc.WNetLOG.NetworkCardName = ini->ReadString("RecordMAC","NerworkCardName","");
	//
	for(int i = 0 ; i < 5 ; i++)
	{
		INI_Desc.PITEM_PD_DESCRIPOR[i].PD_Voltage
			= ini->ReadString("PD_"+AnsiString(i+1),"Voltage","5");
		INI_Desc.PITEM_PD_DESCRIPOR[i].bTest
			= ini->ReadBool("PD_"+AnsiString(i+1),"TEST",true);
		INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadMinVoltage
			= ini->ReadString("PD_"+AnsiString(i+1),"NoLoadVoltageRange_Min","0");
		INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadMaxVoltage
			= ini->ReadString("PD_"+AnsiString(i+1),"NoLoadVoltageRange_Max","0");
		INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadMinVoltage
			= ini->ReadString("PD_"+AnsiString(i+1),"FullLoadVoltageRange_Min","0");
		INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadMaxVoltage
			= ini->ReadString("PD_"+AnsiString(i+1),"FullLoadVoltageRange_Max","0");
		INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadCurrent
			= ini->ReadString("PD_"+AnsiString(i+1),"LoadCurrent","0");
		INI_Desc.PITEM_PD_DESCRIPOR[i].FullInitLoadCurrent
			= ini->ReadString("PD_"+AnsiString(i+1),"InitLoadCurrent","0");
		INI_Desc.PITEM_PD_DESCRIPOR[i].dwLoadTime
			= ini->ReadInteger("PD_"+AnsiString(i+1),"LoadTime",1000);
		INI_Desc.PITEM_PD_DESCRIPOR[i].LossVol
			= ini->ReadString("PD_"+AnsiString(i+1),"LossVoltage","0");
		//
		INI_Desc.PITEM_PD_DESCRIPOR[i].dwBeforeChangeVoltageDelay
			= ini->ReadInteger("PD_"+AnsiString(i+1),"BeforeChangeVoltageDelay",0);
		INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterChangeVoltageDelay
			= ini->ReadInteger("PD_"+AnsiString(i+1),"AfterChangeVoltageDelay",0);
		INI_Desc.PITEM_PD_DESCRIPOR[i].dwBeforeFullLoadDelay
			= ini->ReadInteger("PD_"+AnsiString(i+1),"BeforeFullLoadTestDelay",0);
		INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterFullLoadDelay
			= ini->ReadInteger("PD_"+AnsiString(i+1),"AfterFullLoadTestDelay",0);
		INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterTestDelay
			= ini->ReadInteger("PD_"+AnsiString(i+1),"AfterTestDelay",0);
	}
	return INI_Desc;
}
void cFileControl::WriteINIFile(INI_DESCRIPOR info)
{
	TIniFile *ini;
	String fn = ChangeFileExt(strSettingINI, ".ini");
	if (!FileExists(fn)) {
		return;
	}
	ini = new TIniFile(fn);
	INI_Desc = info;
	//
	ini->WriteBool("DUT_VPID_AUTO_TEST","AUTO"
		,INI_Desc.VPID_AutoTest);
	ini->WriteString("DUT_VPID_AUTO_TEST","PIDVID"
		,"vid_"+INI_Desc.Auto_VID+"&pid_"+INI_Desc.Auto_PID);
	//
	ini->WriteBool("DUT_VOLTAGE_AUTO_TEST","AUTO",INI_Desc.Voltage_AutoTest);
	ini->WriteString("DUT_VOLTAGE_AUTO_TEST","Voltage_Value",INI_Desc.Auto_VoltageValue);

	for(int i = 0 ; i < 5 ; i++)
	{
		ini->WriteString("PD_"+AnsiString(i+1),"Voltage"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].PD_Voltage);
		ini->WriteBool("PD_"+AnsiString(i+1),"TEST"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].bTest);
		ini->WriteString("PD_"+AnsiString(i+1),"NoLoadVoltageRange_Min"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadMinVoltage);
		ini->WriteString("PD_"+AnsiString(i+1),"NoLoadVoltageRange_Max"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].NoLoadMaxVoltage);
		ini->WriteString("PD_"+AnsiString(i+1),"FullLoadVoltageRange_Min"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadMinVoltage);
		ini->WriteString("PD_"+AnsiString(i+1),"FullLoadVoltageRange_Max"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadMaxVoltage);
		ini->WriteString("PD_"+AnsiString(i+1),"LoadCurrent"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].FullLoadCurrent);
		ini->WriteString("PD_"+AnsiString(i+1),"InitLoadCurrent"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].FullInitLoadCurrent);
		ini->WriteInteger("PD_"+AnsiString(i+1),"LoadTime"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].dwLoadTime);
		//
		ini->WriteInteger("PD_"+AnsiString(i+1),"BeforeChangeVoltageDelay"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].dwBeforeChangeVoltageDelay);
		ini->WriteInteger("PD_"+AnsiString(i+1),"AfterChangeVoltageDelay"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterChangeVoltageDelay);
		ini->WriteInteger("PD_"+AnsiString(i+1),"BeforeFullLoadTestDelay"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].dwBeforeFullLoadDelay);
		ini->WriteInteger("PD_"+AnsiString(i+1),"AfterFullLoadTestDelay"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterFullLoadDelay);
		ini->WriteInteger("PD_"+AnsiString(i+1),"AfterTestDelay"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].dwAfterTestDelay);
		ini->WriteString("PD_"+AnsiString(i+1),"LossVoltage"
			,INI_Desc.PITEM_PD_DESCRIPOR[i].LossVol);
	}
	//
	delete ini;
}
