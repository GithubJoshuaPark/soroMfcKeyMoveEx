
// soroMfcKeyMoveExView.h : interface of the CsoroMfcKeyMoveExView class
//

#pragma once

#include "CTrackWnd.h"

class CsoroMfcKeyMoveExView : public CView
{
protected: // create from serialization only
	CsoroMfcKeyMoveExView() noexcept;
	DECLARE_DYNCREATE(CsoroMfcKeyMoveExView)

// Attributes
public:
	CsoroMfcKeyMoveExDoc* GetDocument() const;

// Operations
public:
	CTrackWnd m_wndTrack;  // 추가한 클래스

	CWnd m_wndChild;
	CPoint m_ptChildWindowPos;
	bool m_isDragForChildWindow;

	CPoint m_pointMouse;
	int movingStep = 1;

	CPoint m_ptItemText; // 문자열죄표
	bool m_isDrag;

	bool m_isTrack;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CsoroMfcKeyMoveExView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};

#ifndef _DEBUG  // debug version in soroMfcKeyMoveExView.cpp
inline CsoroMfcKeyMoveExDoc* CsoroMfcKeyMoveExView::GetDocument() const
   { return reinterpret_cast<CsoroMfcKeyMoveExDoc*>(m_pDocument); }
#endif

