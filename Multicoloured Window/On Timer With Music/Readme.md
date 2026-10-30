# OnTimerWithMusic 

A Windows GUI application developed using **C, the Win32 API, and Windows Multimedia APIs** to demonstrate timer-based event handling, dynamic background color changes, and asynchronous music playback.

This project extends the basic timer-based window application by combining periodic color transitions with looping music, providing practical experience with Windows message handling, GDI rendering, and multimedia integration.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📌 About the Project

The objective of this project is to understand how timers and multimedia APIs can be integrated into a native Windows GUI application.

The application creates a Windows window that automatically changes its background color every **one second** while playing music continuously in the background.

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

After displaying all nine colors, the application returns to black and repeats the sequence.

Music starts when the window is created and continues looping asynchronously while the application is running. Pressing the **Escape key** closes the window and stops the music.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ✨ Features

- Native Windows GUI application
- Timer-based background color transitions
- Automatic color changes every second
- Nine different background colors
- Continuous color cycling
- Embedded resource-based music playback
- Looping background music
- Asynchronous audio playback
- Win32 timer event handling
- Windows GDI-based background rendering
- Keyboard event handling
- Escape key support for closing the application
- Timer management using `SetTimer()` and `KillTimer()`
- Multimedia handling using `PlaySound()`

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📚 Concepts Covered

### Windows Timer Mechanism

- `SetTimer()`
- `KillTimer()`
- `WM_TIMER`
- Timer identifiers
- Periodic event handling
- Timer interval configuration

### Windows Multimedia Programming

- `PlaySound()`
- `SND_LOOP`
- `SND_ASYNC`
- `SND_RESOURCE`
- Embedded audio resources
- Asynchronous music playback
- Stopping audio playback

### Windows Message Handling

- `WM_CREATE`
- `WM_PAINT`
- `WM_TIMER`
- `WM_KEYDOWN`
- `WM_DESTROY`
- Window procedure (`WndProc`)
- Windows message loop

### Windows GDI

- Device Context (`HDC`)
- `BeginPaint()`
- `EndPaint()`
- `CreateSolidBrush()`
- `FillRect()`
- `DeleteObject()`
- `InvalidateRect()`
- RGB color representation

### C Programming

- Functions and callback functions
- Structures and pointers
- Switch statements
- Windows data types and handles
- Event-driven programming

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🔄 Application Workflow

The application combines window creation, timer initialization, music playback, and background color updates.

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
            │      ├── Start Looping Music
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
                   ├── Stop Music
                   └── PostQuitMessage()
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🪟 Window Creation

The application initializes a `WNDCLASSEX` structure and configures the properties required to create a native Windows window.

The window class is registered using:

```c
RegisterClassEx(&myWindowClass);
```

The window is created using `CreateWindow()` and displayed using `ShowWindow()` and `UpdateWindow()`.

The window title is:

```text
SHIVA WinDev-2026 : First Window
```

The application uses the standard Win32 message loop to receive and dispatch Windows messages to `WndProc()`.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎵 Music Playback

Music playback begins when the window receives the `WM_CREATE` message.

The application uses the Windows Multimedia API function `PlaySound()` to play an audio resource embedded in the application.

```c
PlaySound(
    MAKEINTRESOURCE(GOAT_BIRTHDAY_MUSIC),
    GetModuleHandle(NULL),
    SND_LOOP | SND_ASYNC | SND_RESOURCE
);
```

### Understanding the Flags

| Flag | Purpose |
|---|---|
| `SND_LOOP` | Repeats the sound continuously until playback is stopped |
| `SND_ASYNC` | Plays the sound asynchronously without blocking the application's message loop |
| `SND_RESOURCE` | Loads the sound from an application resource |

The resource identifier `GOAT_BIRTHDAY_MUSIC` identifies the embedded music resource used by the application.

### Why Asynchronous Playback?

Using `SND_ASYNC` allows the application to continue processing timer events, repaint requests, and keyboard input while the music plays.

This enables the background color transitions and music playback to operate concurrently from the user's perspective.

---

## ⏱️ Timer Initialization

The application defines a custom timer identifier:

```c
#define SHIVA_TIMER 201
```

The timer is initialized when the window receives `WM_CREATE`:

```c
SetTimer(hwnd, SHIVA_TIMER, 1000, NULL);
```

The arguments specify:

- `hwnd` – Handle of the window associated with the timer.
- `SHIVA_TIMER` – Identifier used to recognize the timer.
- `1000` – Timer interval in milliseconds, equivalent to one second.
- `NULL` – Uses Windows timer messages instead of a custom timer callback.

When the timer expires, Windows posts a `WM_TIMER` message to the application's message queue.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🌈 Dynamic Background Color Changes

The application maintains a static color flag:

```c
static unsigned int iColorFlag = 0;
```

This flag determines the background color used by the `WM_PAINT` handler.

The application creates a solid brush corresponding to the current flag and uses it to fill the window's client area.

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

After the white background, the flag resets to zero and the background returns to black. The color cycle then repeats continuously.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🔁 WM_TIMER – Handling Timer Events

The `WM_TIMER` handler controls the background color sequence.

When a timer event occurs, the application:

1. Stops the current timer using `KillTimer()`.
2. Increments the color flag.
3. Resets the flag to zero when it exceeds nine.
4. Requests a repaint using `InvalidateRect()`.
5. Restarts the timer with a one-second interval.

The core logic is:

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

### Role of `InvalidateRect()`

`InvalidateRect()` marks the specified window area as needing to be repainted.

The application invalidates the entire client area, allowing Windows to schedule a `WM_PAINT` message. The painting handler then uses the updated color flag to display the next background color.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🖌️ WM_PAINT – Painting the Window

The `WM_PAINT` handler is responsible for rendering the selected background color.

The application first obtains the client-area rectangle using:

```c
GetClientRect(hwnd, &rect);
```

It then begins the painting operation:

```c
hdc = BeginPaint(hwnd, &ps);
```

A solid brush is created using `CreateSolidBrush()` according to the current color flag.

The client area is filled using:

```c
FillRect(hdc, &rect, hBrush);
```

After painting, the brush is deleted using:

```c
DeleteObject(hBrush);
```

Finally, the painting operation is completed using:

```c
EndPaint(hwnd, &ps);
```

This allows the application to update the background whenever a repaint is requested.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⌨️ Keyboard Event Handling

The application supports closing the window using the Escape key.

The `WM_KEYDOWN` handler checks whether the pressed key is `VK_ESCAPE`:

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

When Escape is pressed, `DestroyWindow()` destroys the window and initiates the application's window destruction process.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🛑 WM_DESTROY – Stopping Music and Terminating the Application

When the window is destroyed, the application receives the `WM_DESTROY` message.

The handler stops the currently playing sound using:

```c
PlaySound(NULL, NULL, 0);
```

It then calls:

```c
PostQuitMessage(0);
```

`PlaySound(NULL, NULL, 0)` stops playback initiated through `PlaySound()`, while `PostQuitMessage()` posts a quit message that allows the application's message loop to terminate.

This ensures that the looping music stops when the application window is closed.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📋 Message Handling Summary

| Windows Message | Purpose |
|---|---|
| `WM_CREATE` | Starts looping music and initializes the timer |
| `WM_TIMER` | Advances the color sequence and requests repainting |
| `WM_PAINT` | Paints the window using the selected background color |
| `WM_KEYDOWN` | Detects the Escape key |
| `WM_DESTROY` | Stops music and initiates application termination |

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🧩 Important Windows APIs

| API | Purpose |
|---|---|
| `PlaySound()` | Plays or stops a sound |
| `SetTimer()` | Creates or starts a timer |
| `KillTimer()` | Stops an existing timer |
| `InvalidateRect()` | Marks a window area for repainting |
| `BeginPaint()` | Begins a painting operation |
| `EndPaint()` | Completes a painting operation |
| `CreateSolidBrush()` | Creates a solid-color brush |
| `FillRect()` | Fills a rectangular area using a brush |
| `DeleteObject()` | Deletes a GDI object |
| `GetClientRect()` | Retrieves client-area dimensions |
| `DestroyWindow()` | Destroys a window |
| `PostQuitMessage()` | Requests termination of the message loop |

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📂 Repository Structure

```text
OnTimerWithMusic/
│
├── Window.c
├── Window.h
├── Resource Files
└── README.md
```

The application requires the resource definition and embedded audio resource associated with `GOAT_BIRTHDAY_MUSIC`. The exact resource filenames depend on the project configuration.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🛠️ Technologies Used

- C
- Win32 API
- Windows Multimedia API (`PlaySound`)
- Windows GDI
- Windows Timer Mechanism
- Windows Resource Management
- Visual Studio
- Windows Desktop Application Development

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ▶️ Getting Started

### Clone the Repository

```bash
git clone https://github.com/PratikChavan19/Windows-Development.git
cd Windows-Development/MulticolouredWindow/OnTimerWithMusic
```

### Build and Run

1. Open the project in Visual Studio.
2. Ensure that the project is configured as a Windows Desktop application.
3. Include the required `.c`, `.h`, and resource files.
4. Ensure that the `GOAT_BIRTHDAY_MUSIC` resource is defined and included in the application.
5. Link the Windows Multimedia library, `winmm.lib`.
6. Build and run the application.

The source includes:

```c
#pragma comment(lib, "winmm.lib")
```

which instructs supported Microsoft C/C++ toolchains to link the Windows Multimedia library automatically.

If building with a different toolchain, configure the linker to include the appropriate multimedia library.

### Expected Behavior

- A Windows GUI window opens.
- Music starts playing and loops continuously.
- The background changes color every second.
- Nine colors are displayed in sequence before the cycle repeats.
- Pressing **Escape** closes the window and stops the music.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎯 Learning Objectives

Through this project, I aim to:

- Understand the Win32 timer mechanism.
- Learn how `SetTimer()` and `WM_TIMER` work together.
- Integrate multimedia functionality into a Windows GUI application.
- Understand asynchronous audio playback.
- Work with embedded Windows resources.
- Implement periodic operations using event-driven programming.
- Dynamically update a window's appearance using GDI.
- Understand the relationship between `InvalidateRect()` and `WM_PAINT`.
- Manage GDI resources using `DeleteObject()`.
- Handle keyboard input and application termination.
- Explore the interaction between timers, multimedia playback, and the Windows message loop.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🚀 Future Enhancements

Possible improvements include:

- Add controls to pause and resume music.
- Add keyboard controls for pausing and resuming color transitions.
- Make the timer interval configurable.
- Add additional background colors.
- Implement smoother color transitions.
- Add a music selection feature.
- Display the current background color.
- Add controls for volume and playback.
- Improve resource and timer cleanup.
- Explore more advanced Windows multimedia APIs.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🤝 Contributions

This repository is primarily maintained as a personal learning and practice project.

Suggestions, improvements, and alternative implementations are welcome.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⭐ Support

If you find this project useful for learning Windows development, consider giving the repository a star.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
