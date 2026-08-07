class Solution {
public:

    map<int, map<int,int>> factor = {
        {0, {}}, {1, {}},
        {2, {{2,1}}},
        {3, {{3,1}}},
        {4, {{2,2}}},
        {5, {{5,1}}},
        {6, {{2,1},{3,1}}},
        {7, {{7,1}}},
        {8, {{2,3}}},
        {9, {{3,2}}}
    };


    int sumValues(map<int,int>& mp) {
        int sum = 0;
        for(auto &[k,v] : mp)
            sum += v;
        return sum;
    }


    map<int,int> subtractMap(map<int,int> a, map<int,int> b) {
        for(auto &[k,v] : b) {
            a[k] = max(0, a[k] - v);
        }
        return a;
    }


    bool isSubset(map<int,int>& a, map<int,int>& b) {

        for(auto &[k,v] : a) {
            if(b[k] < v)
                return false;
        }

        return true;
    }


    pair<map<int,int>, bool> getPrimeCount(long long t) {

        map<int,int> cnt = {
            {2,0},{3,0},{5,0},{7,0}
        };


        for(int p : {2,3,5,7}) {

            while(t % p == 0) {
                cnt[p]++;
                t /= p;
            }
        }

        return {cnt, t == 1};
    }


    map<int,int> getPrimeCountFromString(string num) {

        map<int,int> cnt = {
            {2,0},{3,0},{5,0},{7,0}
        };


        for(char c:num) {

            int d = c-'0';

            for(auto &[p,f] : factor[d])
                cnt[p] += f;
        }

        return cnt;
    }



    map<int,int> getFactorCount(map<int,int> cnt) {

        map<int,int> res;


        int c8 = cnt[2]/3;
        int rem2 = cnt[2]%3;


        int c9 = cnt[3]/2;
        int rem3 = cnt[3]%2;


        int c4 = rem2/2;
        int c2 = rem2%2;


        int c6 = 0;


        if(c2 == 1 && rem3 == 1) {
            c2 = 0;
            rem3 = 0;
            c6 = 1;
        }


        if(rem3 == 1 && c4 == 1) {
            c2 = 1;
            c6 = 1;
            rem3 = 0;
            c4 = 0;
        }


        res[2]=c2;
        res[3]=rem3;
        res[4]=c4;
        res[5]=cnt[5];
        res[6]=c6;
        res[7]=cnt[7];
        res[8]=c8;
        res[9]=c9;


        return res;
    }



    string construct(map<int,int>& cnt) {

        string ans="";

        for(int d=2; d<=9; d++) {

            ans += string(cnt[d], char('0'+d));
        }

        return ans;
    }



    string smallestNumber(string num, long long t) {


        auto [primeCount, ok] = getPrimeCount(t);


        if(!ok)
            return "-1";



        auto factorCount = getFactorCount(primeCount);



        if(sumValues(factorCount) > num.size()) {

            return construct(factorCount);
        }



        auto prefix = getPrimeCountFromString(num);



        int zero = num.find('0');

        if(zero == string::npos) {

            zero = num.size();

            if(isSubset(primeCount,prefix))
                return num;
        }



        for(int i=num.size()-1;i>=0;i--) {


            int d = num[i]-'0';


            prefix = subtractMap(prefix,factor[d]);


            int remaining = num.size()-1-i;



            if(i > zero)
                continue;



            for(int bigger=d+1;bigger<=9;bigger++) {


                auto need =
                    subtractMap(
                        subtractMap(
                            primeCount,
                            prefix
                        ),
                        factor[bigger]
                    );


                auto digits = getFactorCount(need);



                if(sumValues(digits) <= remaining) {


                    int ones =
                        remaining - sumValues(digits);


                    return num.substr(0,i)
                        + char('0'+bigger)
                        + string(ones,'1')
                        + construct(digits);
                }
            }
        }



        auto bigger = getFactorCount(primeCount);


        return string(
            num.size()+1-sumValues(bigger),
            '1'
        ) + construct(bigger);
    }
};