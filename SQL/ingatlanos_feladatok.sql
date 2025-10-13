use ab_i_04_tovabbigyak;

/*
 List�zza ki azoknak a nem budapesti ingatlanoknak a helys�gnev�t, szobasz�m�t, �r�t �s a
k�pvisel� �gyn�k nev�t, amelyek gar�zzsal rendelkeznek vagy H�zr�sz t�pus�ak! A list�t rendezze �r
szerint cs�kken� sorrendbe!
*/
select
	helyseg,
	szobaszam,
	ar,
	ugynok_nev
from ingatlanok
inner join tipusok on tipus_ID = fk_tipusID
inner join ugynokok on ugynok_ID = fk_ugynokID
where (garazs = 1 or tipus_nev = 'H�zr�sz')
and helyseg not in ('Budapest')
order by ar;

/*
Jelen�tse azoknak az �gyn�k�knek a nev�t �s telefonsz�m�t, akikhez nem kapcsol�dik ingatlan!
*/

select
	--ingatlan_ID,
	ugynok_nev,
	telefon
from ugynokok
left join ingatlanok on ugynok_ID = fk_ugynokID
where ingatlan_ID is null;


/*V�rosonk�nt (helys�genk�nt) sz�ml�lja meg, h�ny olyan ingatlan van, amelynek �ra 10 �s 14
milli� Ft k�z�tt van! A lista a megsz�ml�lt �rt�k szerint cs�kken� sorrendben jelenjen meg!*/

select
 helyseg,
 count(*) as ingatlan_szama
from ingatlanok
where ar between 10 and 14
group by helyseg
order by ingatlan_szama;

/* List�zza ki �tlag�r szerinti sorrendben azoknak az ingatlant�pusoknak a nev�t �s az adott
t�pushoz tartoz� ingatlanok �tlagos �r�t, amelyeknek �tlag�ra 17.5 MFt-n�l kisebb!*/

select
	tipus_nev,
	avg(ar) as atlag_ar
from ingatlanok
inner join tipusok on tipus_ID = fk_tipusID
group by tipus_nev
having avg(ar) < 17.5
order by atlag_ar;

/*List�zza ki minden v�rosb�l a legdr�g�bb ingatlan helys�gnev�t �s �r�t! A list�ban csak az
els� 20 tal�lat legyen l�that�!*/

select
	helyseg,
	max(ar) as legdragabb
from ingatlanok
group by helyseg
limit 20;

/* K�sz�tsen megyek n�ven egy olyan t�bl�t, amelynek h�rom mez�je van: (1) a megye_ID mez�
legyen automatikus sz�moz�s�, INT t�pus� els�dleges kulcs; (2) a megye_nev legfeljebb 30 karakteres
sz�vegeket megenged� mez�; (3) az indul_datum legyen d�tum t�pus�! A l�trehoz�shoz sz�ks�ges
SQL-parancsot vagy a t�bla szerkezeti n�zet�nek k�perny�k�p�t mentse a word-dokumentumba!*/

create table megyek (
	megye_id	int	auto_increment primary key,
	megye_nev	varchar(30),
	indul_datum	date
);


/*: B�v�tse az ingatlanok t�bl�t olyan fk_megyeID nev�, INT t�pus� �j mez�vel, amelybe csak
olyan idegenkulcs-�rt�k besz�rhat�, amely a megyek t�bl�ban m�r szerepel kulcs�rt�kk�nt! A
l�trehoz�shoz haszn�lt SQL-parancso(ka)t mentse a word-dokumentumba!*/

alter table ingatlanok
add column fk_megye_id int;

ALTER TABLE ingatlanok
add CONSTRAINT foreign key (fk_megye_id) references megyek(megye_id);

/*K�sz�tsen t�rl� lek�rdez�st, amellyel t�r�lheti az ingatlanok t�bl�b�l azokat az ingatlanokat,
amelyek 1.000.000 Ft-n�l olcs�bbak vagy Ajk�n tal�lhat�ak! A t�rl� parancsot mentse a worddokumentumba*/

delete from ingatlanok
where ar < 1 or helyseg = 'Ajka';

select * from ingatlanok