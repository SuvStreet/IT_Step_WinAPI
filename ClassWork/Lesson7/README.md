Общие элементы управления
===

![]()

нужно подключить библиотеку **`comctl32.dll`**

Создание элемента управления
---

* подключить заголовочный файл `commctrl.h`
* прописать путь к библиотеке (`#pragma comment (lib, "comctl32")`)
* создать объект структуры типа `INITCOMMONCONTROLSEX`
* зарегистрировать оконный класс (вызвать функцию `InitCommonControlsEx`)
* создать нужный элемент

Создание элемента управления (пример)
---

```cpp
#include "commctrl.h"

#pragma comment (lib, "comctl32")

// ...
INITCOMMONCONTROLSEX cc;        // создание объекта структуры
cc.dwSize = sizeof(cc);         // установка размера структуры
cc.dwICC = ICC_WIN95_CLASSES;   // установка флагов (какие элементы загружаем)
InitCommonControlsEx(&cc);      // регистрация класса
// ...
```

Индикатор (Progress Bar)
---

* отражает процесс выполнения операции
* относится к классу `PROGRESS_CLASS`
* программно создается с помощью функции `CreateWindow` или `CreateWindowEx`
* получает **`сообщения`** от родительского окна

![]()

Стили (свойства) индикатора
---

* начинаются с префикса **`PBS_`**

ProgressBarStyle                | Описание
--------------------------------|---------------------------------------
**`PBS_VERTICAL (Vertical)`**   |   Индикатор приобретает вертикальное положение
**`PBS_SMOOTH (Smooth)`**       |   Индикатор заполняется без фрагментирования (используется сплошное заполнение)
**`PBS_MARQUEE (c v6.0)`**      |   Индикатор не заполняется; вместо этого внутри него регулярно пробегает сплошная полоса

* общие стили, которые поддерживаются


WindowStyle                   | Описание
------------------------------|----------------------------------------
**`WS_EX_NOPARENTNOTIFY`**    |   Отменяет посылку сообщений родительскому окну
**`WS_TABSTOP (Tabstop)`**    |   Позволяет переходить на элемент по нажатию Tab
**`WS_DISABLED (Disabled)`**  |   Делает элемент управления запрещенным
**`WS_BORDER (Border)`**      |   Устанавливает границу вокруг индикатора

Создание индикатора
---

```cpp
static HWND hProgressBar;
// ...
hProgressBar = CreateWindowEx(
    NULL,
    PROGRESS_CLASS,                     // класс
    NULL,
    WS_CHILD | WS_VISIBLE | PBS_SMOOTH, // Стили
    10, 10, 200, 35,
    hWndParent,                         // Родительское окно
    NULL,
    GetModuleHandle(NULL),
    NULL); 
```

Коды сообщений
---

ProgressBarMessage      | Действие
------------------------|-----------------------
**`PBM_SETBKCOLOR`**    |   Задать цвет фона индикатора
**`PBM_SETBARCOLOR`**   |   Задать цвет самого индикатора
**`PBM_SETRANGE`**      |   Установить диапазон для индикатора
**`PBM_SETPOS`**        |   Установить позицию индикатора в `nNewPos`
**`PBM_DELTAPOS`**      |   Прибавить к текущей позиции индикатора `nDelta`
**`PBM_SETSTEP`**       |   Задать шаг индикатора `nStep`
**`PBM_STEPIT`**        |   Прибавить к текущей позиции заданный шаг `nStep`
**`PBM_GETPOS`**        |   Получить текущую позицию

wParam  | lParam
--------|-----------
0       |   (COLORREF) clrBk
0       |   (COLORREF)clrBar
0       |   MAKELPARAM (min, max)
nNewPos |   0
nDelta  |   0
nStep   |   0 
0       |   0
0       |   0

Обработка сообщений (пример)
---

```cpp
static HWND hPb;
// ...
case WM_INITDIALOG:
  hPb = CreateWindowEx(
    NULL,
    PROGRESS_CLASS,
    NULL,
    WS_CHILD | WS_VISIBLE | WS_BORDER | PBS_SMOOTH,
    30, 100, 280, 25,
    hwnd,
    NULL,
    GetModuleHandle(NULL),
    NULL);
    
  SendMessage(hPb, PBM_SETBKCOLOR, 0, RGB(255, 255, 255));
  SendMessage(hPb, PBM_SETBARCOLOR, 0, RGB(50, 250, 100));
  SendMessage(hPb, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
  SetTimer(hwnd, 1, 1000, 0);
return true;

case WM_TIMER:
  SendMessage(hPb, PBM_DELTAPOS, 1, 0);
return true;
```

Ползунок (Slider Control)
---

* позволяет выбирать дискретные значения в заданном диапазоне
* относится к классу **`TRACKBAR_CLASS`**
* программно **`создается`** с помощью функции `CreateWindow` или `CreateWindowEx`
* **`получает сообщения`** от родительского окна
* посылает сообщения родительскому окну (`WM_NOTIFY`)

![]()

Стили (свойства) ползунка
---

* начинаются с префикса **`TBS_`**

TrackBarStule                                                     | Описание
------------------------------------------------------------------|------------------------------------------
**`TBS_HORZ (Orientation: Horizontal)`**                          |   Задает горизонтальную ориентацию ползунка
**`TBS_VERT (Orientation: Vertical)`**                            |   Задает вертикальную ориентацию ползунка
**`TBS_NOTICKS (Tick Marks: False)`**                             |   Устанавливает полное отсутствие меток
**`TBS_AUTOTICKS (Auto Ticks: True)`**                            |   Устанавливает метки для всех значений в диапазоне; иначе метки лишь в крайних позициях
**`TBS_BOTH, TBS_LEFT, TBS_RIGHT (Point: Both / Left / Right)`**  |   Устанавливает, где будут метки: с двух сторон, сверху / слева, снизу / справа
**`TBS_TOOLTIPS (Tooltips: True)`**                               |   Добавляет всплывающие подсказки






[**-->     Laboratory_work7     <--**](https://github.com/SuvStreet/IT_Step_WinAPI/tree/master/Laboratory_work/Work6)

**24.08.2017**
