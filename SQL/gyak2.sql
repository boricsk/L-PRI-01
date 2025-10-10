use adatb1_1415i_konz04;

select
	vevo_nev,
	irsz,
	helyseg,
	vevo_cim
from vevok inner join telepulesek on telepulesek.irsz = vevok.vevo_irsz
where helyseg = 'Kecskemét'
order by vevo_nev;

--Decartes megoldás
select 
	vevo_nev, irsz, helyseg, vevo_cim
from vevok, telepulesek
where vevo_irsz = irsz and helyseg = 'Kecskemét'
order by vevo_nev;

--Osszes szolnoki vevő vevő név, vásárlás dátum, számlaszám
select
	vevo_nev,
	szamla_datum,
	szamla_szam
from vevok
inner join telepulesek on irsz = vevo_irsz
inner join szamlak on vevo_kod = szamla_vevokod
where helyseg = 'Szolnok'
order by vevo_nev

/*
 * Adjuk meg egy lekérdezéssel az összes kiskunhalasi vevő nevét, helységnevét, közelebbi címét, a vevő
neve szerint rendezve!
*/
select 
	vevo_nev,
	helyseg,
	vevo_cim
from vevok
inner join telepulesek on vevo_irsz = irsz
where helyseg = 'Kiskunhalas'
order by vevo_nev

/*
 * Készítsünk lekérdezést, amely a „Te” névkezdetű termékek vásárlásairól listát készít. A listán
szerepeljen a számlaszám, a vásárlás dátuma, az áru neve, egységára, a vásárolt mennyiség. Rendezzük
a listát a számlaszám szerint csökkenő sorrendbe!
 * */

select
	szr_szamlaszam,
	szamla_datum,
	szr_vasaroltmennyiseg,
	aru_egysegar,
	aru_nev
from aruk
inner join szamlakreszletei on aru_kod = szr_arukod
inner join szamlak on szamla_szam = szr_szamlaszam
where aru_nev like 'Te%'
order by szr_szamlaszam desc

/*Az eladott áru egységára szerinti csökkenő sorrendben jelenítsem meg az összes Műszaki kategóriában
eladott, 10000 Ft-nál drágább termék nevét, egységárát, darabszámát (szr_vasaroltmennyiseg) és az
eladás dátumát!*/

select 
	szr_szamlaszam,
	szamla_datum,
	szr_vasaroltmennyiseg,
	aru_egysegar,
	aru_nev
from aruk
inner join kategoriak on aru_kategoriakod = kategoria_kod
inner join szamlakreszletei on aru_kod = szr_arukod
inner join szamlak on szamla_szam = szr_szamlaszam
where aru_egysegar > 10000 
and szr_vasaroltmennyiseg > 0 
and kategoria_nev = 'Műszaki'
order by aru_egysegar desc

select * from kategoriak

/*Készítsen listát a három legolcsóbb Barkács kategóriájú áru nevéről és egységáráról!
*/

select
	aru_nev,
	aru_egysegar
from aruk
inner join kategoriak on aru_kategoriakod = kategoria_kod
where kategoria_nev = 'Barkács'
order by aru_egysegar 
limit 3


