Обработка сообщений
===

Ресурсы
---

* содержат различные элементы: иконки, курсоры, шаблоны диалоговых окон, меню и др.
* файл описания ресурсов имеет расширение .rc
* нужна компиляция
* создается файл resource.h

```cpp
#include "resource.h"
wndclass.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
```

Изменение иконки (вариант 1)
---

* если ресурсов нет, то добавить новый ресурс (**`Resource Files / Add / Resource… / Icon / Import...`** и выбрать свою иконку)
* скомпилировать файл ресурсов
* узнать числовую константу (**`IDI`**) для иконки (`View Code...` и найти символьную константу для иконки – например, **`IDI_ICON1`**)
* подключить заголовочный файл **`"resource.h"`**

```cpp
#include "resource.h"
wndclass.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
```

Изменение иконки (вариант 2)
---

* если ресурсов нет, то добавить новый ресурс
(**`Resource Files / Add / Resource… / Icon / Import…`** и выбрать свою иконку)
* скомпилировать файл ресурсов
* узнать числовую константу (**`IDI`**) для иконки
(зайти в Resource View [Ctrl + LShift + E], в дереве правой кнопкой щелкнуть по нужной иконке `View Code...` и посмотреть `Resource Symbols...`)

```cpp
wndclass.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(101));
```

Сообщения мыши
---

* начинаются с префикса **`WM_`**

  Cообщения             | Описание
------------------------|--------------------
**`WM_LBUTTONDOWN`**    |   нажата левая кнопка мыши
**`WM_RBUTTONDOWN`**    |   нажата правая кнопка мыши
**`WM_LBUTTONUP`**      |   отпущена левая кнопка мыши
**`WM_RBUTTONUP`**      |   отпущена правая кнопка мыши
**`WM_LBUTTONDBLCLK`**  |   двойной щелчок левой кнопкой мыши
**`WM_RBUTTONDBLCLK`**  |   двойной щелчок правой кнопкой мыши
**`WM_MOUSEMOVE`**      |   перемещение курсора мыши
**`WM_MOUSEWHEEL`**     |   прокрутка колесика




















[**-->     Laboratory_work3     <--**](https://github.com/SuvStreet/IT_Step_WinAPI/tree/master/Laboratory_work/Work3)

**16.08.2017**
