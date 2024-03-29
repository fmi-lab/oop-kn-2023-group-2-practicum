# Практикум 15 - Изключения

## Задача 00 - Изключение при липса на файл
Реализирайте ваше собствено изключение, което да сигнализира за липса на файл при опит за неговото отваряне.

## Задача 01 - Обработване на грешки при работа с файлове
Като използвате създаденото от вас изключение в `Задача 00`, погрижете се за правилното обработване на грешки в задачите от `Седмица 13`. При нужда, може да използвате и изключенията от стандартната библиотека. Целете се да постигнете `strong exception guarantee`. Експлицитно обявете кои функции не трябва да хвърлят изключение.

## Задача 02 - Плейлист
Да се реализира клас `Song`, който представлява песен с име, автор и продължителност. При опит за създаване на песен с невалидни данни, да се хвърли подходящо изключение.

Да се реализира клас `Playlist`, който представлява плейлист с песни, който съдържа име на плейлиста и списък от песни. Да се реализират следните методи за класа:
- добавяне на песен - ако песента вече е част от плейлиста, да се хвърли подходящо изключение;
- премахване на песен - ако песента, която се иска да бъде премхната не е част от спсисъка, да се хвърли подходящо изключение;
- изпълняване на песните - принтира на нов ред песните в реда, в който са в момента. При опита за изпълняване на празен плейлист да се хвърли подходящо изключение;
- разбъркване на плейлиста - променя реда на песните в плейлиста на произволен принцип. При опит за разбъркване на празен плейлист да се хвърли подходящо изключение;
- намиране на общата продължителност на песните в плейлиста.

Целете се да постигнете `strong exception guarantee`. Експлицитно обявете кои функции не трябва да хвърлят изключение.

### Бонус:
Информацията за плейлиста да се зарежда от двоичен файл. При приключване на работата с плейлиста, информацията да се записва обратно във файла.