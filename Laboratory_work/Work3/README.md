### ЛАБОРАТОРНАЯ РАБОТА №3

**Задание**
  1. Слушатель Глеб, пребывая в состоянии пьяной лени, попытался создать оконное приложение под Windows (файл `first_application.cpp`), но оказалось, что код не компилируется. Помогите Глебу отладить программу.
  
  2. Измените приложение следующим образом:
    * размеры окна 200х100 (задаются как константы);
    * окно нельзя максимизировать;
    * окно нельзя свернуть.
  
  3. В приложении `first_application` замените иконку на myIcon.ico или любую свою.
  
  4. Измените курсор в приложении на курсор, созданный самостоятельно с помощью редактора ресурсов.
  
  5. Измените приложение `first_application` таким образом, чтобы спустя 10 секунд после запуска у пользователя спрашивалось, хочет ли он завершить работу.
  
  6. Настройте обработку сообщений мыши следующим образом:
    * по нажатию на левую кнопку мыши курсор приложения изменяется на один из стандартных курсоров;
    * по двойному щелчку левой кнопкой мыши курсор приложения изменяется на исходный;
    * по нажатию на правую кнопку мыши цвет фона меняется случайным образом;
    * по двойному щелчку правой кнопкой мыши цвет фона изменяется на белый.
        * Получить дескриптор приложения можно с помощью функции GetModuleHandle с аргументом NULL.
  
  7. Настройте обработку сообщений клавиатуры следующим образом:
    * по сочетанию клавиш Alt + ↓ окно сворачивается;
    * по сочетанию клавиш Alt + ↑ окно максимизируется;
    * по сочетанию клавиш Alt + ← или Alt + → окно показывается в своем исходном размере;
    * по сочетанию клавиш Alt + F4 появляется диалоговое окно с предложением завершить работу приложения;
    * по нажатию на клавишу Enter окно перемещается в правый верхний угол рабочего стола и начинает перемещаться вдоль его границы с постоянной скоростью;
    * по нажатию на клавишу Escape окно прекращает движение.
        * Чтобы получить размеры рабочего стола, воспользуйтесь функцией SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0).
  
  8. Настойте прорисовку в центре окна системного времени в формате часы:минуты:секунды. Время должно обновляться каждую секунду.
    * Чтобы вызвать обновление окна, вызовите следующую функцию:
        * RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW).