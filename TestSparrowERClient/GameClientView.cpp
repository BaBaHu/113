#include "stdafx.h"
#include "GameClientView.h"


#define IDC_START						100								//开始按钮
#define IDC_TRUSTEE_CONTROL				104								//托管控制
#define IDC_SCORE						105								//查分按钮

//动作标识
#define IDI_BOMB_EFFECT					101								//动作标识
#define IDI_DISC_EFFECT					102								//丢弃效果
#define IDI_MOVE_CARD					103								//

//动作数目
#define BOMB_EFFECT_COUNT				12								//动作数目
#define DISC_EFFECT_COUNT				8								//丢弃效果		

#define MOVE_STEP_COUNT					4								//移动步数
#define TIME_MOVE_CARD					5								//牌动画定时时间


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

	//加载位图
	HINSTANCE hInstance = AfxGetInstanceHandle();
	m_ImageBack.LoadFromResource(this, hInstance, IDB_VIEW_BACK);
	m_ImageCenter.LoadFromResource(this, hInstance, IDB_VIEW_CENTER);

	enDirection Direction[] = { Direction_North,Direction_South };

	// 设置牌在那一边？
 	m_HeapCard[0].SetDirection(Direction[0]);
 	m_HeapCard[1].SetDirection(Direction[1]);

	m_HandCardControl.LoadResource(this);
	m_HandCardControl.SetWindowSink(this);

	//组合扑克
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
	//创建控件
	m_btStart.Create(NULL, WS_CHILD | WS_CLIPSIBLINGS, rcCreate, this, IDC_START);
	m_btStart.SetButtonImage(IDB_BT_START, AfxGetInstanceHandle(), false, false);
	m_btStart.ShowWindow(SW_HIDE);
	
	return 0;
}

VOID CGameClientView::ResetGameView()
{
//	m_UserCard.SetCardData(1, 1);
	
//扑克设置
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
	int nYCenter = nHeight / 2 - 20 ;	// windows 的坐标点0,0 我记得是在屏幕的左上角开始的， 显示牌的话，所以需要在此刻-20
	// 减两个20 往下掉了
	
	// 调整牌的位置
	//m_HeapCard[0].SetControlPoint(nXCenter - 289 + 44, nYCenter - 215);

	// 双数: nXCenter = nXCenter - 多少张牌/2 * 每张牌的宽度 
	// 单数: nXCenter = nXCenter - 多少张牌/2 * 每张牌的宽度 - 一张牌的宽度/2

	//由于最小话的时候，nWidth是固定的，所以，这里也是固定的。
	m_HeapCard[0].SetControlPoint(nXCenter - 289 + 44, nYCenter - 215);
	m_HeapCard[1].SetControlPoint(nXCenter + 290 - 55, nYCenter + 212);

	m_UserCard.SetControlPoint(nWidth / 2 - 240, m_nYBorder + m_nYFace + 10);
	m_UserCard.SetDirection(Direction_North); // 设置用户的方位
	m_UserCard.SetCardData(3,false);		  // 其他用户有多少张牌。

	m_UserCard.AddCardData(true);			  // 添加一张牌

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

	//组合扑克
	nXControl = nWidth / 2 - 295;
	nYControl = nHeight - m_nYFace - m_nYBorder - 63;
	for (BYTE i = 0; i < CountArray(m_WeaveCard[1]); i++)
	{
		m_WeaveCard[1][i].SetControlPoint(nXControl, nYControl);
		nXControl += 110;
	}

	m_WeaveCard[0][1].SetDirectionCardPos((BYTE)2);
	m_WeaveCard[0][1].SetCardData(cbCardData,4);

	//丢弃扑克
	m_DiscardCard[0].SetControlPoint(nXCenter + 176, nYCenter - 153);
	m_DiscardCard[1].SetControlPoint(nXCenter - 184, nYCenter + 160);

	//设置扑克
	BYTE cbCardData_1[MAX_COUNT] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
	BYTE cbCardCount = MAX_COUNT-1;
	ASSERT((cbCardCount - 1) % 3 == 0);
	m_HandCardControl.SetCardData(cbCardData_1, cbCardCount, 2);
	m_HandCardControl.SetDisplayItem(true);

	CRect rcButton;
	HDWP hDwp = BeginDeferWindowPos(32);
	m_btStart.GetWindowRect(&rcButton);
	const UINT uFlags = SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOCOPYBITS | SWP_NOSIZE;

	//移动调整
	DeferWindowPos(hDwp, m_btStart, NULL, (nWidth - rcButton.Width()) / 2, nHeight - m_nYBorder - 175, 0, 0, uFlags);


	//结束移动 必须加上这句，移动才生效。
	EndDeferWindowPos(hDwp);
}

VOID CGameClientView::DrawGameView(CDC * pDC, INT nWidth, INT nHeight)
{
	DrawViewImage(pDC, m_ImageBack, DRAW_MODE_SPREAD);
	DrawViewImage(pDC, m_ImageCenter, DRAW_MODE_CENTENT);

	
	//堆积扑克
	m_HeapCard[0].DrawCardControl(pDC);
	m_HeapCard[1].DrawCardControl(pDC);

	m_UserCard.DrawCardControl(pDC);

	m_TableCard[0].DrawCardControl(pDC);

	//桌面扑克
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
			//向游戏引擎 发送消息
			SendEngineMessage(IDM_START, 0, 0);
		}
		break;
		default:
			break;
	}
	return TRUE;
}


