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



//��������
bool CGameClientEngine::OnInitGameEngine()
{

	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	m_pIClientKernel->SetGameAttribute(KIND_ID, GAME_PLAYER, VERSION_CLIENT, hIcon, GAME_NAME);

	return true;
}


//���ú���
bool CGameClientEngine::OnResetGameEngine()
{

	return true;
}

//ʱ��ɾ��
bool CGameClientEngine::OnEventGameClockKill(WORD wChairID)
{
	return true;
}

//ʱ����Ϣ
bool CGameClientEngine::OnEventGameClockInfo(WORD wChairID, UINT nElapse, WORD wClockID)
{

	return false;
}

//�Թ���Ϣ
bool CGameClientEngine::OnEventLookonMode(VOID * pData, WORD wDataSize)
{
	//�˿˿���

	return true;
}

//��Ϸ��Ϣ
bool CGameClientEngine::OnEventGameMessage(WORD wSubCmdID, VOID * pData, WORD wDataSize)
{
	//ֹͣɫ�Ӷ���

	return true;
}

//������Ϣ
bool CGameClientEngine::OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, VOID * pData, WORD wDataSize)
{

	return false;
}

LRESULT CGameClientEngine::OnStart(WPARAM wParam, LPARAM lParam)
{
	// ������Ӧ ��ʼ��ť����

	// ���� GameClientView �Լ�����

//	m_GameClientView.m_UserCard.SetCardData(0, false);

// 	//�����˿�
// 	for (WORD i = 0; i < GAME_PLAYER; i++)
// 	{
// 		m_GameClientView.m_HeapCard[i].ResetCardData();
// 		m_GameClientView.m_HeapCard[i].SetHeapCardInfo(0, 0);
// 	}

	return 0;
}
