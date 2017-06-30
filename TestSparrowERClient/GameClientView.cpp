#include "stdafx.h"
#include "GameClientView.h"


#define IDC_START						100								//��ʼ��ť
#define IDC_TRUSTEE_CONTROL				104								//�йܿ���
#define IDC_SCORE						105								//��ְ�ť

//������ʶ
#define IDI_BOMB_EFFECT					101								//������ʶ
#define IDI_DISC_EFFECT					102								//����Ч��
#define IDI_MOVE_CARD					103								//

//������Ŀ
#define BOMB_EFFECT_COUNT				12								//������Ŀ
#define DISC_EFFECT_COUNT				8								//����Ч��		

#define MOVE_STEP_COUNT					4								//�ƶ�����
#define TIME_MOVE_CARD					5								//�ƶ�����ʱʱ��


BEGIN_MESSAGE_MAP(CGameClientView, CGameFrameViewGDI)
	ON_WM_CREATE()
// 	ON_WM_SETCURSOR()
// 	ON_WM_LBUTTONDOWN()
// 	ON_WM_TIMER()
END_MESSAGE_MAP()


CGameClientView::CGameClientView()
{
}

CGameClientView::~CGameClientView()
{
}

int CGameClientView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (__super::OnCreate(lpCreateStruct) == -1) return -1;

	g_CardResource.LoadResource(this);

	//����λͼ
	HINSTANCE hInstance = AfxGetInstanceHandle();
	m_ImageBack.LoadFromResource(this, hInstance, IDB_VIEW_BACK);
	m_ImageCenter.LoadFromResource(this, hInstance, IDB_VIEW_CENTER);

	enDirection Direction[] = { Direction_North,Direction_South };

	// ����������һ�ߣ�
 	m_HeapCard[0].SetDirection(Direction[0]);
 	m_HeapCard[1].SetDirection(Direction[1]);

	m_HandCardControl.LoadResource(this);
	m_HandCardControl.SetWindowSink(this);

	//����˿�
	for (WORD i = 0; i < GAME_PLAYER; i++)
	{
		m_DiscardCard[i].SetDirection(Direction[i]);

		for (BYTE j = 0; j < CountArray(m_WeaveCard[i]); j++)
		{
			m_WeaveCard[i][j].SetDisplayItem(true);
			m_WeaveCard[i][j].SetDirection(Direction[i]);
			m_WeaveCard[i][j].LoadResource(this);
		}
	}


	CRect rcCreate(0, 0, 0, 0);
	//�����ؼ�
	m_btStart.Create(NULL, WS_CHILD | WS_CLIPSIBLINGS, rcCreate, this, IDC_START);
	m_btStart.SetButtonImage(IDB_BT_START, AfxGetInstanceHandle(), false, false);
	m_btStart.ShowWindow(SW_HIDE);
	
	return 0;
}

VOID CGameClientView::ResetGameView()
{
//	m_UserCard.SetCardData(1, 1);
	
//�˿�����
	for (WORD i = 0; i < GAME_PLAYER; i++)
	{
		m_HeapCard[i].SetHeapCardInfo(0, 0);
		m_TableCard[i].SetCardData(NULL, 0);
		m_DiscardCard[i].SetCardData(NULL, 0);
		for (BYTE j = 0; j < CountArray(m_WeaveCard[i]); j++)
			m_WeaveCard[i][j].SetCardData(NULL, 0);
	}

	m_HandCardControl.SetPositively(true);
	m_HandCardControl.SetDisplayItem(true);


	m_btStart.ShowWindow(SW_HIDE);
}

VOID CGameClientView::RectifyControl(INT nWidth, INT nHeight)
{
	int m_nXFace = 50, m_nYFace = 50, m_nXBorder = 0, m_nYBorder = 0, m_nXTimer = 0, m_nYTimer = 0;

	int nXCenter = nWidth / 2;
	int nYCenter = nHeight / 2 - 20 ;	// windows �������0,0 �Ҽǵ�������Ļ�����Ͻǿ�ʼ�ģ� ��ʾ�ƵĻ���������Ҫ�ڴ˿�-20
	// ������20 ���µ���
	
	// �����Ƶ�λ��
	//m_HeapCard[0].SetControlPoint(nXCenter - 289 + 44, nYCenter - 215);

	// ˫��: nXCenter = nXCenter - ��������/2 * ÿ���ƵĿ�� 
	// ����: nXCenter = nXCenter - ��������/2 * ÿ���ƵĿ�� - һ���ƵĿ��/2

	//������С����ʱ��nWidth�ǹ̶��ģ����ԣ�����Ҳ�ǹ̶��ġ�
	m_HeapCard[0].SetControlPoint(nXCenter - 289 + 44, nYCenter - 215);
	m_HeapCard[1].SetControlPoint(nXCenter + 290 - 55, nYCenter + 212);

	m_UserCard.SetControlPoint(nWidth / 2 - 240, m_nYBorder + m_nYFace + 10);
	m_UserCard.SetDirection(Direction_North); // �����û��ķ�λ
	m_UserCard.SetCardData(3,false);		  // �����û��ж������ơ�

	m_UserCard.AddCardData(true);			  // ���һ����

//	m_TableCard[0].SetControlPoint(nWidth / 2 + 200, m_nYBorder + m_nYFace + 10);	
//	m_TableCard[0].SetDirection(Direction_North);
//  m_TableCard[1].SetControlPoint(nWidth / 2 - 200, nHeight - m_nYFace - m_nYBorder - 63);

	m_HandCardControl.SetBenchmarkPos(nWidth / 2 + 10, nHeight - m_nYFace - m_nYBorder - 9, enXCenter, enYBottom);

	BYTE cbCardData[7] = { 1,2,3,4,5,6,7};
	m_TableCard[0].SetCardData(cbCardData, 4);


	int nXControl = nWidth / 2 + 255;
	int nYControl = m_nYBorder + m_nYFace + 10;
	for (BYTE i = 0; i < CountArray(m_WeaveCard[0]); i++)
	{
		m_WeaveCard[0][i].SetControlPoint(nXControl, nYControl);
		nXControl -= 105;
	}

	//����˿�
	nXControl = nWidth / 2 - 295;
	nYControl = nHeight - m_nYFace - m_nYBorder - 63;
	for (BYTE i = 0; i < CountArray(m_WeaveCard[1]); i++)
	{
		m_WeaveCard[1][i].SetControlPoint(nXControl, nYControl);
		nXControl += 110;
	}

	m_WeaveCard[0][1].SetDirectionCardPos((BYTE)2);
	m_WeaveCard[0][1].SetCardData(cbCardData,4);

	//�����˿�
	m_DiscardCard[0].SetControlPoint(nXCenter + 176, nYCenter - 153);
	m_DiscardCard[1].SetControlPoint(nXCenter - 184, nYCenter + 160);

	//�����˿�
	BYTE cbCardData_1[MAX_COUNT] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
	BYTE cbCardCount = MAX_COUNT-1;
	ASSERT((cbCardCount - 1) % 3 == 0);
	m_HandCardControl.SetCardData(cbCardData_1, cbCardCount, 2);
	m_HandCardControl.SetDisplayItem(true);

	CRect rcButton;
	HDWP hDwp = BeginDeferWindowPos(32);
	m_btStart.GetWindowRect(&rcButton);
	const UINT uFlags = SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOCOPYBITS | SWP_NOSIZE;

	//�ƶ�����
	DeferWindowPos(hDwp, m_btStart, NULL, (nWidth - rcButton.Width()) / 2, nHeight - m_nYBorder - 175, 0, 0, uFlags);


	//�����ƶ� ���������䣬�ƶ�����Ч��
	EndDeferWindowPos(hDwp);
}

VOID CGameClientView::DrawGameView(CDC * pDC, INT nWidth, INT nHeight)
{
	DrawViewImage(pDC, m_ImageBack, DRAW_MODE_SPREAD);
	DrawViewImage(pDC, m_ImageCenter, DRAW_MODE_CENTENT);

	
	//�ѻ��˿�
	m_HeapCard[0].DrawCardControl(pDC);
	m_HeapCard[1].DrawCardControl(pDC);

	m_UserCard.DrawCardControl(pDC);

	m_TableCard[0].DrawCardControl(pDC);

	//�����˿�
	for (WORD i = 0; i < GAME_PLAYER; i++)
	{
		m_TableCard[i].DrawCardControl(pDC);
		for (BYTE j = 0; j < CountArray(m_WeaveCard[i]); j++)
			m_WeaveCard[i][j].DrawCardControl(pDC, true);
	}

	m_DiscardCard[0].DrawCardControl(pDC);
	m_DiscardCard[1].DrawCardControl(pDC);

	m_HandCardControl.DrawCardControl(pDC);
}

BOOL CGameClientView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		case IDC_START:
		{
			//����Ϸ���� ������Ϣ
			SendEngineMessage(IDM_START, 0, 0);
		}
		break;
		default:
			break;
	}
	return TRUE;
}


