# Window Messages – Win32 API 🪟

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📌 Project Overview

A Windows desktop development project demonstrating **Windows Message Handling** using the Win32 API.

The application creates a native Windows window and processes different Windows messages through the `WndProc` callback function. It demonstrates handling **mouse input, keyboard input, character input, and window lifecycle events**.

The project is part of my ongoing exploration of **Windows API programming, event-driven programming, and system-level C development**.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎯 Learning Objectives

This project focuses on understanding:

* The Windows message-driven programming model
* Window procedure (`WndProc`)
* Mouse event handling
* Keyboard event handling
* Character input messages
* `WPARAM` and `LPARAM`
* Extracting mouse coordinates from `LPARAM`
* Handling virtual key codes
* Managing the Windows message loop

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⚙️ Application Workflow

```text
                 WinMain
                    │
                    ▼
             Initialize Window
                    │
                    ▼
           Register Window Class
                    │
                    ▼
              Create Window
                    │
                    ▼
             Message Loop
                    │
                    ▼
          DispatchMessage()
                    │
                    ▼
                WndProc
                    │
        ┌───────────┼──────────────┐
        ▼           ▼              ▼
     Mouse        Keyboard       Window
    Messages      Messages       Messages
        │           │              │
        ▼           ▼              ▼
   WM_LBUTTON    WM_KEYDOWN     WM_CREATE
   WM_RBUTTON    WM_CHAR        WM_DESTROY
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🖱️ Mouse Message Handling

The application handles mouse button events using:

* `WM_LBUTTONDOWN`
* `WM_RBUTTONDOWN`

### Left Mouse Button

When the left mouse button is clicked, the application extracts the cursor coordinates from `lParam` and displays them using a message box.

Example:

```text
Left Mouse Button Clicked at : (X, Y)
```

### Right Mouse Button

Similarly, `WM_RBUTTONDOWN` is used to detect right mouse button clicks and display the click coordinates.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📍 Extracting Mouse Coordinates

The project demonstrates extracting X and Y coordinates using:

```cpp
clickXCoord = LOWORD(lParam);
clickYCoord = HIWORD(lParam);
```

`LOWORD` extracts the lower 16 bits of `lParam`, while `HIWORD` extracts the higher 16 bits.

The source also contains an alternative implementation using:

```cpp
GET_X_LPARAM(lParam);
GET_Y_LPARAM(lParam);
```

This implementation is commented out in the current source and is included to demonstrate another approach to retrieving mouse coordinates.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# ⌨️ Keyboard Message Handling

The application demonstrates two different keyboard-related Windows messages:

* `WM_KEYDOWN`
* `WM_CHAR`

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## WM_KEYDOWN

`WM_KEYDOWN` is used to detect keyboard key presses.

The application specifically handles:

### ESC

Pressing **ESC** calls:

```cpp
DestroyWindow(hwnd);
```

which initiates the window destruction process.

### A

Pressing `A` displays:

```text
A is Pressed.
```

### Z

Pressing `Z` displays:

```text
Z is Pressed.
```

The source uses the hexadecimal values:

```text
0x41 → A
0x5A → Z
```

for these cases.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🔤 WM_CHAR

The project also demonstrates character-specific input using `WM_CHAR`.

It handles:

* `A`
* `Z`
* `a`
* `z`

and displays a corresponding message box.

For other characters, the received character is stored and displayed dynamically:

```cpp
ch = wParam;
wsprintf(str, TEXT("%c Character Key Pressed"), ch);
```

This demonstrates how `wParam` can provide character information for `WM_CHAR`.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🪟 Window Lifecycle Messages

The application also handles two important window lifecycle messages.

### WM_CREATE

When the window is created, the application displays:

```text
WM_CREATE Message Received.
```

using an informational `MessageBox`.

### WM_DESTROY

When the window is destroyed, the application displays:

```text
WM_DESTROY Message Received.
```

and calls:

```cpp
PostQuitMessage(0);
```

to terminate the application's message loop.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🧠 Windows Messages Covered

| Message          | Purpose                          |
| ---------------- | -------------------------------- |
| `WM_CREATE`      | Handles window creation          |
| `WM_LBUTTONDOWN` | Detects left mouse button click  |
| `WM_RBUTTONDOWN` | Detects right mouse button click |
| `WM_KEYDOWN`     | Handles physical key presses     |
| `WM_CHAR`        | Handles character input          |
| `WM_DESTROY`     | Handles window destruction       |

---

# 🛠️ Technologies Used

* **C**
* **Win32 API**
* **Windows SDK**
* `windows.h`
* `windowsx.h`
* Windows Message Loop
* `WNDCLASSEX`
* `WndProc`

The source explicitly includes both `windows.h` and `windowsx.h`, with `windowsx.h` supporting the Windows-specific helper macros demonstrated in the commented coordinate-handling implementation.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🔑 Important Win32 Concepts

### `WPARAM`

Used by the application to obtain information associated with keyboard and character messages, such as the pressed key or character.

### `LPARAM`

Used for additional message-specific information. In this project, it contains mouse position information for mouse button messages.

### `WndProc`

The window procedure receives and processes Windows messages through:

```cpp
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT iMsg,
    WPARAM wParam,
    LPARAM lParam
);
```

The project uses a `switch` statement to process individual message types.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# ▶️ How to Build and Run

## Prerequisites

* Microsoft Windows
* Windows SDK
* C compiler
* Visual Studio or another compatible Windows development environment

## Build

Open the project in your Windows development environment and compile the source together with its required header and resource files.

The source includes:

```cpp
#include "Window.h"
```

and references the `GOAT_ICON` resource, so the corresponding project files and resource definitions are required.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🧪 Expected Behavior

After launching the application:

* A native Windows window is created.
* `WM_CREATE` triggers an informational message.
* Left-clicking displays the click coordinates.
* Right-clicking displays the click coordinates.
* Pressing `A` or `Z` triggers keyboard-related messages.
* Other character keys are handled through `WM_CHAR`.
* Pressing `ESC` destroys the window.
* `WM_DESTROY` triggers a final message before the application exits.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 📚 Key Learning Outcomes

Through this project, I am learning:

* Win32 event-driven programming
* Windows message architecture
* Mouse input handling
* Keyboard input handling
* Character input processing
* `WPARAM` and `LPARAM`
* Message-specific data extraction
* Window lifecycle management
* Windows message loop and dispatching

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🚀 Future Enhancements

Potential extensions include:

* Handling mouse movement using `WM_MOUSEMOVE`
* Handling double-click events
* Adding additional keyboard shortcuts
* Handling mouse wheel events
* Exploring `WM_PAINT`
* Drawing using GDI
* Adding menus and keyboard accelerators
* Handling window resizing using `WM_SIZE`
* Building a more interactive Win32 application

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 👨‍💻 Author

**Pratik Chavan**

Software Engineer | C/C++ Developer | Windows Development Learner

Exploring Windows API programming, system-level development, and native application development through practical implementations.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
