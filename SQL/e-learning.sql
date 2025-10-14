use world;

/*Készítsük el a minta-adatbázisból az európai országok nevét és lakosságának nagyságát bemutató lekérdezést az ország neve szerint rendezve!*/

select
	name, population
from country
where continent = 'Europe'
order by name

/*Készítsük el a minta-adatbázisból azoknak az európai, legfeljebb 10 000 000 lakosú országoknak a listáját, amelyeknek a neve F betűvel kezdődik 
 * vagy a betűre végződik! A listában az ország neve és lakosságának nagysága jelenjen meg, a lakosság szerint csökkenő sorrendben!*/

select
	name,
	population
from country
where population <= 10000000
and continent = 'Europe'
and (name like 'F%' or name like '%a')
order by population desc


/*Készítsen lekérdezést, amely a minta-adatbázisból megjeleníti azokat az országokat, amelyeknek a lakossága több, mint 30 millió ember, vagy pedig 
 * a területe nagyobb, mint 1 milló négyzetkilométer (a terület nagysága négyzetkilométerben adott)!*/
select 
	count(name)
from country
where population > 30000000 or surfacearea > 1000000

/*Egészítse ki a szöveget a helyes adattal (az elkészített és lefuttatott parancs eredménye alapján)!

Korlátozza az előző lekérdezés eredménytábláját úgy, hogy csak a három legnagyobb területű ország adatai jelenjenek meg!*/

select 
	name,
	indepyear
from country
order by surfacearea desc 
limit 3

/*Egy lekérdezéssel annak az észak- vagy dél-amerikai országnak a nevét és függetlensége évét szeretnénk megjeleníteni, 
 * amelyik a legrégebben független. Húzza a hiányzó elemeket az SQL-parancsba!*/

select 
	name,
	indepyear
from country
where continent like '%America' and indepyear is not null
order by indepyear 
limit 1

--Decartes szorzat
select * from country, city;

select * from country, city
where country.code = city.countrycode;

select 
	country.name,
	city.name
from country
inner join city on code = countrycode

/*
 * Írjuk ki az Al karakterekkel kezdődő nevű országok nevét, városai nevét és a beszélt hivatalos nyelvek nevét!
 * */

select
	country.name,
	city.name,
	language
from country
inner join city on code = city.countrycode
inner join countrylanguage on code = countrylanguage.countrycode
where country.name like 'Al%' and isofficial = 'T'

/*
 * készítsen lekérdezést, amely a Canada országban beszélt nyelveket jeleníti meg ábécé-sorrendben!*/

select
	Language
from country
inner join countrylanguage on countrycode = code
where country.name = 'Canada' and isofficial = 'T'
order by language


/*Készítsünk olyan lekérdezést, amely azoknak az országoknak a nevét és földrészét jeleníti meg, amelyekhez nem kapcsolódik város!
 * */

select 
	country.name,
	continent
from country
left join city on code = countrycode
where city.name is null


/*Húzza a hiányzó szavakat, kifejezéseket a parancsba úgy, hogy a parancs az európai országok 
 * átlagos területét, majd az európai országok számát jelenítse meg!

*/

select
	round(avg(surfacearea),2),
	count(name)
from country
where continent = 'Europe'
group by continent

/*Egészítse ki úgy a parancsot a hiányzó szavak beírásával, hogy a parancs megszámlálja a különöbző nevű városokat a city táblában!*/

select
	count(*)
from city

select 
	count(distinct name)
from city

/*
 * Például: Számláljuk meg, hány olyan ország van, ahol hivatalos nyelv az angol!

Megoldás: A country és a countrylanguage táblát összekapcsolva szűrhetjük azokat a rekordokat, 
ahol a nyelv English, az IsOfficial mezőben pedig T szerepel. Ezeket a sorokat kell megszámlálni 
(az eredmény 44 lesz).
 * */

select 
	count(name)
from country
inner join countrylanguage on countrycode = code
where language = 'English' and isofficial = 'T'


/*Aggregálás - Csoportképzés*/


select 
	continent,
	count(code)
from country
group by continent

/*a két legnagyobb területű földrész nevét és területét írja ki (a country táblában szerepelő országok területének összegzésével)!*/

select 
	continent,
	sum(surfacearea) as sumarea
from country
group by continent 
order by sumarea desc
limit 2;


/*Földrészenként számláljuk meg, melyiken hány olyan ország van, ahol az angol vagy a spanyol 
 * nyelv hivatalos nyelv! A földrész neve és az országok száma jelenjen meg!*/

select
	continent,
	count(distinct name) as countofcountries
from country
inner join countrylanguage on code = countrycode
where language in ('English', 'Spanish') and isofficial = 'T'
group by continent

/*az európai országok 1 000 000 főnél nagyobb városainak összlakosságát írja ki, az ország 
 * neve szerint rendezve! (A Name és a Population mező mindkét táblában előfordul.)*/

select 
	country.name,
	sum(city.population) as sumpopulation
from country
inner join city on countrycode = code
where city.population > 1000000 and continent = 'Europe'
group by country.name
order by country.name

/*Jelenítsük meg azoknak a nyelveknek a listáját, amelyeket 25-nél több országban beszélnek (az országok mennyisége is jelenjen meg)!*/

select 
	language,
	count(name) as amountofcountries
from country
inner join countrylanguage on code = countrycode
group by language
having amountofcountries > 25


/*Egészítse ki a következő parancsot úgy, hogy a tárolt városok lakosságát összegezve (tehát nem a country tábla Population mezője alapján) 
 az a 3 legkisebb összlakosságú európai ország szerepeljen benne (az ország neve és számított összlakossága), amelyeknek az összlakossága 
 (a tárolt városok alapján) több, mint 15 000 000!*/


select 
	co.name,
	sum(ci.population) as sumofpop
from country as co
inner join city as ci on code = countrycode
where continent = 'Europe'
group by co.name
having sumofpop > 15000000
order by sumofpop
limit 3

/*Listázza azoknak a nem egyesült államokbeli városoknak a nevét és országának nevét, amelyek valamelyik tárolt egyesült államokbeli várossal azonos nevűek!*/

select
	c.name,
	co.name
from country as co
inner join city as c on countrycode = code
where continent not in ('North America') and c.name in (
select 
	name
from city where countrycode = 'USA'
)

/*Húzza a hiányzó szavakat, kifejezéseket a parancsba úgy, hogy azoknak az országoknak a listáját kapja, ahol legalább egy olyan nyelvet beszélnek, amelyet 
 * Argentínában is! Minden ilyen ország csak egyszer jelenjen meg (akkor is, ha több közös nyelve van Argentínával)! A listában Argentína ne szerepeljen!*/

select 
	distinct c.name
from country as c
inner join countrylanguage as clang on clang.countrycode = c.code
where clang.language in (
	select
		clangb.language
	from country as cb
	inner join countrylanguage as clangb on clangb.countrycode = cb.code
	where cb.name = 'Argentina'
) and c.name <> 'Argentina'

/* Készítsen listát az országok nevéről, és minden országból a tároltak közül a legkisebb lakosságú város nevéről és lakosságáról!*/

select 
	c1.name,
	city.population
from country c1
inner join city on code = countrycode
where city.population = (
	select
		min(city.population)
	from country
	inner join city on code = countrycode
	where country.name = c1.name
)

/*Például: Oldjuk meg a 3.3.2. fejezet első példáját, azaz készítsünk listát az egyes földrészek nevéről, 
 * és a földrész legnagyobb területű országának nevéről, területéről és lakosságáról!

Megoldás: A FROM záradékba beágyazzuk azt a csoportosító lekérdezést, amely földrészenként kiszámítja az országok 
területének maximumát. Ennek a lekérdezésnek az eredménytábláját elnevezzük (a megoldásban temp-nek), és 
összekapcsoljuk az eredeti country táblával. Végül azokat a rekordokat tartjuk meg, ahol az eredeti táblában 
az ország területe megegyezik a temp tábla kiszámított maximumával - amelynek szintén álnevet adunk.*/

SELECT country.Continent, Name, SurfaceArea
    FROM country INNER JOIN (
          SELECT Continent, MAX(SurfaceArea) MaxArea
          FROM country
          GROUP BY Continent
      ) temp ON country.Continent = temp.Continent
WHERE SurfaceArea = temp.MaxArea;

/*A megfelelő sorok húzásával készítse el azt a lekérdezést, amely megjeleníti a 10 legnagyobb GNP-vel 
 * rendelkező ország nevét, földrészét és GNP (buttó nemzeti össztermék) értékét! A feladathoz a 
 * minta-adatbázist kell használnia.

*/

select name, continent, gnp
from country
order by gnp desc
limit 10;

/*
Készítsen lekérdezést, amely az 5 000 000-nál több lakosú, ázsiai országok nevét és 
területét jeleníti meg, az ország neve szerint növekvő sorrendben! A megoldáshoz a 
minta-adatbázist kell használni!

*/

select
	name,
	surfacearea
from country
where continent = 'Asia' and population > 5000000
order by name


/*Készítsen lekérdezést, amely az 1820 és 1920 között függetlenné vált, B betűvel kezdődő nevű  
 országok nevét és GNP-jét jeleníti meg, a függetlenné válás szerint növekvő sorrendben!
A megoldáshoz a minta-adatbázist kell használni!*/

select
	name,
	gnp
from country
where indepyear between 1820 and 1920 and name like 'B%'
order by indepyear

/*
 * Készítsen lekérdezést, amely az karibi régióban lévő, legfeljebb 4 000 000 lakosú országok 
 * nevét és területét jeleníti meg, a lakosság szerint csökkenő sorrendben! A megoldáshoz a 
 * minta-adatbázist kell használni!
 * */

select
 name,
 surfacearea,
from country
where region = 'Caribbean' and population <= 4000000
order by population desc


/*
 * A szövegrészek húzásával készítse el azt a parancsot, amely a Kelet-Európa (Eastern Europe) régió 
 * országainak nevét, továbbá az ezekben az országokban nyilvántartott városok nevét és lakosságát 
 * jeleníti meg! A lista az ország neve szerint növekvő, azon belül a város lakossága szerint csökkenő 
 * sorrendben jelenjen meg! A megoldáshoz a minta-adatbázist kell használni!
 * */

select 
	co.name,
	ci.name,
	ci.population
from country co
inner join city ci on code = countrycode
where region = 'Eastern Europe'
order by co.name asc, ci.population desc;

/*
 * 
 * A sorok húzásával készítse el azt a parancsot, amellyel azoknak a régióknak a név szerint növekvő listáját 
 * jeleníti meg (minden régiónevet legfeljebb egyszer), amelyekben van olyan ország, amelyhez nem kapcsolódik város!
 * */

select 
	distinct region
from country co
left join city ci on code = countrycode
where id is null
order by region


select
	language,
	count(*)
from country inner join countrylanguage on code = countrycode
where isofficial = 'T' and continent = 'Europe'
group by language
order by count(*) desc, language

/*
 * Készítsen lekérdezést, amely az ázsai vagy európai országok területének régiónkénti összegét számítja ki,
 *  és az összterület szerint csökkenő sorrendben megjeleníti a régió nevét és országai összterületét!
 *  A megoldáshoz a minta-adatbázist kell használni!
 * */

select
	region,
	sum(surfacearea)
from country
where continent = 'Asia' or continent = 'Europe'
group by region
order by sum(surfacearea) desc

/*
 * Melyik az 5. legtöbb ember által beszélt nyelv az adatbázis szerint? Készítsen lekérdezést, amely 
 * nyelvenként összesíti az azt beszélők számátl A helyes megoldáshoz -többek között - az adott ország 
 * lakosainak számát meg kell szorozni az azt beszélők országon belüli arányszámával (Percentage) és 
 * osztani 100-zal. A megoldáshoz a minta-adatbázist kell használni!
 * */

select
	language,
	sum(population)
from country
inner join countrylanguage on countrycode = code
group by language
order by sum(population) desc
limit 5;

/*
 * Készítsen lekérdezést, amely megjeleníti a 300 000 000-nál nagyobb összlakosságú régiók nevét és
 *  összlakosságát, az utóbbi szerint csökkenő sorrendben! A megoldáshoz a minta-adatbázist kell használni!
 * */

select
	region,
	sum(population)
from country
group by region
having sum(population) > 300000000
order by sum(population) desc

/*
 * Készítsen lekérdezést, amely az ország neve szerint növekvő sorrendben megjeleníti azoknak az Észak- vagy 
 * Dél-Amerikában található országoknak a nevét és lakosságát, amelyeknek kevesebb lakosuk van, mint a 
 * legkevesebb lakosú ázsiai országnak!  A megoldáshoz a minta-adatbázist kell használni!
 * */

select *
from country
where (continent = 'South America' or continent = 'North America') and population < (
	select 
		min(population)
	from country
	where continent = 'Asia'
)




