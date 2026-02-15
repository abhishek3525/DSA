class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n1 = a.length() - 1;
        int n2 = b.length() - 1;
        int carry = 0;

        while (n1 >= 0 || n2 >= 0 || carry) {
            int sum = carry;

            if (n1 >= 0) {
                sum += a[n1] - '0';
                n1--;
            }

            if (n2 >= 0) {
                sum += b[n2] - '0';
                n2--;
            }

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
