use ab_i_04_tovabbigyak;

/*
 Listázza ki azoknak a nem budapesti ingatlanoknak a helységnevét, szobaszámát, árát és a
képviselõ ügynök nevét, amelyek garázzsal rendelkeznek vagy Házrész típusúak! A listát rendezze ár
szerint csökkenõ sorrendbe!
*/
select
	helyseg,
	szobaszam,
	ar,
	ugynok_nev
from ingatlanok
inner join tipusok on tipus_ID = fk_tipusID
inner join ugynokok on ugynok_ID = fk_ugynokID
where (garazs = 1 or tipus_nev = 'Házrész')
and helyseg not in ('Budapest')
order by ar;

/*
Jelenítse azoknak az ügynököknek a nevét és telefonszámát, akikhez nem kapcsolódik ingatlan!
*/

select
	--ingatlan_ID,
	ugynok_nev,
	telefon
from ugynokok
left join ingatlanok on ugynok_ID = fk_ugynokID
where ingatlan_ID is null;


/*Városonként (helységenként) számlálja meg, hány olyan ingatlan van, amelynek ára 10 és 14
millió Ft között van! A lista a megszámlált érték szerint csökkenõ sorrendben jelenjen meg!*/

select
 helyseg,
 count(*) as ingatlan_szama
from ingatlanok
where ar between 10 and 14
group by helyseg
order by ingatlan_szama;

/* Listázza ki átlagár szerinti sorrendben azoknak az ingatlantípusoknak a nevét és az adott
típushoz tartozó ingatlanok átlagos árát, amelyeknek átlagára 17.5 MFt-nál kisebb!*/

select
	tipus_nev,
	avg(ar) as atlag_ar
from ingatlanok
inner join tipusok on tipus_ID = fk_tipusID
group by tipus_nev
having avg(ar) < 17.5
order by atlag_ar;

/*Listázza ki minden városból a legdrágább ingatlan helységnevét és árát! A listában csak az
elsõ 20 találat legyen látható!*/

select
	helyseg,
	max(ar) as legdragabb
from ingatlanok
group by helyseg
limit 20;

/* Készítsen megyek néven egy olyan táblát, amelynek három mezõje van: (1) a megye_ID mezõ
legyen automatikus számozású, INT típusú elsõdleges kulcs; (2) a megye_nev legfeljebb 30 karakteres
szövegeket megengedõ mezõ; (3) az indul_datum legyen dátum típusú! A létrehozáshoz szükséges
SQL-parancsot vagy a tábla szerkezeti nézetének képernyõképét mentse a word-dokumentumba!*/

create table megyek (
	megye_id	int	auto_increment primary key,
	megye_nev	varchar(30),
	indul_datum	date
);


/*: Bõvítse az ingatlanok táblát olyan fk_megyeID nevû, INT típusú új mezõvel, amelybe csak
olyan idegenkulcs-érték beszúrható, amely a megyek táblában már szerepel kulcsértékként! A
létrehozáshoz használt SQL-parancso(ka)t mentse a word-dokumentumba!*/

alter table ingatlanok
add column fk_megye_id int;

ALTER TABLE ingatlanok
add CONSTRAINT foreign key (fk_megye_id) references megyek(megye_id);

/*Készítsen törlõ lekérdezést, amellyel törölheti az ingatlanok táblából azokat az ingatlanokat,
amelyek 1.000.000 Ft-nál olcsóbbak vagy Ajkán találhatóak! A törlõ parancsot mentse a worddokumentumba*/

delete from ingatlanok
where ar < 1 or helyseg = 'Ajka';

select * from ingatlanok