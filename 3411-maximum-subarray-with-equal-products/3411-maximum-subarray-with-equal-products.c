
int maxLength(int* nums, int numsSize) {
    int primes[] = {2, 3, 5, 7};
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {

        int sum[4] = {0, 0, 0, 0};
        int minExp[4] = {100, 100, 100, 100};
        int maxExp[4] = {0, 0, 0, 0};

        for (int j = i; j < numsSize; j++) {

            int x = nums[j];

            for (int k = 0; k < 4; k++) {

                int count = 0;

                while (x % primes[k] == 0) {
                    count++;
                    x /= primes[k];
                }

                sum[k] += count;

                if (count < minExp[k])
                    minExp[k] = count;

                if (count > maxExp[k])
                    maxExp[k] = count;
            }

            int valid = 1;

            for (int k = 0; k < 4; k++) {
                if (sum[k] != minExp[k] + maxExp[k]) {
                    valid = 0;
                    break;
                }
            }

            if (valid) {
                int len = j - i + 1;

                if (len > ans)
                    ans = len;
            }
        }
    }

    return ans;
}
