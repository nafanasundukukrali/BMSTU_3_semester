# Тесты для лабораторной работы №06
## Входные данные
file - наименование файла, строка, не  более 25 символов;
field - поле, по которому будет осуществляться поиск, строка, не более 25 символов;
[key] - ключ, по которому будет осуществляться поиск, строка, не более 25 символов;
## Выходные данные
Массив структур, обнаруженных в ходе поиска по файлу ("Not found", если таких структур нет
 и полный список, если отсуствует параметр key).
## Позитивные тесты:
- 01 - уже упорядоченный файл со структурами, ключ нет;
- 02 - разопорядоченный файл со структурами, ключа нет;
- 03 - поиск по названию фильма, названия нет;
- 04 - поиск по названию фильма, есть в списке (в начале);
- 05 - поиск по фамилии режиссёра, имени нет;
- 06 - поиск по фамилии режиссёра, есть в спике (в середине);
- 07 - поиск по году, года нет;
- 08 - поиск по году, есть в списке (в конце).
## Негативные тесты:
- 01 - количество параметров меньше 2;
- 02 - количество параметров больше 3;
- 03 - файл не существует;
- 04 - файл пустой;
- 05 - какая-то структура не полностью записана;
- 06 - интересующее поле отсуствует  списке;
- 07 - интересующее поле слишком длинное;
- 08 - значение слишком длинное;
- 09 - при сортировки по году вводится не число.
