#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define space cout << ' ';


/**
 * 			-		-				 -		 -		-		 -		 -		 -		 a
 *   |		 |		 |		| |		| 		| 		 |		| |		| |		| |		f b
 *   		-		-		 -		 -		 -				 -		 -				 g
 *	 |	   |		 |		  |		  |		| |		 |		| |		  |		| |		e c
 * 			-		-				 -		 -				 -		 -		 -		 d
 */		


string onlyNumbers(string s) {
	string nums = "";
	for (char c : s) {
		if (isdigit(c)) nums += c;
	}
	return nums;
}

void printHorizontalSegment(char segment[], int num, int size) {
	space;
	for (int j=0; j<size; j++) cout << segment[num];
	space;
}

void printVerticalSegments(char segmentLeft[], char segmentRight[], int num, int size) {
	cout << segmentLeft[num];
	for (int j=0; j<size; j++) space;
	cout << segmentRight[num];
}


int main(){
	
	int size, nNums, lastNumber;
	string line, numbersStr;
	vector <int> numbersNoLast;

	// 0 1 2 3 4 5 6 7 8 9
	char segment_a[] = {'-', ' ', '-', '-', ' ', '-', '-', '-', '-', '-'};
	char segment_b[] = {'|', '|', '|', '|', '|', ' ', ' ', '|', '|', '|'};
	char segment_c[] = {'|', '|', ' ', '|', '|', '|', '|', '|', '|', '|'};
	char segment_d[] = {'-', ' ', '-', '-', ' ', '-', '-', ' ', '-', '-'};
	char segment_e[] = {'|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', ' '};
	char segment_f[] = {'|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|'};
	char segment_g[] = {' ', ' ', '-', '-', '-', '-', '-', ' ', '-', '-'};

	while(cin >> size >> line) {
		numbersStr = onlyNumbers(line);
		nNums = numbersStr.length();
		if (size == 0 && nNums == 1 && numbersStr[0] == '0') break;

		numbersNoLast.clear();
		for (int i=0; i<nNums-1; i++) {
			numbersNoLast.push_back(numbersStr[i] - 48);
		}
		lastNumber = numbersStr[nNums-1] - 48;


		// line 1. segment a
		for (int num : numbersNoLast) {
			printHorizontalSegment(segment_a, num, size);
			space;
		}
		printHorizontalSegment(segment_a, lastNumber, size);
		cout << '\n';

		// line 2. segments f and b
		for (int i=0; i<size; i++){
			for (int num : numbersNoLast) {
				printVerticalSegments(segment_f, segment_b, num, size);
				space;
			}
			printVerticalSegments(segment_f, segment_b, lastNumber, size);
			cout << '\n';
		}
		
		// line 3. segment g
		for (int num : numbersNoLast) {
			printHorizontalSegment(segment_g, num, size);
			space;
		}
		printHorizontalSegment(segment_g, lastNumber, size);
		cout << '\n';

		// line 4. segments e and c
		for (int i=0; i<size; i++){
			for (int num : numbersNoLast) {
				printVerticalSegments(segment_e, segment_c, num, size);
				space;
			}
			printVerticalSegments(segment_e, segment_c, lastNumber, size);
			cout << '\n';
		}
		
		// line 5. segment d
		for (int num : numbersNoLast) {
			printHorizontalSegment(segment_d, num, size);
			space;
		}
		printHorizontalSegment(segment_d, lastNumber, size);
		cout << '\n';


		cout << '\n';
	}

	return 0;
}
