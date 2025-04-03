#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_N = 10;
const int MAX_M = 10;

void rysuj_gore()
{
	char ho1 = 0xCD;
	char ho2 = 0xCB;
	char ho3 = 0xC9;
	char ho4 = 0xBB;
	char lewy = 0xBB;
	char prawy = 0xC9;

	cout << endl << " " << ho3 << ho1 << ho1 << ho1 << ho1 << ho1 << ho2 << ho1 << ho1 << ho1 << ho1 << ho1 << ho2
		<< ho1 << ho1 << ho1 << ho1 << ho1 << lewy << " " << prawy << ho1 << ho1 << ho1 << ho1 << ho1 << ho2 << ho1 << ho1 << ho1 << ho1 << ho1 << ho2
		<< ho1 << ho1 << ho1 << ho1 << ho1 << ho4 << endl;
}

void rysuj_dol()
{
	char ho1 = 0xCD;
	char ho2 = 0xCA;
	char do3 = 0xC8;
	char do4 = 0xBC;
	char prawy = 0xBC;
	char lewy = 0xC8;

	cout << endl << " " << do3 << ho1 << ho1 << ho1 << ho1 << ho1 << ho2 << ho1 << ho1 << ho1 << ho1 << ho1 << ho2
		<< ho1 << ho1 << ho1 << ho1 << ho1 << prawy << " " << lewy << ho1 << ho1 << ho1 << ho1 << ho1 << ho2 << ho1 << ho1 << ho1 << ho1 << ho1 << ho2
		<< ho1 << ho1 << ho1 << ho1 << ho1 << do4 << endl;
}

void rysuj_srodek()
{
	char lew = 0xCC;
	char sr_sk = 0xCE;
	char do_h = 0xCD;
	char pra = 0xB9;
	char dou_ver_lew = 0xB9;
	char dou_ver_praw = 0xCC;

	cout << endl << " " << lew << do_h << do_h << do_h << do_h << do_h << sr_sk << do_h << do_h << do_h << do_h << do_h
		<< sr_sk << do_h << do_h << do_h << do_h << do_h << dou_ver_lew << " " << dou_ver_praw << do_h << do_h << do_h << do_h << do_h
		<< sr_sk << do_h << do_h << do_h << do_h << do_h << sr_sk << do_h << do_h << do_h << do_h << do_h << pra << endl;

}

void rysuj_srodek_bez_endl_dol()
{
	char lew = 0xC9;
	char sr_sk = 0xCE;
	char do_h = 0xCD;
	char pra = 0xBB;
	char poziom = 0xCB;

	cout << " " << lew << do_h << do_h << do_h << do_h << do_h << poziom << do_h << do_h << do_h << do_h << do_h
		<< poziom << do_h << do_h << do_h << do_h << do_h << pra << " " << lew << do_h << do_h << do_h << do_h << do_h
		<< poziom << do_h << do_h << do_h << do_h << do_h << poziom << do_h << do_h << do_h << do_h << do_h << pra << endl;

}

void rysuj_srodek_bez_endl_gora()
{
	char lew = 0xC8;
	char sr_sk = 0xCE;
	char do_h = 0xCD;
	char pra = 0xBC;
	char poziom = 0xCA;

	cout << endl << " " << lew << do_h << do_h << do_h << do_h << do_h << poziom << do_h << do_h << do_h << do_h << do_h
		<< poziom << do_h << do_h << do_h << do_h << do_h << pra << " " << lew << do_h << do_h << do_h << do_h << do_h
		<< poziom << do_h << do_h << do_h << do_h << do_h << poziom << do_h << do_h << do_h << do_h << do_h << pra << endl;

}

void rysuj_plansze(char tab[][MAX_M])
{
	char pion = 0xBA;
	rysuj_gore();
	for (int i = 1; i <= 6; i++)
	{
		cout << " ";
		for (int j = 1; j <= 6; j++)
		{
			if (j == 4)
			{
				tab[i][j] = ' ';
				cout << pion << " " << pion << "  " << tab[i][j] << "  ";
			}
			else
			{
				tab[i][j] = ' ';
				cout << pion << "  " << tab[i][j] << "  ";
			}
			if (i == 6 && j == 6)
			{
				cout << pion;
			}
			if (j == 6 && i != 6 && i != 3)
			{
				cout << pion;
				rysuj_srodek();
			}
			if (i == 3 && j == 6)
			{
				cout << pion;
			}
		}
		if (i == 3)
		{
			rysuj_srodek_bez_endl_gora();
			rysuj_srodek_bez_endl_dol();
		}
		if (i == 6)
		{
			rysuj_dol();
		}
	}
}

bool wygrana(char tab[][MAX_M], char g)
{

	for (int i = 1; i <= 6; i++)														// Sprawdzanie czy w poziomie po wierszach nie wystepuje 5 razy z rzedu znak g
	{
		for (int j = 1; j <= 2; j++)
		{
			if (tab[i][j] == tab[i][j + 1] == tab[i][j + 2] == tab[i][j + 3] == tab[i][j + 4] == g)
			{
				return true;
			}
		}
	}

	for (int i = 1; i <= 2; i++)														// Sprawdzanie czy w pionie po kolumnach nie wystepuje 5 razy z rzedu znak g
	{
		for (int j = 1; j <= 6; j++)
		{
			if (tab[i][j] == tab[i + 1][j] == tab[i + 2][j] == tab[i + 3][j] == tab[i + 4][j] == g)
			{
				return true;
			}
		}
	}

	for (int i = 1; i <= 2; i++)														// Sprawdzanie po glownej lewej przekatnej i 2 bocznych przylegajacych jego przeatnych
	{																					// czy nie wystapilo 5 razy z rzedu znak g
		for (int j = 1; j <= 2; j++)
		{
			if (tab[i][j] == tab[i + 1][j + 1] == tab[i + 2][j + 2] == tab[i + 3][j + 3] == tab[i + 4][j + 4] == g)
			{
				return true;
			}
		}
	}

	for (int i = 1; i <= 2; i++)														// Sprawdzanie po glownej prawej przekatnej i 2 bocznych przylegajacych jego przeatnych
	{																					// czy nie wystapilo 5 razy z rzedu znak g
		for (int j = 5; j <= 6; j++)
		{
			if (tab[i][j] == tab[i + 1][j - 1] == tab[i + 2][j - 2] == tab[i + 3][j - 3] == tab[i + 4][j - 4] == g)
			{
				return true;
			}
		}
	}

	if (true)
	{
		rysuj_plansze(tab);
		cout << "\nGRACZ: " << g << " WYGRYWA!!!\n";
	}

	return false;
}

bool remis(char tab[][MAX_M])														// sprawdz czy remis,
{
	for (int i = 1; i <= 6; i++)													
	{																				// jezeli ktores z miejsc jest puste to zwroc false, tzn ze  tablica nie jest jeszcze cala uzupelniona
		for (int j = 1; j <= 6; j++)												// i hipotetycznie moze ktos jeszcze wygrac mimo niskiego prawdopodobienstwa
		{
			if (tab[i][j] == ' ')
				return false;
		}
	}
	rysuj_plansze(tab);																// w przeciwnym wypadku ( jezeli nie jest false ) zwroc i wyswietl uzytkownikowi plansze oraz napis remis
	cout << "\nREMIS !!!\n";															
	return true;
}

void ruch_gracza(char tab[][MAX_M], char& gracz)
{
	char czesc_planszy;
	int numer_pola;
	int i, j;

	rysuj_plansze(tab);
	cout << "\nGRACZ " << gracz << " : TWOJ RUCH : \n";
	cout << "Wybierz czesc planszy: q, w, a, s \n";
	cin >> czesc_planszy;
	cout << "Wybierz numer pola: ( 1 - 9 ) \n";
	cin >> numer_pola;

	for (int i = 1; i <= 3; i++)
	{
		for ( int j=1; j<=3; j++)
		{
			tab[i][j] = gracz;
			}
	}
		
			

	switch (numer_pola)
	{
		case '1':
			{
				i = 3;
				j = 1;
			break;
			}
		case '2':
			{
				i = 3;
				j = 2;
			break;
			}
		case '3':
			{
				i = 3;
				j = 3;
			break;
			}
		case '4':
			{
				i = 2;
				j = 1;
			break;
			}
		case '5':
			{
				i = 2;
				j = 2;
			break;
			}
		case '6':
			{
				i = 2;
				j = 3;
			break;
			}
		case '7':
			{
				i = 1;
				j = 1;
			break;
			}
		case '8':
			{
				i = 1;
				j = 2;
			break;
			}
		case '9':
			{
				i = 1;
				j = 3;
			break;
			}
	}
	switch (czesc_planszy)
	{
		case 'w':
			{
				j += 3;
			break;
			}
		case 'a':
			{
				i += 3;
			break;
			}
		case 's':
			{
				i += 3;
				j += 3;
			break;
			}
	}

	if ((numer_pola >= 1) && (numer_pola <= 9) && ((czesc_planszy == 'q') || (czesc_planszy == 'w') || (czesc_planszy == 'a') || (czesc_planszy == 's')) && (tab[i][j] == ' '))
	{								 
		tab[czesc_planszy + numer_pola][czesc_planszy + numer_pola] = gracz;

		gracz = (gracz == 'O') ? 'X' : 'O';




	}
	else if ((numer_pola < 1) && (numer_pola > 9) && ((czesc_planszy != 'q') || (czesc_planszy != 'w') || (czesc_planszy != 'a') || (czesc_planszy != 's')) && (tab[i][j] != ' '))
	{
		cout << "To miejsce jest zajete badz zle wybrane !!! \n";
		cout << "Sprobuj ponownie !! \n";
	}
}
void wczytaj_gracza()
{
	string gracz1;
	string gracz2;

	cout << endl;
	cout << "Prosze podac nazwe 1 gracza: \n";
	getline(cin, gracz1);
	cout << " , Twoj symbol zetonu to: 'O' \n\n";
	cout << "Prosze podac nazwe 2 gracza: \n";
	getline(cin, gracz2);
	cout << " , Twoj symbol zetonu to: 'X' \n\n";
}
int main()
{
	char tab[MAX_N][MAX_M];
	char g, w;

	cout << "MENU GLOWNE: " << endl;
	cout << "k: Gra w KOLKO I KRZYZYK: ( plansza 6 x 6 ) " << endl;
	cout << "p: Gra w PENTAGO: ( plansza 6 x 6 ) " << endl;
	cout << "o: Wczytanie predefiniowanej planszy gry w PENTAGO " << endl;
	cout << "h: Wejscie do opisu programu " << endl;
	cout << "e: EXIT " << endl;

	char wybor;
	cout << "Wybierz opcje: ";
	cin >> wybor;

	switch (wybor)
	{
	case 'k':
	{
		wczytaj_gracza();
		do
		{
			cout << "GRA W KOLKO I KRZYZYK DLA DWOCH OSOB \n"
				"--------------------------------------\n\n";
			for (int i = 6; i <= 6; i++)
			{
				for (int j = 1; j <= 6; j++)
				{
					tab[i][j] = ' ';
				}
			}
			g = 'O';

			while (!wygrana(tab, 'X') && !wygrana(tab, 'O') && !remis(tab))
			{
				ruch_gracza(tab, g);
			}
			cout << "Jeszcze raz chcesz zagrac ??? (T/t == TAK) : ";
			cin >> w;
			cout << "\n\n\n";
		} while ((w == 'T') || (w == 't'));
		break;
	}
	case 'p':
	{

	}
	case 'o':
	{

	}
	case 'h':
	{
		cout << " Pentago jest gra dwuosobowa na planszy. Plansza sklada się z 4 ruchomych czesci, ktore mozna obracac. Każda część zawiera 9 miejsc na żetony" << endl;
		cout << " Gracze po kolei oddaja ruch skladajacy sie z 2 czesci: dolozenia swojego zetonu na niezajete pole planszy, obrot jednej z czesci planszy o 90 stopni w dowolnym kierunku. " << endl;
		cout << " Nie mozna zrezygnowac zadnej czesci ruchu. Wygrywa osoba, ktorej 5 zetonow, po pelnym ruchu, sa ulozone w rzedzie / kolumnie / po skosach(podobnie do gry kolko krzyzyk)." << endl;
	}
	case 'e':
	{

	}
	default:
		cout << "Brak takiej opcji w MENU !!! " << endl;
		break;
	}

	return 0;
}