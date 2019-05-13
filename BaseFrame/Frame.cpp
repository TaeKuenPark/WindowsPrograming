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
	// ������ �󿡼� â�� ������ ��ġ ����

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	// ���α׷� ��ũ���� ������ ����

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	// ���α׷����� ���콺 Ŀ�� ����

	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// ������ �� ����

	WndClass.hInstance = hInstance;
	// hInstance

	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	// ���μ��� ����

	WndClass.lpszClassName =lpszClass;
	// ���α׷� �̸���

	WndClass.lpszMenuName = NULL;
	// �޴� ��� ����

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	// ��Ÿ��

	RegisterClass(&WndClass);
	// ����

	// �⺻������ ����

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
