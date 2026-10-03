-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Multicoloured Window – On Left Mouse Button Click 🎨🖱️

A **Win32 API application written in C** that changes the window's background color whenever the **left mouse button is clicked**.

The application cycles through multiple colors using the `WM_LBUTTONDOWN` Windows message and redraws the window using GDI.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📌 About the Project

This project demonstrates how to handle **mouse input events** in a native Windows application.

Every time the user clicks the **left mouse button**, the application changes the background color to the next color in the sequence.

The color sequence contains **9 colors**:

```text
Black → Red → Green → Blue → Cyan → Magenta
     → Yellow → Orange → Violet → White → Black → ...
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## The application maintains the current color using the `iColorFlag` variable. Each left-click increments this value, and after the ninth color, it resets back to `0`.

## 🛠️ Technologies Used

* **C**
* **Win32 API**
* **Windows SDK**
* **GDI (Graphics Device Interface)**
* **Visual Studio**

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📂 Project Structure

```text
On Left Mouse Button Click/
│
├── Window.c
├── Window.h
├── ...
└── README.md
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⚙️ How It Works

The application follows the standard Win32 application lifecycle:

```text
WinMain()
   ↓
Register Window Class
   ↓
Create Window
   ↓
Show Window
   ↓
Message Loop
   ↓
WndProc()
```

The window class is initialized and registered using `WNDCLASSEX` and `RegisterClassEx()`. The application then creates the window using `CreateWindow()`.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🔄 Windows Message Loop

The application uses the standard Windows message loop:

```c
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

The messages are dispatched to the `WndProc()` callback function for processing.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🖱️ Left Mouse Button Handling

The main functionality is implemented using:

```c
case WM_LBUTTONDOWN:
```

Whenever the left mouse button is pressed:

```c
iColorFlag++;
```

The application then checks whether all nine colors have been used:

```c
if (iColorFlag > 9)
{
    iColorFlag = 0;
}
```

Finally, `InvalidateRect()` is called to request a repaint of the window.

### Event Flow

```text
Left Mouse Button Click
          ↓
    WM_LBUTTONDOWN
          ↓
    iColorFlag++
          ↓
   Check color range
          ↓
    InvalidateRect()
          ↓
       WM_PAINT
          ↓
    Create GDI Brush
          ↓
       Fill Window
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎨 Color Mapping

The `WM_PAINT` handler uses `iColorFlag` to determine which brush should be created.

| `iColorFlag` | Color   | RGB                  |
| -----------: | ------- | -------------------- |
|          `0` | Black   | `RGB(0, 0, 0)`       |
|          `1` | Red     | `RGB(255, 0, 0)`     |
|          `2` | Green   | `RGB(0, 255, 0)`     |
|          `3` | Blue    | `RGB(0, 0, 255)`     |
|          `4` | Cyan    | `RGB(0, 255, 255)`   |
|          `5` | Magenta | `RGB(255, 0, 255)`   |
|          `6` | Yellow  | `RGB(255, 255, 0)`   |
|          `7` | Orange  | `RGB(255, 128, 0)`   |
|          `8` | Violet  | `RGB(128, 128, 255)` |
|          `9` | White   | `RGB(255, 255, 255)` |

The corresponding GDI brushes are created using `CreateSolidBrush()`.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🖌️ Painting the Window

When Windows sends a `WM_PAINT` message, the application:

1. Gets the client-area rectangle using `GetClientRect()`.
2. Starts painting using `BeginPaint()`.
3. Determines the current color.
4. Creates a solid GDI brush.
5. Selects the brush into the device context.
6. Fills the window using `FillRect()`.
7. Deletes the brush.
8. Finishes painting using `EndPaint()`.

The core rendering operation is:

```c
SelectObject(hdc, hBrush);
FillRect(hdc, &rect, hBrush);
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🔁 Color Cycling

The color state is stored in:

```c
static unsigned int iColorFlag = 0;
```

Because it is declared as `static`, the value persists between calls to `WndProc()`.

Each left-click increments the value:

```text
0 → 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9
↑                                       ↓
└───────────────────────────────────────┘
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## After reaching `9`, the next click resets the value to `0`.

## ⌨️ Keyboard Control

Although the primary interaction is through the mouse, the application also handles the `ESC` key.

Pressing `ESC` triggers:

```c
case VK_ESCAPE:
    DestroyWindow(hwnd);
    break;
```

This closes the application.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🧹 GDI Resource Management

The application explicitly deletes the dynamically created brush:

```c
if (hBrush)
{
    DeleteObject(hBrush);
    hBrush = NULL;
}
```

The device context is released using:

```c
EndPaint(hwnd, &ps);
```

This demonstrates basic GDI resource management in Win32 programming.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🚀 How to Run

### Using Visual Studio

1. Clone the repository:

```bash
git clone https://github.com/PratikChavan19/Windows-Development.git
```

2. Open the project in **Visual Studio**.

3. Navigate to:

```text
Windows-Development/Multicoloured Window/On Left Mouse Button Click
```

4. Build the project.

5. Run the application.

6. Click the **left mouse button** inside the window to cycle through the colors.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎮 Controls

| Input                 | Action               |
| --------------------- | -------------------- |
| 🖱️ Left Mouse Button | Change to next color |
| `ESC`                 | Exit application     |

### Color Cycle

```text
Click 1  → Red
Click 2  → Green
Click 3  → Blue
Click 4  → Cyan
Click 5  → Magenta
Click 6  → Yellow
Click 7  → Orange
Click 8  → Violet
Click 9  → White
Click 10 → Black
...
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📚 Concepts Demonstrated

This project demonstrates:

* Win32 API programming
* Event-driven programming
* Mouse event handling
* `WM_LBUTTONDOWN`
* Keyboard event handling
* `WM_KEYDOWN`
* `WM_PAINT`
* `WM_DESTROY`
* Window procedure callbacks
* `WPARAM`
* GDI programming
* `HDC`
* `HBRUSH`
* `CreateSolidBrush()`
* `SelectObject()`
* `FillRect()`
* `DeleteObject()`
* `InvalidateRect()`
* `BeginPaint()` / `EndPaint()`
* Windows message loop
* GDI resource management

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎯 Learning Objective

The main objective of this project is to understand how **mouse events can be captured and used to dynamically modify the graphical state of a Windows application**.

Compared with a keyboard-controlled color-changing window, this implementation demonstrates how the same rendering mechanism can be triggered by a **mouse event** using `WM_LBUTTONDOWN`.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🔮 Possible Improvements

Future improvements could include:

* Add right-click color cycling
* Use middle-click for another action
* Display the current color name
* Add mouse movement effects
* Add a random color mode
* Add custom RGB color selection
* Add a color palette
* Add smooth color transitions
* Handle double-click events using `WM_LBUTTONDBLCLK`
* Add different actions for different mouse buttons

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 👨‍💻 Author

**Pratik Chavan**

GitHub: [PratikChavan19](https://github.com/PratikChavan19)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
