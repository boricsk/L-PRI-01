use adatb1_1415i_konz04;

/*Jelenítsük meg azoknak a településeknek az irányítószámát és nevét, ahonnan még nem volt vevőnk!*/
select 
	*
from telepulesek 
left join vevok on vevo_irsz = irsz
where vevo_kod is null

/*Adjuk meg egy lekérdezéssel az összes kiskunhalasi vevő nevét, helységnevét, közelebbi címét, a vevő
neve szerint rendezve!*/

select 
	vevo_nev,
	vevo_cim
from vevok
inner join telepulesek on irsz = vevo_irsz 
where helyseg = "Kiskunhalas"
order by vevo_nev 


/*Készítsünk lekérdezést, amely a „Te” névkezdetű termékek vásárlásairól listát készít. A listán
szerepeljen a számlaszám, a vásárlás dátuma, az áru neve, egységára, a vásárolt mennyiség. Rendezzük
a listát a számlaszám szerint csökkenő sorrendbe!*/

select
	szr_szamlaszam,
	szamla_datum,
	aru_nev,
	aru_egysegar
from aruk
inner join szamlakreszletei on szr_arukod = aru_kod
inner join szamlak on szamla_szam = szr_szamlaszam
where aru_nev like 'Te%'
order by szr_szamlaszam desc


/*Az eladott áru egységára szerinti csökkenő sorrendben jelenítsem meg az összes Műszaki kategóriában
eladott, 10000 Ft-nál drágább termék nevét, egységárát, darabszámát (szr_vasaroltmennyiseg) és az
eladás dátumát!*/

select
	aru_nev ,
	aru_egysegar ,
	szr_vasaroltmennyiseg ,
	szamla_datum	
from aruk
inner join szamlakreszletei on aru_kod = szr_arukod
inner join szamlak on szr_szamlaszam = szamla_szam
inner join kategoriak on aru_kategoriakod = kategoria_kod 
where aru_egysegar > 10000 and kategoria_nev = "Műszaki"
order by aru_egysegar 

/*Készítsen listát a három legolcsóbb Barkács kategóriájú áru nevéről és egységáráról!*/

select
	aru_nev ,
	aru_egysegar 	
from aruk
inner join kategoriak on aru_kategoriakod = kategoria_kod 
where kategoria_nev = "Barkacs"
order by aru_egysegar 
limit 3

/*Kategóriánként adjuk meg a kategória nevét és azt, hogy melyik kategóriába hányféle termék tartozik!*/

select
	kategoria_nev,
	count(*)
from aruk
inner join kategoriak on aru_kategoriakod = kategoria_kod
group by kategoria_nev  


/*Termékenként határozzuk meg, melyikből hány darabot adtak el összesen 2012. februárjában. Csak
azoknak a termékeknek a nevét és eladott mennyiségét jelenítsük meg, amelyből 10-nél kevesebbet
adtunk el.*/

select
	aru_nev,
	sum(szr_vasaroltmennyiseg)
from szamlak
inner join szamlakreszletei on szr_szamlaszam = szamla_szam
inner join aruk on aru_kod = szr_arukod 
where szamla_datum between "2012-02-01" and "2012-02-29" and szr_vasaroltmennyiseg < 10
group by aru_nev 


/*Városonként számolja meg, hány T-vel vagy K-val kezdődő nevű vásárlónk van! Írja ki a város nevét
és a vásárlók számát! A lista elején a legnagyobb számok álljanak!*/

select
	helyseg,
	count(*)
from vevok 
inner join telepulesek t on vevo_irsz = t.irsz
where vevo_nev like 'T%' or vevo_nev like 'K%'
group by t.helyseg 
order by count(*) desc

/*Árunként összegezve írjuk ki, melyik műszaki áruból hány darabot adtunk el! Csak azok az áruk
jelenjenek meg, amiből összesen legalább 10 darabot eladtunk! A lista az áru neve szerint legyen
rendezett!*/

select
	aru_nev ,
	sum(szr_vasaroltmennyiseg)
from szamlakreszletei
inner join aruk on szr_arukod = aru_kod 
inner join kategoriak on aru_kategoriakod = kategoria_kod
where szr_vasaroltmennyiseg >= 10
group by aru_nev 
order by aru_nev

/*Jelenítsük meg azoknak a termékeknek az összes adatát, amelyek drágábbak, mint a legolcsóbb „Játék”
kategóriájú termék!*/

select
	*
from aruk
where aru_egysegar > (
	select
		min(aru_egysegar)
	from aruk
	inner join kategoriak on aru_kategoriakod = kategoria_kod
	where kategoria_nev = 'Játék'
	limit 1
)

/*Jelenítsük meg azoknak a településeknek az irányítószámát és nevét, ahonnan még nem volt vevőnk!*/

select 
	irsz ,
	helyseg
from telepulesek
left join vevok on irsz = vevo_irsz
where vevo_kod is null

/*Minden település esetén írjuk ki a település nevét, továbbá annak (azoknak) a vevő(k)nek a nevét és
közelebbi címét, akik a településükről utoljára vásároltak! Ha egy településen belül többen is
vásároltak ezen a napon, akkor mindegyiket írjuk ki! Jelenjen meg a vásárlás dátuma is!*/

select 
	helyseg,
	vevo_nev ,
	vevo_cim ,
	szamla_datum 
from telepulesek t
inner join vevok vk on irsz = vevo_irsz
inner join szamlak szk on szamla_vevokod = vevo_kod
where szamla_datum = (
	select
		max(szamla_datum) 
	from vevok vb
	inner join telepulesek tb on tb.irsz =vb.vevo_irsz 
	inner join szamlak sb on sb.szamla_vevokod = vb.vevo_kod 
	where tb.helyseg = t.helyseg 
)

/*Készítsünk lekérdezést, amely a műszaki termékek egységárát 10%-kal megnöveli!*/
update aruk 
set aru_egysegar = aru_egysegar * 1.1
where aru_kategoriakod = (
	select
		kategoria_kod
	from kategoriak kb
	where kb.kategoria_nev = 'Műszaki'
)

/*Készítsünk lekérdezést, amely törli az aruk táblából a 300 Ft-nál olcsóbb termékeket!*/

delete from aruk 
where aru_egysegar < 300

/*Készítsünk lekérdezést, amelynek segítségével az aruk táblát egy új mezővel bővíthetjük. Az új mező
neve legyen aru_vonalkod, 20 karakter hosszú vonalkódok tárolására legyen alkalmas!*/

alter table aruk 
add aru_vonalkod nvarchar(20)










