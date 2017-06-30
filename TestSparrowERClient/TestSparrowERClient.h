
// TestSparrowERClient.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "stdafx.h"
#include "resource.h"		// 主符号


// CTestSparrowERClientApp: 
// 有关此类的实现，请参阅 TestSparrowERClient.cpp
//

class CTestSparrowERClientApp : public CGameFrameApp
{
public:
	CTestSparrowERClientApp();
	virtual ~CTestSparrowERClientApp();


// 	virtual BOOL InitInstance();

public:
	//创建引擎
	virtual CGameFrameEngine * GetGameFrameEngine(DWORD dwSDKVersion);


};

extern CTestSparrowERClientApp theApp;
