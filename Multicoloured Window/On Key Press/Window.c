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
	// variable declarations
	static RECT rect;
	HDC hdc = NULL;		// Handle to Device Context (Painter)
	PAINTSTRUCT ps;
	static char chColorFlag = '\0';
	HBRUSH hBrush = NULL;

	// code
	switch (iMsg)
	{
	case WM_CREATE:		// WM_CREATE Message Handler
	{
		break;
	}

			// This is also a way to handle window size
/*		case WM_SIZE:
		{
			ZeroMemory((void*)&rect, sizeof(RECT));			// zero out the rect structure
			// Step 1 : Get the client area rectangle of your window.
			GetClientRect(hwnd, &rect);

			break;
		}*/

	case WM_PAINT:
	{
		ZeroMemory((void*)&rect, sizeof(RECT));			// zero out the rect structure
		// Step 1 : Get the client area rectangle of your window.
		GetClientRect(hwnd, &rect);

		ZeroMemory((void*)&ps, sizeof(PAINTSTRUCT));	// zero out the ps structure
		// Step 2 : Get the painter to paint you window.
		hdc = BeginPaint(hwnd, &ps);

		// Step 3 : Create brush of desired colour.
		switch (chColorFlag)
		{
			case 'R':		// Red Colour
			case 'r':
				hBrush = CreateSolidBrush(RGB(255, 0, 0));
				break;

			case 'G':		// Green Colour
			case 'g':
				hBrush = CreateSolidBrush(RGB(0, 255, 0));
				break;

			case 'B':		// Blue Colour
			case 'b':
				hBrush = CreateSolidBrush(RGB(0, 0, 255));
				break;

			case 'C':		// Cyan Colour
			case 'c':
				hBrush = CreateSolidBrush(RGB(0, 255, 255));
				break;

			case 'M':		// Magenta Colour
			case 'm':
				hBrush = CreateSolidBrush(RGB(255, 0, 255));
				break;

			case 'Y':		// Yellow Colour
			case 'y':
				hBrush = CreateSolidBrush(RGB(255, 255, 0));
				break;

			case 'O':		// Orange Colour
			case 'o':
				hBrush = CreateSolidBrush(RGB(255, 128, 0));
				break;

			case 'V':		// Violet Colour
			case 'v':
				hBrush = CreateSolidBrush(RGB(128, 128, 255));
				break;

			case 'W':		// White Colour
			case 'w':
				hBrush = CreateSolidBrush(RGB(255, 255, 255));
				break;

			default:		// For any key pressed other than the above, create default Black Coloured brush
				hBrush = CreateSolidBrush(RGB(0, 0, 0));
				break;
		}

		// Step 4 : Give this newly created brush to the painter hdc (select this new brush).
		SelectObject(hdc, hBrush);

		// Step 5 : Now fill the client area rectangle with the selected brush colour.
		FillRect(hdc, &rect, hBrush);

		// Step 6 : Now delete the brush.
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}

		// Step 7 : Release the painter
		if (hdc)
		{
			EndPaint(hwnd, &ps);
			hdc = NULL;
		}

		break;
	}

	case WM_KEYDOWN:		// WM_KEYDOWN Message Handler
		switch (wParam)
		{
			case VK_ESCAPE:
				DestroyWindow(hwnd);
				break;

			default:
				break;
		}
		break;

	case WM_CHAR:
		chColorFlag = wParam;

		// Now explicitly trigger WM_PAINT for the pressed character key
		InvalidateRect(hwnd, NULL, TRUE);	// Posts WM_PAINT

		break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);

		break;
	}

		default :
			break;
	}

	// Forward the message to Default Window Procedure
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
