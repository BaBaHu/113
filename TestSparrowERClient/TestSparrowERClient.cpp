
// TestSparrowERClient.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "TestSparrowERClient.h"
#include "GameClientEngine.h"

// #ifdef _DEBUG
// #define new DEBUG_NEW
// #endif

CTestSparrowERClientApp theApp;

CTestSparrowERClientApp::CTestSparrowERClientApp()
{


}

CTestSparrowERClientApp::~CTestSparrowERClientApp()
{

}


//创建引擎
CGameFrameEngine * CTestSparrowERClientApp::GetGameFrameEngine(DWORD dwSDKVersion)
{
	//版本检测
	if (InterfaceVersionCompare(VERSION_FRAME_SDK, dwSDKVersion) == false)
	{
		ASSERT(FALSE);
		return NULL;
	}

	//创建引擎
	return new CGameClientEngine;
}

