#pragma once
#include<stdio.h>
#include<iostream>

#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam);
HINSTANCE g_hInstance;

LPSTR lpszClass = "First";
// 파일의 스크린의 이름을 정한다.
