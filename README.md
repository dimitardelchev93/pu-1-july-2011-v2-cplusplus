# pu-1-july-2011-v2-cplusplus

Напишете програма за информационно облужване на филмотека, чиито филми не надхвърлят 10000. За целта:

1. За всеки филм да се въведе следната информация: заглавие на филма (до 40 знака), пълни имена на изпълнителите на главната роля, разделени с запетая (до 250 знака), година на производство на филма, лицензна такса за продажба на филма. Пълните имена на всеки изпълнител се разделят на произволен брой имена с точно един интервал.

2. Да се изведе списък на всички филми, съдържащ заглавие на филма, пълни имена на изпълнителите на главната роля, година на производство, лицензна такса. Списъкът да бъде подреден по име на филм (в азбучен ред). Полетата да бъдат разделени с точка и запетая и един интервал. Например:
Голямата сватба; Робърт де Ниро, Аманда Сийфрид, Даян Кийтън; 2011; 100000

3. Да се изведе списък на всички фирми с Робърт де Ниро в главна роля. Списъкът да бъде подреден по година на производство (в низходящ ред), а тези от една и съща година - по лицензна такса (в наразтващ ред).

4. Да се въведе информация за три филмотеки, като се контролира броят на филмите да не надхвърля 10000. За всяка от тях да се изведат справките от точки 2 и 3 и да се пресметне и изведе на екрана средната лицензна такса на филмите от 2010 година. Да се намери и отпечата най-високата от трите средни лицензни такси.

Стъпки:

1. C++ Hello World Project
2. Menu with the four options, 0 to exit
3. Option 1 Add chosen amount of movies with validation
4. Option 2 Show an ordered list of all the movies
5. Option 3 Show an ordered (double) list by a predetermined criteria of all the movies
6. Option 4 Do 1 three times, do 2 and 3 based on that and show average tax for each, after that print the highest average tax

Конзолата не работи с кирилица.

Тестови данни

1
5
title31
artist11, artist12
2000
10000
title22
artist21, Robert de Niro, artist22
2001
400.23
title13
artist31, Robert de Niro
2004
30001.24
title13
Robert de Niro
2004
30000.24
title13
artist31, Robert de Niro, artist32
2008
30000.24
2
3
4
5
title31
artist11, artist12
2000
10000
title22
artist21, Robert de Niro, artist22
2001
400.23
title13
artist31, Robert de Niro
2004
101.24
title13
Robert de Niro
2004
1100.24
title13
artist31, Robert de Niro, artist32
2008
200.24
5
title31
artist11, artist12
2000
22000
title22
artist21, Robert de Niro, artist22
2001
400.23
title13
artist31, Robert de Niro
2004
3301.24
title13
Robert de Niro
2004
30000.24
title13
artist31, Robert de Niro, artist32
2008
31000.24
5
title31
artist11, artist12
2000
10
title22
artist21, Robert de Niro, artist22
2001
400.23
title13
artist31, Robert de Niro
2004
101.24
title13
Robert de Niro
2004
200.24
title13
artist31, Robert de Niro, artist32
2008
10.24
