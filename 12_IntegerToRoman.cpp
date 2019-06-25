class Solution {
private: 
    void concat(string& s, int& num, int denom) {
        string c;
        switch (denom) 
        {
            case 1000:
                c = "M";
                break;
            case 100:
                c = "C";
                break;
            case 10:
                c = "X";
                break;
            case 1:
                c = "I";
                break;
            default:
                cout << "Invalid denominator!!!" << endl;
        }
            
        int q = num / denom;
        for (int i = 0; i < q; ++i) {
            s += c;
        }
        num -= q * denom;
    }
    
public:
    string intToRoman(int num) {
        string s;
        while (num > 0) {
            int q;
            if (num >= 1000) {
                concat(s, num, 1000);
            } else if (num >= 500) {
                if (num >= 900) {
                    s += "CM";
                    num -= 900;
                } else { // 500 <= num < 900
                    s += "D";
                    num -= 500;
                }
            } else if (num >= 100) {
                if (num >= 400) {
                    s += "CD";
                    num -= 400;
                } else { // 100 <= num < 400
                    concat(s, num, 100);
                }
            } else if (num >= 50) {
                if (num >= 90) {
                    s += "XC";
                    num -= 90;
                } else { // 50 <= num < 90
                    s += "L";
                    num -= 50;
                }
            } else if (num >= 10) {
                if (num >= 40) {
                    s += "XL";
                    num -= 40;
                } else { // 10 <= num < 40
                    concat(s, num, 10);
                }
            } else if (num >= 5) {
                if (num >= 9) {
                    s += "IX";
                    num -= 9;
                } else { // 5 <= num < 9
                    s += "V";
                    num -= 5;
                }
            } else if (num == 4) {
                s += "IV";
                num -= 4;
            } else { // num < 4
                concat(s, num, 1);
            }
        }
        return s;
    }
};
