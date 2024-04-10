/* ConstantString.h 1: */
/* ConstantString.h 2: */
/* ConstantString.h 3: */
/* ConstantString.h 4: */
/* ConstantString.h 5: */
/* ConstantString.h 6: */
/* ConstantString.h 7: */
/* ConstantString.h 8: */
/* ConstantString.h 9: */
/* ConstantString.h 10: */
/* ConstantString.h 11: */
/* ConstantString.h 12: */
/* ConstantString.h 13: */
/* ConstantString.h 14: */
/* ConstantString.h 15: */
/* ConstantString.h 16: */
/* ConstantString.h 17: */
/* ConstantString.h 18: */
/* ConstantString.h 19: */
/* ConstantString.h 20: */
/* ConstantString.h 21: */
/* ConstantString.h 22: */
/* ConstantString.h 23: */
/* ConstantString.h 24: */
/* ConstantString.h 25: */
/* ConstantString.h 26: */
/* ConstantString.h 27: */
/* ConstantString.h 28: */
/* ConstantString.h 29: */
/* ConstantString.h 30: */
/* ConstantString.h 31: */typedef struct _ITEM_PD_DESCRIPOR
/* ConstantString.h 32: */{
/* ConstantString.h 33: */bool	 bTest;
/* ConstantString.h 34: */
/* ConstantString.h 35: */AnsiString FullLoadCurrent;
/* ConstantString.h 36: */AnsiString NoLoadMaxVoltage;
/* ConstantString.h 37: */AnsiString NoLoadMinVoltage;
/* ConstantString.h 38: */AnsiString FullLoadMaxVoltage;
/* ConstantString.h 39: */AnsiString FullLoadMinVoltage;
/* ConstantString.h 40: */
/* ConstantString.h 41: */TPanel* plNoLoadValue;
/* ConstantString.h 42: */TPanel* plFullLoadValue;
/* ConstantString.h 43: */AnsiString PD_Voltage;
/* ConstantString.h 44: */AnsiString SetVoltageCMD;
/* ConstantString.h 45: */bool bWattIsOver;
/* ConstantString.h 46: */
/* ConstantString.h 47: */DWORD dwLoadTime;
/* ConstantString.h 48: */DWORD dwBeforeChangeVoltageDelay;
/* ConstantString.h 49: */DWORD dwAfterChangeVoltageDelay;
/* ConstantString.h 50: */DWORD dwBeforeFullLoadDelay;
/* ConstantString.h 51: */DWORD dwAfterFullLoadDelay;
/* ConstantString.h 52: */DWORD dwAfterTestDelay;
/* ConstantString.h 53: */}ITEM_PD_DESCRIPOR;
/* ConstantString.h 54: */
/* ConstantString.h 55: */typedef struct _INI_DESCRIPOR
/* ConstantString.h 56: */{
/* ConstantString.h 57: */bool VPID_AutoTest;
/* ConstantString.h 58: */AnsiString Auto_VID;
/* ConstantString.h 59: */AnsiString Auto_PID;
/* ConstantString.h 60: */
/* ConstantString.h 61: */bool Voltage_AutoTest;
/* ConstantString.h 62: */AnsiString Auto_VoltageValue;
/* ConstantString.h 63: */AnsiString LossVol;
/* ConstantString.h 64: */
/* ConstantString.h 65: */DWORD dwDelayTime_ChangeTo5V;
/* ConstantString.h 66: */DWORD dwDelayTime_ChangeTo20V;
/* ConstantString.h 67: */
/* ConstantString.h 68: */ITEM_PD_DESCRIPOR PITEM_PD_DESCRIPOR[5];
/* ConstantString.h 69: */
/* ConstantString.h 70: */bool bSetting;
/* ConstantString.h 71: */bool bTesting;
/* ConstantString.h 72: */bool bError;
/* ConstantString.h 73: */bool bHIDError;
/* ConstantString.h 74: */bool bSwitchBack5V;
/* ConstantString.h 75: */bool bExitWhenPASS;
/* ConstantString.h 76: */
/* ConstantString.h 77: */AnsiString strReadValueNow;
/* ConstantString.h 78: */AnsiString strLoaderName;
/* ConstantString.h 79: */DWORD dwTestStatus;
/* ConstantString.h 80: */DWORD dwExitWhenPASSCount;
/* ConstantString.h 81: */
/* ConstantString.h 82: */}INI_DESCRIPOR;
/* ConstantString.h 83: */
/* ConstantString.h 84: */
/* ConstantString.h 85: */
/* ConstantString.h 86: */
/* ConstantString.h 87: */
/* ConstantString.h 88: */
/* ConstantString.h 89: */
/* ConstantString.h 90: */
/* ConstantString.h 91: */
/* ConstantString.h 92: */
/* ConstantString.h 93: */
/* ConstantString.h 94: */
/* ConstantString.h 95: */
/* ConstantString.h 96: */