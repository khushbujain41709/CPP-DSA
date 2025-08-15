import math
def mirrorReflection(p, q):
    lcm = p * q // math.gcd(p, q)
    m = lcm // p  # horizontal reflections
    n = lcm // q  # vertical reflections
    if m % 2 == 1 and n % 2 == 1:
        return 1
    elif m % 2 == 0 and n % 2 == 1:
        return 0
    else:
        return 2
mirrorReflection(2, 1)  # Output: 2
mirrorReflection(3, 1)  # Output: 1
