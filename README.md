# Map

Программа была скомпилирована и написана в QT creator под ОС Linux Lubuntu 

/*
 * Информация о программе
 *
 * Программа получает на вход текстовый документ,который хранит путь к изображениям карты.
 * Программа также получает на вход текстовый gcp файл, который хранит координаты меток вида : Долгота Широта Высота px py mapName
 *
 * Когда map и gcp файл выбраны,программа выводит метки,указанные в gcp файле на условной карте
 *
 * Что сделано:
 *
  + Базовый интерфейс
 *
  + Выбор документа с путями к изображениям
  + Выбор gcp документа.
 *
  + Чтение и отображение меток на условной карте (тема с OpenDroneMap чересчур размыта + нет обратной связи => отсутствие настоящей или желаемой карты).
  + Добавление новых изображений к существующей карте.
 *
 * Что не сделано:
 *
  - Графическое удаление меток
  - Всё,что может прийти в голову
 *
 *
 *
 *
 *
 *
 * Спасибо за просмотр данного, скорее всего , некрасивого и недореализованого проекта :D
 */


Чтобы проверить работоспособность файла,я заранее загрузил в папку build-Map-Desktop-Debug файлы map.txt (в котором записаны пути к изображениям карты) и gcp.txt ,
для проверки как "это" работает, достаточно запустить файл Map , в новом окне нажать сначала кнопку "Load Map" и выбрать map.txt,
а затем выбрать кнопку Select GCP file и выбрат соответственно gcp.txt. 

Теперь можно слева выбрать элемент списка,который при нажатии выведет изображение . На нем уже можно связывать соответствующие точки изображения с географическими координатами.