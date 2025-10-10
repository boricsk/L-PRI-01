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



