create database db1;
use db1;

create table proba (
	id		int	primary key not null,
	nev		varchar(40) not null
);

insert into proba values
	(1, 'Kiss Péter'),
	(2, 'Nagy János');

insert into proba values
	(4, 'Nagy Sára'),
	(5, 'Huszár Tibor');

select * from db1.proba

drop table proba;

create table osztaly (
	osztalykod varchar(3) primary key,
	osztalynev varchar(20),
	vezadoszam decimal(10)
) engine = 'InnoDB'

create table dolgozo (
	adoszam	decimal(10) primary key,
	nev varchar(30),
	lakcim varchar (40) default 'Ismeretlen',
	osztalykod char(3),
	foreign key (osztalykod) references osztaly(osztalykod)
) engine = 'InnoDb'

insert into osztaly values
('ADO', 'Adóügy', 1234567),
('MUN', 'Munkaügy', 2143657);

insert into dolgozo values 
(3216547, 'Kiss Péter','','RAK');
--hiba, mert a RAK nem létezik az osztályok között

select * from osztaly;

insert into dolgozo values 
(3216547,'Kiss Péter', '', 'MUN'),
(4321765, 'Nagy Ágnes', '', 'ADO'),
(5432176, 'Horváth Éva', default, 'MUN'),
(6543217, 'Tóth Gábor', null, 'ADO');

select * from dolgozo;

--szintaktikailag jó, de nem törölhető mert sérti az idegenkulcs definiciót
delete from osztaly where osztalykod='MUN';
update osztaly set osztalykod='MNK' where osztalykod='MUN';

--Táblaszerk. módosítása
alter table dolgozo drop foreign key dolgozo_ibfk_1;
alter table dolgozo add foreign key (osztalykod) references osztaly(osztalykod) on update cascade;

update osztaly set osztalykod='MNK' where osztalykod='MUN';

select * from dolgozo;

/*
 * A két tábla összekapcsolása után készítsen adószám szerint csökkenő sorrendbe rendezett listát 
a Munkaügyi osztály dolgozóiról (ne az osztály kódja, hanem a neve alapján szűrjön)! A listában az 
adószám, a dolgozó neve, az osztály neve és a lakcím látsszon!
 */
select adoszam, nev, osztalynev, lakcim
from osztaly
inner join dolgozo on osztaly.osztalykod = dolgozo.osztalykod
where osztalynev='Munkaügy'
order by adoszam desc

/*
 * A két tábla összekapcsolása után készítsen az osztály neve szerint növekvő, azon belül név 
szerint csökkenő sorrendbe rendezett listát azokról, akiknek a neve N betűvel kezdődik vagy az 
adószáma nagyobb, mint 5000000 vagy definiálatlan a lakcíme! A listában az adószám, a dolgozó 
neve, az osztály neve és a lakcím látsszon!
*/

select 
	adoszam,
	nev,
	osztalynev,
	lakcim
from dolgozo
inner join osztaly on osztaly.osztalykod=dolgozo.osztalykod
where nev like 'N%' or adoszam > 5000000 or lakcim is NULL
