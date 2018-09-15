# Sinteza, merenje, predikcija

Projekat u okviru kursa Verifikacija softvera, Matematički fakultet, školska godina 2017/18.

Tema projekta je automatsko generisanje funkcionalno ekvivalentnih funkcija i ispitivanje vremenskog ograničenja CBMC-a (alat za verifikaciju softvera). Na osnovu izmerenog vremena izvršavanja, određuju se vremenski zahtevi za slične verifikacijske probleme. Detaljnije o korišćenim algoritmima i dobijenim rezultatima može se pročitati u fajlu SystemDescription.

##  mehanizma za raznovrsno generisanje funkcionalno ekvivalentnih funkcija
	
    Zahtevi:
        - python (kompatibilno sa python3)

    Način automatskog generisanja funkcionalno ekvivalentnih funkcija:
        - Ubaciti odgovarajući c program u direktorijum "test code"
        - Pokrenuti python skriptu test.py (skripta generiše funkcionalno ekvivalentne funkcije u okviru direktorijuma function_equivalent_code)
		- primer pokretanja:
            cp 1.c ./test\ code/
            python3 tests.py

    Dostupni primeri:
        - Svi u okviru direktorijuma "test code"

## automatska provera ekvivalentnosti generisanih funkcija i merenje potrebnog vremena

    Zahtevi:
        - python (kompatibilno sa python3)
        - CBMC 5.3

    Način pokretanja:
        - python3 measure_test.py

    Zahtevi:
        - Ulaz (direktorijum function_equivalent_code)
            c program koji želimo da testiramo sa odgovarajućim CBMC komandama
        - Izlaz (direktorijum result)
            .csv fajl sa potrebnim informacijama za predikciju
			
    Dostupni primeri:
        - Svi u okviru direktorijuma function_equivalent_code

##  uočavanje zavisnosti na osnovu izmerenih rezultata

    Zahtevi:
        - python (kompatibilno sa python3)
        - Jupyter Notebook

    Način pokretanja:
        - Otvoriti iz Jupyter menija, pokrenuti sve ćelije put Run komade

    Zahtevi:
        - Ulaz (function_time.csv datoteka)
            .csv fajl sa potrebnim informacijama za predikciju 
        - Izlaz (Ispis željenih podataka, slika boksplota)
            Ispisuje dobijene regresione koeficijente 
    
