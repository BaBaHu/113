#ifndef CARD_CONTROL_HEAD_FILE
#define CARD_CONTROL_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "Resource.h"
#include "GameLogic.h"
//#include "cassert"

//////////////////////////////////////////////////////////////////////////

//X ���з�ʽ
enum enXCollocateMode 
{ 
	enXLeft,						//�����
	enXCenter,						//�ж���
	enXRight,						//�Ҷ���
};

//Y ���з�ʽ
enum enYCollocateMode 
{ 
	enYTop,							//�϶���
	enYCenter,						//�ж���
	enYBottom,						//�¶���
};

//����ö��
enum enDirection
{
	Direction_North=0,					//����
	Direction_West,						//����
	Direction_South,					//����
	Direction_East,						//����
};

//�滭ƫ��,���ڶ���,�����ƵĻ滭
#define Y_USER_LEFT_EXCUSION		25									//��ʾ����
#define Y_USER_RIGHT_EXCUSION		25									//��ʾ����
#define Y_TABLE_LEFT_EXCUSION		25									//��ʾ����
#define Y_TABLE_BOTTOM_EXCUSION		36									//��ʾ����
#define Y_TABLE_RIGHT_EXCUSION		25									//��ʾ����
#define Y_TABLE_TOP_EXCUSION		36									//��ʾ����
#define Y_HEAP_DOUBLE_V_EXCUSION	24									//��ʾ����

//////////////////////////////////////////////////////////////////////////

//�˿�ͼƬ
class CCardListImage
{
	//λ�ñ���
protected:
	int								m_nItemWidth;						//����߶�
	int								m_nItemHeight;						//�������

	//��Դ����
protected:
	CPngImageEx						m_CardListImage;					//ͼƬ��Դ
	CPngImageEx						m_ImageCardShadow;					//����ӰͼƬ

	//��������
public:
	//���캯��
	CCardListImage();
	//��������
	virtual ~CCardListImage();

	//��Ϣ����
public:
	//��ȡ����
	int GetViewWidth() { return m_nItemWidth; }
	//��ȡ�߶�
	int GetViewHeight() { return m_nItemHeight; }

	//��Դ����
public:
	//������Դ
	bool LoadResource(CWnd *pWnd,HINSTANCE hInstance,LPCTSTR pszResourceCard,LPCTSTR pszResourceShadow);
	//�ͷ���Դ
	bool DestroyResource();

	//���ܺ���
public:
	//��ȡһ����ͼƬ��λ�� 
	inline int GetImageIndex(BYTE cbCardData);
	//�滭�˿�
	inline bool DrawCardItem(CDC * pDestDC, BYTE cbCardData, int xDest, int yDest, bool bShadow);
};

//////////////////////////////////////////////////////////////////////////

//�˿���Դ
class CCardResource
{
	//�û��˿�
public:
	CPngImageEx						m_ImageUserTop;						//ͼƬ��Դ
	CPngImageEx						m_ImageUserLeft;					//ͼƬ��Դ
	CPngImageEx						m_ImageUserRight;					//ͼƬ��Դ
	CCardListImage					m_ImageUserBottom;					//ͼƬ��Դ
	CCardListImage					m_ImageUserBtGrayed;				//ͼƬ��Դ

	//�����˿�
public:
	CCardListImage					m_ImageTableTop;					//ͼƬ��Դ
	CCardListImage					m_ImageTableLeft;					//ͼƬ��Դ
	CCardListImage					m_ImageTableRight;					//ͼƬ��Դ
	CCardListImage					m_ImageTableBottom;					//ͼƬ��Դ

	//�˿���Ӱ
public:
	CPngImageEx						m_ImageUserTopShadow;				//ͼƬ��Դ
	CPngImageEx						m_ImageUserLeftShadow;				//ͼƬ��Դ
	CPngImageEx						m_ImageUserRightShadow;				//ͼƬ��Դ
	CPngImageEx						m_ImageHeapSingleVShadow;			//ͼƬ��Դ
	CPngImageEx						m_ImageHeapSingleHShadow;			//ͼƬ��Դ
	CPngImageEx						m_ImageHeapDoubleVShadow;			//ͼƬ��Դ
	CPngImageEx						m_ImageHeapDoubleHShadow;			//ͼƬ��Դ

	//�ƶ��˿�
public:
	CPngImageEx						m_ImageHeapSingleV;					//ͼƬ��Դ	.. ˮƽ
	CPngImageEx						m_ImageHeapSingleH;					//ͼƬ��Դ	������ʾ.. ��ֱ
	CPngImageEx						m_ImageHeapDoubleV;					//ͼƬ��Դ ... ˮƽ��ʾ
	CPngImageEx						m_ImageHeapDoubleH;					//ͼƬ��Դ �����齫�ص����� ��ʾ�ı��� ��ֱ��ʾ

	//��������
public:
	//���캯��
	CCardResource();
	//��������
	virtual ~CCardResource();

	//���ܺ���
public:
	//������Դ
	bool LoadResource(CWnd *pWnd);
	//������Դ
	bool DestroyResource();
};

//////////////////////////////////////////////////////////////////////////

//�����˿�
class CHeapCard
{
	//���Ʊ���
protected:
	CPoint							m_ControlPoint;						//��׼λ��
	enDirection						m_CardDirection;					//�˿˷���

	//�˿˱���
protected:
	WORD							m_wFullCount;						//ȫ����Ŀ
	WORD							m_wMinusHeadCount;					//ͷ����ȱ
	WORD							m_wMinusLastCount;					//β����ȱ

	BYTE							m_cbCardData[HEAP_FULL_COUNT];		//��ֵ
	BYTE							m_cbTailCount;						//����β��

	//��������
public:
	//���캯��
	CHeapCard();
	//��������
	virtual ~CHeapCard();

	//���ܺ���
public:
	//�滭�˿�
	void DrawCardControl(CDC * pDC);
	//�����˿�
	bool SetHeapCardInfo(WORD wMinusHeadCount, WORD wMinusLastCount,BYTE cbTailCount=0);
	//���÷���,wIndex����β��������ֻ������
	void SetCardData( WORD wIndex, BYTE cbCardData );
	//��ȡ����λ��
	CPoint GetDispatchCardPos( bool bTail,WORD zwMinusHeadCount, WORD wMinusLastCount,BYTE cbTailCount);
	//��ȡ����λ��,����wIndex��ʾ����β������ֻ������
	CPoint GetDispatchCardPos( WORD wIndex );
	//���ƶ��Ƴ���,bTailָ�Ƿ����β�Ƴ�
	bool DeductionHeapCard( bool bTail ,BYTE &wMinusHeadCount, BYTE &wMinusLastCount,BYTE &cbTailCount,bool bChangeTail[]=NULL);
	//���÷���
	void ResetCardData();
	//������Ϊ��,wIndex����β��������ֻ����
	void SetCardEmpty( WORD wIndex, BYTE cbEmptyCount );

	//�ؼ�����
public:
	//���÷���
	void SetDirection(enDirection Direction) { m_CardDirection=Direction; }
	//��׼λ��
	void SetControlPoint(int nXPos, int nYPos) 
	{ 
		m_ControlPoint.SetPoint(nXPos,nYPos); 
	}
};

//////////////////////////////////////////////////////////////////////////

//����˿�
class CWeaveCard
{
	//���Ʊ���
protected:
	bool							m_bDisplayItem;						//��ʾ��־
	CPoint							m_ControlPoint;						//��׼λ��
	enDirection						m_CardDirection;					//�˿˷���		
	BYTE							m_cbDirectionCardPos;				//�����˿�	
	CSize							m_sizeImageDirection;				//��������ͼ��С

	//�˿�����
protected:
	WORD							m_wCardCount;						//�˿���Ŀ
	BYTE							m_cbCardData[4];					//�˿�����

	//ͼƬ��Դ
protected:
	CPngImageEx						m_ImageDirectionPos;				//��������

	//��������
public:
	//���캯��
	CWeaveCard();
	//��������
	virtual ~CWeaveCard();
	//������Դ
	bool LoadResource(CWnd *pWnd);
	//���ܺ���
public:
	//�滭�˿�
	void DrawCardControl(CDC * pDC, bool bShadow);
	//�滭�˿�
	void DrawCardControl(CDC * pDC, int nXPos, int nYPos, bool bShadow);
	//�����˿�
	bool SetCardData(const BYTE cbCardData[], WORD wCardCount);

	//�ؼ�����
public:
	//������ʾ
	void SetDisplayItem(bool bDisplayItem) { m_bDisplayItem=bDisplayItem; }
	//���÷���
	void SetDirection(enDirection Direction) { m_CardDirection=Direction; }
	//��׼λ��
	void SetControlPoint(int nXPos, int nYPos) { m_ControlPoint.SetPoint(nXPos,nYPos); }
	//������
	void SetDirectionCardPos(BYTE cbPos) { m_cbDirectionCardPos = cbPos;}

	//�ڲ�����
private:
	//��ȡ�˿�
	inline BYTE GetCardData(WORD wIndex);
};

//////////////////////////////////////////////////////////////////////////

//�û��˿�
class CUserCard
{
	//�˿�����
protected:
	WORD							m_wCardCount;						//�˿���Ŀ
	bool							m_bCurrentCard;						//��ǰ��־

	//���Ʊ���
protected:
	CPoint							m_ControlPoint;						//��׼λ��
	enDirection						m_CardDirection;					//�˿˷���

	//��������
public:
	//���캯��
	CUserCard();
	//��������
	virtual ~CUserCard();

	//���ܺ���
public:
	//�滭�˿�
	void DrawCardControl(CDC * pDC);
	//�����˿�
	bool SetCurrentCard(bool bCurrentCard);
	//�����˿�  wCardCount=�Ƶ�������bCurrentCard=��Ҫ���Ƶ�����
	bool SetCardData(WORD wCardCount, bool bCurrentCard);
	//�����˿�
	bool AddCardData(bool bCurrentCard);
	//��ȡ����
	WORD GetCardCount() { return m_wCardCount; }
	//�Ƿ��е�ǰ��
	bool IsHaveCurrentCard() { return m_bCurrentCard; }
	//��ȡ����λ��
	CPoint GetDispatchCardPos();

	//�ؼ�����
public:
	//���÷���
	void SetDirection(enDirection Direction) { m_CardDirection=Direction; }
	//��׼λ��
	void SetControlPoint(int nXPos, int nYPos) { m_ControlPoint.SetPoint(nXPos,nYPos); }
};

//////////////////////////////////////////////////////////////////////////

//������
struct tagDiscardItem 
{
	BYTE				cbCardData;										//�˿�����
	CPoint				ptExcusion;										//��Ի�׼λ��
};

//������ģ��
typedef	CWHArray<tagDiscardItem>	CDiscardItemArray;

//�����˿�
class CDiscardCard
{
	//�˿�����
protected:
	BYTE							m_cbCurrentMaxCount;				//��ǰ���������Ŀ
	BYTE							m_cbCurrentCount;					//��ǰ����
	CDiscardItemArray				m_ItemArray;						//�˿�����

	//���Ʊ���
protected:
	CPoint							m_ControlPoint;						//��׼λ��
	enDirection						m_CardDirection;					//�˿˷���

	//��������
public:
	//���캯��
	CDiscardCard();
	//��������
	virtual ~CDiscardCard();

	//���ܺ���
public:
	//�滭�˿�
	void DrawCardControl(CDC * pDC);
	//�����˿�
	bool AddCardItem(BYTE cbCardData);
	//�����˿�
	bool SetCardData(const BYTE cbCardData[], WORD wCardCount);
	//��ȡ���һֻ��λ��
	CPoint GetLastCardPosition();
	//��ȡ����λ��
	CPoint GetDispatchCardPos();
	//�Ӷ��������Ƴ���,cbRemoveCountָ�Ƴ���Ŀ
	void RemoveCard( BYTE cbRemoveCount );
	//��ȡ����
	INT_PTR GetCardCount() { return m_ItemArray.GetCount(); }

	//�ؼ�����
public:
	//���÷���
	void SetDirection(enDirection Direction);
	//��׼λ��
	void SetControlPoint(int nXPos, int nYPos) { m_ControlPoint.SetPoint(nXPos,nYPos); }
};

//////////////////////////////////////////////////////////////////////////

//�����˿�
class CTableCard
{
	//�˿�����
protected:
	WORD							m_wCardCount;						//�˿���Ŀ
	BYTE							m_cbCardData[MAX_COUNT];			//�˿�����

	//���Ʊ���
protected:
	CPoint							m_ControlPoint;						//��׼λ��
	enDirection						m_CardDirection;					//�˿˷���

	//��������
public:
	//���캯��
	CTableCard();
	//��������
	virtual ~CTableCard();

	//���ܺ���
public:
	//�滭�˿�
	void DrawCardControl(CDC * pDC);
	//�����˿�
	bool SetCardData(const BYTE cbCardData[], WORD wCardCount);

	//�ؼ�����
public:
	//���÷���
	void SetDirection(enDirection Direction) { m_CardDirection=Direction; }
	//��׼λ��
	void SetControlPoint(int nXPos, int nYPos) { m_ControlPoint.SetPoint(nXPos,nYPos); }
};

//////////////////////////////////////////////////////////////////////////

//�˿˽ṹ
struct tagCardItem
{
	bool							bShoot;								//�����־
	bool							bGrayed;							//
	BYTE							cbCardData;							//�˿�����
};

//ѡ���˿���Ϣ
struct tagSelectCardInfo
{
	WORD							wActionMask;						//������
	BYTE							cbActionCard;						//������
	BYTE							cbCardCount;						//ѡ����Ŀ
	BYTE							cbCardData[MAX_COUNT];				//ѡ����
};

//�˿˿ؼ�
class CCardControl
{
	//״̬����
protected:
	bool							m_bPositively;						//��Ӧ��־
	bool							m_bDisplayItem;						//��ʾ��־
	bool							m_bSelectMode;						//ѡ��ģʽ
	BYTE							m_cbSelectInfoCount;				//ѡ���˿������Ŀ
	tagSelectCardInfo				m_SelectCardInfo[MAX_COUNT];		//ѡ���˿������Ϣ
	CRect							m_rcSelectCard[MAX_COUNT];			//ѡ���˿��������
	BYTE							m_cbCurSelectIndex;					//��ǰѡ������

	//λ�ñ���
protected:
	CPoint							m_BenchmarkPos;						//��׼λ��
	enXCollocateMode				m_XCollocateMode;					//��ʾģʽ
	enYCollocateMode				m_YCollocateMode;					//��ʾģʽ

	//�˿�����
protected:
	WORD							m_wCardCount;						//�˿���Ŀ
	WORD							m_wHoverItem;						//��������
	tagCardItem						m_CurrentCard;						//��ǰ�˿�
	tagCardItem						m_CardItemArray[MAX_COUNT-1];		//�˿�����

	//��Դ����
protected:
	CSize							m_ControlSize;						//�ؼ���С
	CPoint							m_ControlPoint;						//�ؼ�λ��
	CPngImageEx						m_ImageCardShadow;					//��ӰͼƬ
	CGameFrameViewGDI							*m_pSinkWnd;						//֪ͨ����

	//��������
public:
	//���캯��
	CCardControl();
	//��������
	virtual ~CCardControl();

	VOID SetWindowSink(CGameFrameViewGDI *pSinkWnd){ m_pSinkWnd = pSinkWnd;	}
	//������Դ
	bool LoadResource(CWnd *pWnd);
	//��ѯ����
public:
	//��ȡ�˿�
	BYTE GetHoverCard();
	//��ȡ�˿�
	BYTE GetCurrentCard() { return m_CurrentCard.cbCardData; }

	//�˿˿���
public:
	//�����˿�
	bool SetCurrentCard(BYTE cbCardData);
	//�����˿�
	bool SetCurrentCard(tagCardItem CardItem);
	//�����˿�
	bool SetCardData(const BYTE cbCardData[], WORD wCardCount, BYTE cbCurrentCard);
	//�����˿�
	bool SetCardItem(const tagCardItem CardItemArray[], WORD wCardCount);
	//�����˿�
	bool AddCardData(const BYTE cbCardData[], WORD wCardCount);

	//�ؼ�����
public:
	//������Ӧ
	void SetPositively(bool bPositively) { m_bPositively=bPositively; }
	//������ʾ
	void SetDisplayItem(bool bDisplayItem) { m_bDisplayItem=bDisplayItem; }
	//��׼λ��
	void SetBenchmarkPos(int nXPos, int nYPos, enXCollocateMode XCollocateMode, enYCollocateMode YCollocateMode);
	//��׼λ��
	void SetBenchmarkPos(const CPoint & BenchmarkPos, enXCollocateMode XCollocateMode, enYCollocateMode YCollocateMode);
	//���ò���ģʽ
	void SetSelectMode( bool bSelectMode );
	//��ȡ����ģʽ
	bool GetSelectMode() { return m_bSelectMode; }
	//�����������Ƿ��ɫ
	void SetAllCardGray( bool bGray );
	//�������Ƿ��ɫ
	void SetCardGray( BYTE cbCardData[], BYTE cbCardCount, bool bGray );
	//��ȡ��ɫ��
	BYTE GetGrayCard( BYTE cbCardData[], BYTE cbMaxCount, bool bGetGray );
	//��ȡ����λ��
	CPoint GetDispatchCardPos();
	//��ȡ��Ҳ������
	void GetUserSelectResult( tagSelectCardInfo &SelectInfo );

	//�¼�����
public:
	//�滭�˿�
	void DrawCardControl(CDC * pDC);
	//�����Ϣ
	bool OnEventSetCursor(CPoint Point, CRect &rcRePaint);
	//��갴��
	bool OnEventLeftHitCard();
	//��ҳ���
	bool OnEventUserAction( const tagSelectCardInfo SelectInfo[], BYTE cbInfoCount );

	//�ڲ�����
private:
	//�����л�
	WORD SwitchCardPoint(CPoint & MousePoint);
	//��ȡ����
	CRect GetCardRect( WORD wItemIndex );


};


//////////////////////////////////////////////////////////////////////////

//��������
//��������
extern CCardResource				g_CardResource;						//�˿���Դ

//////////////////////////////////////////////////////////////////////////

#endif