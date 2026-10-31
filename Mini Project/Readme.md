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
- Windows
