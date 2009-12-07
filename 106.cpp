#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int max( int x, int y)
{
	return x > y ? x : y;
}


int gcd(int getal1, int getal2)
{
	if (getal1 < getal2)
		return gcd(getal2,getal1);
	else if (getal2 == 0)
		return getal1;
	else
		return gcd(getal2, getal1 % getal2);
}


void computeTriplets(int N)
{
	for(size_t m = 0; m < N/2; ++m)
	{
		m2 = 
	}
}


int main (int argc, char const *argv[])
{
	int N;
	
	while(scanf("%d\n", &N) == 1 )
	{
		int triplets = 0;
		int notriplets = 0;
		set<int> numbersInTriplet;
		set<int> cs;

		// int N2 = N * N;
		int N4 = max( N / 2 , 1);
		int N12 = max( N / 4 , 1);
		
		for ( int k = 1 ; k < N12  ; k = k+2)
		{
			for ( int n = 1 ; n < N4 ; n++ )
			{
				int b1 = 2 * k * n;
				if (b1 > N)
					break;
				
				int n2 = n * n;
				int c1 = k * n2;
				if (c1 > N)
					break;


					
				
				for ( int m = n + 1 ; m < N4 ; m++ )
				{
					// cout << "k: " << k  << " n: " << n << " m: " << m << endl;
					int m2 = m * m;
					int c2 = k * m2;
					if (c2 > N)
						break;
					
					int c = c2 + c1;
					if ( c > N)
						break;
					
					
					
					int b = b1 * m;
					if (b > N)
						break;
				
					
					int a = k * ( m2 - n2 );
					
					// if ( a > b)
					// 	break;
					
					// cout << "a:" << a << ", b:" << b << ", c:" << c << endl;
					
					// compute number of unique triples
					if ( gcd(a,b) == 1 && gcd(a,c) == 1 && gcd(b,c) == 1 )
						triplets++;

					// cout << a << "," << b << " - " << c << endl;


					numbersInTriplet.insert(a);
					numbersInTriplet.insert(b);
					numbersInTriplet.insert(c);
					
				}
			}
			
		}
		
		
		
		
		// for ( int x = 1 ; x < N ; x++)
		// {
		// 	int x2 = x*x;
		// 	for ( int y = x + 1 ; y < N ; y++ )
		// 	{
		// 		int y2 = y*y;
		// 		int z2 = x2 + y2;
		// 		// cout << x << "," << y << endl;
		// 		// cout << x2 << "," << y2 << " - " << z2 << endl;
		// 		if (z2 > N2)
		// 			break;
		// 		double a = sqrt(z2);
		// 		double a2 = round(a);
		// 		int z = (int) a2;
		// 		if ( abs(a - a2) > 0.00000000000001 )
		// 			continue;
		// 		else
		// 		{
		// 			if ( gcd(x,y) == 1 && gcd(z,x) == 1 && gcd(z,y) == 1 )
		// 				triplets++;
		// 			// TRIPLET
		// 			numbersInTriplet.insert(x);
		// 			numbersInTriplet.insert(y);
		// 			numbersInTriplet.insert(z);
		// 		}
		// 	}
		// }
		notriplets = N - numbersInTriplet.size();
		
		printf("%d %d\n", triplets, notriplets);
	}
	return 0;
}