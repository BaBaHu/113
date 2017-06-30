#pragma once

#include "../消息定义/CMD_Game.h"
#include "resource.h"
#include "GameClientView.h"

// GAME_LOGO               BITMAP                  "res\\GAME_LOGO.bmp"  
// 使用 CGameFrameEngine 的注意事项，
// 1.必须用 包含一个 GAME_LOGO 的bmp 用来加载程序的 图标
// 2.必须定义一个GameClientView 类 


class CGameClientEngine : public CGameFrameEngine
{
public:
	CGameClientEngine();

	~CGameClientEngine();

public:
	//创建函数
	virtual bool OnInitGameEngine();
	//重置函数
	virtual bool OnResetGameEngine();
	//游戏设置
	//	virtual void OnGameOptionSet();

	//时钟事件
public:
	//时钟删除
	virtual bool OnEventGameClockKill(WORD wChairID);
	//时钟信息
	virtual bool OnEventGameClockInfo(WORD wChairID, UINT nElapse, WORD wClockID);

	//游戏事件
public:
	//旁观消息
	virtual bool OnEventLookonMode(VOID * pData, WORD wDataSize);
	//游戏消息
	virtual bool OnEventGameMessage(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//场景消息
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, VOID * pData, WORD wDataSize);

	//消息映射

protected:
	//时间消息
//	VOID OnTimer(UINT nIDEvent);
	//开始消息
	LRESULT OnStart(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

protected:
	CGameClientView					m_GameClientView;					//游戏视图
};

