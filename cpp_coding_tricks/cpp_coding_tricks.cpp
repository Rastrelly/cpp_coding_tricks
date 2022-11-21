/*sources:
https://www.geeksforgeeks.org/c-tricks-competitive-programming-c-11/
https://betterprogramming.pub/8-neat-c-programming-tricks-you-should-know-be331b828be1
https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
https://www.geeksforgeeks.org/how-to-find-the-minimum-and-maximum-element-of-a-vector-using-stl-in-c/
*/

#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
	//autofill arrays with iota
	//use #include <numeric>
	int a[5] = { 0 };
	char c[3] = { '0' };
	int * f = new int[10];

	std::iota(a, a + 5, 10);
	std::iota(c, c + 3, 'a'); // {'a', 'b', 'c'}
	std::iota(f, f + 10, 1); //dynamic array
	
	for (int i = 0; i<5; i++) std::cout << a[i] << std::endl;
	for (int i = 0; i<3; i++) std::cout << c[i] << std::endl;
	for (int i = 0; i < 10; i++) std::cout << f[i] << std::endl;

	//fast number of digits
	//use #include <cmath>
	int v = -1234567890; //10
	int nDigits = floor(log10(abs(v))) + 1;
	std::cout << "v =" << v << "; digits in v = " << nDigits << std::endl;

	//copy arrays
	//use #include <algorithm>
	int src[5] = { 0, 12, 34, 50, 80 };
	int trg[5];
	std::copy_n(src, 5, trg);

	for (int i = 0; i < 5; i++) std::cout << src[i] << std::endl;
	for (int i = 0; i < 5; i++) std::cout << trg[i] << std::endl;

	int * src_d = new int[10];
	std::iota(src_d, src_d + 10, 0);
	int * trg_d = new int[10];
	std::copy_n(src_d, 10, trg_d);

	for (int i = 0; i < 10; i++) std::cout << src_d[i] << std::endl;
	for (int i = 0; i < 10; i++) std::cout << trg_d[i] << std::endl;

	//variable swap
	int v1 = 1;
	int v2 = 2;

	std::cout << "Pre swap: v1 =" << v1 << "; v2 = " << v2 << std::endl;

	v1 ^= v2 ^= v1 ^= v2; //"^" is bitwise XOR

	std::cout << "Post swap: v1 =" << v1 << "; v2 = " << v2 << std::endl;

	//bitwise operators
	// v1 = 5(00000101), v2 = 9(00001001)
	v1 = 5;
	v2 = 9;

	// The result is 00000001
	std::cout << "v1 = " << v1 << "," << " v2 = " << v2 << std::endl;
	std::cout << "v1 & v2 = " << (v1 & v2) << std::endl;

	// The result is 00001101
	std::cout << "v1 | v2 = " << (v1 | v2) << std::endl;

	// The result is 00001100
	std::cout << "v1 ^ v2 = " << (v1 ^ v2) << std::endl;

	// The result is 11111010
	std::cout << "~v1 = " << (~v1) << std::endl;

	// The result is 00010010
	std::cout << "v2 << 1" << " = " << (v2 << 1) << std::endl;

	// The result is 00000100
	std::cout << "v2 >> 1 " << "= " << (v2 >> 1) << std::endl;

	//fast min/max
	std::vector <int> getminmax = { 1, 3, 5, 7, 12 };
	int mn = *min_element(getminmax.begin(), getminmax.end());
	int mx = *max_element(getminmax.begin(), getminmax.end());
	std::cout << "min = " << mn << " max = " << mx << std::endl;

	int mn_std = std::min(10, 5);
	int mx_std = std::max(10, 5);
	std::cout << "min = " << mn_std << " max = " << mx_std << std::endl;
	std::initializer_list<int> dat = { 1, 3, 5, 7, 12 };
	int mn_arr = std::min(dat);
	std::min({ 1, 3, 5, 7, 12 });
	std::cout << "min list = " << mn_arr << std::endl;

	return 0;

}