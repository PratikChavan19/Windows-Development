// Header Files
#include <windows.h>
#include <windowsx.h>

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
	// variable declarations
	char ch = '\0';
	unsigned int clickXCoord = 0;
	unsigned int clickYCoord = 0;
	TCHAR str[255];

	// code
	switch (iMsg)
	{
		case WM_CREATE :		// WM_CREATE Message Handler
			MessageBox(hwnd,
					   TEXT("WM_CREATE Message Received."),
					   TEXT("Message"),
					   MB_OK | MB_ICONINFORMATION);
			break;

		case WM_LBUTTONDOWN :		// Left Mouse Button Click Message Handler
			clickXCoord = LOWORD(lParam);	// Lower word of lParam of WM_LBUTTONDOWN contains X coordinate of left mouse button clicked
			clickYCoord = HIWORD(lParam);	// Higher word of lParam of WM_LBUTTONDOWN contains Y coordinate of left mouse button clicked
			wsprintf(str, TEXT("Left Mouse Button Clicked at : (%u, %u)"), clickXCoord, clickYCoord);
			MessageBox(hwnd,
				str,
				TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

		case WM_RBUTTONDOWN :		// Right Mouse Button Click Message Handler
			clickXCoord = LOWORD(lParam);	// Lower word of lParam of WM_LBUTTONDOWN contains X coordinate of right mouse button clicked
			clickYCoord = HIWORD(lParam);	// Higher word of lParam of WM_LBUTTONDOWN contains Y coordinate of right mouse button clicked
			wsprintf(str, TEXT("Right Mouse Button Clicked at : (%u, %u)"), clickXCoord, clickYCoord);
			MessageBox(hwnd,
				str,
				TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;


		// Another way to get the click coordinates, this is recommended than LOWORD, HIWORD
/*		case WM_LBUTTONDOWN:
			clickXCoord = GET_X_LPARAM(lParam);
			clickYCoord = GET_Y_LPARAM(lParam);
			wsprintf(str, TEXT("Left Mouse Button Clicked at : (%u, %u)"), clickXCoord, clickYCoord);
			MessageBox(hwnd,
				str,
				TEXT("Message using GET_LPARAM"),
				MB_OK | MB_ICONINFORMATION);
			break;
		
		case WM_RBUTTONDOWN:		// Right Mouse Button Click Message Handler
			clickXCoord = GET_X_LPARAM(lParam);
			clickYCoord = GET_Y_LPARAM(lParam);
			wsprintf(str, TEXT("Right Mouse Button Clicked at : (%u, %u)"), clickXCoord, clickYCoord);
			MessageBox(hwnd,
				str,
				TEXT("Message using GET_LPARAM"),
				MB_OK | MB_ICONINFORMATION);
			break;*/

		case WM_KEYDOWN :		// WM_KEYDOWN Message Handler
			switch (wParam)
			{
				case VK_ESCAPE :
					DestroyWindow(hwnd);
					break;

				case 0x41 :		// 0x41 Hexadecimal value of ASCII value of A
					MessageBox(hwnd,
						TEXT("A is Pressed."),
						TEXT("WM_KEYDOWN Message"),
						MB_OK | MB_ICONINFORMATION);
					break;

				case 0x5a:		// 0x5a Hexadecimal value of ASCII value of Z
					MessageBox(hwnd,
						TEXT("Z is Pressed."),
						TEXT("WM_KEYDOWN Message"),
						MB_OK | MB_ICONINFORMATION);
					break;

				default:
					break;
			}
			break;

		case WM_CHAR :		// Character specific message handler
			switch (wParam)
			{
				case 'A':		
					MessageBox(hwnd,
						TEXT("A is Pressed."),
						TEXT("WM_CHAR Message"),
						MB_OK | MB_ICONINFORMATION);
					break;

				case 'Z':		
					MessageBox(hwnd,
						TEXT("Z is Pressed."),
						TEXT("WM_CHAR Message"),
						MB_OK | MB_ICONINFORMATION);
					break;

				case 'a':		
					MessageBox(hwnd,
						TEXT("a is Pressed."),
						TEXT("WM_CHAR Message"),
						MB_OK | MB_ICONINFORMATION);
					break;

				case 'z':		
					MessageBox(hwnd,
						TEXT("z is Pressed."),
						TEXT("WM_CHAR Message"),
						MB_OK | MB_ICONINFORMATION);
					break;

				default:
					ch = wParam;
					wsprintf(str, TEXT("%c Character Key Pressed", ch));
					MessageBox(hwnd,
						str,
						TEXT("WM_CHAR Message"),
						MB_OK | MB_ICONINFORMATION);
					break;
			}
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
