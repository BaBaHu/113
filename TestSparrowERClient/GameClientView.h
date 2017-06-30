#pragma once

#include "Resource.h"
#include "CardControl.h"

//////////////////////////////////////////////////////////////////////////
//消息定义

#define IDM_START					(WM_USER+100)						//开始消息
#define IDM_OUT_CARD				(WM_USER+101)						//出牌消息
#define IDM_TRUSTEE_CONTROL			(WM_USER+102)						//托管控制
#define IDM_CARD_OPERATE			(WM_USER+106)						//玩家操作牌
#define IDM_MOVE_CARD_FINISH		(WM_USER+107)						//扑克动画结束消息


class CGameClientView : public CGameFrameViewGDI
{
public:
	CGameClientView();
	virtual~CGameClientView();

public:

	//WIN7支持
	virtual bool RealizeWIN7() { return true; }
protected:
	DECLARE_MESSAGE_MAP()

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	//重载函数
private:
	//重置界面 当有
	virtual VOID ResetGameView();

	//调整控件  一开始
	virtual VOID RectifyControl(INT nWidth, INT nHeight);
	//绘画界面
	virtual VOID DrawGameView(CDC * pDC, INT nWidth, INT nHeight);
	//命令函数
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

public:
	CBitImageEx						m_ImageBack;						//背景图案
	CBitImageEx						m_ImageCenter;						//LOGO图	

	
	CHeapCard						m_HeapCard[GAME_PLAYER];					//堆立扑克
	CUserCard						m_UserCard;									//其他用户牌，可设置方位，张数，当前张数等

	CTableCard						m_TableCard[GAME_PLAYER];					//桌面扑克  桌子上 背面朝上的牌，比如暗抗的。好像不对

	CWeaveCard						m_WeaveCard[GAME_PLAYER][MAX_WEAVE];		//组合扑克  显示:杠，碰，吃
	CDiscardCard					m_DiscardCard[GAME_PLAYER];					//丢弃扑克 已经出的牌，显示在桌子上

	CCardControl					m_HandCardControl;							//手上扑克

private:
	CSkinButton						m_btStart;							//开始按钮
};

