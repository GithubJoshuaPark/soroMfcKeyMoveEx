
// soroMfcKeyMoveExView.cpp : implementation of the CsoroMfcKeyMoveExView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "soroMfcKeyMoveEx.h"
#endif

#include "soroMfcKeyMoveExDoc.h"
#include "soroMfcKeyMoveExView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsoroMfcKeyMoveExView

IMPLEMENT_DYNCREATE(CsoroMfcKeyMoveExView, CView)

BEGIN_MESSAGE_MAP(CsoroMfcKeyMoveExView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_SYSKEYDOWN()
	ON_WM_SYSCHAR()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

// CsoroMfcKeyMoveExView construction/destruction

CsoroMfcKeyMoveExView::CsoroMfcKeyMoveExView() noexcept
{
	// TODO: add construction code here

}

CsoroMfcKeyMoveExView::~CsoroMfcKeyMoveExView()
{
}

BOOL CsoroMfcKeyMoveExView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsoroMfcKeyMoveExView drawing

void CsoroMfcKeyMoveExView::OnDraw(CDC* /*pDC*/)
{
	CsoroMfcKeyMoveExDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: add draw code for native data here
}


// CsoroMfcKeyMoveExView printing

BOOL CsoroMfcKeyMoveExView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsoroMfcKeyMoveExView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsoroMfcKeyMoveExView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CsoroMfcKeyMoveExView diagnostics

#ifdef _DEBUG
void CsoroMfcKeyMoveExView::AssertValid() const
{
	CView::AssertValid();
}

void CsoroMfcKeyMoveExView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsoroMfcKeyMoveExDoc* CsoroMfcKeyMoveExView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsoroMfcKeyMoveExDoc)));
	return (CsoroMfcKeyMoveExDoc*)m_pDocument;
}
#endif //_DEBUG


// CsoroMfcKeyMoveExView message handlers


int CsoroMfcKeyMoveExView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_wndChild.Create(_T("STATIC"), 
						_T("GoodNeighborhood"), 
						WS_CHILD | WS_VISIBLE | WS_BORDER, 
						CRect(100, 100, 400, 400), 
						this, 
						1234);

	m_wndTrack.Create(_T("STATIC"),
		_T("TRACT_TEST"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | SS_NOTIFY,
		CRect(500, 100, 650, 400),
		this,
		12345);

	m_ptChildWindowPos = CPoint(100, 100);
	m_ptItemText = CPoint(10, 50);
	m_pointMouse = NULL;	
	m_isDrag = false;
	m_isDragForChildWindow = false;
	m_isTrack = false;

	return 0;
}


void CsoroMfcKeyMoveExView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CPoint cPoint;
	CRect cRect;
	CString l_str = _T("");

	// Get the child window's coordination points based on the Monitor
	m_wndChild.GetWindowRect(&cRect);
	cPoint.x = cRect.left;
	cPoint.y = cRect.top;

	l_str.Format(_T("※○※○※○ After GetWindowRect: %d, %d, %d, %d\n"), 
					cPoint.x, cPoint.y, cRect.Width(), cRect.Height());
	OutputDebugStringW(l_str);

	// convert view area coordination from screen(Monitor) coordination
	ScreenToClient(&cPoint);

	l_str.Format(_T("※○※○※○ After ScreenToClient: %d, %d, %d, %d\n"),
		cPoint.x, cPoint.y, cRect.Width(), cRect.Height());
	OutputDebugStringW(l_str);

	int li_moving_step = (movingStep * 10);

	switch (nChar)
	{
	case VK_LEFT:
		cPoint.x -= li_moving_step;
		break;
	case VK_RIGHT:
		cPoint.x += li_moving_step;
		break;
	case VK_UP:
		cPoint.y -= li_moving_step;
		break;
	case VK_DOWN:
		cPoint.y += li_moving_step;
		break;
	}

	// move the child view (m_wndChild) with the convertied monitor coordinator
	m_wndChild.SetWindowPos(&CWnd::wndTop, 
							cPoint.x, cPoint.y, 0, 0, 
							SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOSIZE);



	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CsoroMfcKeyMoveExView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CString ls_str = _T("");;
	ls_str.Format(_T("※○※○※○ After OnChar: %c\n"),nChar);
	m_wndChild.SetWindowTextW(ls_str);

	OutputDebugStringW(ls_str);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


// Alt Key, F10 Key
void CsoroMfcKeyMoveExView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CString ls_str = TEXT("");

	WORD wResult = ::GetKeyState(VK_SPACE);
	BYTE byHigh = HIBYTE(wResult);

	if (byHigh & 0x01) {
		// Alt
		ls_str += TEXT("※○※○※○ Alt + Space\n");


		wResult = ::GetKeyState(VK_CAPITAL);
		// 하위 바이트이ㅡ 1번 비트가 1이면 토글 키가 켜진 상태
		BYTE byLow = LOBYTE(wResult);
		if (byLow & 0x01) ls_str += TEXT("※○※○※○ CAPS LOCK ON\n");
		else ls_str += TEXT("※○※○※○ CAPS LOCK OFF\n");

		OutputDebugStringW(ls_str);
	}

	CView::OnSysKeyDown(nChar, nRepCnt, nFlags);
}


void CsoroMfcKeyMoveExView::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CString ls_str = _T("");

	if (nChar == VK_RETURN)
		ls_str = _T("※○※○※○ Alt + Enter\n");
	else if (nChar == 's' || nChar == 'S')
		ls_str = _T("※○※○※○ Alt + S\n");
	else if (nChar == 'x' || nChar == 'X') {
		ls_str = _T("※○※○※○ Alt + X\n");
		OutputDebugStringW(ls_str);
		exit(1);
	}
		

	OutputDebugStringW(ls_str);

	CView::OnSysChar(nChar, nRepCnt, nFlags);
}


void CsoroMfcKeyMoveExView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_pointMouse = point;

	if (m_isDrag) {

		CRect rect;
		GetClientRect(&rect);

		if (rect.PtInRect(point)) {
			m_ptItemText = point;
		}
		else {
			m_ptItemText.x = point.x < 0 ? 0 : (point.x > rect.right-20 ? rect.right-20 : point.x);
			m_ptItemText.y = point.y < 0 ? 0 : (point.y > rect.bottom-20 ? rect.bottom-20 : point.y);
		}
		RedrawWindow();		
	}

	if (m_isDragForChildWindow) {

		CRect rect;
		GetClientRect(&rect);

		if (rect.PtInRect(point)) {
			m_ptChildWindowPos = point;
		}
		else {
			m_ptChildWindowPos.x = point.x < 0 ? 0 : (point.x > rect.right - 20 ? rect.right - 20 : point.x);
			m_ptChildWindowPos.y = point.y < 0 ? 0 : (point.y > rect.bottom - 20 ? rect.bottom - 20 : point.y);
		}

		CRect cRectForChildWindow;
		m_wndChild.GetWindowRect(&cRectForChildWindow);
		ScreenToClient(&cRectForChildWindow);
		InvalidateRect(&cRectForChildWindow, 1);
	}


	if (!m_isTrack) {

		TRACKMOUSEEVENT tme = { 0 };
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = m_hWnd;
		tme.dwHoverTime = 0;

		m_isTrack = ::_TrackMouseEvent(&tme);

		if (m_isTrack) 
			SetWindowText(_T("Tracking"));

		CString ls_str = _T("");
		ls_str = _T("※○※○※○ CsoroMfcKeyMoveExView-OnMouseMove TrackMouseEvent On\n");
		OutputDebugStringW(ls_str);
	}

	CView::OnMouseMove(nFlags, point);
}


void CsoroMfcKeyMoveExView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CString ls_str = _T("");
	ls_str.Format(_T("x: %03d, y: %03d"), m_pointMouse.x, m_pointMouse.y);
	dc.TextOutW(10, 10, ls_str);

	if (m_isDrag) {
		ls_str.Format(_T("is dragging..."));
	}
	else {
		ls_str.Format(_T("is not dragging"));
	}
	dc.TextOutW(m_ptItemText.x, m_ptItemText.y, ls_str);


	if (m_isDragForChildWindow) {
		m_wndChild.SetWindowPos(&CWnd::wndTop,
			m_ptChildWindowPos.x, m_ptChildWindowPos.y, 0, 0,
			SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOSIZE);
	}

}


BOOL CsoroMfcKeyMoveExView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default
	CString ls_str = _T("");
	ls_str.Format(_T("※○※○※○ zDelta: %d\n"), zDelta);
	OutputDebugStringW(ls_str);

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void CsoroMfcKeyMoveExView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x >= m_ptItemText.x - 16 &&
		point.x <= m_ptItemText.x + 16 &&
		point.y >= m_ptItemText.y - 16 &&
		point.y <= m_ptItemText.y + 16) {
		m_isDrag = true;
		RedrawWindow();
		SetCapture();
	}

	CRect cRect;
	m_wndChild.GetWindowRect(&cRect);
	ScreenToClient(&cRect);

	if (cRect.PtInRect(point)) {
		m_ptChildWindowPos = point;		
		m_isDragForChildWindow = true;
		InvalidateRect(&cRect, 1);
		SetCapture();
	}

	
	CView::OnLButtonDown(nFlags, point);
}


void CsoroMfcKeyMoveExView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDblClk(nFlags, point);
}


void CsoroMfcKeyMoveExView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_isDrag) {

		CRect rect;
		GetClientRect(&rect);

		if (rect.PtInRect(point)) {
			m_ptItemText = point;

		}
		else {
			m_ptItemText.x = point.x < 0 ? 0 : (point.x > rect.right-20 ? rect.right-20 : point.x);
			m_ptItemText.y = point.y < 0 ? 0 : (point.y > rect.bottom-20 ? rect.bottom-20 : point.y);
		}

		m_isDrag = false;

		RedrawWindow();
		ReleaseCapture();
	}

	if (m_isDragForChildWindow) {

		CRect rect;
		GetClientRect(&rect);

		if (rect.PtInRect(point)) {
			m_ptChildWindowPos = point;

		}
		else {
			m_ptChildWindowPos.x = point.x < 0 ? 0 : (point.x > rect.right - 20 ? rect.right - 20 : point.x);
			m_ptChildWindowPos.y = point.y < 0 ? 0 : (point.y > rect.bottom - 20 ? rect.bottom - 20 : point.y);
		}

		m_isDragForChildWindow = false;

		RedrawWindow();
		ReleaseCapture();
	}


	CView::OnLButtonUp(nFlags, point);
}


void CsoroMfcKeyMoveExView::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default	
	SetWindowText(_T("Track Test"));
	m_isTrack = false;

	CString ls_str = _T("");
	ls_str = _T("※○※○※○ CsoroMfcKeyMoveExView-OnMouseLeave TrackMouseEvent Off\n");
	OutputDebugStringW(ls_str);

	CView::OnMouseLeave();
}
