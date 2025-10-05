SELECT diak.nev
FROM diak,
(SELECT d.id, Count(*) AS letszam FROM diak AS d, diak AS d2
	WHERE d.szuldatum ??? d2.szuldatum GROUP BY d.id) ???,
(SELECT d.id, Count(*) ??? FROM diak AS d, diak AS d2
	WHERE d.szuldatum>d2.szuldatum GROUP BY d.id) AS elotte
WHERE diak.id=utana.id 
AND diak.id=elotte.id 
AND elotte.letszam ??? utana.???
