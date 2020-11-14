int solution(int n, int coins[], int i) {
    if (n == 0)
        return 0;
    if (coins[i] > n)
        return solution(n, coins, i - 1);
    return 1 + solution(n - coins[i], coins, i);
}