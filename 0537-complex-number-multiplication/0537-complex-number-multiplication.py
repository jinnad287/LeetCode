class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        # (a + bi) and (c + di)
        # Split the strings by the '+' character
        r1, i1 = num1.split('+')
        r2, i2 = num2.split('+')

        # Convert the real parts to integers
        a = int(r1)
        c = int(r2)

        # Convert the imaginary parts to integers (ignoring the 'i' at the end)
        b = int(i1[:-1])
        d = int(i2[:-1])

        real_part = (a * c) - (b * d)
        imaginary_part = (a * d) + (b * c)

        return f"{real_part}+{imaginary_part}i"
