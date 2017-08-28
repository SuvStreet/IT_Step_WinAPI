
> **Материал подготовлен преподователем Волчек Оксаной Анатольевной по курсу WinAPI. Учебное заведение "Компьютерная Академия Шаг".**

Меню
===

Виды меню
---

![](https://pp.userapi.com/c639423/v639423715/3c74f/clvqfxFpK0U.jpg)

Главное меню
---

![](https://pp.userapi.com/c639423/v639423715/3c70b/9Sxrh8ay0uE.jpg)

Создание меню с помощью IDE
---

1. добавить меню в ресурсы (`Add/Resource/Menu/New`)
2. в открывшемся редакторе ресурсов **`создать необходимые пункты`** меню и **`установить их свойства`**
  * `ID` (идентификатор пункта-команды меню)
  * `Caption` (текст пункта; с помощью & перед буквой можно задать горячую клавишу)
  * `Grayed` (недоступность пункта меню)
  * `Checked` (пункт отмечен флажком)
  * `Separator` (устанавливает разделитель)
3. загрузить меню с помощью функции `LoadMenu`

```cpp
HMENU LoadMenu(HINSTANCE hInst,   // дескриптор приложения
               LPCTSTR lpszMenuID) // указатель на строку с ID меню из ресурсов
```

4. установить меню с помощью функции `SetMenu`

```cpp
BOOL SetMenu(HWND hWnd,    // дескриптор родит. окна
             HMENU hMenu)  // дескриптор меню
```

Создание главного меню (пример)
---

```cpp
static HMENU hMenu;
// ...
case WM_INITDIALOG:
 hMenu = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));
 SetMenu(hWnd, hMenu);
return true;
```

Специальные функции (получить дескриптор)
---

* получить дескриптор главного меню

```cpp
HMENU GetMenu(HWND hWnd) // дескриптор главного окна
```

* получить дескриптор подменю

```cpp
HMENU GetSubMenu(HMENU hMenu, // дескриптор меню
                    int iPos) // позиция пункта-подменю
```

Специальные функции (доступность / недоступность пункта)
---

* установить доступность / недоступность пункта

```cpp
BOOL EnableMenuItem(HMENU hMenu, // дескриптор меню
                   UINT uItemID, // ID | pos пункта меню
                   UINT uFlags)  // флаги
```

* 
   * `MF_BYCOMMAND` (ID) или `MF_BYPOSITION` (позиция)
   * `MF_ENABLED | MF_DISABLED | MF_GRAYED`

```cpp
static HMENU hMenu;
// ...
case WM_INITDIALOG:
 EnableMenuItem(hMenu, IDM_SAVE, MF_BYCOMMAND | MF_GRAYED);
return true;
```

Специальные функции (выставить / снять флажок)
---

* выставить / снять флажок у пункта меню

```cpp
DWORD CheckMenuItem(HMENU hMenu,   // дескриптор меню
                    UINT uItemID,  // ID | pos пункта меню
                    UINT uFlags)   // флаги
```

* 
 * `MF_BYCOMMAND` (ID) или `MF_BYPOSITION` (позиция)
 * `MF_CHECKED` (установить)| `MF_UNCHECKED` (снять)

```cpp
static HMENU hMenu;
// ...
case WM_INITDIALOG:
 CheckMenuItem(hMenu, IDM_OPEN, MF_BYCOMMAND | MF_CHECKED);
return true;
```

Специальные функции (отметить переключателем пункт меню)
---

* отметить переключателем пункт меню

```cpp
DWORD CheckMenuRadioItem(HMENU hMenu,     // дескриптор
                         UINT uIDFirst,   // ID или позиция первого пункта в группе
                         UINT uIDLast,    // ID или позиция последнего пункта в группе
                         UINT uIDCHECKED, // ID или позиция выбранного пункта
                         UINT uFlags)     // флаги
```

> **Идентификаторы пунктов меню в группе должны иметь сплошную нумерацию!**

Сообщения от меню
---

* при выборе разрешенного пункта-команды посылается сообщение `WM_COMMAND`:
 * LOWORD(wParam) содержит **`идентификатор пункта`**
 * HIWORD(wParam) и LPARAM содержат **`0`**
* при выборе любого пункта-команды (разрешенного, недоступного, запрещенного) также посылается сообщение `WM_MENUSELECT`:
 * LOWORD(wParam) содержит **`идентификатор пункта`**
* перед отображением меню посылается сообщение `WM_INITMENU` или `INITMENUPOPUP`

Обработка сообщений (пример)
---

```cpp
static HMENU hMenu;
// ...
case WM_INITDIALOG:
 EnableMenuItem(hMenu, IDM_SAVE, MF_BYCOMMAND | MF_GRAYED);
return true;

case WM_COMMAND:
 if (LOWORD(wParam) == IDM_OPEN) {
  EnableMenuItem(hMenu, IDM_SAVE, MF_BYCOMMAND | MF_ENABLED);
  CheckMenuItem(hMenu, IDM_OPEN, MF_BYCOMMAND | MF_CHECKED);
 }
return true;
```

Функции для программного создания меню (1)
---

1. HMENU `CreateMenu`() – создать меню
2. HMENU `CreatePopupMenu`() – создать подменю
3. BOOL `AppendMenu`(HMENU hMenu, UINT uFlags, UINT_PTR uIdNewItem, LPCTSTR lpNewItem) – добавить пункт в конец меню

**`MF_POPUP`**
**`MF_SEPARATOR`**
**`MF_STRING`**
**`MF_CHECKED`**
**`MF_UNCHECKED`**
**`MF_ENABLED`**
**`MF_DISABLED`**
**`MF_GRAYED`**
















**28.08.2017**

![**<-- Общие элементы управления**](https://github.com/SuvStreet/IT_Step_WinAPI/tree/master/ClassWork/Lesson7#Общие-элементы-управления) `________________________________________________________________________` ![**Next -->**]()
