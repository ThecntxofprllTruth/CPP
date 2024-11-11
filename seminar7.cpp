#include <iostream>
#include <iomanip>

using namespace std;


class produs
{
	char* np, um[5];
	int q;
	float pu;
public:
	produs(const char* fnp = "Nedefinit", const char* fum = "N/A", int cant = 0, float pret = 0) : q(cant), pu(pret)
	{
		np = new char[strlen(fnp) + 1];
		strcpy_s(np, strlen(fnp) + 1, fnp);
		strcpy_s(um, strlen(fum) + 1, fum);
	}

	produs(const produs& fprod) : q(fprod.q), pu(fprod.pu)
	{
		strcpy_s(um, strlen(fprod.um) + 1, fprod.um);
		np = new char[strlen(fprod.np) + 1];
		strcpy_s(np, strlen(fprod.np) + 1, fprod.np);
	}

	void set_cantitate(int);
	void set_denumire(const char*);

	int get_cantitate() { return q; }
	float get_valoare() { return pu * q; }
	char* get_denumire() { return np; }



	void afis_produs()
	{
		cout << setw(20) << setiosflags(ios::left) << np << "|" << resetiosflags(ios::left) << setw(4) << um << "|" << setw(5) << q << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << pu << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << get_valoare() << endl;
	}

	void citire_produs()
	{
		char stemp[100];
		cout << "nume produs: "; cin >> stemp;
		set_denumire(stemp);
		cout << "unitate de masura: "; cin >> um;
		cout << "cantitatea: "; cin >> q;
		cout << "pretul unitar: "; cin >> pu;
	}

	produs& operator =(produs obg)
	{
		set_denumire(obg.np);
		q = obg.q; pu = obg.pu;
		strcpy_s(um, strlen(obg.um) + 1, obg.um);
		return *this;
	}
	friend ostream& operator << (ostream& os, produs& prod)
	{
		os << setw(20) << setiosflags(ios::left) << prod.np << "|" << resetiosflags(ios::left) << setw(4) << prod.um << "|" << setw(5) << prod.q << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod.pu << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod.get_valoare() << endl;
		return os;
	}
	friend istream& operator >> (istream& is, produs& prod)
	{
		char stemp[100];
		cout << "nume produs: "; is >> stemp;
		prod.set_denumire(stemp);
		cout << "unitate de masura: "; is >> prod.um;
		cout << "cantitatea: "; is >> prod.q;
		cout << "pretul unitar: "; is >> prod.pu;
	}

	bool operator == (produs& prod)
	{
		return get_valoare() == prod.get_valoare();
	}

	bool operator == (float x)
	{
		return get_valoare() == x;
	}

	friend bool operator == (float x, produs& prod)
	{
		return prod.get_valoare() == x;
	}

	produs& operator ++()
	{
		q++;
		return *this;
	}

	produs operator++(int)
	{
		produs pn(*this);
		q++;
		return pn;
	}

	operator float()
	{
		return get_valoare();
	}

	produs operator +(int i)
	{
		return produs(np, um, q + i, pu);
	}

	friend produs operator + (int k, produs& p)
	{
		return produs(p.np, p.um, p.q + k, p.pu);
	}

	//produs& operator + (produs& prod)
	//{
	//	produs op;
	//	op.q = this->get_valoare() + prod.get_valoare();
	//	
	//	return op;
	//}

	~produs()
	{
		delete[] np;
	}
};

void produs::set_cantitate(int fq)
{
	if (fq >= 0) q = fq;
	else cerr << "Cantitate negativa!";
}

void produs::set_denumire(const char* fnp)
{
	if (strlen(fnp) > strlen(np))
	{
		delete[] np;
		np = new char[strlen(fnp) + 1];
	}
	strcpy_s(np, strlen(fnp) + 1, fnp);
}

class Magazie
{
	char nume[100];
	int nr_produse;
	produs* vp[100];

public:
	Magazie(const char* fnume = "Magazie") :nr_produse(0) { strcpy_s(nume, strlen(fnume) + 1, fnume); }
	Magazie& operator <<(produs * p) {
		vp[nr_produse++] = p;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Magazie& fm)
	{
		os << "Magazie: " << fm.nume << endl;
		for (int i = 0; i < fm.nr_produse; i++)
			os << *fm.vp[i];
		return os;
	}
};

void main()
{
	Magazie m1("Victoria");
	m1 << new produs("Mouse", "buc", 20, 30) << new produs("Tastatura", "buc", 30, 40) << new produs("Monitor", "buc", 40, 450);
	cout << m1;
}
