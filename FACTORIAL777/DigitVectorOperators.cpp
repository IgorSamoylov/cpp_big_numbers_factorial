#include <vector>
#include <algorithm>

using namespace std;

// Returns the sum of digit vectors using oveloaded operator +
vector <char> operator + (const vector <char>& v1, const vector <char>& v2)
{
	vector <char> x, y, result;
	x = v1; y = v2;
	// Vector y will always has max length
	if (x.size() > y.size()) swap(x, y);
	// Filling vector x with zeros in tail to conform vector y
	x.insert(x.end(), y.size() - x.size(), 0);

	// First step: Easy summing the elements of vectors
	for (size_t i = 0; i < y.size(); ++i) {
		result.push_back(x[i] + y[i]);
	}

	//Second step: Find overloaded bits and makes augment in a higher bits
	size_t isPresentNumber;
	char k;
	do
	{
		for (size_t i = 0; i < result.size(); ++i) {

			k = result[i];

			if (k > 9) {

				result[i] = k % 10;
				if (i < result.size() - 1) result[i + 1] += k / 10;

				// Compliting the result vector with a new higher bits
				else result.emplace(result.end(), k / 10);
			}
		}
		//Testing the result vector for bits that contains numbers but not digits only
		isPresentNumber = 0;
		for (size_t i = 0; i < result.size(); ++i) {
			if (result[i] < 10) ++isPresentNumber;
		}

	} while (isPresentNumber < result.size() - 1);
	return result;
}


//Returns product of two digit vector using overloaded operator *
vector <char> operator * (const vector <char>& x, const vector <char>& y)
{
	vector <char> term_one, term_two;

	for (size_t i = 0; i < x.size(); ++i) {
		//Fills the vector of current sum by multiplication of each bit
		for (size_t k = 0; k < y.size(); ++k) {
			term_one.push_back(x[i] * y[k]);
		}
		// Insert zeros in head of vector for provide shifting 
		term_one.insert(term_one.begin(), i, 0);
		// Summation of the two equal sized vectors
		term_two = term_one + term_two;
		// Clearing the vector of current summ
		term_one.clear();
	}
	return term_two;
}


//Returns result of subtraction of two digit vectors using overloaded operator -
vector <char> operator - (const vector <char>& v1, const vector <char>& v2) {

	vector <char> x, y, result;

	x = v1; y = v2;

	// Vector x length is always max
	if (x.size() < y.size()) swap(x, y);

	// Filling smallest vector y with zeros in tail
	y.insert(y.end(), x.size() - y.size(), 0);

	//Easy subtraction of vectors that provides some negative numbers in bits
	for (size_t i = 0; i < x.size(); ++i) {
		result.push_back(x[i] - y[i]);
	}

	// Finding the negative numbers and sequential transfer ones from higher bits 
	size_t isPresentNegative = 0;
	while (isPresentNegative < result.size() - 1) {

		for (size_t i = 0; i < result.size(); ++i) {
			if (result[i] < 0 && i < result.size() - 1) { result[i + 1] -= 1; result[i] += 10; }
		}

		//Testing for a negative numbers presence in bits
		isPresentNegative = 0;
		for (size_t i = 0; i < result.size(); ++i) {
			if (result[i] >= 0) isPresentNegative++;
		}
	}
	return result;
}