#pragma once
#include <afxwin.h>
class CTrackWnd :
    public CWnd
{
public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    // Mouse tracking boolean
    bool m_bTrack;

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnMouseLeave();
};

