def getZarr(string, z):
    n = len(string)
    l, r, k = 0, 0, 0

    for i in range(1, n):
        if i > r:
            # Case 1: i is outside the current Z-box
            l, r = i, i
            while r < n and string[r - l] == string[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:
            k = i - l
            if z[k] < r - i + 1:
                # Case 2a: z[k] is less than remaining length
                z[i] = z[k]
            else:
                # Case 2b: z[k] is greater or equal to remaining length
                l = i
                while r < n and string[r - l] == string[r]:
                    r += 1
                z[i] = r - l
                r -= 1

    return z

def zAlgorithm(s, p, n, m):
    res = 0
    concat = p + "$" + s
    l = len(concat)
    z = [0] * l
    z = getZarr(concat, z)
    for i in range(l):
        if z[i] == m:
            # A match of length m is found at index i
            res += 1
    return res