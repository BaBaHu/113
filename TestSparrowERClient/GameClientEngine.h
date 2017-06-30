#pragma once

#include "../��Ϣ����/CMD_Game.h"
#include "resource.h"
#include "GameClientView.h"

// GAME_LOGO               BITMAP                  "res\\GAME_LOGO.bmp"  
// ʹ�� CGameFrameEngine ��ע�����
// 1.������ ����һ�� GAME_LOGO ��bmp �������س���� ͼ��
// 2.���붨��һ��GameClientView �� 


class CGameClientEngine : public CGameFrameEngine
{
public:
	CGameClientEngine();

	~CGameClientEngine();

public:
	//��������
	virtual bool OnInitGameEngine();
	//���ú���
	virtual bool OnResetGameEngine();
	//��Ϸ����
	//	virtual void OnGameOptionSet();

	//ʱ���¼�
public:
	//ʱ��ɾ��
	virtual bool OnEventGameClockKill(WORD wChairID);
	//ʱ����Ϣ
	virtual bool OnEventGameClockInfo(WORD wChairID, UINT nElapse, WORD wClockID);

	//��Ϸ�¼�
public:
	//�Թ���Ϣ
	virtual bool OnEventLookonMode(VOID * pData, WORD wDataSize);
	//��Ϸ��Ϣ
	virtual bool OnEventGameMessage(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//������Ϣ
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, VOID * pData, WORD wDataSize);

	//��Ϣӳ��

protected:
	//ʱ����Ϣ
//	VOID OnTimer(UINT nIDEvent);
	//��ʼ��Ϣ
	LRESULT OnStart(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

protected:
	CGameClientView					m_GameClientView;					//��Ϸ��ͼ
};

