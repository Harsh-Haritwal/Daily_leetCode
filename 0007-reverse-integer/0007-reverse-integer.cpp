class Solution {
public:
    int reverse(int x) {
        int y = 0;

        if (x > INT_MAX || x < INT_MIN) {
            return 0;
        }
        while (x != 0) {
            // Check for positive overflow
            if (y > INT_MAX / 10 || (y == INT_MAX / 10 && x > 7))
                return 0;

            // Check for negative overflow
            if (y < INT_MIN / 10 || (y == INT_MIN / 10 && x < -8))
                return 0;
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return y;

        return y;
    }
};