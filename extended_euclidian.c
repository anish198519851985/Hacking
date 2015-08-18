void extended_euclid(long a, long b, long *x,
                long *y, long *d)
/* calculates a * *x + b * *y = gcd(a, b) = *d */
/* Author: Pate Williams (c) 1997 */
{
        long q, r, x1, x2, y1, y2;

        if (b == 0) {
                *d = a, *x = 1, *y = 0;
                return;
        }
        x2 = 1, x1 = 0, y2 = 0, y1 = 1;
        while (b > 0) {
                q = a / b, r = a - q * b;
                *x = x2 - q * x1, *y = y2 - q * y1;
                a = b, b = r;
                x2 = x1, x1 = *x, y2 = y1, y1 = *y;
        }
        *d = a, *x = x2, *y = y2;
}
