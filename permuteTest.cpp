/*  Twig Griffin
    2024-11-14
    Permutation timing by data type
*/

#include "Timer.hpp"
#include <iostream>

using namespace std;


long factorial( int n ) {
	if( n < 0 ) {
		return 0;
	}

	long result = 1;
	while( n > 1 ) {
		result *= n;
		n--;
	}
	return result;
}

void swapIndexDouble( double* arr, const int size, int i1, int i2 ) {
	// cout << "swapping\n";
	if( size == 0 ) { return; }

	if ( i1 <= -1 ) {
		i1 = size + i1;
	}
	if ( i2 <= -1 ) {
		i2 = size + i2;
	}
	double temp = arr[i1];

	arr[i1] = arr[i2];
	arr[i2] = temp;
	// cout << "temp is " << temp << "\n";
}

void nextPermutationDouble( double* arr, const int size ) {
	// cout << "permuting\n";
	if( size == 0 ) { return; }
	int m, k, p ,q;
	m = size - 2;
	while( arr[m] > arr[m+1]) {
		m--;
		if( m == -1 ) {
			break;
		}
	}
	
	k = size - 1;
	while( m >= 0 && arr[m] > arr[k] ) {
		k--;
	}
	
	swapIndexDouble(arr, size, m, k);

	p = m + 1;
	q = size - 1;
	while( p < q ) {
		swapIndexDouble(arr, size, p, q);
		p++;
		q--;
	}
}


void swapIndexFloat( float* arr, const int size, int i1, int i2 ) {
	// cout << "swapping\n";
	if( size == 0 ) { return; }

	if ( i1 <= -1 ) {
		i1 = size + i1;
	}
	if ( i2 <= -1 ) {
		i2 = size + i2;
	}
	float temp = arr[i1];

	arr[i1] = arr[i2];
	arr[i2] = temp;
	// cout << "temp is " << temp << "\n";
}

void nextPermutationFloat( float* arr, const int size ) {
	// cout << "permuting\n";
	if( size == 0 ) { return; }
	int m, k, p ,q;
	m = size - 2;
	while( arr[m] > arr[m+1]) {
		m--;
		if( m == -1 ) {
			break;
		}
	}
	
	k = size - 1;
	while( m >= 0 && arr[m] > arr[k] ) {
		k--;
	}
	
	swapIndexFloat(arr, size, m, k);

	p = m + 1;
	q = size - 1;
	while( p < q ) {
		swapIndexFloat(arr, size, p, q);
		p++;
		q--;
	}
}


void swapIndexInt( int* arr, const int size, int i1, int i2 ) {
	// cout << "swapping\n";
	if( size == 0 ) { return; }

	if ( i1 <= -1 ) {
		i1 = size + i1;
	}
	if ( i2 <= -1 ) {
		i2 = size + i2;
	}
	int temp = arr[i1];

	arr[i1] = arr[i2];
	arr[i2] = temp;
	// cout << "temp is " << temp << "\n";
}

void nextPermutationInt( int* arr, const int size ) {
	// cout << "permuting\n";
	if( size == 0 ) { return; }
	int m, k, p ,q;
	m = size - 2;
	while( arr[m] > arr[m+1]) {
		m--;
		if( m == -1 ) {
			break;
		}
	}
	
	k = size - 1;
	while( m >= 0 && arr[m] > arr[k] ) {
		k--;
	}
	
	swapIndexInt(arr, size, m, k);

	p = m + 1;
	q = size - 1;
	while( p < q ) {
		swapIndexInt(arr, size, p, q);
		p++;
		q--;
	}
}


void swapIndexLong( long* arr, const int size, int i1, int i2 ) {
	// cout << "swapping\n";
	if( size == 0 ) { return; }

	if ( i1 <= -1 ) {
		i1 = size + i1;
	}
	if ( i2 <= -1 ) {
		i2 = size + i2;
	}
	long temp = arr[i1];

	arr[i1] = arr[i2];
	arr[i2] = temp;
	// cout << "temp is " << temp << "\n";
}

void nextPermutationLong( long* arr, const int size ) {
	// cout << "permuting\n";
	if( size == 0 ) { return; }
	int m, k, p ,q;
	m = size - 2;
	while( arr[m] > arr[m+1]) {
		m--;
		if( m == -1 ) {
			break;
		}
	}
	
	k = size - 1;
	while( m >= 0 && arr[m] > arr[k] ) {
		k--;
	}
	
	swapIndexLong(arr, size, m, k);

	p = m + 1;
	q = size - 1;
	while( p < q ) {
		swapIndexLong(arr, size, p, q);
		p++;
		q--;
	}
}


void swapIndexUnsigned( unsigned* arr, const int size, int i1, int i2 ) {
	// cout << "swapping\n";
	if( size == 0 ) { return; }

	if ( i1 <= -1 ) {
		i1 = size + i1;
	}
	if ( i2 <= -1 ) {
		i2 = size + i2;
	}
	unsigned temp = arr[i1];

	arr[i1] = arr[i2];
	arr[i2] = temp;
	// cout << "temp is " << temp << "\n";
}

void nextPermutationUnsigned( unsigned* arr, const int size ) {
	// cout << "permuting\n";
	if( size == 0 ) { return; }
	int m, k, p ,q;
	m = size - 2;
	while( arr[m] > arr[m+1]) {
		m--;
		if( m == -1 ) {
			break;
		}
	}
	
	k = size - 1;
	while( m >= 0 && arr[m] > arr[k] ) {
		k--;
	}
	
	swapIndexUnsigned(arr, size, m, k);

	p = m + 1;
	q = size - 1;
	while( p < q ) {
		swapIndexUnsigned(arr, size, p, q);
		p++;
		q--;
	}
}



int timeDoubles( double* arr, const int size, const int totalPerms ) {
  Timer timer;
	timer.start();

  long numPerms = 0;
	do {
    nextPermutationDouble( arr, size );
    numPerms++;
  } while( numPerms < totalPerms );

	return timer.report();
}

int timeFloats( float* arr, const int size, const int totalPerms ) {
  Timer timer;
	timer.start();

  long numPerms = 0;
	do {
    nextPermutationFloat( arr, size );
    numPerms++;
  } while( numPerms < totalPerms );

	return timer.report();
}

int timeInts( int* arr, const int size, const int totalPerms ) {
  Timer timer;
	timer.start();

  long numPerms = 0;
	do {
    nextPermutationInt( arr, size );
    numPerms++;
  } while( numPerms < totalPerms );

	return timer.report();
}

int timeLongs( long* arr, const int size, const int totalPerms ) {
  Timer timer;
	timer.start();

  long numPerms = 0;
	do {
    nextPermutationLong( arr, size );
    numPerms++;
  } while( numPerms < totalPerms );

	return timer.report();
}

int timeUnsigneds( unsigned* arr, const int size, const int totalPerms ) {
  Timer timer;
	timer.start();

  long numPerms = 0;
	do {
    nextPermutationUnsigned( arr, size );
    numPerms++;
  } while( numPerms < totalPerms );

	return timer.report();
}



int main() {

  int arrSize = 11;
  long totalPerms = factorial(arrSize);

	int numTests = 10;

  
  float floats[arrSize] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
  cout << "Floats";
	for(int i = 0; i < numTests; i++ ) {
		cout << ", " << timeFloats(floats, arrSize, totalPerms);
	}
	cout << "\n";


  double doubles[arrSize] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
  cout << "Doubles";
	for(int i = 0; i < numTests; i++ ) {
		cout << ", " << timeDoubles(doubles, arrSize, totalPerms);
	}
	cout << "\n";


  int ints[arrSize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout << "Ints";
	for(int i = 0; i < numTests; i++ ) {
		cout << ", " << timeInts(ints, arrSize, totalPerms);
	}
	cout << "\n";
  

  long longs[arrSize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout << "Longs";
	for(int i = 0; i < numTests; i++ ) {
		cout << ", " << timeLongs(longs, arrSize, totalPerms);
	}
	cout << "\n";


  unsigned unsigneds[arrSize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout << "Unsigneds";
	for(int i = 0; i < numTests; i++ ) {
		cout << ", " << timeUnsigneds(unsigneds, arrSize, totalPerms);
	}
	cout << "\n";
  return 0;
}
