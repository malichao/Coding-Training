/*
 * FibonacciBuzzFizzPrime.cpp
 *
 *  Created on: Apr 28, 2016
 *      Author: Lichao
 */
#include <utility>
#include <string>
#include <vector>

namespace fbfp{

using std::string;
using std::vector;

typedef std::pair<uint64_t, string> fbfp_pair;

inline bool isFizz(uint64_t n){
	if(n<3) return false;
	return n%3==0;
}

inline bool isBuzz(uint64_t n){
	if(n<5) return false;
	return n%5==0;
}

inline bool isPrime(uint64_t n){
	if(n<=1)
		return false;
	for(uint64_t i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

class FBFP {
public:


	//generate fibonacci series and its regarding string for n
	//===Test Cases===
	//-null cases	 : n=0,result.size()=0
	//-illegal cases : n<0
	//-range cases	 : fibonacci >=uint64_t
	//-normal cases	 : n=1,2,3,4,5,...
	void generate(const int n, vector<fbfp_pair> &result) {
		if(n<0)
			return;

		result.emplace_back(0, "0");	//n=0
		result.emplace_back(1, "1");	//n=1
		result.emplace_back(1, "1");	//n=2
		if(n<3){
			result.resize(n+1);
			return;
		}

		fbfp_pair f1, f2;
		for (int i = 3; i <= n; i++) {
			f1 = result[i - 1];
			f2 = result[i - 2];
			uint64_t sum = f1.first + f2.first;
			string s = fbfp::isFizz(sum) ? "Fizz" : "";
			s = fbfp::isBuzz(sum) ? "Buzz" : "";
			s = fbfp::isPrime(sum) ? "FizzBuzz" : std::to_string(sum);
			result.emplace_back(sum,s);
		}
	}

};


}