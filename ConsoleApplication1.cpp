#include <iostream>
void functiaMea() {
	int x = 7;
	int* addr_x = &x;
	int** addr_xaddr_x = &addr_x;
	int*** addr_xaddr_xaddr_x = &addr_xaddr_x;
	cout << x;
    cout << *addr_x;
	cout << **addr_xaddr_x;

	int main(); {
		functiaMea;
		return 0;
	}


}