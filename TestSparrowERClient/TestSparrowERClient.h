
// TestSparrowERClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "stdafx.h"
#include "resource.h"		// ������


// CTestSparrowERClientApp: 
// �йش����ʵ�֣������ TestSparrowERClient.cpp
//

class CTestSparrowERClientApp : public CGameFrameApp
{
public:
	CTestSparrowERClientApp();
	virtual ~CTestSparrowERClientApp();


// 	virtual BOOL InitInstance();

public:
	//��������
	virtual CGameFrameEngine * GetGameFrameEngine(DWORD dwSDKVersion);


};

extern CTestSparrowERClientApp theApp;
