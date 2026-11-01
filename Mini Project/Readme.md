# Win32 Birthday Animation 🎂🎉

An interactive Windows GUI mini project developed using **C, Win32 API, and Windows GDI**. This application demonstrates graphical rendering, circle animation, keyboard and mouse interaction, timer-based movement, and multimedia integration.

The project creates a birthday-themed window featuring a lemon-yellow circle with the message **"Happy Birthday Win32"** against a lavender background. Users can control the circle through keyboard shortcuts, move it using the mouse pointer, trigger horizontal and vertical animations, and play or stop background music.

---

## 📌 About the Project

The objective of this mini project is to explore interactive Windows GUI development by combining multiple Win32 programming concepts into a single application.

The application provides different interaction modes:

- **Animation:** Move the birthday circle automatically using timer events.
- **Horizontal Movement:** Animate the circle from left to right and right to left.
- **Vertical Movement:** Animate the circle from top to bottom and bottom to top.
- **Mouse Tracking:** Move the circle along with the mouse pointer.
- **Circle Interaction:** Display a surprise message when the birthday circle is clicked.
- **Music Control:** Play or stop embedded birthday music using keyboard input.
- **Reset:** Restore the circle to the center of the window.

The application uses Windows messages to process keyboard input, mouse interactions, timer events, and painting operations.

---

## ✨ Features

- Native Windows GUI application
- Birthday-themed graphical interface
- Lavender-colored window background
- Lemon-yellow animated circle
- Birthday message rendered inside the circle
- Horizontal circle animation
- Vertical circle animation
- Automatic movement using Windows timer events
- Mouse-controlled circle movement
- Mouse click detection inside the circle
- Interactive surprise message using `MessageBox()`
- Embedded birthday music playback
- Keyboard-controlled animation and interaction
- Dynamic window resizing support
- Windows GDI-based rendering

---

## 🎮 Keyboard Controls

The application supports the following keyboard shortcuts:

| Key | Function |
|---|---|
| `A` / `a` | Start or stop circle animation |
| `H` / `h` | Enable or disable horizontal animation |
| `V` / `v` | Enable or disable vertical animation |
| `C` / `c` | Stop animation and reset the circle to the center |
| `M` / `m` | Enable or disable mouse-controlled circle movement |
| `S` / `s` | Play or stop birthday music |
| `ESC` | Close the application |

**Note:** Horizontal and vertical animation controls work when animation is active. The `A` key toggles the animation state, while `H` and `V` select the animation direction.

---

## 📚 Concepts Covered

### Windows Application Development
- `WinMain()`
- `WNDCLASSEX`
- `RegisterClassEx()`
- `CreateWindow()`
- `ShowWindow()`
- Windows message loop
- Window procedure (`WndProc`)

### Windows Message Handling
- `WM_CREATE`
- `WM_PAINT`
- `WM_SIZE`
- `WM_MOUSEMOVE`
- `WM_LBUTTONDOWN`
- `WM_KEYDOWN`
- `WM_CHAR`
- `WM_TIMER`
- `WM_DESTROY`

### Windows GDI
- Device Context (`HDC`)
- `BeginPaint()`
- `EndPaint()`
- `CreateSolidBrush()`
- `SelectObject()`
- `DeleteObject()`
- `FillRect()`
- `Ellipse()`
- `DrawText()`
- `SetTextColor()`
- `SetBkColor()`
- RGB color representation

### Timer-Based Animation
- `SetTimer()`
- `KillTimer()`
- `WM_TIMER`
- Animation intervals
- Coordinate updates
- Boundary detection
- Direction reversal

### Mouse and Keyboard Interaction
- Keyboard event processing
- Character input using `WM_CHAR`
- Mouse movement using `WM_MOUSEMOVE`
- Mouse click detection using `WM_LBUTTONDOWN`
- Mouse coordinates using `LOWORD()` and `HIWORD()`
- Pixel color detection using `GetPixel()`

### Windows Multimedia
- `PlaySound()`
- `SND_LOOP`
- `SND_ASYNC`
- `SND_RESOURCE`
- Embedded audio resources
- Asynchronous music playback

---

## 🔄 Application Workflow

The application combines window creation, graphical rendering, keyboard and mouse input, timer events, and multimedia functionality.

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
            │
            ├── WM_SIZE
            │
            ├── WM_PAINT
            │      ├── Draw Background
            │      ├── Draw Birthday Circle
            │      └── Draw Birthday Text
            │
            ├── WM_CHAR
            │      ├── A → Animation
            │      ├── H → Horizontal Mode
            │      ├── V → Vertical Mode
            │      ├── C → Reset Circle
            │      ├── M → Mouse Movement
            │      └── S → Music Control
            │
            ├── WM_MOUSEMOVE
            │
            ├── WM_LBUTTONDOWN
            │
            ├── WM_TIMER
            │
            ├── WM_KEYDOWN
            │
            └── WM_DESTROY
```

---

## 🎨 Graphical Interface

The application uses Windows GDI to draw the birthday-themed interface.

### Background

The window background uses a custom lavender color:

```c
#define BACKGROUND_LAVENDER_COLOR RGB(128, 128, 255)
```

### Birthday Circle

The circle is rendered using a lemon-yellow color:

```c
#define CIRCLE_LEMON_YELLOW_COLOR RGB(255, 244, 79)
```

The circle radius is defined as:

```c
#define CIRCLE_RADIUS 100
```

### Birthday Message

The application displays the following message inside the circle:

```c
TCHAR str[] = TEXT("Happy Birthday Win32");
```

The text is rendered using `DrawText()` with horizontal and vertical centering.

---

## 🔁 Circle Animation

The application implements timer-based circle animation using the Win32 timer mechanism.

The animation configuration is defined using:

```c
#define SHIVA_TIMER 201
#define ANIMATION_DELTA 5
```

- `SHIVA_TIMER` identifies the timer.
- `ANIMATION_DELTA` determines the number of pixels by which the circle's center moves during an animation update.

When animation is enabled, the application periodically updates the circle's coordinates and invalidates the window to trigger repainting.

### Horizontal Animation

The horizontal animation moves the circle between the left and right boundaries of the client area.

The direction is controlled using:

```c
static BOOL bAnimateCircleTowardsRight = TRUE;
```

When the circle reaches the right boundary, its direction is reversed. Similarly, when it reaches the left boundary, it starts moving right again.

### Vertical Animation

The vertical animation moves the circle between the top and bottom boundaries of the client area.

The direction is controlled using:

```c
static BOOL bAnimateCircleTowardsBottom = TRUE;
```

When the circle reaches the bottom boundary, it moves upward. When it reaches the top boundary, it moves downward again.

### Animation Direction

The application maintains separate flags for horizontal and vertical animation:

```c
static BOOL bHorizontalAnimation = TRUE;
static BOOL bVerticalAnimation = FALSE;
```

These flags determine which animation mode is active.

---

## ⏱️ Timer Event Handling

The application uses `SetTimer()` to generate periodic timer events.

The timer is configured with an interval of **100 milliseconds**:

```c
SetTimer(hwnd, SHIVA_TIMER, 100, NULL);
```

When the timer expires, Windows sends a `WM_TIMER` message to the window procedure.

The application processes this message and requests a repaint:

```c
case WM_TIMER:
{
    if (bAnimate)
    {
        KillTimer(hwnd, SHIVA_TIMER);

        InvalidateRect(hwnd, NULL, TRUE);

        SetTimer(hwnd, SHIVA_TIMER, 100, NULL);
    }

    break;
}
```

The `WM_PAINT` handler updates the circle's coordinates when animation is enabled and renders the updated position.

---

## 🖱️ Mouse-Controlled Circle Movement

The application supports moving the birthday circle using the mouse pointer.

This functionality is controlled through the `M` key.

When mouse movement mode is enabled, the application processes the `WM_MOUSEMOVE` message.

```c
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
```

The mouse coordinates are extracted from `lParam`:

- `LOWORD(lParam)` – Horizontal mouse coordinate.
- `HIWORD(lParam)` – Vertical mouse coordinate.

The circle's center is updated using these coordinates, and the window is invalidated to display the circle at its new position.

---

## 🎯 Circle Click Detection

The application detects mouse clicks inside the birthday circle using the `WM_LBUTTONDOWN` message.

It uses the `GetPixel()` GDI function to inspect the color of the clicked pixel.

```c
if ((!bMoveCircleWithMousePointer) &&
    (GetPixel(hdc, LOWORD(lParam), HIWORD(lParam)) ==
     CIRCLE_LEMON_YELLOW_COLOR))
{
    MessageBox(
        hwnd,
        TEXT("You have clicked inside the Birthday Circle."),
        TEXT("Surprise Message"),
        MB_OK | MB_ICONINFORMATION
    );
}
```

When the clicked pixel matches the lemon-yellow circle color and mouse-follow mode is disabled, a surprise message box is displayed.

This demonstrates basic pixel-based interaction using Windows GDI.

---

## 🎵 Birthday Music Integration

The application provides music playback functionality through the Windows Multimedia API.

The `S` key toggles music playback.

### Playing Music

```c
PlaySound(
    MAKEINTRESOURCE(GOAT_BIRTHDAY_MUSIC),
    GetModuleHandle(NULL),
    SND_LOOP | SND_ASYNC | SND_RESOURCE
);
```

### Stopping Music

```c
PlaySound(NULL, NULL, 0);
```

The application maintains a Boolean flag:

```c
static BOOL bSoundOn = FALSE;
```

This flag tracks whether music is currently enabled.

The audio is loaded from an embedded application resource and played asynchronously in a continuous loop.

---

## 🖌️ Windows GDI Rendering

The application uses Windows Graphics Device Interface (GDI) functions to render the graphical elements.

### Background Rendering

`CreateSolidBrush()` creates the lavender background brush, and `FillRect()` fills the client area.

### Circle Rendering

The application creates a lemon-yellow brush and draws the circle using:

```c
Ellipse(
    hdc,
    circleRect.left,
    circleRect.top,
    circleRect.right,
    circleRect.bottom
);
```

### Text Rendering

The birthday message is drawn inside the circle using:

```c
DrawText(
    hdc,
    str,
    -1,
    &circleRect,
    DT_CENTER | DT_VCENTER | DT_SINGLELINE
);
```

The text color is black, and the text background color is lemon yellow.

---

## 📐 Window Resizing

The application handles the `WM_SIZE` message to update the window dimensions.

It retrieves the client-area rectangle using:

```c
GetClientRect(hwnd, &windowRect);
```

The width and height are calculated as:

```c
windowWidth = windowRect.right - windowRect.left;
windowHeight = windowRect.bottom - windowRect.top;
```

The circle is initially positioned at the center of the client area:

```c
circleCentreX = windowWidth / 2;
circleCentreY = windowHeight / 2;
```

This allows the initial circle position to adapt to the window's dimensions.

---

## 📋 Message Handling Summary

| Windows Message | Purpose |
|---|---|
| `WM_CREATE` | Handles initial window creation |
| `WM_PAINT` | Draws the background, circle, and birthday message |
| `WM_SIZE` | Updates window dimensions and circle position |
| `WM_MOUSEMOVE` | Updates circle position in mouse-follow mode |
| `WM_LBUTTONDOWN` | Detects clicks inside the birthday circle |
| `WM_KEYDOWN` | Handles Escape key |
| `WM_CHAR` | Processes animation, movement, reset, and music controls |
| `WM_TIMER` | Triggers periodic animation updates |
| `WM_DESTROY` | Initiates application termination |

---

## 🧩 Important Win32 APIs

| API | Purpose |
|---|---|
| `SetTimer()` | Creates or starts a timer |
| `KillTimer()` | Stops an existing timer |
| `InvalidateRect()` | Requests window repainting |
| `GetClientRect()` | Retrieves client-area dimensions |
| `BeginPaint()` | Begins a painting operation |
| `EndPaint()` | Completes a painting operation |
| `CreateSolidBrush()` | Creates a solid-color brush |
| `FillRect()` | Fills a rectangular area |
| `Ellipse()` | Draws an ellipse |
| `DrawText()` | Renders formatted text |
| `GetPixel()` | Retrieves the color of a pixel |
| `PlaySound()` | Plays or stops audio |
| `MessageBox()` | Displays a message dialog |
| `DestroyWindow()` | Destroys a window |
| `PostQuitMessage()` | Requests message loop termination |

---

## 📂 Repository Structure

```text
MiniProject/
│
├── Window.c
├── Window.h
├── Resource Files
└── README.md
```

*The exact filenames and resource organization may vary depending on the Visual Studio project configuration.*

---

## 🛠️ Technologies Used

- C
- Win32 API
- Windows GDI
- Windows Multimedia API
- Windows Timer Mechanism
- Windows Resource Management
- Visual Studio
- Windows Desktop Application Development

---

## ▶️ Getting Started

### Clone the Repository

```bash
git clone https://github.com/PratikChavan19/Windows-Development.git
cd Windows-Development/MiniProject
```

### Build and Run

1. Open the project in Visual Studio.
2. Configure it as a Windows Desktop application.
3. Include the required `.c`, `.h`, and resource files.
4. Ensure that the `GOAT_BIRTHDAY_MUSIC` audio resource and `GOAT_ICON` icon resource are available.
5. Link the Windows Multimedia library, `winmm.lib`.
6. Build and run the application.

The source includes:

```c
#pragma comment(lib, "winmm.lib")
```

which automatically links the multimedia library when using a compatible Microsoft toolchain.

---

## 🎯 Learning Objectives

Through this mini project, I aim to:

- Understand native Windows GUI application architecture.
- Implement interactive graphical applications using C.
- Work with Windows messages and event-driven programming.
- Implement timer-based animations.
- Understand horizontal and vertical movement algorithms.
- Handle keyboard and mouse interactions.
- Perform pixel-based click detection using GDI.
- Draw graphical objects using Windows GDI.
- Integrate multimedia functionality into a Windows application.
- Manage application state using Boolean flags.
- Handle dynamic window resizing.
- Understand the relationship between `WM_TIMER`, `InvalidateRect()`, and `WM_PAINT`.

---

## 🚀 Future Enhancements

Possible improvements include:

- Add diagonal circle movement.
- Introduce multiple animated circles.
- Implement smooth animation transitions.
- Add customizable circle colors and sizes.
- Improve mouse-based interaction.
- Add more interactive keyboard controls.
- Introduce additional birthday animations.
- Add music selection and volume controls.
- Improve rendering performance.
- Explore more advanced GDI and Win32 programming techniques.

---

## 🤝 Contributions

This project is primarily developed as a learning-oriented mini project to explore Windows GUI programming.

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
