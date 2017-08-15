Введение в Windows-программирование
===

API (Application Program Interface)
---

* набор констант, классов, структур и функций для разработки приложений
* главный элемент приложения – окно

![](https://pp.userapi.com/c840135/v840135772/221c1/cZN8GwRZBUs.jpg)

События и сообщения
---

![](https://pp.userapi.com/c840135/v840135772/221c8/Y4CpHN4VGWE.jpg)

Окно
---

**`Объект, над которым выполняют действие`**

* у каждого окна **`есть родитель`** (для окон верхнего уровня – окно рабочего стола)
* родитель дочернего окна – **`окно верхнего уровня или другое дочернее окно`**
* владельцем окна верхнего уровня может быть другое окно того же уровня (тогда оно отображается поверх окна-владельца)
* кнопки – это **`тоже окна`**

Виды окон
---

* **окно приложения**
  * главное окно приложения
  * появляется первым при запуске
  * закрывается последним

* **диалоговое окно**
  * обеспечивает обмен данными между пользователем и приложением

Дескриптор
---

* число
* все объекты в Windows **`описываются через дескрипторы`**
* дескриптор окна **`однозначно определяет окно`** в системе
* тип и имя дескриптора начинается с **`префикса H`** (HINSTANCE, HWND, HICON, HFONT, hWnd, hInst и т. п.)

Сообщения окнам (Message window)
---

  Message window (MW)   |  Описание
------------------------|-------------------
**WM_CREATE**           |   (создать окно)
**WM_DESTROY**          |   (разрушить окно)
**WM_CLOSE**            |   (закрыть окно)
**WM_QUIT**             |   (завершить приложение)
**WM_ACTIVATE**         |   (активировать окно)
**WM_SHOWWINDOW**       |   (скрыть или отобразить окно)
**WM_ENABLE**           |   (сделать окно доступным или нет)
**WM_MOVE**             |   (положение окна изменилось)
**WM_SIZE**             |   (размер окна изменился)
**WM_SETFOCUS**         |   (получить фокус ввода)
**WM_KILLFOCUS**        |   (потерять фокус ввода)
**WM_QUERYENDSESSION**  |   (сообщает о конце сеанса Windows)

Структура сообщения
---

* каждое сообщение имеет свой **`код`**
* каждому коду сопоставлена **`символическая константа`** (код 0х200 – WM_MOUSEMOVE и т.п.)
* сообщение представляется как **`структура`**

```cpp
struct MSG {
  HWND    hwnd;     // дескриптор окна
  UINT    message;  // код сообщения
  WPARAM  wParam;   // доп. информация
  LPARAM  lParam;   // доп. информация
  DWORD   time;     // время отправки
  POINT   pt;       // позиция курсора
};
```

Функции для работы с окнами
---

  Функции             | Описание
----------------------|-------------------------------
CreateWindow          |
ShowWindow            |
CloseWindow           |   (закрывает, но не разрушает окно!)
IsWindowVisible       |   (возвращает состояние окна)
MoveWindow            |   (изменяет расположение и размеры)
GetClientRect         |   (получить координаты клиентской области)
GetWindowPlacement    |   (данные о расположении окна)
FindWindow            |   (поиск окна верхнего уровня)
GetParent             |   (получить дескриптор родителя)
GetWindow             |   (получить дескриптор окна)
IsChild               |   (дочернее ли окно)
IsWindow              |   (соответствует ли дескриптор окну)
OpenIcon              |   (восстанавливает свернутое окно)
SetWindowPlacement    |   (свертывает и развертывает окно)

Минимальное Win32-приложение
---

* включает две функции:
  * **`WinMain`** (инициализация приложения в ОС)
    * инициализация переменных
    * регистрация оконного класса
    * создание окна
    * отображение окна
    * создание цикла обработки сообщений
  * **`WndProc`** (обработка сообщений; может быть вызвана только ОС)

```cpp
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
```










