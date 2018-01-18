#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a[114] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
"No", "Lr" };

bool wordCheck(string str)
{
	for (int i = 0; i < 114; i++)
	{
		if (a[i].compare(str) == 0) return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	int T, test_case;

	for (int i = 0; i < 114; i++)
	{
		transform(a[i].begin(), a[i].end(), a[i].begin(), ::tolower);
	}

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		string input;
		cin >> input;

		string Answer;
		int len = input.length();
		bool check[50005] = { false };

		check[0] = true;
		check[1] = wordCheck(input.substr(0, 1));

		for (int i = 2; i <= len; i++)
			check[i] = (check[i - 1] && wordCheck(input.substr(i - 1, 1)) || check[i - 2] && wordCheck(input.substr(i - 2, 2)));

		if (check[len])
			Answer = "YES";
		else
			Answer = "NO";

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}