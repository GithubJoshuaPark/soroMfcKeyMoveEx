#include "pch.h"
#include "CTrackWnd.h"
BEGIN_MESSAGE_MAP(CTrackWnd, CWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()


void CTrackWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bTrack) {
		
		TRACKMOUSEEVENT tme = { 0 };
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = m_hWnd;
		tme.dwHoverTime = 0;

		m_bTrack = ::_TrackMouseEvent(&tme);

		if(m_bTrack) 
			SetWindowText(_T("Tracking"));

		CString ls_str = _T("");
		ls_str = _T("�ءۡءۡء� CTrackWnd-OnMouseMove TrackMouseEvent On\n");
		OutputDebugStringW(ls_str);
	}

	CWnd::OnMouseMove(nFlags, point);
}



int CTrackWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_bTrack = false;

	return 0;
}


void CTrackWnd::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default
	SetWindowText(_T("Track Test"));
	m_bTrack = false;

	CString ls_str = _T("");
	ls_str = _T("�ءۡءۡء� CTrackWnd-OnMouseLeave TrackMouseEvent Off\n");
	OutputDebugStringW(ls_str);

	CWnd::OnMouseLeave();
}
