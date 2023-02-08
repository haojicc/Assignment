#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define n 10


string dezero(string num){
    long int i;
    for(i = 0; i < num.length(); i++){
        if(num.at(i) > 48) break;
    }
    if(i ==num.length()) return "0";
    num.erase(0,i);
    return num;
}

int judge(string num1, string num2){
    if(num1.length() > num2.length()) return 1;
    if(num1.length() < num2.length()) return -1;
    long int i;
    for(i = 0; i < num1.length(); i++){
        if(num1.at(i) > num2.at(i)) return 1;
        if(num1.at(i) < num2.at(i)) return -1;
    }
    return 0;
}
class Solution {
public:

    string multiply(string num1, string num2){
        int s1 = num1.size();
        int s2 = num2.size();
        if(num1 == "0" || num2 == "0") return "0";
        int k = s1 + s2 - 2;
        if(k <= 0) return "";
        vector<int> v(s1+s2, 0);
        for(int i = 0; i < s1; i++){
            for(int j = 0; j < s2; j++){
                v[k-i-j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for(int i = 0; i < s1 + s2; i++){
            v[i] += carry;
            carry = v[i]/10;
            v[i] = v[i] % 10;
        }
        reverse(v.begin(), v.end());
        int u = 0;
        while(v[u] == 0) u++;
        string result = "";
        for(int i = u; i < v.size(); i++)
            result+=v[i]+'0';
        return result;
    }

    string addtion(string num1, string num2){
        string str1 = num1;
        string str2 = num2;
        int len = max(str1.size(), str2.size());
        string result;
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int carry = 0;
        for (int i = 0; i < len; ++i) {
            int str1_i = i < str1.size() ? str1[i] - '0' : 0;
            int str2_i = i < str2.size() ? str2[i] - '0' : 0;
            int val = (str1_i + str2_i + carry) % 10;
            carry = (str1_i + str2_i + carry) / 10;
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1) result.insert(result.begin(), '1');
        if (result[0] == '0') result[0] = ' ';
        return result;
    }

    string subtraction(string num1, string num2){
        num1 = dezero(num1);
        num2 = dezero(num2);
        long int i, j = 0;
        string c = "0";
        string c1, c2;
        string d = "-";
        if(judge(num1, num2) == 0) return c;
        if(judge(num1, num2) == 1){
            c1 = num1;
            c2 = num2;
        }
        if(judge(num1, num2) == -1){
            c1 = num2;
            c2 = num1;
            j = -1;
        }
        reverse(c1.begin(), c1.end());
        reverse(c2.begin(), c2.end());
        for(i = 0; i < c2.length(); i++){
            if(c2.at(i) >= 48 && c2.at(i) <= 57) c2.at(i)-=48;
            if(c2.at(i) >= 97 && c2.at(i) <= 122) c2.at(i)-=87;
        }
        for(i = 0; i < c1.length(); i++){
            if(c1.at(i)>=48&&c1.at(i)<=57) c1.at(i)-=48;
            if(c1.at(i)>=97&&c1.at(i)<=122) c1.at(i)-=87;
        }
        for(i = 0;i < c2.length(); i++){
            c1.at(i)=c1.at(i)-c2.at(i);
        }
        for(i = 0; i < c1.length()-1; i++){
            if(c1.at(i) < 0){
                c1.at(i) += n;
                c1.at(i+1)--;
            }
        }
        for(i = c1.length()-1; i >= 0; i--){
            if(c1.at(i)>0) break;
        }
        c1.erase(i+1,c1.length());
        for(i = 0; i < c1.length(); i++){
            if(c1.at(i)>=10) c1.at(i) += 87;
            if(c1.at(i)<10) c1.at(i) += 48;
        }
        reverse(c1.begin(),c1.end());
        if(j == -1) c1.insert(0,d);
        return c1;
    }

    string divide(string num1, string num2)
    {
        if(num2.length() == 1 && num2.at(0) == 48) return "error";
        long int i, j;
        string c1, c2, d, e;
        if(judge(num1,num2) == 0) return "1";
        if(judge(num1,num2) == -1){
            return "0";
        }
        c1 = dezero(num1);
        c2 = dezero(num2);
        d = "";
        e = "";
        for(i=0;i<c1.length();i++){
            j = 0;
            d = d + c1.at(i);
            d = dezero(d);
            while(judge(d,num2)>=0){
                d = subtraction(d,num2);
                d = dezero(d);
                j++;
            }
            e = e + "0";
            e.at(i) = j;
        }
        for(i = 0; i < e.length(); i++){
            if(e.at(i) >= 10) e.at(i) += 87;
            if(e.at(i) < 10) e.at(i) += 48;
        }
        e = dezero(e);
        return e;
    }


};

int main() {
    Solution ojb;
    string n1 = "10";
    string n2 = "2";

//    string n1 = "35978";
//    string n2 = "8805922";

    string ret = ojb.divide(n1, n2);
//    string ret = ojb.multiply(n1, n1);

    int lenth = ret.length();
    int prev = lenth % 3;
//    for(int i = 0; i < prev; i++){
//        std::cout << ret[i];
//    }
//    for(int i = prev; i < ret.length(); i+=3){
//        std::cout << ',' << ret[i] << ret[i+1] << ret[i+2];
//    }
    std::cout << "resulte.size=" << lenth << std::endl;
    for(int i = 0; i < ret.length(); i++){
        std::cout << ret[i];
    }
}

//subtraction;multiply
