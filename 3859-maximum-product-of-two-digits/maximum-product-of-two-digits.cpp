class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int secondLargest = 0;

        for (; n > 0; n /= 10) {
            int digit = n % 10;

            if (digit >= largest) {
                secondLargest = largest;
                largest = digit;
            }
            else if (digit > secondLargest) {
                secondLargest = digit;
            }
        }

        return largest * secondLargest;
    }
};
