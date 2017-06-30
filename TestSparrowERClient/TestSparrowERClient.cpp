
// TestSparrowERClient.cpp : ����Ӧ�ó��������Ϊ��
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


//��������
CGameFrameEngine * CTestSparrowERClientApp::GetGameFrameEngine(DWORD dwSDKVersion)
{
	//�汾���
	if (InterfaceVersionCompare(VERSION_FRAME_SDK, dwSDKVersion) == false)
	{
		ASSERT(FALSE);
		return NULL;
	}

	//��������
	return new CGameClientEngine;
}

