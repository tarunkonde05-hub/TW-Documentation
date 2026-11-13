"""Vector addition and dot product."""

from multiprocessing import Pool


def vec_add(a, b):
    if len(a) != len(b):
        raise ValueError("vectors must have the same length")
    return [x + y for x, y in zip(a, b)]


def dot(a, b):
    if len(a) != len(b):
        raise ValueError("vectors must have the same length")
    with Pool() as pool:
        products = pool.starmap(_mul, zip(a, b))
    return sum(products)


def _mul(x, y):
    return x * y


if __name__ == "__main__":
    a = [1, 2, 3, 4]
    b = [5, 6, 7, 8]
    print("a + b =", vec_add(a, b))
    print("a . b =", dot(a, b))
