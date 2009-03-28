#pragma once

class CSettings
{
public:
	CSettings();
	~CSettings();

	TCHAR Config[MAX_PATH];

	int BufferHeight;
	
	LOGFONT LogFont, LogFont2;
	COLORREF Colors[0x20];
	bool isExtendColors;
	char nExtendColor;

	/* Background image */
    TCHAR sBgImage[MAX_PATH];
	bool isShowBgImage, isBackgroundImageValid;

	/* Command Line (Registry) */
	LPTSTR psCmd;
	/* Command Line ("/cmd" arg) */
	LPTSTR psCurCmd;
	/* "Active" command line */
	LPCTSTR GetCmd();

    DWORD FontSizeX;
    DWORD FontSizeX2;
	DWORD FontSizeX3;
    bool isFullScreen;
    bool isFixFarBorders;
    bool isCursorV;
    bool isCursorColor;
    char isRClickSendKey;
    bool isSentAltEnter;
	bool isMinToTray;
    bool isForceMonospace, isTTF;
    bool isUpdConHandle;
    BYTE isDragEnabled;
	BYTE isDropEnabled;
    DWORD nLDragKey, nRDragKey;
    bool isDefCopy;
    bool isDnDsteps;
    bool isGUIpb;
    char isTabs;
    DWORD wndWidth, wndHeight, ntvdmHeight;
    int wndX, wndY;
    u8 bgImageDarker;
    bool isConVisible;
    DWORD nSlideShowElapse;
    DWORD nIconID;
    bool isTryToCenter;
	RECT rcTabMargins;
	bool isTabFrame;
	bool isConMan;

	// ��������� �����
	TCHAR szTabPanels[32];
	TCHAR szTabEditor[32];
	TCHAR szTabEditorModified[32];
	TCHAR szTabViewer[32];
	DWORD nTabLenMax;

	bool isVisualizer;
	char nVizNormal, nVizFore, nVizTab, nVizEOL, nVizEOF;
	wchar_t cVizTab, cVizEOL, cVizEOF;

	char isAllowDetach;
	bool isCreateAppWindow;	
    bool isScrollTitle;
    DWORD ScrollTitleLen;
    
    UINT nMainTimerElapse; // �������������, � ������� �� ������� ����������� �����
    //bool isAdvLangChange; // � ����� ��� ConIme � ����� ������� �� �������� ����, ���� �� ������� WM_SETFOCUS. �� ��� ���� �������� ������ �������� ������
	//bool isSkipFocusEvents;
	
	DWORD nAffinity;
    
	// Working variables...
	HBITMAP hBgBitmap;
	COORD	bgBmp;
	HDC     hBgDc;
	HFONT   mh_Font, mh_Font2;
	WORD    FontWidth[0x10000]; //, Font2Width[0x10000];

    HWND hMain, hColors, hInfo;

	bool LoadImageFrom(TCHAR *inPath, bool abShowErrors=false);
	static BOOL CALLBACK wndOpProc(HWND hWnd2, UINT messg, WPARAM wParam, LPARAM lParam);
	static BOOL CALLBACK mainOpProc(HWND hWnd2, UINT messg, WPARAM wParam, LPARAM lParam);
	static BOOL CALLBACK colorOpProc(HWND hWnd2, UINT messg, WPARAM wParam, LPARAM lParam);
	static BOOL CALLBACK infoOpProc(HWND hWnd2, UINT messg, WPARAM wParam, LPARAM lParam);
	void LoadSettings();
	void InitSettings();
	BOOL SaveSettings();
	bool ShowColorDialog(HWND HWndOwner, COLORREF *inColor);
	static BOOL CALLBACK EnumFamCallBack(LPLOGFONT lplf, LPNEWTEXTMETRIC lpntm, DWORD FontType, LPVOID aFontCount);
	void UpdateMargins(RECT arcMargins);
	static void Dialog();
	void UpdatePos(int x, int y);
	void UpdateSize(UINT w, UINT h);
	void UpdateTTF(BOOL bNewTTF);
	void Performance(UINT nID, BOOL bEnd);
public:
	LRESULT OnInitDialog();
	LRESULT OnButtonClicked(WPARAM wParam, LPARAM lParam);
	LRESULT OnColorButtonClicked(WPARAM wParam, LPARAM lParam);
	LRESULT OnEditChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnColorEditChanged(WPARAM wParam, LPARAM lParam);
	LRESULT OnComboBox(WPARAM wParam, LPARAM lParam);
	LRESULT OnColorComboBox(WPARAM wParam, LPARAM lParam);
	LRESULT OnTab(LPNMHDR phdr);
private:
	COLORREF acrCustClr[16]; // array of custom colors
	BOOL mb_IgnoreEditChanged, mb_IgnoreTtfChange;
	i64 mn_Freq;
	i64 mn_Counter[tPerfInterval-gbPerformance];
	i64 mn_CounterMax[tPerfInterval-gbPerformance];
	DWORD mn_CounterTick[tPerfInterval-gbPerformance];
	HWND hwndTip;
	void RegisterTipsFor(HWND hChildDlg);
	HFONT CreateFontIndirectMy(LOGFONT *inFont);
	// Theming
	HMODULE mh_Uxtheme;
	typedef HRESULT (STDAPICALLTYPE *SetWindowThemeT)(HWND hwnd,LPCWSTR pszSubAppName,LPCWSTR pszSubIdList);
	SetWindowThemeT SetWindowThemeF;
	typedef HRESULT (STDAPICALLTYPE *EnableThemeDialogTextureT)(HWND hwnd,DWORD dwFlags);
	EnableThemeDialogTextureT EnableThemeDialogTextureF;
};