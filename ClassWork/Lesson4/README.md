Дочерние окна Статик
===

* окно, которое не может выйти из области другого окна (родительского)
* обычно нужно затем, чтобы разделить окно на **`несколько различных областей`**
* положение определяется **`относительно левого верхнего угла рабочей области родителя`**
* не может иметь меню

Создание дочернего окна
---

* создать отдельный **`дескриптор окна`**
* можно зарегистрировать отдельный оконный класс со своим именем класса и оконной процедурой
* при создании окна (в функции CreateWindow) установить **`стиль WS_CHILD`** и **`задать родительское окно`**
* показать окно с помощью функции **`ShowWindow`**

Создание дочернего окна (пример)
---

```cpp
HWND hWndParent, hWndChild;
// ...
hWndChild = CreateWindowEx(
    WS_EX_TOPMOST,
    szClassName,
    L"Child Window",
    WS_CHILD | WS_OVERLAPPEDWINDOW,
    10, 10, 200, 200,
    hWndParent,
    NULL,
    hInstance,
    NULL);
    
if (!hWndChild) {
    return false;
}

ShowWindow(hWndChild, 1);
UpdateWindow(hWndChild);
```

Полезные функции
---

```cpp
HWND GetParent(HWND hwndChild);
```

```cpp
HWND WINAPI SetParent(HWND hwndCh, HWND hwndNewP);
```

* функции позволяют **`узнать родителя`** или **`поменять родителя`** у дочернего окна

```cpp
case WM_LBUTTONDOWN:
  SetParent(hWndChild, NULL);
}
```

Элементы управления
---

![](https://pp.userapi.com/c837225/v837225341/52d6c/SeNXhxwwujw.jpg)

* все элементы управления – это **`дочерние окна`** (стиль **`WS_CHILD`**)
* относятся к **`предопределенным классам`** (`BUTTON`, `LISTBOX`, `COMBOBOX`, `STATIC` ...)
* каждый элемент управления имеет **`уникальный идентификатор`**
* создаются с помощью функции `CreateWindow` или `CreateWindowEx`
* лучше создавать при обработке `WM_CREATE`

Статик
---

* относятся к классу `STATIC`
* создаются с помощью функции `CreateWindow` или `CreateWindowEx`
* получают **`сообщения`** от родительского окна
* не посылают родительскому окну сообщения
* нужны **`для размещения текста`** (надписи)

Стили статика (Styles statics)
---

* часто начинаются с префикса **`SS_`**

Styles statics                                               | Описание
-------------------------------------------------------------|-----------------
**`SS_BLACKFRAME`**, **`SS_GRAYFRAME`**, **`SS_WHITEFRAME`** |   Рамки разных цветов, текста заголовка нет; незакрашенные
**`SS_BLACKRECT`**, **`SS_GRAYRECT`**, **`SS_WHITERECT`**    |   Закрашенные прямоугольники разных цветов, текста заголовка нет
**`SS_LEFT`**, **`SS_RIGHT`**, **`SS_CENTER`**               |   Выравнивание текста, переносит текст на несколько строк, если это нужно
**`SS_CENTERIMAGE`**                                         |   Выравнивание текста по центру по вертикали
**`SS_SIMPLE`**                                              |   Выводит текст в одну строку
**`SS_NOTIFY`**                                              |   Посылает сообщения STN_CLICKED и STN_DBLCLK о нажатии или двойном щелчке левой клавишей мыши

Создание статика (пример)
---

```cpp
HWND hWndParent, hWndStat;
// ...
hWndStat = CreateWindowEx(
    WS_EX_TOPMOST,
    L"STATIC",
    L"Click", // Текст
    WS_CHILD | WS_VISIBLE, // Стиль
    10, 10, 200, 200,
    hWndParent, // Родитель
    (HMENU) NULL,
    hInstance,
    NULL); 
```

[**-->     Laboratory_work4     <--**](https://github.com/SuvStreet/IT_Step_WinAPI/tree/master/Laboratory_work/Work4)

**17.08.2017**
