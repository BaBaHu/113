
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

// #include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#include "..\..\..\SDKCondition.h"
#ifdef SDK_CONDITION

//////////////////////////////////////////////////////////////////////////////////
//��������
//////////////////////////////////////////////////////////////////////////////////
//��������

#include "..\..\..\������\Include\GameFrameHead.h"

#include "../��Ϣ����/CMD_Game.h"

#ifndef _DEBUG
#ifndef _UNICODE
#pragma comment (lib,"../../../������/Lib/Ansi/WHImage.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/GameFrame.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/GameEngine.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/SkinControl.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/ServiceCore.lib")
#else
#pragma comment (lib,"../../../������/Lib/Unicode/WHImage.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/GameFrame.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/GameEngine.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/SkinControl.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/ServiceCore.lib")
#endif
#else
#ifndef _UNICODE
#pragma comment (lib,"../../../������/Lib/Ansi/WHImageD.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/GameFrameD.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/GameEngineD.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/SkinControlD.lib")
#pragma comment (lib,"../../../������/Lib/Ansi/ServiceCoreD.lib")
#else
#pragma comment (lib,"../../../������/Lib/Unicode/WHImageD.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/GameFrameD.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/GameEngineD.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/SkinControlD.lib")
#pragma comment (lib,"../../../������/Lib/Unicode/ServiceCoreD.lib")
#endif
#endif

//////////////////////////////////////////////////////////////////////////////////

#else

//////////////////////////////////////////////////////////////////////////////////
//ϵͳ����

#include "..\..\..\..\ϵͳģ��\�ͻ������\��Ϸ���\GameFrameHead.h"

#ifndef _DEBUG
#ifndef _UNICODE
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/WHImage.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/GameFrame.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/GameEngine.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/SkinControl.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/ServiceCore.lib")
#else
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/WHImage.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/GameFrame.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/GameEngine.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/SkinControl.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/ServiceCore.lib")
#endif
#else
#ifndef _UNICODE
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/WHImageD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/GameFrameD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/GameEngineD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/SkinControlD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Ansi/ServiceCoreD.lib")
#else
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/WHImageD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/GameFrameD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/GameEngineD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/SkinControlD.lib")
#pragma comment (lib,"../../../../ϵͳģ��/���ӿ�/Unicode/ServiceCoreD.lib")
#endif
#endif

//////////////////////////////////////////////////////////////////////////////////





#endif