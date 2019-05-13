#include"Basic.h"

int APIENTRY WinMain(HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR IpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInstance = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	// 윈도우 상에서 창의 열리는 위치 조정

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// 프로그램 스크린의 색상을 결정

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	// 프로그램상의 마우스 커서 설정

	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// 아이콘 모델 설정

	WndClass.hInstance = hInstance;
	// hInstance

	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	// 프로세스 설정

	WndClass.lpszClassName =lpszClass;
	// 프로그램 이름명

	WndClass.lpszMenuName = NULL;
	// 메뉴 사용 여부

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	// 스타일

	RegisterClass(&WndClass);
	// 적용

	// 기본프레임 셋팅

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam)
{
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, IParam));
}
