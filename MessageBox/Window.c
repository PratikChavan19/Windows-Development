// Header Files
#include <windows.h>

// Including our own header file
#include "Window.h"

// Global declaration of Wndow Procedure Callback Function
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry-point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Variable declarations
	WNDCLASSEX myWindowClass;	// struct
	TCHAR szMyWindowClassName[] = TEXT("SHIVA_WinDev");
	HWND hwnd = NULL;
	MSG msg;	// struct

	// code
	// Initializing our Window Class
	ZeroMemory((void*)&myWindowClass, sizeof(WNDCLASSEX));

	myWindowClass.cbSize = sizeof(WNDCLASSEX);
	myWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	myWindowClass.cbClsExtra = 0;
	myWindowClass.cbWndExtra = 0;
	myWindowClass.lpfnWndProc = WndProc;
	myWindowClass.lpszClassName = szMyWindowClassName;
	myWindowClass.lpszMenuName = NULL;
	myWindowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	myWindowClass.hInstance = hInstance;
	myWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	myWindowClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(GOAT_ICON));
	myWindowClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(GOAT_ICON));

	// Register the above Window Class
	RegisterClassEx(&myWindowClass);

	// Create the Window
	hwnd = CreateWindow(
		szMyWindowClassName,
		TEXT("SHIVA WinDev-2026 : First Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// Show the Window
	ShowWindow(hwnd, iCmdShow);

	// Update the Window
	UpdateWindow(hwnd);

	// Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// Translate or Simplify the Message
		TranslateMessage(&msg);

		// Dispatch or post the message to WndProc()
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

// Defining Window Procedure Callback Function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// code
	switch (iMsg)
	{
		case WM_CREATE :		// WM_CREATE Message Handler
			MessageBox(hwnd,
					   TEXT("WM_CREATE Message Received."),
					   TEXT("Message"),
					   MB_OK | MB_ICONINFORMATION);
			break;

		case WM_DESTROY :		// WM_DESTROY Message Handler
			MessageBox(hwnd,
				TEXT("WM_DESTROY Message Received."),
				TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			PostQuitMessage(0);
			break;

		default :
			break;
	}

	// Forward the message to Default Window Procedure
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
