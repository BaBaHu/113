#pragma once

#include "Resource.h"
#include "CardControl.h"

//////////////////////////////////////////////////////////////////////////
//��Ϣ����

#define IDM_START					(WM_USER+100)						//��ʼ��Ϣ
#define IDM_OUT_CARD				(WM_USER+101)						//������Ϣ
#define IDM_TRUSTEE_CONTROL			(WM_USER+102)						//�йܿ���
#define IDM_CARD_OPERATE			(WM_USER+106)						//��Ҳ�����
#define IDM_MOVE_CARD_FINISH		(WM_USER+107)						//�˿˶���������Ϣ


class CGameClientView : public CGameFrameViewGDI
{
public:
	CGameClientView();
	virtual~CGameClientView();

public:

	//WIN7֧��
	virtual bool RealizeWIN7() { return true; }
protected:
	DECLARE_MESSAGE_MAP()

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	//���غ���
private:
	//���ý��� ����
	virtual VOID ResetGameView();

	//�����ؼ�  һ��ʼ
	virtual VOID RectifyControl(INT nWidth, INT nHeight);
	//�滭����
	virtual VOID DrawGameView(CDC * pDC, INT nWidth, INT nHeight);
	//�����
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

public:
	CBitImageEx						m_ImageBack;						//����ͼ��
	CBitImageEx						m_ImageCenter;						//LOGOͼ	

	
	CHeapCard						m_HeapCard[GAME_PLAYER];					//�����˿�
	CUserCard						m_UserCard;									//�����û��ƣ������÷�λ����������ǰ������

	CTableCard						m_TableCard[GAME_PLAYER];					//�����˿�  ������ ���泯�ϵ��ƣ����簵���ġ����񲻶�

	CWeaveCard						m_WeaveCard[GAME_PLAYER][MAX_WEAVE];		//����˿�  ��ʾ:�ܣ�������
	CDiscardCard					m_DiscardCard[GAME_PLAYER];					//�����˿� �Ѿ������ƣ���ʾ��������

	CCardControl					m_HandCardControl;							//�����˿�

private:
	CSkinButton						m_btStart;							//��ʼ��ť
};

