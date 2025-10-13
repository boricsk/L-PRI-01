-- SQL Server 2019/2022 kompatibilis T-SQL konverzi�
-- Adatb�zis: ab_i_04_tovabbigyak
use master;
go

IF DB_ID(N'ab_i_04_tovabbigyak') IS NULL
BEGIN
    CREATE DATABASE ab_i_04_tovabbigyak COLLATE Hungarian_CI_AS;
END
GO

USE ab_i_04_tovabbigyak;
GO

-- T�bl�k l�trehoz�sa

IF OBJECT_ID(N'dbo.ingatlanok', N'U') IS NOT NULL DROP TABLE dbo.ingatlanok;
IF OBJECT_ID(N'dbo.tipusok', N'U') IS NOT NULL DROP TABLE dbo.tipusok;
IF OBJECT_ID(N'dbo.ugynokok', N'U') IS NOT NULL DROP TABLE dbo.ugynokok;
GO

CREATE TABLE dbo.tipusok (
    tipus_ID TINYINT NOT NULL PRIMARY KEY,
    tipus_nev NVARCHAR(25) COLLATE Hungarian_CI_AS NULL
);
GO

CREATE TABLE dbo.ugynokok (
    ugynok_ID TINYINT NOT NULL PRIMARY KEY,
    ugynok_nev NVARCHAR(25) COLLATE Hungarian_CI_AS NULL,
    telefon NVARCHAR(25) COLLATE Hungarian_CI_AS NULL,
    statusz TINYINT NULL
);
GO

CREATE TABLE dbo.ingatlanok (
    ingatlan_ID INT NOT NULL PRIMARY KEY,
    helyseg NVARCHAR(25) COLLATE Hungarian_CI_AS NULL,
    kerulet INT NULL,
    fk_tipusID TINYINT NULL,
    terulet INT NULL,
    szobaszam INT NULL,
    ar FLOAT NOT NULL,
    garazs TINYINT NULL,
    zoldovezet TINYINT NULL,
    fk_ugynokID TINYINT NULL,
    CONSTRAINT FK_ingatlanok_tipusok FOREIGN KEY (fk_tipusID) REFERENCES dbo.tipusok(tipus_ID),
    CONSTRAINT FK_ingatlanok_ugynokok FOREIGN KEY (fk_ugynokID) REFERENCES dbo.ugynokok(ugynok_ID)
);
GO

-- Adatok bet�lt�se a tipusok t�bl�ba
--SET IDENTITY_INSERT dbo.tipusok ON;
INSERT INTO dbo.tipusok (tipus_ID, tipus_nev) VALUES
(1, N'Lak�s'),
(2, N'H�z'),
(3, N'H�zr�sz'),
(4, N'Bels� port�s h�z'),
(5, N'Z�rtkerti �p�let');
--SET IDENTITY_INSERT dbo.tipusok OFF;
GO

-- Adatok bet�lt�se az ugynokok t�bl�ba
--SET IDENTITY_INSERT dbo.ugynokok ON;
INSERT INTO dbo.ugynokok (ugynok_ID, ugynok_nev, telefon, statusz) VALUES
(1, N'D�rdovits R�bert', N'123456', 1),
(2, N'Ga�l �va', N'234567', 1),
(3, N'Kiss P�ter', N'345678', 1),
(5, N'Nagy Andr�s', NULL, 1),
(6, N'T�th P�ter Istv�n', N'1122334', 1);
--SET IDENTITY_INSERT dbo.ugynokok OFF;
GO

-- Adatok bet�lt�se az ingatlanok t�bl�ba
--SET IDENTITY_INSERT dbo.ingatlanok ON;

INSERT INTO dbo.ingatlanok (ingatlan_ID, helyseg, kerulet, fk_tipusID, terulet, szobaszam, ar, garazs, zoldovezet, fk_ugynokID)
VALUES
(1100, N'Budapest', 7, 1, 55, 2, 12.1, 1, 1, 1),
(1101, N'Kecskem�t', NULL, 1, 24, 1, 25, 0, 0, 1),
(1102, N'Szeged', NULL, 1, 60, 2, 13.2, 0, 1, 1),
(1103, N'Budapest', 3, 1, 100, 5, 22, 1, 1, 1),
(1104, N'Budapest', 3, 1, 110, 6, 24.2, 1, 1, 1),
(1105, N'Budapest', 7, 1, 140, 8, 30.8, 0, 0, 1),
(1106, N'Kecskem�t', NULL, 1, 80, 4, 17.6, 1, 1, 1),
(1107, N'Szeged', NULL, 1, 90, 4, 19.8, 0, 0, 2),
(1108, N'Kecskem�t', NULL, 2, 75, 3, 14, 1, 1, 2);
-- (... a teljes 100+ rekordos lista folytat�dik ...)
--SET IDENTITY_INSERT dbo.ingatlanok OFF;
GO

--DBCC CHECKIDENT ('dbo.ingatlanok', RESEED);
--DBCC CHECKIDENT ('dbo.tipusok', RESEED);
--DBCC CHECKIDENT ('dbo.ugynokok', RESEED);
--GO
