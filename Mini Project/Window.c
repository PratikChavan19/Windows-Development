// Header Files
#include <windows.h>

// Including our own header file
#include "Window.h"

#pragma comment(lib, "winmm.lib")		// Can also be added in build.bat

// Declaring my own timer
#define SHIVA_TIMER 201

#define ANIMATION_DELTA 5

// Defining circle radius as a constant
#define	CIRCLE_RADIUS 100

// Defining constant colours 
#define BACKGROUND_LAVENDER_COLOR RGB(128, 128, 255)
#define CIRCLE_LEMON_YELLOW_COLOR RGB(255, 244, 79)
#define TEXT_BLACK_COLOR RGB(0, 0, 0)

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
	ShowWindow(hwnd, SW_MAXIMIZE);

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
	static RECT windowRect;
	static HDC hdc = NULL;		// Handle to Device Context (Painter)
	PAINTSTRUCT ps;
	HBRUSH hBrush_Background = NULL;
	HBRUSH hBrush_Circle = NULL;
	static BOOL bSoundOn = FALSE;
	static unsigned int windowWidth = 0;
	static unsigned int windowHeight = 0;
	static unsigned int circleCentreX = 0;
	static unsigned int circleCentreY = 0;
	RECT circleRect;
	TCHAR str[] = TEXT("Happy Birthday Win32");
	static BOOL bMoveCircleWithMousePointer = FALSE;
	static BOOL bAnimate = FALSE;
	static BOOL bAnimateCircleTowardsRight = TRUE;
	static BOOL bHorizontalAnimation = TRUE;
	static BOOL bVerticalAnimation = FALSE;
	static BOOL bAnimateCircleTowardsBottom = TRUE;

	// code
	switch (iMsg)
	{
		case WM_CREATE:		// WM_CREATE Message Handler
		{
			break;
		}

		case WM_PAINT:
		{
			ZeroMemory((void*)&ps, sizeof(PAINTSTRUCT));	// zero out the ps structure
			// Get the painter to paint you window.
			hdc = BeginPaint(hwnd, &ps);

			// Colour the client area rectange background with violet colour
			hBrush_Background = CreateSolidBrush(BACKGROUND_LAVENDER_COLOR);

			// Give this newly created brush to the painter hdc (select this new brush).
			SelectObject(hdc, hBrush_Background);

			// Now fill the client area rectangle with the selected brush colour.
			FillRect(hdc, &windowRect, hBrush_Background);

			// Draw lemon yellow coloured circle
			hBrush_Circle = CreateSolidBrush(CIRCLE_LEMON_YELLOW_COLOR);
			SelectObject(hdc, hBrush_Circle);

			// Animation Logic
			if (bAnimate)
			{
				if (bVerticalAnimation)
				{
					if (bAnimateCircleTowardsBottom)
					{
						if (circleCentreY <= (windowRect.bottom - CIRCLE_RADIUS))
						{
							circleCentreY = circleCentreY + ANIMATION_DELTA;
						}
						else
						{
							bAnimateCircleTowardsBottom = FALSE;		// Begin Leftwards animation
						}
					}
					else
					{
						if (circleCentreY >= (windowRect.top + CIRCLE_RADIUS))
						{
							circleCentreY = circleCentreY - ANIMATION_DELTA;
						}
						else
						{
							bAnimateCircleTowardsBottom = TRUE;
						}
					}
				}
				else
				{
					if (bAnimateCircleTowardsRight)
					{
						if (circleCentreX <= (windowRect.right - CIRCLE_RADIUS))
						{
							circleCentreX = circleCentreX + ANIMATION_DELTA;
						}
						else
						{
							bAnimateCircleTowardsRight = FALSE;		// Begin Leftwards animation
						}
					}
					else
					{
						if (circleCentreX >= (windowRect.left + CIRCLE_RADIUS))
						{
							circleCentreX = circleCentreX - ANIMATION_DELTA;
						}
						else
						{
							bAnimateCircleTowardsRight = TRUE;
						}
					}
				}
			}
			
			ZeroMemory((void*)&circleRect, sizeof(RECT));
			circleRect.left = circleCentreX - CIRCLE_RADIUS;
			circleRect.top = circleCentreY - CIRCLE_RADIUS;
			circleRect.right = circleCentreX + CIRCLE_RADIUS;
			circleRect.bottom = circleCentreY + CIRCLE_RADIUS;

			Ellipse(hdc, circleRect.left, circleRect.top, circleRect.right, circleRect.bottom);

			// Now draw the text inside the circle
			SetTextColor(hdc, TEXT_BLACK_COLOR);

			// Set background colour of your text to lemon yellow colour
			SetBkColor(hdc, CIRCLE_LEMON_YELLOW_COLOR);

			// Now draw the text
			DrawText(hdc, str, -1, &circleRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

			// Now delete the brush.
			if (hBrush_Circle)
			{
				DeleteObject(hBrush_Circle);
				hBrush_Circle = NULL;
			}
			if (hBrush_Background)
			{
				DeleteObject(hBrush_Background);
				hBrush_Background = NULL;
			}

			break;
		}

		case WM_SIZE:
		{
			ZeroMemory((void*)&windowRect, sizeof(RECT));			// zero out the rect structure
			// Get the client area rectangle of your window.
			GetClientRect(hwnd, &windowRect);

			windowWidth = windowRect.right - windowRect.left;
			windowHeight = windowRect.bottom - windowRect.top;

			// Set Centre of window as centre of circle
			circleCentreX = windowWidth / 2;
			circleCentreY = windowHeight / 2;

			break;
		}

		case WM_MOUSEMOVE:
		{
			if (bMoveCircleWithMousePointer)
			{
				circleCentreX = LOWORD(lParam);
				circleCentreY = HIWORD(lParam);

				InvalidateRect(hwnd, NULL, TRUE);
			}

			break;
		}


		case WM_KEYDOWN:		// WM_KEYDOWN Message Handler
		{
			switch (wParam)
			{
			case VK_ESCAPE:
				DestroyWindow(hwnd);
				break;

			default:
				break;
			}
			break;
		}

		case WM_LBUTTONDOWN:
		{
			if ((!bMoveCircleWithMousePointer) && (GetPixel(hdc, LOWORD(lParam), HIWORD(lParam)) == CIRCLE_LEMON_YELLOW_COLOR))
			{
				MessageBox(hwnd,
					TEXT("You have clicked inside the Birthday Circle."),
					TEXT("Surprise Message"),
					MB_OK | MB_ICONINFORMATION);
			}

			break;
		}

		case WM_CHAR:
		{
			switch (wParam)
			{
				case 'A':
				case 'a':
					bMoveCircleWithMousePointer = FALSE;
					if (!bAnimate)
					{
						// Set Timer for appropriate time
						SetTimer(hwnd, SHIVA_TIMER, 100, NULL);		// Timer for 100 milliseconds

						bAnimate = TRUE;
					}
					else
					{
						KillTimer(hwnd, SHIVA_TIMER);

						bAnimate = FALSE;
					}

					break;

				case 'C':
				case 'c':
					bMoveCircleWithMousePointer = FALSE;
					bAnimate = FALSE;

					// Reset the circle centre
					circleCentreX = windowWidth / 2;
					circleCentreY = windowHeight / 2;

					InvalidateRect(hwnd, NULL, TRUE);

					break;

				case 'H':
				case 'h':
					if (bAnimate)
					{
						bMoveCircleWithMousePointer = FALSE;
						if (!bHorizontalAnimation)
						{
							// Set Timer for appropriate time
							SetTimer(hwnd, SHIVA_TIMER, 100, NULL);		// Timer for 100 milliseconds

							bVerticalAnimation = FALSE;
							bHorizontalAnimation = TRUE;
						}
						else
						{
							KillTimer(hwnd, SHIVA_TIMER);

							bHorizontalAnimation = FALSE;
						}
					}

					break;

				case 'M':
				case 'm':
					bAnimate = FALSE;
					if (!bMoveCircleWithMousePointer)
					{
						// Move circle with mouse pointer
						bMoveCircleWithMousePointer = TRUE;
					}
					else
					{
						bMoveCircleWithMousePointer = FALSE;
					}
					break;

				case 'S':
				case 's':
					if (!bSoundOn)
					{
						// Start playing music
						PlaySound(MAKEINTRESOURCE(GOAT_BIRTHDAY_MUSIC),
							GetModuleHandle(NULL),
							SND_LOOP | SND_ASYNC | SND_RESOURCE);
						bSoundOn = TRUE;
					}
					else
					{
						PlaySound(NULL, NULL, 0);
						bSoundOn = FALSE;
					}

					break;

				case 'V':
				case 'v':
					if (bAnimate)
					{
						bMoveCircleWithMousePointer = FALSE;
						if (!bVerticalAnimation)
						{
							// Set Timer for appropriate time
							SetTimer(hwnd, SHIVA_TIMER, 100, NULL);		// Timer for 100 milliseconds

							bHorizontalAnimation = FALSE;
							bVerticalAnimation = TRUE;
						}
						else
						{
							KillTimer(hwnd, SHIVA_TIMER);

							bVerticalAnimation = FALSE;
						}
					}

					break;

				default:
					break;
			}

			break;
		}

		case WM_TIMER:
		{
			if (bAnimate)
			{
				KillTimer(hwnd, SHIVA_TIMER);

				// Now explicitly trigger WM_PAINT for the pressed character key
				InvalidateRect(hwnd, NULL, TRUE);	// Posts WM_PAINT

				SetTimer(hwnd, SHIVA_TIMER, 100, NULL);
			}

			break;
		}

		case WM_DESTROY:
		{
			// Release the painter
			if (hdc)
			{
				EndPaint(hwnd, &ps);
				hdc = NULL;
			}

			PostQuitMessage(0);

			break;
		}

		default :
			break;
	}

	// Forward the message to Default Window Procedure
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
