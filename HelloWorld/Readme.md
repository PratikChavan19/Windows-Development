-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# HelloWorld 🪟

A simple **Windows Desktop Application** developed using the **Win32 API in C**.

This project demonstrates the fundamental concepts of Windows GUI programming, including **window class registration, window creation, message handling, the Windows message loop, and basic text rendering** using the Win32 API.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📌 About the Project

The **HelloWorld** application creates a native Windows window using the Win32 API and displays:

> **Hello World, WinDev-2026!**

The application is implemented in C using Windows-specific APIs provided through `windows.h`.

The project serves as a starting point for understanding the architecture and lifecycle of a basic Windows GUI application.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🛠️ Technologies Used

* **C**
* **Win32 API**
* **Windows API**
* **Visual Studio**
* **Windows SDK**

### Key APIs Used

* `WinMain()`
* `RegisterClassEx()`
* `CreateWindow()`
* `ShowWindow()`
* `UpdateWindow()`
* `GetMessage()`
* `TranslateMessage()`
* `DispatchMessage()`
* `BeginPaint()`
* `DrawText()`
* `EndPaint()`
* `PostQuitMessage()`

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📂 Project Structure

```text
HelloWorld/
│
├── Window.c
├── Window.h
├── ...
└── README.md
```

> The project may contain additional resource/header files required for building the Windows application.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⚙️ How It Works

The application follows the standard Win32 application lifecycle.

### 1. Application Entry Point

The application starts execution from `WinMain()`:

```c
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine,
    int iCmdShow
);
```

`WinMain()` acts as the entry point for the Windows GUI application.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 2. Window Class Initialization

A `WNDCLASSEX` structure is initialized and configured with properties such as:

* Window procedure
* Window class name
* Background brush
* Application instance
* Cursor
* Window icons

The window procedure is assigned using:

```c
myWindowClass.lpfnWndProc = WndProc;
```

The window class is then registered using:

```c
RegisterClassEx(&myWindowClass);
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 3. Creating the Window

The actual window is created using:

```c
CreateWindow(...)
```

The application uses the registered class and creates a standard overlapped Windows window.

The title of the window is:

```text
SHIVA WinDev-2026 : First Window
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 4. Showing the Window

After creation, the window is displayed and updated using:

```c
ShowWindow(hwnd, iCmdShow);
UpdateWindow(hwnd);
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 5. Windows Message Loop

A Windows GUI application continuously processes messages using the message loop:

```c
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

The message loop is responsible for receiving and dispatching events such as:

* Mouse input
* Keyboard input
* Window movement
* Window resizing
* Painting
* Closing the application

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🖌️ Window Procedure

The `WndProc()` function acts as the **Window Procedure Callback**.

```c
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT iMsg,
    WPARAM wParam,
    LPARAM lParam
);
```

It receives and handles messages sent to the window.

The project currently handles the following messages:

### `WM_CREATE`

Triggered when the window is being created.

```c
case WM_CREATE:
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

### `WM_PAINT`

Responsible for drawing the contents of the window.

The application:

1. Gets the client-area rectangle.
2. Begins painting.
3. Sets the background color to black.
4. Sets the text color to green.
5. Draws the text in the center.
6. Ends the painting operation.

```c
SetBkColor(hdc, RGB(0, 0, 0));
SetTextColor(hdc, RGB(0, 255, 0));

DrawText(
    hdc,
    str,
    -1,
    &rect,
    DT_CENTER | DT_VCENTER | DT_SINGLELINE
);
```

The displayed text is:

```text
Hello World, WinDev-2026!
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

### `WM_DESTROY`

When the window is closed, the application posts a quit message:

```c
PostQuitMessage(0);
```

This causes the message loop to terminate.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎨 Output

The application creates a native Windows window with:

* **Black background**
* **Green text**
* Text centered horizontally and vertically
* Window title: `SHIVA WinDev-2026 : First Window`

Displayed message:

```text
Hello World, WinDev-2026!
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🚀 Building and Running

### Using Visual Studio

1. Clone the repository:

```bash
git clone https://github.com/PratikChavan19/Windows-Development.git
```

2. Open the project in **Visual Studio**.

3. Navigate to:

```text
Windows-Development/HelloWorld
```

4. Select the appropriate build configuration, such as:

```text
Debug / Release
x64 / x86
```

5. Build the project.

6. Run the application.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📚 Concepts Demonstrated

This project provides an introduction to:

* Win32 API programming
* Windows application entry points
* `WNDCLASSEX`
* Window class registration
* Window creation
* Window handles (`HWND`)
* Device contexts (`HDC`)
* Windows messages
* Message loops
* Callback functions
* `WM_CREATE`
* `WM_PAINT`
* `WM_DESTROY`
* Basic GDI text rendering
* Windows resource handling
* Event-driven programming

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎯 Purpose

This project is part of my **Windows Development learning journey**, focusing on understanding native Windows programming using **C and the Win32 API**.

It establishes the foundation for more advanced topics such as:

* Windows message handling
* GDI programming
* Windows controls
* Resource management
* Multithreading
* DLL development
* Win32 system programming

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
