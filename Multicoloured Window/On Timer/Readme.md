# OnTimer ⏱️🌈

A Windows GUI application developed using **C and the Win32 API** to demonstrate timer-based event handling and dynamic background color changes.

This project uses the Windows timer mechanism to periodically change the background color of a window, providing practical experience with `SetTimer()`, `WM_TIMER`, `WM_PAINT`, and Windows GDI.

---

## 📌 About the Project

The objective of this project is to understand how timer events can be used to perform periodic operations in a Windows GUI application without requiring a continuously running manual loop.

The application creates a native Windows window and automatically changes its background color every **one second**.

The background cycles through nine colors:

- Red
- Green
- Blue
- Cyan
- Magenta
- Yellow
- Orange
- Violet
- White

After displaying all nine colors, the application returns to black and repeats the cycle.

The user can press the **Escape key** to close the window.

---

## ✨ Features

- Native Windows GUI application
- Timer-based background color transitions
- Automatic color changes every second
- Nine different background colors
- Continuous color cycling
- Win32 timer event handling
- Custom window procedure (`WndProc`)
- Window painting using Windows GDI
- Keyboard event handling
- Escape key support for closing the application
- Proper timer management using `SetTimer()` and `KillTimer()`

---

## 📚 Concepts Covered

### Windows Timer Mechanism

- `SetTimer()`
- `KillTimer()`
- `WM_TIMER`
- Timer identifiers
- Periodic event handling
- Timer interval configuration

### Windows Message Handling

- `WM_CREATE`
- `WM_PAINT`
- `WM_TIMER`
- `WM_KEYDOWN`
- `WM_DESTROY`
- `WndProc()`
- `DefWindowProc()`

### Windows GDI

- Device Context (`HDC`)
- `BeginPaint()`
- `EndPaint()`
- `CreateSolidBrush()`
- `SelectObject()`
- `FillRect()`
- `DeleteObject()`
- `InvalidateRect()`
- RGB color representation

### C Programming

- Functions and callback functions
- Variables and conditional statements
- Switch statements
- Windows data types and handles
- Event-driven programming

---

## 🔄 Application Workflow

The application follows the standard Win32 GUI lifecycle, with timer events triggering periodic background color changes.

```text
WinMain()
    │
    ├── Initialize WNDCLASSEX
    │
    ├── RegisterClassEx()
    │
    ├── CreateWindow()
    │
    ├── ShowWindow()
    │
    └── Message Loop
            │
            ▼
         WndProc()
            │
            ├── WM_CREATE
            │      │
            │      └── SetTimer()
            │
            ├── WM_TIMER
            │      │
            │      ├── Update Color Flag
            │      ├── InvalidateRect()
            │      └── Restart Timer
            │
            ├── WM_PAINT
            │      │
            │      ├── Create Color Brush
            │      └── Fill Window Background
            │
            ├── WM_KEYDOWN
            │      │
            │      └── Escape → DestroyWindow()
            │
            └── WM_DESTROY
                   │
                   └── PostQuitMessage()
```

---

## 🪟 Window Creation

The application creates a native Windows window using the Win32 API.

The window class is configured using the `WNDCLASSEX` structure, which specifies the window procedure, background brush, cursor, application icon, and other properties.

The window class is registered using:

```c
RegisterClassEx(&myWindowClass);
```

The application creates the window using `CreateWindow()` and displays it using `ShowWindow()` and `UpdateWindow()`.

The window title is:

```text
SHIVA WinDev-2026 : First Window
```

---

## ⏱️ Timer Initialization

The timer is initialized when the window receives the `WM_CREATE` message.

A custom timer identifier is defined as:

```c
#define SHIVA_TIMER 201
```

The application starts the timer using:

```c
SetTimer(hwnd, SHIVA_TIMER, 1000, NULL);
```

The arguments specify:

- `hwnd` – Handle of the window associated with the timer.
- `SHIVA_TIMER` – Identifier used to recognize the timer.
- `1000` – Timer interval in milliseconds, equivalent to one second.
- `NULL` – Uses the Windows message queue instead of a custom timer callback function.

When the timer expires, Windows posts a `WM_TIMER` message to the application's message queue.

---

## 🎨 Dynamic Background Color Changes

The application maintains a static color flag:

```c
static unsigned int iColorFlag = 0;
```

This flag determines which color should be used when painting the window.

Inside the `WM_PAINT` handler, the application creates a solid brush corresponding to the current color flag.

### Colors Implemented

| Color Flag | Color | RGB Value |
|---:|---|---|
| 0 | Black | `RGB(0, 0, 0)` |
| 1 | Red | `RGB(255, 0, 0)` |
| 2 | Green | `RGB(0, 255, 0)` |
| 3 | Blue | `RGB(0, 0, 255)` |
| 4 | Cyan | `RGB(0, 255, 255)` |
| 5 | Magenta | `RGB(255, 0, 255)` |
| 6 | Yellow | `RGB(255, 255, 0)` |
| 7 | Orange | `RGB(255, 128, 0)` |
| 8 | Violet | `RGB(128, 128, 255)` |
| 9 | White | `RGB(255, 255, 255)` |

After the white background, the flag resets to zero and the background returns to black. The sequence then repeats.

---

## 🔁 WM_TIMER – Handling Timer Events

The `WM_TIMER` handler controls the background color cycle.

When a timer event occurs, the application performs the following operations:

1. Stops the current timer using `KillTimer()`.
2. Increments the color flag.
3. Resets the flag to zero after the ninth color.
4. Invalidates the window to request repainting.
5. Restarts the timer with a one-second interval.

The relevant Win32 APIs are:

```c
KillTimer(hwnd, SHIVA_TIMER);

iColorFlag++;

if (iColorFlag > 9)
{
    iColorFlag = 0;
}

InvalidateRect(hwnd, NULL, TRUE);

SetTimer(hwnd, SHIVA_TIMER, 1000, NULL);
```

### Why `InvalidateRect()`?

`InvalidateRect()` marks the specified window area as needing to be repainted.

In this application, it requests a repaint of the entire client area, causing Windows to generate a `WM_PAINT` message when painting is processed.

The `WM_PAINT` handler then uses the updated color flag to fill the background with the next color.

---

## 🖌️ WM_PAINT – Painting the Window

The `WM_PAINT` handler is responsible for applying the selected background color.

The application first obtains the client-area rectangle:

```c
GetClientRect(hwnd, &rect);
```

It then begins the painting operation:

```c
hdc = BeginPaint(hwnd, &ps);
```

A solid brush is created using `CreateSolidBrush()` according to the current color flag.

The brush is then used to fill the client area:

```c
FillRect(hdc, &rect, hBrush);
```

After the painting operation, the brush is deleted:

```c
DeleteObject(hBrush);
```

Finally, the painting context is released using:

```c
EndPaint(hwnd, &ps);
```

This process allows the background color to update whenever the window is repainted.

---

## ⌨️ Keyboard Event Handling

The application supports closing the window using the Escape key.

The `WM_KEYDOWN` handler checks the pressed key:

```c
case WM_KEYDOWN:
    switch (wParam)
    {
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;

        default:
            break;
    }
    break;
```

When the Escape key is pressed, `DestroyWindow()` destroys the window and initiates the normal window destruction process.

---

## 🛑 WM_DESTROY – Application Termination

When the window is destroyed, Windows sends the `WM_DESTROY` message.

The application handles it using:

```c
case WM_DESTROY:
    PostQuitMessage(0);
    break;
```

`PostQuitMessage()` posts a quit message to the message queue, allowing the main message loop to terminate.

---

## 📋 Message Handling Summary

| Windows Message | Purpose |
|---|---|
| `WM_CREATE` | Initializes the one-second timer |
| `WM_TIMER` | Advances the color sequence and requests repainting |
| `WM_PAINT` | Paints the window using the selected background color |
| `WM_KEYDOWN` | Detects the Escape key |
| `WM_DESTROY` | Initiates application termination |

---

## 🧩 Important Win32 APIs

| API | Purpose |
|---|---|
| `SetTimer()` | Creates or starts a timer |
| `KillTimer()` | Stops an existing timer |
| `InvalidateRect()` | Marks a window area for repainting |
| `BeginPaint()` | Begins a painting operation |
| `EndPaint()` | Completes a painting operation |
| `CreateSolidBrush()` | Creates a brush with a solid color |
| `FillRect()` | Fills a rectangular area using a brush |
| `DeleteObject()` | Deletes a GDI object |
| `GetClientRect()` | Retrieves the client-area dimensions |
| `DestroyWindow()` | Destroys a window |
| `PostQuitMessage()` | Requests termination of the message loop |

---

## 📂 Repository Structure

```text
OnTimer/
│
├── Window.c
├── Window.h
└── README.md
```

*The exact filenames may vary depending on the files included in the project.*

---

## 🛠️ Technologies Used

- C
- Win32 API
- Windows GUI Programming
- Windows GDI
- Windows Timer Mechanism
- Visual Studio
- Windows Desktop Application Development

---

## ▶️ Getting Started

### Clone the Repository

```bash
git clone https://github.com/PratikChavan19/Windows-Development.git
cd Windows-Development/MulticolouredWindow/OnTimer
```

### Build and Run

1. Open the project in Visual Studio.
2. Ensure that the application is configured as a Windows Desktop application.
3. Include the required `.c`, `.h`, and resource files.
4. Build the project.
5. Run the application.

### Expected Behavior

- A Windows GUI window opens.
- The background changes color automatically every second.
- Nine colors are displayed in sequence.
- The color sequence repeats continuously.
- Pressing **Escape** closes the window.

---

## 🎯 Learning Objectives

Through this project, I aim to:

- Understand the Win32 timer mechanism.
- Learn how `SetTimer()` and `WM_TIMER` work together.
- Implement periodic operations in a GUI application.
- Understand Windows message-driven programming.
- Dynamically update a window's appearance.
- Use GDI brushes to draw and fill window regions.
- Understand the relationship between `InvalidateRect()` and `WM_PAINT`.
- Manage GDI resources using `DeleteObject()`.
- Handle keyboard events in a Windows application.
- Strengthen my understanding of native Windows development using C.

---

## 🚀 Future Enhancements

Possible improvements include:

- Make the timer interval configurable.
- Add more background colors.
- Implement smooth color transitions.
- Add keyboard controls for pausing and resuming the timer.
- Add a reset option for the color sequence.
- Display the current color name.
- Add user controls for selecting colors.
- Explore timer-based animations using Windows GDI.

---

## 🤝 Contributions

This repository is primarily maintained as a personal learning and practice project.

Suggestions, improvements, and alternative implementations are welcome.

---

## ⭐ Support

If you find this project useful for learning Windows development, consider giving the repository a star.

---

## 👨‍💻 Author

**Pratik Chavan**

Software Engineer | C++ | System Programming | Windows Development

Passionate about systems programming, Windows development, software engineering, and continuous learning through practical implementation.

> *"Learning Windows Development one program at a time."*
