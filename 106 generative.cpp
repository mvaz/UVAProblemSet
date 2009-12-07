#include <iostream>
#include <cmath>
#include <set>


#define IS_EVEN( __N__ ) ( !(__N__ & 1))
// #define IS_EVEN( __N__ ) ( !(__N__ & 1))

using namespace std;


int gcd(int getal1, int getal2)
{
	if (getal1 < getal2)
		return gcd(getal2,getal1);
	else if (getal2 == 0)
		return getal1;
	else
		return gcd(getal2, getal1 % getal2);
}



int main (int argc, char const *argv[])
{
	int N;


	while(scanf("%d\n", &N) == 1 )
	{
		int myints[N+1];
		for(size_t i = 0; i < N+1; ++i)
		{
			myints[i] = 0;
		}
		int involved = 0;
		int primitives = 0;
		// set<int> involved;

		for(int m = 1, m2 = 1; m2 <= N; ++m && (m2 += m + m - 1) )
		{
			// cout << "m = " << m << ", m2 = " << m2 << endl;
	
			for(int n = 1, n2 = 1, mn = m; n < m; ++n && (n2 += n + n - 1) && (mn += m) )
			{
				int c = m2 + n2; // c = m^2 + n^2
				if(c > N)
					break;
		
				int a = m2 - n2; // a = m^2 - n^2
				int b = mn + mn; // b = 2 m n
				// bool coprime = gcd( m, n) <= 1;
				if(( (IS_EVEN(a) && not IS_EVEN(b)) || (IS_EVEN(b) && not IS_EVEN(a))) && gcd( m, n) == 1 )
					primitives++;
		
				// 
				int ak = a, bk = b, ck = c;

				while(ck <= N)
				{
					if (myints[ak] == 0) {
						myints[ak] = 1;
						involved++;
					}
					
					if (myints[bk] == 0) {
						myints[bk] = 1;
						involved++;
					}
					
					
					if (myints[ck] == 0) {
						myints[ck] = 1;
						involved++;
					}
						
						
						
					// involved.insert( ak );
					// involved.insert( bk );				
					// involved.insert( ck );
					ak += a + a;
					bk += b + b;
					ck += c + c;
				}
			}

		}
		// cout << primitives << " " <<  << endl;
		printf("%d %d\n", primitives, N - involved ); //( N - involved.size() ));
		// printf("%d %d\n", primitives, ( N - involved.size() ));
	}
			
	return 0;
}