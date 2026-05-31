// User function Template for C++
class Solution {
	public:
	int number(int n) {
		int c = 0;
		while (n > 0) {
			n = n / 10;
			c++;
		}
		return c;
	}
	bool armstrongNumber(int n) {
	    int res=number(n);
	    int temp=n;
		int sum=0;
		while(n>0){
		    int rem=n%10;
		    n=n/10;
		    sum+=pow(rem,res);
		}
		
		if(temp==sum) return true;
		return false;
		
	}
};
