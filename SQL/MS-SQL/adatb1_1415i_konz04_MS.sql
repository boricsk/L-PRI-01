
-- Converted from MySQL dump to Microsoft SQL Server T-SQL (compatible with SQL Server 2019/2022)
-- Database: adatb1_1415i_konz04
-- Conversion notes:
--  - MySQL AUTO_INCREMENT columns are created as IDENTITY.
--  - To preserve original numeric keys the script uses SET IDENTITY_INSERT ON when inserting explicit IDs.
--  - Collation set to Hungarian_CI_AS and NVARCHAR used for text to preserve accents.
--  - Foreign keys are added after data insertion to avoid ordering issues.
--  - This script recreates all data from the provided MySQL dump.

IF NOT EXISTS (SELECT name FROM sys.databases WHERE name = N'adatb1_1415i_konz04')
BEGIN
    CREATE DATABASE adatb1_1415i_konz04 COLLATE Hungarian_CI_AS;
END
GO

USE adatb1_1415i_konz04;
GO

-- Drop tables if they exist (to allow reruns)
IF OBJECT_ID('dbo.szamlakreszletei', 'U') IS NOT NULL DROP TABLE dbo.szamlakreszletei;
IF OBJECT_ID('dbo.szamlak', 'U') IS NOT NULL DROP TABLE dbo.szamlak;
IF OBJECT_ID('dbo.vevok', 'U') IS NOT NULL DROP TABLE dbo.vevok;
IF OBJECT_ID('dbo.telepulesek', 'U') IS NOT NULL DROP TABLE dbo.telepulesek;
IF OBJECT_ID('dbo.aruk', 'U') IS NOT NULL DROP TABLE dbo.aruk;
IF OBJECT_ID('dbo.kategoriak', 'U') IS NOT NULL DROP TABLE dbo.kategoriak;
GO

-- Create tables (IDENTITY for auto-increment columns)
CREATE TABLE kategoriak (
    kategoria_kod INT IDENTITY(1,1) PRIMARY KEY,
    kategoria_nev NVARCHAR(30) COLLATE Hungarian_CI_AS NOT NULL
);
GO

CREATE TABLE aruk (
    aru_kod INT IDENTITY(1,1) PRIMARY KEY,
    aru_nev NVARCHAR(30) COLLATE Hungarian_CI_AS NOT NULL,
    aru_egysegar INT NOT NULL,
    aru_kategoriakod INT NOT NULL
);
GO

CREATE TABLE telepulesek (
    irsz NVARCHAR(4) COLLATE Hungarian_CI_AS PRIMARY KEY,
    helyseg NVARCHAR(50) COLLATE Hungarian_CI_AS NOT NULL
);
GO

CREATE TABLE vevok (
    vevo_kod INT IDENTITY(1,1) PRIMARY KEY,
    vevo_nev NVARCHAR(30) COLLATE Hungarian_CI_AS NOT NULL,
    vevo_irsz NVARCHAR(4) COLLATE Hungarian_CI_AS NOT NULL,
    vevo_cim NVARCHAR(30) COLLATE Hungarian_CI_AS NOT NULL
);
GO

CREATE TABLE szamlak (
    szamla_szam INT IDENTITY(1,1) PRIMARY KEY,
    szamla_vevokod INT NOT NULL,
    szamla_datum DATE NOT NULL
);
GO

CREATE TABLE szamlakreszletei (
    szr_szamlaszam INT NOT NULL,
    szr_arukod INT NOT NULL,
    szr_vasaroltmennyiseg INT NOT NULL,
    CONSTRAINT PK_szamlakreszletei PRIMARY KEY (szr_szamlaszam, szr_arukod)
);
GO

-- Insert data preserving original IDs using IDENTITY_INSERT
-- kategoriak
SET IDENTITY_INSERT kategoriak ON;
INSERT INTO kategoriak (kategoria_kod, kategoria_nev) VALUES
(1, N'Műszaki'),
(2, N'Sportfelszerelés'),
(3, N'Játék'),
(4, N'Számítástechnika'),
(5, N'Barkács'),
(6, N'Könyv'),
(7, N'Konyhafelszerelés');
SET IDENTITY_INSERT kategoriak OFF;
GO
DBCC CHECKIDENT ('kategoriak', RESEED, 7);
GO

-- aruk
SET IDENTITY_INSERT aruk ON;
INSERT INTO aruk (aru_kod, aru_nev, aru_egysegar, aru_kategoriakod) VALUES
(1, N'Video magnó', 32000, 1),
(2, N'Ping-pong ütő', 4200, 2),
(3, N'Rádió', 36000, 1),
(4, N'Ping-pong labda', 400, 2),
(5, N'Televízió', 42000, 1),
(6, N'Televízió', 76000, 1),
(7, N'Hi-fi torony', 112000, 1),
(8, N'Izzó 40W', 200, 1),
(9, N'Izzó 60W', 240, 1),
(10, N'Izzó 11W', 1100, 1),
(11, N'DVD-lejátszó', 88000, 1),
(12, N'Pool asztal', 96000, 2),
(13, N'Térdvédő', 3000, 2),
(14, N'Kézisúlyzó', 4000, 2),
(15, N'Activity', 4400, 3),
(16, N'Labirintus', 3600, 3),
(17, N'Magyar kártya', 840, 3),
(18, N'LEGO 6123', 15600, 3),
(19, N'LEGO 3411', 6200, 3),
(20, N'Egér', 1200, 4),
(21, N'Opt. egér', 4800, 4),
(22, N'Billentyűzet', 2800, 4),
(23, N'HDD 80GB', 22000, 4),
(24, N'Fali konzol', 400, 5),
(25, N'Dübelkészlet', 800, 5),
(26, N'Kétoldali ragasztócsík', 2500, 5),
(27, N'Fúrógép', 8800, 5),
(28, N'Csavarhúzókészlet', 4100, 5),
(29, N'Heller, J.: A 22-es csapdája', 1200, 6),
(30, N'Asimov, A.: Alapítvány', 2900, 6),
(31, N'Bócz P., Szász P.: A világháló', 2998, 6),
(32, N'Cantú, M.: Delphi 3 mester...', 6600, 6),
(33, N'Asztali lámpa', 3100, 1),
(34, N'Scrabble', 5500, 3),
(35, N'Safari', 2880, 3),
(36, N'Szelezsán J.: Adatbázisok', 2200, 6),
(37, N'Csavarkészlet', 2000, 5),
(38, N'Teniszütő', 14000, 2),
(39, N'Sátor', 4700, 2),
(40, N'Monitor TFT', 99900, 4),
(41, N'Nyomtató HP 920C', 27000, 4),
(42, N'Edénykészlet rozsdamentes', 13000, 7),
(43, N'Konzervnyitó', 2600, 7);
SET IDENTITY_INSERT aruk OFF;
GO
DBCC CHECKIDENT ('aruk', RESEED, 43);
GO

-- telepulesek (irsz is primary key, no identity)
INSERT INTO telepulesek (irsz, helyseg) VALUES
(N'2700', N'Cegléd'),
(N'2750', N'Nagykőrös'),
(N'3100', N'Salgótarján'),
(N'3200', N'Eger'),
(N'5000', N'Szolnok'),
(N'6000', N'Kecskemét'),
(N'6001', N'Kecskemét'),
(N'6100', N'Kiskunfélegyháza'),
(N'6400', N'Kiskunhalas');
GO

-- vevok
SET IDENTITY_INSERT vevok ON;
INSERT INTO vevok (vevo_kod, vevo_nev, vevo_irsz, vevo_cim) VALUES
(1, N'Flaxtor Bt.', N'6000', N'Kis u. 2.'),
(2, N'Neptun Rt.', N'6000', N'Nagy u. 5.'),
(3, N'Kovács Péter', N'6001', N'Pf.: 126'),
(4, N'Horváth és Fia', N'6100', N'Kerekes u. 12.'),
(5, N'Norvégminta Bt.', N'6100', N'Halasi út 50.'),
(6, N'Kiss Ádám', N'6000', N'Nap u. 20.'),
(7, N'GépElem Kft.', N'6400', N'Kő u. 13.'),
(8, N'Németh Lajos', N'3100', N'Platán u. 13.'),
(9, N'Huszáros Bt.', N'3100', N'Káva u. 21.'),
(10, N'SzGTe Bt.', N'6000', N'Kígyó u. 5.'),
(11, N'Laczkó János', N'6100', N'Eper u. 12.'),
(12, N'MaMarJo Bt.', N'6000', N'Cipó u. 45.'),
(13, N'Flaisz Péter', N'6400', N'Jég u. 22.'),
(14, N'Danyi és Társa Bt.', N'5000', N'Tégla u. 20.'),
(15, N'Németh Lajos', N'6100', N'Szegedi út 16.'),
(16, N'Lajos Norbert', N'6000', N'Fagy u. 10.'),
(17, N'Nemes József', N'6400', N'Hamar u. 43.'),
(18, N'Török Basa Bt.', N'3200', N'Vár u. 11.'),
(19, N'Fundella Rt.', N'6000', N'Kőrösi u. 15.'),
(20, N'Kiss És Nagy Bt.', N'3100', N'Üveg u. 11.'),
(21, N'Jópaál Kristóf', N'5000', N'Sas u. 38.'),
(22, N'Huszár Péter', N'6100', N'Ibolya u. 5.'),
(23, N'Csillag Bt.', N'3200', N'Vár u. 28.'),
(24, N'Kovácsoló Rt.', N'6400', N'Vadkerti út 1.'),
(25, N'Hukker Bt.', N'6000', N'Kasza u. 3.');
SET IDENTITY_INSERT vevok OFF;
GO
DBCC CHECKIDENT ('vevok', RESEED, 25);
GO

-- szamlak
SET IDENTITY_INSERT szamlak ON;
INSERT INTO szamlak (szamla_szam, szamla_vevokod, szamla_datum) VALUES
(1, 5, '2012-02-11'),
(2, 7, '2012-02-14'),
(3, 10, '2012-02-15'),
(4, 5, '2012-02-18'),
(5, 6, '2012-02-20'),
(6, 2, '2012-02-20'),
(7, 1, '2012-02-21'),
(8, 3, '2012-02-22'),
(9, 5, '2012-02-22'),
(10, 4, '2012-02-22'),
(11, 7, '2012-02-23'),
(12, 14, '2012-02-24'),
(13, 16, '2012-02-24'),
(14, 10, '2012-02-24'),
(15, 12, '2012-02-24'),
(16, 5, '2012-02-24'),
(17, 8, '2012-02-25'),
(18, 9, '2012-02-25'),
(19, 1, '2012-02-28'),
(20, 3, '2012-02-28'),
(21, 5, '2012-02-28'),
(22, 8, '2012-03-01'),
(23, 13, '2012-03-01'),
(24, 14, '2012-03-01'),
(25, 15, '2012-03-01'),
(26, 11, '2012-03-01'),
(27, 2, '2012-03-01'),
(28, 20, '2012-03-02'),
(29, 23, '2012-03-02'),
(30, 22, '2012-03-02'),
(31, 9, '2012-03-02'),
(32, 19, '2012-03-03'),
(33, 21, '2012-03-03'),
(34, 22, '2012-03-03'),
(35, 24, '2012-03-03'),
(36, 25, '2012-03-04'),
(37, 2, '2012-03-04'),
(38, 4, '2012-03-04'),
(39, 5, '2012-03-04'),
(40, 10, '2012-03-04'),
(41, 11, '2012-03-05'),
(42, 14, '2012-03-05'),
(43, 13, '2012-03-05'),
(44, 12, '2012-03-06'),
(45, 10, '2012-03-06'),
(46, 15, '2012-03-06'),
(47, 16, '2012-03-06'),
(48, 19, '2012-03-06'),
(49, 25, '2012-03-06'),
(50, 17, '2012-03-07'),
(51, 18, '2012-03-07');
SET IDENTITY_INSERT szamlak OFF;
GO
DBCC CHECKIDENT ('szamlak', RESEED, 51);
GO

-- szamlakreszletei
INSERT INTO szamlakreszletei (szr_szamlaszam, szr_arukod, szr_vasaroltmennyiseg) VALUES
(1, 10, 5),
(1, 13, 1),
(2, 1, 1),
(2, 3, 1),
(3, 20, 10),
(3, 21, 4),
(3, 22, 15),
(3, 40, 1),
(3, 41, 1),
(4, 1, 1),
(4, 14, 2),
(4, 18, 1),
(4, 30, 1),
(5, 7, 1),
(6, 8, 10),
(6, 9, 12),
(6, 25, 1),
(6, 27, 1),
(6, 37, 2),
(7, 12, 1),
(7, 26, 4),
(7, 28, 1),
(8, 41, 1),
(9, 16, 1),
(9, 26, 2),
(10, 11, 1),
(10, 15, 1),
(10, 19, 2),
(11, 8, 5),
(11, 9, 5),
(11, 15, 4),
(11, 20, 1),
(11, 29, 1),
(11, 30, 1),
(12, 7, 1),
(13, 17, 1),
(14, 16, 2),
(14, 34, 3),
(14, 35, 5),
(15, 29, 1),
(15, 30, 1),
(15, 32, 1),
(16, 6, 1),
(16, 33, 3),
(17, 3, 1),
(18, 2, 2),
(18, 4, 5),
(19, 5, 1),
(20, 21, 1),
(20, 23, 1),
(20, 32, 1),
(21, 17, 1),
(22, 6, 1),
(22, 10, 3),
(23, 8, 10),
(24, 25, 2),
(24, 37, 2),
(25, 11, 1),
(26, 40, 1),
(27, 20, 2),
(27, 22, 2),
(27, 40, 1),
(28, 8, 2),
(29, 24, 10),
(29, 27, 1),
(29, 28, 1),
(29, 37, 2),
(30, 6, 1),
(31, 12, 1),
(32, 12, 1),
(33, 4, 10),
(34, 13, 1),
(34, 34, 1),
(34, 38, 1),
(34, 39, 1),
(35, 16, 1),
(35, 17, 1),
(35, 34, 1),
(36, 5, 1),
(37, 31, 1),
(37, 32, 1),
(37, 33, 1),
(38, 24, 8),
(38, 28, 1),
(38, 37, 1),
(39, 10, 3),
(39, 21, 2),
(40, 27, 1),
(41, 21, 1),
(41, 23, 1),
(42, 18, 2),
(42, 19, 1),
(43, 5, 1),
(43, 14, 1),
(44, 2, 2),
(44, 4, 4),
(44, 13, 1),
(45, 17, 5),
(45, 35, 3),
(46, 20, 1),
(46, 22, 1),
(47, 32, 1),
(47, 36, 2),
(48, 2, 4),
(48, 15, 1),
(49, 33, 1),
(50, 3, 1),
(50, 5, 1),
(51, 8, 5),
(51, 9, 10),
(51, 10, 5);
GO

-- Add foreign key constraints to mirror original structure
ALTER TABLE aruk
    ADD CONSTRAINT FK_aruk_kategoriak FOREIGN KEY (aru_kategoriakod) REFERENCES kategoriak(kategoria_kod);
GO

ALTER TABLE vevok
    ADD CONSTRAINT FK_vevok_telepulesek FOREIGN KEY (vevo_irsz) REFERENCES telepulesek(irsz);
GO

ALTER TABLE szamlak
    ADD CONSTRAINT FK_szamlak_vevok FOREIGN KEY (szamla_vevokod) REFERENCES vevok(vevo_kod);
GO

ALTER TABLE szamlakreszletei
    ADD CONSTRAINT FK_szr_szamlaszam_szamlak FOREIGN KEY (szr_szamlaszam) REFERENCES szamlak(szamla_szam)    
GO

ALTER TABLE szamlakreszletei
    ADD CONSTRAINT FK_szr_arukod_aruk FOREIGN KEY (szr_arukod) REFERENCES aruk(aru_kod);
GO
-- End of script
