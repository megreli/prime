#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
	vector<int> primes;
	vector<int>::iterator p1, p2;
	primes.push_back(2);	// პირველი მარტივი რიცხვი
	primes.push_back(3);	// მეორე მარტივი რიცხვი
	int k, n = 10000;	// ფიქსირებული ზღვარი - არჩევადი (INT_MAX-ამდე)
	for(int l = 6; l < n; l += 2) {	// 2n
		// მარტივი რიცხვის პოვნა
		k = l - 1;	// მარტო კენტი რიცხვებია 2-ის გარდა
		p1 = primes.begin() + 1;   // 2 - ის გამოტოვება (ბიჯ.შემც)
		p2 = primes.end();
		while(p1 != p2) {
			if(k % *p1 == 0) break;	// შედგენილი რიცხვი
			//cout << k << " ? " << *p1 << " P "<< endl;// (ბიჯ.დათვლა)
			p1++;	// ალბათ მარტივი რიცხვია :) შევამოწმოთ თავიდან..
		}
		if(p1 == p2)	// მარტივი რიცხვის შენახვა
			primes.push_back(k);
		// ვიწყებთ გოლდბახის ჰიპოთეზის გადამოწმება
		p1 = primes.end()-1;	// ბიჯების შემცერებისთვის ბოლოდან ვთვლით
		while(p1 != primes.begin()) {
			p2 = primes.begin();	// (ბიჯ.შემც)
			while(p2 != primes.end()) {
				if((*p1 + *p2) > l) p2 = primes.end();	// (ბიჯ.შემც)
				else if((*p1 + *p2) == l) break;	// 2n = P1 + p2
				else {
		//cout << l << " ! " << *p1 << " + " << *p2 << endl;// (ბიჯ.დათვლა)
					p2++;	// 2n ? P1 + p2
				}
			}
			if(p2 != primes.end()) break;	// 2n = p1 + p2
			p1--;	// 2n ? p1 + p2
		}
		if(p1 != primes.begin())	//	ტოლობის ბეჭდვა
			cout << l << " = " << *p1 << " + " << *p2 << endl;
		else	// ვიპოვეთ!
			cout << l << " != " << *p1 << " + " << *p2 << "\t<---!!!" << endl;
	}
	return 0;
}
