#include "stdafx.h"
#include "GameClientEngine.h"


CGameClientEngine::CGameClientEngine()
{
}


CGameClientEngine::~CGameClientEngine()
{
}

BEGIN_MESSAGE_MAP(CGameClientEngine, CGameFrameEngine)
//	ON_WM_TIMER()
 	ON_MESSAGE(IDM_START, OnStart)
// 	ON_MESSAGE(IDM_OUT_CARD, OnOutCard)
// 	ON_MESSAGE(IDM_CARD_OPERATE, OnCardOperate)
// 	ON_MESSAGE(IDM_TRUSTEE_CONTROL, OnStusteeControl)
// 	ON_MESSAGE(IDM_SICE_FINISH, OnSiceFinish)
// 	ON_MESSAGE(IDM_USER_ACTION, OnUserAction)
// 	ON_MESSAGE(IDM_MOVE_CARD_FINISH, OnMoveCardFinish)
END_MESSAGE_MAP()



//创建引擎
bool CGameClientEngine::OnInitGameEngine()
{

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	m_pIClientKernel->SetGameAttribute(KIND_ID, GAME_PLAYER, VERSION_CLIENT, hIcon, GAME_NAME);

	return true;
}


//重置函数
bool CGameClientEngine::OnResetGameEngine()
{

	return true;
}

//时钟删除
bool CGameClientEngine::OnEventGameClockKill(WORD wChairID)
{
	return true;
}

//时钟信息
bool CGameClientEngine::OnEventGameClockInfo(WORD wChairID, UINT nElapse, WORD wClockID)
{

	return false;
}

//旁观消息
bool CGameClientEngine::OnEventLookonMode(VOID * pData, WORD wDataSize)
{
	//扑克控制

	return true;
}

//游戏消息
bool CGameClientEngine::OnEventGameMessage(WORD wSubCmdID, VOID * pData, WORD wDataSize)
{
	//停止色子动画

	return true;
}

//场景消息
bool CGameClientEngine::OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, VOID * pData, WORD wDataSize)
{

	return false;
}

LRESULT CGameClientEngine::OnStart(WPARAM wParam, LPARAM lParam)
{
	// 这里相应 开始按钮。。

	// 设置 GameClientView 自己的牌

//	m_GameClientView.m_UserCard.SetCardData(0, false);

// 	//堆立扑克
// 	for (WORD i = 0; i < GAME_PLAYER; i++)
// 	{
// 		m_GameClientView.m_HeapCard[i].ResetCardData();
// 		m_GameClientView.m_HeapCard[i].SetHeapCardInfo(0, 0);
// 	}

	return 0;
}
