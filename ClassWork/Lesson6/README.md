Списки
===

Виды списков
---

* обычный список (ListBox)

![](https://pp.userapi.com/c840729/v840729055/1347/OIQqOqYaFNE.jpg)

* комбинированный список (ComboBox)

![](https://pp.userapi.com/c840729/v840729055/134e/vK_qx7ML51E.jpg)

Списки строк (listBox)
---

* относятся к классу `LISTBOX`
* позволяют выбирать один или несколько элементов из списка
* элементы нумеруются с 0
* создаются с помощью функции `CreateWindow` или `CreateWindowEx`
* **`получают сообщения`** от родительского окна
* **`посылают сообщения`** родительскому окну (`WM_COMMAND` и др.)

Стили списков ListBox
---

* начинаются с префикса **`LBS_`**

ListBoxStyle            | Описание
------------------------|-----------------------------------------
**`LBS_STANDARD`**      |   Одноколоночный список с рамкой и вертикальной линейкой прокрутки
**`LBS_SORT`**          |   Сортировать строки по алфавиту
**`LBS_NOTIFY`**        |   Сообщать родителю о щелчке мышью
**`LBS_EXTENDEDSEL`**   |   Можно выбрать несколько соседних строк в списке
**`LBS_MULTIPLESEL`**   |   Можно выбрать несколько строк в списке
**`LBS_MULTICOLUMN`**   |   Многоколоночный список (нужно сообщение `LB_SETCOLUMNWIDTH`)
**`LBS_HASSTRINGS`**    |   Список посылает родителю `WM_VKEYTOITEM` с кодом виртуальной клавиши в `LOWORD(wParam)`, с номером текущей строки в `HIWORD(wParam)` и с дескриптором списка в `lParam`

Свойства списков
---

Свойства                                            |   Описание
----------------------------------------------------|----------------------------------------------------------------
**`Selection (Выбор)`**                             |     Можно установить, сколько позиций доступно для выбора в списке: 1. одиночный выбор; 2. множественный выбор
**`Sort (Сортировка)`**                             |     Сортировать строки по алфавиту
**`Notify (Уведомление)`**                          |     Сообщать родителю о щелчке мышью
**`Multicolumn (Несколько столбцов)`**              |     Многоколоночный список
**`Horizontal Scroll (Прокрутка по горизонтали)`**  |     Возможность прокручивать список по горизонтали (значение должно быть выставлено для многоколоночного списка)
**`Disable No Scroll (С полосой прокрутки)`**       |Сразу доступна вертикальная полоса прокрутки

Создание списка
---

```cpp
#define ID_LISTBOX 300

HWND hWndParent, hListBox;
// ...
hListBox = CreateWindowEx(
  WS_EX_TOPMOST,
  L"LISTBOX",                             // класс
  NULL,
  WS_CHILD | WS_VISIBLE | LBS_STANDARD,   //Стили
  10, 10, 100, 50,
  hWndParent,                             // Родительское окно
  (HMENU) ID_LISTBOX,
  hInstance,                              // GetModuleHandle(NULL)
  NULL); 
```

Сообщения списку
---

* чтобы послать сообщение списку, используется функция `SendMessage`

```cpp
LRESULT WINAPI SendMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
```

```cpp
case WM_CREATE:
  // ...
  SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)L"Вариант 1");
  SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)L"Вариант 2");
  break;
```

Коды сообщений
---

Код сообщения         | Действие
----------------------|------------------
**`LB_ADDSTRING`**    | Добавить в список строку szStr
**`LB_DELETESTRING`** | Удалить строку с номером i
**`LB_GETCOUNT`**     | Найти количество строк в списке
**`LB_GETTEXT`**      | Копировать i-ую строку в szStr
**`LB_GETTEXTLEN`**   | Получить длину строки с номером i
**`LB_RESETCONTENT`** | Очистить список
**`LB_SETCURSEL`**    | Выбрать i-ую строку
**`LB_GETCURSEL`**    | Вернуть номер выбранной строки
**`LB_FINDSTRING`**   | Найти строку с префиксом szStr,искать с позиции iStart (-1)
**`LB_GETSELCOUNT`**  | Вернуть число выбранных строк

Значение wParam   |  Значение lParam
------------------|-------------------
0                 |   szStr
I                 |   0 
0                 |   0 
i                 |   szStr
i                 |   0
0                 |   0 
i                 |   0 
0                 |   0 
iStart            |   szStr
0                 |   0

Сообщения от списков
---

* если родителю посылается сообщение `WM_COMMAND` (стиль `LBS_NOTIFY`), то:
  * lParam – **`дескриптор`** списка
  * LOWORD(wParam) – **`идентификатор`** списка
  * HIWORD(wParam) – **`код сообщения`**

```cpp
case WM_COMMAND:
  switch (LOWORD(wParam)) {
    case ID_LISTBOX:
      if (HIWORD(wParam) == LBN_ERRSPACE ) { /* ... */ }
      break;
    // ...
  }
break;
```


Коды сообщений списков
---

Код сообщения         |Назначение
----------------------|----------------
**`LBN_DBLCL`**       | Двойной щелчок левой кнопкой мыши по элементу списка
**`LBN_SELCHANGE`**   | Изменился номер выбранной строки
**`LBN_SELCANCEL`**   | Пользователь отменил выбор в списке
**`LBN_SETFOCUS`**    | Список получил фокус ввода
**`LBN_KILLFOCUS`**   | Список потерял фокус ввода
**`LBN_ERRSPACE`**    | Не хватает памяти для выполнения операции

Обработка сообщений (пример)
---

```cpp
wchar_t buf[100];
int index;
// ...
case WM_COMMAND:
  switch(LOWORD(wParam)) {
  case ID_LISTBOX:
    if (HIWORD(wParam) == LBN_DBLCLK) {
      index = SendMessage(hLbs, LB_GETCURSEL, 0, 0);
    if (index != LB_ERR) {
      SendMessage(hLbs, LB_GETTEXT, index, (LPARAM)buf);
      MessageBox(NULL, buf, L"Тест", MB_OK);
  }
  break;
  // ...
  }
  // ...
```

Комбинированные списки (ComboBox)
---

* объединяют текстовое поле и список строк
* относятся к классу `COMBOBOX`
* создаются с помощью функции `CreateWindow` или `CreateWindowEx`
* **`получают сообщения`** от родительского окна
* **`посылают сообщения`** родительскому окну (`WM_COMMAND` и др.)

Стили списков ComboBox
---

* начинаются с префикса **`CBS_`**

ComboBoxStyle           | Описание
------------------------|------------------------------
**`CBS_LOWERCASE`**     | Преобразовать все символы в строчные
**`CBS_UPPERCASE`**     | Преобразовать все символы в прописные
**`CBS_SORT`**          | Автоматически сортировать строки в списке
**`CBS_SIMPLE`**        | Список всегда виден и расположен под строкойввода
**`CBS_DROPDOWN`**      | Список отображается в свернутом состоянии сострелкой справа; содержимое текстовой строкиможно изменять
**`CBS_DROPDOWNLIST`**  | Список отображается в свернутом состоянии сострелкой справа; в строке ввода нельзяредактировать выбранную запись

Создание списка
---

```cpp
#define ID_COMBOBOX 400

HWND hWndParent, hComboBox;
// ...
hComboBox = CreateWindowEx(
    WS_EX_TOPMOST,
    L"COMBOBOX",                        // класс
    NULL,
    WS_CHILD | WS_VISIBLE | CBS_SIMPLE, //Стили
    10, 10, 100, 150,
    hWndParent,                         // Родительское окно
    (HMENU) ID_COMBOBOX,
    hInstance,
    NULL); 
```

Сообщения списку
---

* чтобы послать сообщение списку, используется функция `SendMessage`

```cpp
LRESULT WINAPI SendMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
```

```cpp
case WM_CREATE:
  // ...
  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"1");
  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)L"2");
break;
```

Коды сообщений
---

Код сообщения         | Действие
----------------------|----------------------------------
**`CB_ADDSTRING`**    |   Добавить в список строку `str`
**`CB_DELETESTRING`** |   Удалить строку с номером `i`
**`CB_GETCOUNT`**     |   Найти количество строк в списке
**`CB_GETCURSEL`**    |   Вернуть номер выбранной  строки
**`CB_SETCURSEL`**    |   Выбрать `i`-ую строку
**`СВ_GETLBTEXT`**    |   Копировать строку с номером `i` в  буфер `buf`
**`CB_FINDSTRING`**   |   Найти строку `str` с позиции `i`
**`СВ_GETEDITSEL`**   |   Получить текущее выделение
**`CB_SETEDITSET`**   |   Выделить текст, начиная с позиции `iStart` и до позиции `iEnd`

wParam    | lParam
----------|--------------------
0         |   str 
I         |   0 
0         |   0 
0         |   0
I         |   0 
I         |   buf
I         |   str
&iStart   |   &iEnd 
iStart    |   iEnd

Сообщения от списков
---

* родителю посылается сообщение `WM_COMMAND`
  * lParam – **`дескриптор`** списка
  * LOWORD(wParam) – **`идентификатор`** списка
  * HIWORD(wParam) – **`код сообщения`**
  
```cpp
case WM_COMMAND:
  switch (LOWORD(wParam)) {
  case ID_COMBOBOX:
    if (HIWORD(wParam) == CBN_CLOSEUP ) {  /* … */ }
  break;
  // ...
}
break;
```

Коды сообщений списков
---

Код сообщения           | Назначение
------------------------|------------------------------
**`CBN_CLOSEUP`**       |   Список стал невидимым
**`CBN_DROPDOWN`**      |   Список стал видимым
**`CBN_SELENDOK`**      |   Пользователь выбрал строку в списке
**`CBN_SELCHANGE`**     |   Изменился номер выбранной строки
**`CBN_SELENDCANCEL`**  |   Пользователь отменил выбор строки в списке
**`CBN_DBLCLK`**        |   Двойной щелчок левой кнопкой мыши по строке
**`CBN_SETFOCUS`**      |   Список получил фокус ввода
**`CBN_KILLFOCUS`**     |   Список потерял фокус ввода
**`CBN_EDITCHANGE`**    |   Пользователь изменил содержимое окна редактирования, изменения отображены
**`CBN_EDITUPDATE`**    |   Пользователь изменил содержимое окна редактирования, изменения не отображены

Обработка сообщений (пример)
---

```cpp
wchar_t buf[100];
int index;
// ...
case WM_COMMAND:
  switch(LOWORD(wParam)) {
  
  case ID_COMBOBOX:
    if (HIWORD(wParam) == CBN_DBLCLK) {
      index = SendMessage(hCmb, CB_GETCURSEL, 0, 0);
        if (index != CB_ERR){
          SendMessage(hCmb, CB_GETLBTEXT, index, (LPARAM)buf);

          MessageBox(NULL, buf, L"Тест", MB_OK);
        }
  break;
  // ...
    }
// ...
```

[**-->     Laboratory_work6     <--**](https://github.com/SuvStreet/IT_Step_WinAPI/tree/master/Laboratory_work/Work6)

**22.08.2017 - 23.08.2017**
