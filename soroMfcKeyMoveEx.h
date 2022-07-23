
// soroMfcKeyMoveEx.h : main header file for the soroMfcKeyMoveEx application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CsoroMfcKeyMoveExApp:
// See soroMfcKeyMoveEx.cpp for the implementation of this class
//

class CsoroMfcKeyMoveExApp : public CWinApp
{
public:
	CsoroMfcKeyMoveExApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsoroMfcKeyMoveExApp theApp;
