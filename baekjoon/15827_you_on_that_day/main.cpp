#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

long long euclidgcd(long long a, long long b);

struct Fraction {
	long long numerator; // above the horizontal line
	long long denominator; // below the horizontal line

	Fraction() : numerator(0), denominator(0) {
	}

	Fraction(long long numerator, long long denominator)
		: numerator(numerator), denominator(denominator) {
	}

	void beautify() {
		long long gcd = euclidgcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;

		if ((numerator < 0 && denominator < 0)
				|| (numerator > 0 && denominator < 0)) {
			numerator *= -1;
			denominator *= -1;
		}
		if (numerator == 0) {
			denominator = 1;
		}
	}

	Fraction operator- () const {
		return Fraction(-numerator, denominator);
	}

	Fraction operator+ (const Fraction &o) {
		Fraction result(0, 0);

		result.numerator = numerator * o.denominator + o.numerator * denominator;
		result.denominator = denominator * o.denominator;

		long long gcd = euclidgcd(result.denominator, result.numerator);

		result.numerator /= gcd;
		result.denominator /= gcd;

		return result;
	}

	Fraction operator-(const Fraction &o) {
		return operator+(-o);
	}

	Fraction operator*(const Fraction &o) {
		Fraction result(0, 0);

		result.numerator = numerator * o.numerator;
		result.denominator = denominator * o.denominator;

		long long gcd = euclidgcd(result.numerator, result.denominator);

		result.numerator /= gcd;
		result.denominator /= gcd;

		return result;
	}

	Fraction operator/ (const Fraction &o) {
		Fraction tmp = o;
		swap(tmp.numerator, tmp.denominator);
		return operator*(tmp);
	}
};

struct Term {
	int factorid;
	string factorname;

	Term(int factorid, const char *factorname)
		: factorid(factorid), factorname(factorname) {
	}

	virtual Fraction evaluate(Term **terms) = 0;
	virtual Fraction derivate(Term **terms, int factorid) = 0;
};

struct EnvironmentalTerm : Term {
	long long value;

	EnvironmentalTerm(int factorid, const char *factorname, long long value)
		: Term(factorid, factorname) {
			this->value = value;
	}

	Fraction evaluate(Term **terms) {
		return Fraction(value, 1);
	}

	Fraction derivate(Term **terms, int factorid) {
		if (this->factorid == factorid) return Fraction(1, 1);
		return Fraction(0, 1);
	}
};

struct ComplexTerm : Term {
	char op; // A, S, M, D

	int leftFactorId;
	int rightFactorId;

	Fraction evaluation;
	bool evaluated;

	ComplexTerm(int factorid, const char *factorname,
			char op, int leftFactorId, int rightFactorId)
		: Term(factorid, factorname) {
			this->op = op;
			this->leftFactorId = leftFactorId;
			this->rightFactorId = rightFactorId;

			evaluated = false;
	}

	Fraction evaluate(Term **terms) {
		if (evaluated == true) {
			return evaluation;
		}

		evaluated = true;

		Fraction left = terms[leftFactorId]->evaluate(terms);
		Fraction right = terms[rightFactorId]->evaluate(terms);

		if (op == 'A') {
			return evaluation = left + right;
		} else if (op == 'S') {
			return evaluation = left - right;
		} else if (op == 'M') {
			return evaluation = left * right;
		} else { // op == 'D'
			return evaluation = left / right;
		}
	}

	Fraction derivate(Term **terms, int factorid) {
		if (this->factorid == factorid) {
			return Fraction(1, 1);
		}

		Term *leftTerm = terms[leftFactorId];
		Term *rightTerm = terms[rightFactorId];

		if (op == 'A') {
			return leftTerm->derivate(terms, factorid) + rightTerm->derivate(terms, factorid);
		} else if (op == 'S') {
			return leftTerm->derivate(terms, factorid) - rightTerm->derivate(terms, factorid);
		} else if (op == 'M') {
			return leftTerm->derivate(terms, factorid) * rightTerm->evaluate(terms)
				+ leftTerm->evaluate(terms) * rightTerm->derivate(terms, factorid);
		} else { // op == 'D'
			return (leftTerm->derivate(terms, factorid) * rightTerm->evaluate(terms)
					- leftTerm->evaluate(terms) * rightTerm->derivate(terms, factorid))
				/ (rightTerm->evaluate(terms) * rightTerm->evaluate(terms));
		}
	}
};

string factornames[1003];
map<string, int> factorid;

Term *terms[1003];

int getfactorid(const char *factorname) {
	string str(factorname);

	if (factorid.find(str) == factorid.end()) // not found
		factorid[str] = factorid.size();

	return factorid[str];
}

long long euclidgcd(long long a, long long b) {
	if (b == 0) return a;
	return euclidgcd(b, a % b);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		char factorname[22];
		char type;
		scanf("%s %c", factorname, &type);

		factornames[n] = string(factorname);
		int factorid = getfactorid(factorname);

		if (type == 'E') { // environmental factor
			long long value;
			scanf("%lld", &value);

			terms[factorid] = new EnvironmentalTerm(factorid, factorname, value);
		} else { // complex factor
			char factorA[22];
			char factorB[22];
			scanf("%s %s", factorA, factorB);

			terms[factorid] = new ComplexTerm(factorid, factorname,
					type, getfactorid(factorA), getfactorid(factorB));
		}
	}
	sort(factornames, factornames + N);

	Term *root = terms[getfactorid("HAPPY")];

	for (int n = 0; n < N; n++) {
		string factorname = factornames[n];
		int factorid = getfactorid(factorname.c_str());

		Fraction result = root->derivate(terms, factorid);
		result.beautify();

		printf("%s %lld/%lld\n", factorname.c_str(), result.numerator, result.denominator);
	}

	return 0;
}
