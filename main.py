from math import log, sqrt


def f(x):
    return x ** 4 + 2 * x ** 3 - 4 * x ** 2 - 8 * x - 1


def f_prime(x):
    return 4 * x ** 3 + 6 * x ** 2 - 8 * x - 8


def lipsh_const():
    x1 = -2
    x2 = (1 - sqrt(17))/4
    x3 = (1 + sqrt(17))/4
    x4 = -3
    x5 = 2
    return max(abs(f_prime(x1)), abs(f_prime(x2)),
               abs(f_prime(x3)), abs(f_prime(x4)), abs(f_prime(x5)))


def broken_lines(a, b, eps, L):
    pass


a, b, eps, L = -3, 2, 0.001, lipsh_const()

